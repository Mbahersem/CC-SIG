#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pgm.h"

void getDimensionsFromPGM(char *fileName, int *height, int *width, int *max) {
    FILE *pgmPtr;
    char line[256], *token;

    if((pgmPtr = fopen(fileName, "r")) == NULL) {
        puts("File could not be opened");
    } else {
        int index = 0;
        fgets(line, sizeof(line), pgmPtr);
        line[strcspn(line, "\n")] = '\0';
        if(strcmp(line, "P2") == 0) {
            while(fgets(line, sizeof(line), pgmPtr)) {
                index++;
                switch (index) {
                case 1:
                    break;
                case 2:
                    line[strcspn(line, "\n")] = '\0';
                    token = strtok(line, " ");
                    *width = atoi(token);
                    token = strtok(NULL, " ");
                    *height = atoi(token);
                    break;
                case 3:
                    line[strcspn(line, "\n")] = '\0';
                    *max = atoi(line);
                    break;
                default:
                    break;
                }
            }
        }        
    }
    fclose(pgmPtr);
}

void writePGM(char *fileName, int **data, int height, int width, int max) {
    FILE *ptr;
    if((ptr = fopen(fileName, "a")) == NULL) {
        puts("File could not be opened");
    } else {
        fprintf(ptr, "%s\n", "P2");
        fprintf(ptr, "# %s\n", fileName);
        fprintf(ptr, "%d %d\n", width, height);
        fprintf(ptr, "%d\n", max);
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

int readPGM(char *fileName, int **data, int width) {
    FILE *pgmPtr;
    int allocated = 0;
    char line[256], *token;

    if((pgmPtr = fopen(fileName, "r")) == NULL) {
        puts("File could not be opened");
        return 0;
    } else {
        int index = 0;
        fgets(line, sizeof(line), pgmPtr);
        line[strcspn(line, "\n")] = '\0';
        if(strcmp(line, "P2") == 0) {
            while(fgets(line, sizeof(line), pgmPtr)) {
                index++;
                switch (index)
                {
                case 1:
                    break;
                case 2:
                    break;
                case 3:
                    break;
                default:
                    line[strcspn(line, "\n")] = '\0';
                    token = strtok(line, " ");
                    for(int i = 0; i < width; i++) {
                        data[index - 4][i] = atoi(token);
                        token = strtok(NULL, " ");
                    }
                    printf("\n");
                    break;
                }
            }
        } else {
            return 0;
        }
    }
    fclose(pgmPtr);
    return 1;
}