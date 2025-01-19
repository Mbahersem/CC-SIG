#include <stdlib.h>
#include "processing.h"

long calculateBrialliance(int **data, int width, int height) {
    long sum = 0;
    for(int i = 0; i < height; i++) {
        for(int j = 0; j < width; j++) {
            sum += data[i][j];
        }
    }
    
    long brilliance = sum / (height * width);
    return brilliance;
}

int getMinimum(int **data, int width, int height) {
    int min = data[0][0];
    for(int i = 0; i < height; i++) {
        for(int j = 0; j < width; j++) {
            if(data[i][j] < min) {
                min = data[i][j];
            }
        }
    }
    return min;
}

void applyBrilliance(int **data, int height, int width, long brilliance, int percentage, int *max) {
    long effectiveBrilliance = (brilliance * percentage) / 100;
    *max += effectiveBrilliance;
    for(int i = 0; i < height; i++) {
        for(int j = 0; j < width; j++) {
            data[i][j] += (int)brilliance;
        }
    }
}

void createHistogram(int **data, int height, int width, int *hist) {
    for(int i = 0; i < height; i++) {
        for(int j = 0; j < width; j++) {
            hist[data[i][j]]++;
        }
    }
}

void addImages(int **data, int height, int width) {
    for(int i = 0; i < height; i++) {
        for(int j = 0; j < width; j++) {
            data[i][j] += data[i][j];
        }
    }
}

void addTwoImages

void substractImages(int **data, int height, int width) {
    for(int i = 0; i < height; i++) {
        for(int j = 0; j < width; j++) {
            data[i][j] -= data[i][j];
        }
    }
}

void multiplyImages(int **data, int height, int width, int ratio) {
    for(int i = 0; i < height; i++) {
        for(int j = 0; j < width; j++) {
            data[i][j] *= ratio;
        }
    }
}