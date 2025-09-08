#include <stdio.h>
#include <stdlib.h>
#include <string.h>


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
unsigned char fromAscii(char x, char y) {
return ((hexToChar(x) << 4) + hexToChar(y));
}
int main(int argc, char* argv[]) {
    if (argc < 2) {
        return -1;
    }

    FILE* fptr;
    fptr = fopen(argv[1], "w");

    for (int i = 2; i< argc; i++) {
        if (strlen(argv[i]) == 2) {
            unsigned char f = fromAscii(argv[i][0], argv[i][1]);

            fwrite(&f, sizeof(unsigned char), 1, fptr);
        }
    }

    fclose(fptr);
}