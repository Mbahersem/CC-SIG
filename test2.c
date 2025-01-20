#include <stdio.h>
#include <stdlib.h>
#include "pgm/pgm.c"
#include "pbm/pbm.c"
#include "processing/processing.c"

void freeMemomry(int **data, int height);
void getFileName(char *fileName);

int main() {
    int choice;
    int height;
    int width;
    int **data;
    int max;
    char fileName[150];

    do {
        printf("===== Menu CC SIG =====\n\n");
        printf("1. Somme de deux images\n");
        printf("2. Difference de deux images\n");
        printf("3. Modification de la luminosite\n");
        printf("4. Modification du contraste\n");
        printf("5. Seuillage d'une image\n");
        printf("6. Filtre passe bas\n");
        printf("7. Filtre passe haut\n");
        printf("8. Modification de la taille d'une image\n");
        printf("9. Transformee de Hough\n");
        printf("10. Multiplication d'images\n");
        printf("11. Quitter\n");
        printf("\nVotre choix : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            getFileName(fileName);
            getDimensionsFromPGM(fileName, &height, &width, &max);
            data = (int**)malloc(height * sizeof(int *));
            for (int i = 0; i < height; i++) {
                data[i] = (int *)malloc(width * sizeof(int));
            }

            if(readPGM(fileName, data, width)) {
                puts("Everything went well...");
            }

            addImages(data, height, width);
            writePGM("addedImages.pgm", data, height, width, max);

            freeMemomry(data, height);
            break;
        
        case 2:
            getFileName(fileName);
            getDimensionsFromPGM(fileName, &height, &width, &max);
            data = (int**)malloc(height * sizeof(int *));
            for (int i = 0; i < height; i++) {
                data[i] = (int *)malloc(width * sizeof(int));
            }

            if(readPGM(fileName, data, width)) {
                puts("Everything went well...");
            }

            substractImages(data, height, width);
            writePGM("subImages.pgm", data, height, width, max);

            freeMemomry(data, height);
            break;

        case 3:
            int percentage;
            getFileName(fileName);
            printf("Entrez le pourcentage : \n");
            scanf("%d", &percentage);

            getDimensionsFromPGM(fileName, &height, &width, &max);
            data = (int**)malloc(height * sizeof(int *));
            for (int i = 0; i < height; i++) {
                data[i] = (int *)malloc(width * sizeof(int));
            }

            if(readPGM(fileName, data, width)) {
                puts("Everything went well...");
            }

            long brilliance = calculateBrialliance(data, width, height);
            applyBrilliance(data, height, width, brilliance, percentage, &max);

            writePGM("brilliant.pgm", data, height, width, max);

            freeMemomry(data, height);

            break;

        case 4:
            getFileName(fileName);

            getDimensionsFromPGM(fileName, &height, &width, &max);
            data = (int**)malloc(height * sizeof(int *));
            for (int i = 0; i < height; i++) {
                data[i] = (int *)malloc(width * sizeof(int));
            }

            if(readPGM(fileName, data, width)) {
                puts("Everything went well...");
            }

            int min = getMinimum(data, width, height);
            applyContrast(data, height, width, min, max);

            writePGM("contrast.pgm", data, height, width, max);

            freeMemomry(data, height);
            break;

        case 5:
            int t;
            getFileName(fileName);

            getDimensionsFromPGM(fileName, &height, &width, &max);
            data = (int**)malloc(height * sizeof(int *));
            for (int i = 0; i < height; i++) {
                data[i] = (int *)malloc(width * sizeof(int));
            }

            printf("Entrez le seuil : \n");
            scanf("%d", &t);

            if(readPGM(fileName, data, width)) {
                puts("Everything went well...");
            }

            threshold(data, height, width, t);
            writePBM("binary.pbm", data, height, width);

            freeMemomry(data, height);
            break;

        case 6:
            /* code */
            break;

        case 7:
            /* code */
            break;

        case 8:
            /* code */
            break;

        case 9:
            /* code */
            break;
        
        case 10:
            int ratio;
            getFileName(fileName);
            getDimensionsFromPGM(fileName, &height, &width, &max);
            data = (int**)malloc(height * sizeof(int *));
            for (int i = 0; i < height; i++) {
                data[i] = (int *)malloc(width * sizeof(int));
            }

            printf("Entrez le ratio souhaite : \n");
            scanf("%d", &ratio);

            if(readPGM(fileName, data, width)) {
                puts("Everything went well...");
            }

            multiplyImages(data, height, width, ratio);
            writePGM("multiplyImages.pgm", data, height, width, max);

            freeMemomry(data, height);
            break;
        
        default:
            break;
        }
    } while(choice != 11);

    return 0;
}

void freeMemomry(int **data, int height) {
    for(int i = 0; i < height; i++) {
        free(data[i]);
    }
    free(data);
}

void getFileName(char *fileName) {
    printf("Entrez le chemin d'acces de l'image : \n");
    scanf("%s", fileName);
}

