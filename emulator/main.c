#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "../ISA.h"

#define STACK_SIZE 4096

bool LoadBinary(const char* fileName, uint8_t* cpu) {
	size_t i = 0;
	FILE* file = fopen(fileName, "rb");
	if (file == NULL) {
		perror("Error opening input file");
		return false;
	}
	while(!feof(file)) {
		if (!fread(cpu + i, 1, 1, file)) {
			if (ferror(file)) {
				perror("Error opening input file");
				fclose(file);
				return false;
			}
		}
		i++;
	}
	fclose(file);
	return true;
}

void RunBinary(uint8_t* cpu) {
	printf("Just to keep the compiler happy: %d\n", cpu[0]);
}

int main(int argc, const char** argv) {
	uint8_t cpu[STACK_SIZE];	// 4K ought to do it for now :D
	
	if (argc == 0) {
		printf("Usage: emulator yourCompiledFile\n");
		return 0;
	}
	if (!LoadBinary(argv[1], cpu)) return 1;
	RunBinary(cpu);
	return 0;
}
