#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "../ISA.h"

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
	printf("Unknown instruction: %s\n", word);
	exit(0);
}

/**
 * Compiles a file
 * @param[in] The name/path of the file to be compiled
 * @param[out] The compiled binary will be stored here
 */
size_t Compile(const char* fileName, uint8_t* output) {
	char line[1024], * temp = NULL;
	size_t i = 0;
	FILE* file = fopen(fileName, "r");
	if (file == NULL) {
		perror("Error opening input file");
		exit(0);
	}
	while(!feof(file)) {
		fgets(line, 1024, file);
		if (ferror(file)) {
			perror("Error reading input file");
			fclose(file);
			exit(0);
		}
		StringToUpperCase(line);
		temp = strtok(line, " \t\r\n");
		while(temp != NULL) {
			if (strcmp(temp, "\\") == 0) break;
			output[i] = Word2Opcode(temp);
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
 * Main entry point - the program starts here. :)
 * @param[in] The number of command-line parameters
 * @param[in] The command-line parameters
 * @returns Zero unless the OS says otherwise
 */
int main(int argc, const char** argv) {
	uint8_t binary[1024];	
	size_t bytesRead = 0;
	if (argc != 3) {
		printf("Usage: dfcc inputFile outputFile\n");
		return 0;
	}
	bytesRead = Compile(argv[1], binary);
	Save(argv[2], binary, bytesRead);
	return 0;
}

