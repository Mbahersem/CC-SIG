#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pbm.h"

void writePBM(char *fileName, int **data, int height, int width) {
    FILE *ptr;
    if((ptr = fopen(fileName, "a")) == NULL) {
        puts("File could not be opened");
    } else {
        fprintf(ptr, "%s\n", "P1");
        fprintf(ptr, "# %s\n", fileName);
        fprintf(ptr, "%d %d\n", width, height);
        for(int i = 0; i < height; i++) {
            int length = 3 * width;
            char concat[1024] = "";

            for(int j = 0; j < width; j++) {
                char *buf;
                sprintf(buf, "%d ", data[i][j]);
                strcat(concat, buf);
            }
            fprintf(ptr, "%s\n", concat);
        }
    }
    fclose(ptr);
}