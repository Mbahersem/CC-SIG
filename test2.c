#include <stdio.h>
#include <stdlib.h>
#include "pgm/pgm.c"
#include "processing/processing.c"

void freeMemomry(int **data, int height);
void getFileName(char *fileName);

int main() {
    int choice;
    int height;
    int width;
    int max;
    char *fileName;

    do {
        printf("===== Menu CC SIG =====\n\n");
        printf("1. Somme de deux images\n");
        printf("2. Différence de deux images\n");
        printf("3. Modification de la luminosité\n");
        printf("4. Modification du contraste\n");
        printf("5. Seuillage d'une image\n");
        printf("6. Filtre passe bas\n");
        printf("7. Filtre passe haut\n");
        printf("8. Modification de la taille d'une image\n");
        printf("9. Transformée de Hough\n");
        printf("10. Quitter\n");
        printf("\nVotre choix : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            getFileName(fileName);
            getDimensionsFromPGM(fileName, &height, &width, &max);
            int **data = (int**)malloc(height * sizeof(int *));
            for (int i = 0; i < height; i++) {
                data[i] = (int *)malloc(width * sizeof(int));
            }

            if(readPGM(file, data, width)) {
                puts("Everything went well...");
            }

            addImages(data, height, width);
            writePGM("addedImages.pgm", data, height, width, max);

            freeMemomry(data, height);
            break;
        
        case 2:
            getFileName(fileName);
            getDimensionsFromPGM(fileName, &height, &width, &max);
            int **data = (int**)malloc(height * sizeof(int *));
            for (int i = 0; i < height; i++) {
                data[i] = (int *)malloc(width * sizeof(int));
            }

            if(readPGM(file, data, width)) {
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
            int **data = (int**)malloc(height * sizeof(int *));
            for (int i = 0; i < height; i++) {
                data[i] = (int *)malloc(width * sizeof(int));
            }

            if(readPGM(file, data, width)) {
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
            int **data = (int**)malloc(height * sizeof(int *));
            for (int i = 0; i < height; i++) {
                data[i] = (int *)malloc(width * sizeof(int));
            }

            int min = getMinimum(data, width, height);
            applyContrast(data, height, width, min, max);

            writePGM("contrast.pgm", data, height, width, max);

            freeMemomry(data, height);
            break;

        case 5:
            /* code */
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
        
        default:
            break;
        }
    } while(choice != 10);

    return 0;
}

void freeMemomry(int **data, int height) {
    for(int i = 0; i < height; i++) {
        free(data[i]);
    }
    free(data);
}

void getFileName(char *fileName) {
    printf("Entrez le chemin d'accès de l'image : \n");
    scanf("%s", fileName);
}

