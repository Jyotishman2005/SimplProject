#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MEMORY_SIZE 256

int main() {
    char line[MEMORY_SIZE];
    unsigned char memory[MEMORY_SIZE] = {0}; // Initialize memory with zeros
    char opcode;
    int address, value;
    
    while (fgets(line, sizeof(line), stdin)) {
        if (line[0] == 'X') break;  // Exit condition
        if (line[0] == '*') {       // Comment line
            printf("Comment: %s", line+1);
            continue;
        }

        if (sscanf(line, "%d %c %d", &address, &opcode, &value) != 3 || address < 0 || address >= MEMORY_SIZE)
            continue; // Invalid input or out-of-bounds address

        switch (opcode) {
            case '=':
                memory[address] = (unsigned char)value;
                break;
            case '+':
                memory[address] += (unsigned char)value;
                break;
            case '-':
                memory[address] -= (unsigned char)value;
                break;
            default:
                continue;
        }
    }
    
    // Print final memory state
    printf("Final Memory State:\n");
    for (int i = 0; i < MEMORY_SIZE; i++) {
        if (memory[i] != 0)
            printf("Address %d: %d\n", i, memory[i]);
    }
    
    return 0;
}
