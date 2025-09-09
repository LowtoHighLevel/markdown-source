#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/**
 * Converts a hex character to its numerical value.
 */
unsigned char hexToChar(char x) {
    if (x >= '0' && x <= '9') {
        return (unsigned char)(x - '0');
    } else if (x >= 'A' && x <= 'F') {
        return (unsigned char)(x - 'A' + 10);
    } else if (x >= 'a' && x <= 'f') {
        return (unsigned char)(x -'a' + 10);
    }
    return 0;
}

/**
 * Converts two ASCII characters to a binary byte
 */
unsigned char fromAscii(char x, char y) {
    return ((hexToChar(x) << 4) + hexToChar(y));
}

/**
 * Main program
 */
int main(int argc, char* argv[]) {
    if (argc < 2) {
        return -1;
    }

    // open output
    FILE* fptr;
    fptr = fopen(argv[1], "w");

    for (int i = 2; i< argc; i++) {
        // convert hex byte to a unsigned integer
        if (strlen(argv[i]) == 2) {
            unsigned char f = fromAscii(argv[i][0], argv[i][1]);

            // output binary
            fwrite(&f, sizeof(unsigned char), 1, fptr);
        }
    }

    fclose(fptr);
}