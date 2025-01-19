long calculateBrialliance(int **data, int width, int height);
void applyBrilliance(int **data, int height, int width, long brilliance, int percentage, int *max);
void createHistogram(int **data, int height, int width, int *hist);
void addImages(int **data, int height, int width);
int getMinimum(int **data, int width, int height);
void substractImages(int **data, int height, int width);