#include <stdio.h>
#include <stdlib.h>
#include "pgm/pgm.c"
#include "processing/processing.c"

#define GRAY 256

void freeMemomry(int **data, int height);

int main(void) {
    int height;
    int width;
    int max;
    char *file = "free.pgm";
    char *toWrite = "brilliant.pgm";
    int hist[GRAY] = {0};

    getDimensionsFromPGM(file, &height, &width, &max);

    int **data = (int**)malloc(height * sizeof(int *));
    for (int i = 0; i < height; i++) {
        data[i] = (int *)malloc(width * sizeof(int));
    }

    if(readPGM(file, data, width)) {
        puts("Everything went well...");
    }
    createHistogram(data, height, width, hist);
    for(int i = 0; i < GRAY; i++) {
        printf("%d ", hist[i]);
    }
    printf("\n");
    // long brilliance = calculateBrialliance(data, width, height);
    // applyBrilliance(data, height, width, brilliance, &max);

    // writePGM(toWrite, data, height, width, max);
    freeMemomry(data, height);
}

void freeMemomry(int **data, int height) {
    for(int i = 0; i < height; i++) {
        free(data[i]);
    }
    free(data);
}