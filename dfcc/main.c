#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "../ISA.h"

/**
 * Checks if a word is a number, with an optional negative sign
 * @param[in] The number
 * @returns True if it is, false if it isn't
 */
bool IsNumber(char* word) {
	size_t i, length;
	if (word == NULL) return false;
	i = word[0] == '-' ? 1 : 0;
	length = strlen(word);
	for (; i<length; i++) if (!isdigit(word[i])) return false;
	return true;
}

/**
 * Makes a string uppercase
 * @param[in, out] The string
 * @remarks This changes the original string, not a copy.
 */
void StringToUpperCase(char* input) {
	size_t i, length;
	if (input == NULL) return;
	length = strlen(input);
	for (i=0; i<length; i++) input[i] = toupper(input[i]);
}

/**
 * Compiles a single word to binary
 * @param[in] The word
 * @returns The binary equivalent of that word
 */
uint8_t Word2Opcode(char* word) {
	if (word[0] == 'B') {
		if (strcmp(word, "BRANCH") == 0) return BRANCH;
		if (strcmp(word, "BYE") == 0) return BYE;
	}
	if (word[0] == 'C') {
		if (strcmp(word, "C@") == 0) return CFETCH;
		if (strcmp(word, "C!") == 0) return CSTORE;
	}
	if (word[0] == 'D') {
		if (strcmp(word, "DOLIST") == 0) return DOLIST;
		if (strcmp(word, "DOLIT") == 0) return DOLIT;
		if (strcmp(word, "DROP") == 0) return DROP;
		if (strcmp(word, "DUP") == 0) return DUP;
	}
	if (word[0] == 'E') {
		if (strcmp(word, "EXECUTE") == 0) return EXECUTE;
		if (strcmp(word, "EXIT") == 0) return EXIT;
	}
	if (word[0] == 'N') {
		if (strcmp(word, "NEXT") == 0) return NEXT;
		if (strcmp(word, "NEXTLOOP") == 0) return NEXTLOOP;
	}
	if (word[0] == 'R') {
		if (strcmp(word, "RP@") == 0) return RP_FETCH;
		if (strcmp(word, "RP!") == 0) return RP_STORE;
		if (strcmp(word, "R>") == 0) return R_FROM;
		if (strcmp(word, "R@") == 0) return R_FETCH;
	}
	if (word[0] == 'S') {
		if (strcmp(word, "SP@") == 0) return SP_FETCH;
		if (strcmp(word, "SP!") == 0) return SP_STORE;
		if (strcmp(word, "SWAP") == 0) return SWAP;
	}
	if (word[0] == '?') {
		if (strcmp(word, "?BRANCH") == 0) return QUESTION_BRANCH;
		if (strcmp(word, "?RX") == 0) return QUESTION_RX;
	}
	if (word[0] == '!') {
		if (strcmp(word, "!IO") == 0) return BANG_IO;
		if (strcmp(word, "!") == 0) return STORE;
	}
	if (strcmp(word, "OR") == 0) return OR;
	if (strcmp(word, "TX!") == 0) return TX_BANG;
	if (strcmp(word, "UM+") == 0) return UM_ADD;
	if (strcmp(word, "AND") == 0) return AND;
	if (strcmp(word, "XOR") == 0) return XOR;
	if (strcmp(word, "@") == 0) return FETCH;
	if (strcmp(word, "0<") == 0) return COMPARE;
	if (strcmp(word, ">R") == 0) return TO_R;
	if (strcmp(word, "OVER") == 0) return OVER;
	return 255;	// for now
}

/**
 * Compiles a file
 * @param[in] The name/path of the file to be compiled
 * @param[out] The compiled binary will be stored here
 */
size_t Compile(const char* fileName, uint8_t* output) {
	char line[1024], * temp = NULL;
	size_t i = 0;
	int32_t literal;
	FILE* file = fopen(fileName, "r");
	if (file == NULL) {
		perror("Error opening input file");
		exit(0);
	}
	while(!feof(file)) {
		// Read the next line
		fgets(line, 1024, file);
		if (ferror(file)) {
			perror("Error reading input file");
			fclose(file);
			exit(0);
		}
		
		// Make it uppercase for easier string-comparison
		StringToUpperCase(line);
		
		// Now go word-by-word, compiling everything it can.
		temp = strtok(line, " \t\r\n");
		while(temp != NULL) {
			// If we've reached a comment, we're done with this line.
			if (strcmp(temp, "\\") == 0) break;
			
			// Try to figure out which opcode the word is.
			output[i] = Word2Opcode(temp);
			
			// If it failed to figure that out - at least for now - the
			// number 255 is returned; in that case, check the word is a
			// number (allowing negative signs but no decimal points)
			if (output[i] == 255) {
				
				// If it's not a number, it's a user error. :)
				if (!IsNumber(temp)) {
					printf("Unknown instruction: %s\n", temp);
					exit(0);
				}
				
				// If it gets here, it's a number; now the question is,
				// how many bytes do we store that number in?  For now, 1.
				output[i] = DOLIT;
				i++;
				literal = atoi(temp);
				output[i] = literal % 256;
				literal >>= 8;
				i++;
				output[i] = literal % 256;
				literal >>= 8;
				i++;
				output[i] = literal % 256;
				literal >>= 8;
				i++;
				output[i] = literal % 256;
			}
			
			// And continue the loop
			i++;
			temp = strtok(NULL, " \t\r\n");
		}
	}
	fclose(file);
	return i -1;	// - 1 because of the i++ loop bove
}

/**
 * Saves compiled binary data to a file
 * @param[in] The name/path of the file to be compiled
 * @param[in] The compiled binary
 * @param[in] The size of the file, in bytes
 */
void Save(const char* fileName, uint8_t* binary, size_t size) {
	FILE* file = fopen(fileName, "wb");
	if (file == NULL) {
		perror("Error opening output file");
		exit(0);
	}
	fwrite(binary, 1, size, file);
	if (ferror(file)) {
		perror("Error writing to output file");
		fclose(file);
		exit(0);
	}
	fclose(file);
}

/**
 * Shows command-line usage and an exmple or two
 */
void ShowHelp() {
	printf("\nDFCC: DIRT'S FORTH CHIP COMPILER\n\n");
	printf("Usage:\n");
	printf("    dfcc inputFile outputFile\n\tdfcc -v|--version\n\n");
	printf("Command-line options:\n");
	printf("    inputFile:         Name/path of the file to be compiled\n");
	printf("    outputFile:        Name/path of the compiled binary\n");
	printf("                       (what to call the compiled file)\n");
	printf("    -v or --version:   Print the version number\n\n");
	printf("Example:\n");
	printf("    dfcc ./myFile.fs ./myBinary\n\n");
}

/**
 * Main entry point - the program starts here. :)
 * @param[in] The number of command-line parameters
 * @param[in] The command-line parameters
 * @returns Zero unless the OS says otherwise
 */
int main(int argc, const char** argv) {
	uint8_t binary[1024];	
	size_t bytesRead = 0;
	if (argc == 2) {
		if (strcmp(argv[1], "-v") == 0 || strcmp(argv[1], "--version") == 0)
			printf("dfcc version 1.0.0\n");
		else ShowHelp();
		return 0;
	}
	
	if (argc != 3) {
		ShowHelp();
		return 0;
	}
	
	bytesRead = Compile(argv[1], binary);
	Save(argv[2], binary, bytesRead);
	return 0;
}

