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

void applyContrast(int **data, int height, int width, int min, int max) {
    for(int i = 0; i < height; i++) {
        for(int j = 0; j < width; j++) {
            data[i][j] = (255 * (data[i][j] - min)) / (max - min);
        }
    }
}

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

void threshold(int **data, int height, int width, int t) {
    for(int i = 0; i < height; i++) {
        for(int j = 0; j < width; j++) {
            if(data[i][j] >= t) {
                data[i][j] = 1;
            } else {
                data[i][j] = 0;
            }
        }
    }
}

void lowPass(int **data, int height, int width) {

}

void highPass(int **data, int **output, int height, int width, int t) {
    int filter[3][3] = {{0, -1, 0}, {-1, 4, -1}, {0, -1, 0}};
    int i, j, m, n;
    for(i = 0; i < height; i++) {
        for(j = 0; j < width; j++) {
            output[i][j] = 0;
            for(m = 0; m < 3; m++) {
                for(n = 0; n < 3; n++) {

                }
            }
        }
    }   
}