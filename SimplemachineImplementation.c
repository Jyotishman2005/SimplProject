#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MEMORY_SIZE 256
//Save & Load Memory (S filename & L filename): Allows saving and loading memory state.
void save_memory(const char *filename, unsigned char memory[]) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        printf("Error saving memory to file.\n");
        return;
    }
    fwrite(memory, sizeof(unsigned char), MEMORY_SIZE, file);
    fclose(file);
    printf("Memory saved to %s\n", filename);
}

void load_memory(const char *filename, unsigned char memory[]) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        printf("Error loading memory from file.\n");
        return;
    }
    fread(memory, sizeof(unsigned char), MEMORY_SIZE, file);
    fclose(file);
    printf("Memory loaded from %s\n", filename);
}

int main() {
    char line[MEMORY_SIZE];
    char file_name[MEMORY_SIZE];
    unsigned char memory[MEMORY_SIZE] = {0}; // Initialize memory with zeros
    char opcode;
    int address, value;
    
    while (fgets(line, sizeof(line), stdin)) {
        if (line[0] == 'X') break;  // Exit condition
        if (line[0] == '*') {       // Comment line
            printf("Comment: %s", line+1);
            continue;
        }
        
        //Memory Dump (D Command): Displays all memory addresses and values.
        //Reset Memory (R Command): Resets all memory values to zero.

        if (line[0] == 'D') { // Dump memory
            printf("Memory Dump:\n");
            for (int i = 0; i < MEMORY_SIZE; i++) {
                printf("Address %d: %d\n", i, memory[i]);
            }
            continue;
        }
        
        if (line[0] == 'R') { // Reset memory
            memset(memory, 0, MEMORY_SIZE);
            printf("Memory reset to zero.\n");
            continue;
        }
        
        if (sscanf(line, "S %s", file_name) == 1) {
            save_memory(file_name, memory);
            continue;
        }
        
        if (sscanf(line, "L %s", file_name) == 1) {
            load_memory(file_name, memory);
            continue;
        }

        if (sscanf(line, "%d %c %d", &address, &opcode, &value) != 3 || address < 0 || address >= MEMORY_SIZE) {
            printf("Invalid input.\n");
            continue; // Invalid input or out-of-bounds address
        }

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
                printf("Invalid opcode: %c\n", opcode);
                continue;
        }
        printf("Updated Address %d: %d\n", address, memory[address]);
    }
    
    printf("Final Memory State:\n");
    for (int i = 0; i < MEMORY_SIZE; i++) {
        if (memory[i] != 0)
            printf("Address %d: %d\n", i, memory[i]);
    }
    
    return 0;
}

