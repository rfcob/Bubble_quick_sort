#include "includes.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>




// Retornar numero de linhas para teste_____________________________________________________________________________________

int numero_linhas(cardapioM *cardapioM) {
    return *(cardapioM->linhas);  
}


//Imprimir o csv na tela____________________________________________________________________________________________________

// TRUNCADO

void truncaExibeCSV(cardapioM *cardapioM, int limL) {

    for (int i = 0; i < limL; i++) {
        for (int j = 0; j < MAX_COLUNAS && cardapioM->mat[i][j][0] != '\0'; j++) {
            printf("%-10s ", cardapioM->mat[i][j]);
        }
       printf("\n");
    }
}

//INTEIRO

void exibeCSV(cardapioM *cardapioM) {

    for (int i = 0; i < *(cardapioM->linhas); i++) {
        for (int j = 0; j < MAX_COLUNAS && cardapioM->mat[i][j][0] != '\0'; j++) {
            printf("%-14s ", cardapioM->mat[i][j]);
        }
       //printf("\n");
    }
}

    
//Abre o arquivo e conta as linhas Alocando memoria_________________________________________________________________________
void openCSV(const char *nomeArquivo, char delimitador, cardapioM *cardapioM) {
    FILE *file = fopen(nomeArquivo, "r");

    if (!file) {
        fprintf(stderr, "Erro ao abrir o arquivo!\n");
        return;
    }

    // Alocar memoria
    cardapioM->linhas = (int *)malloc(sizeof(int)); 
    *(cardapioM->linhas) = 0;  


    // Alocar a matriz de strings
    cardapioM->mat = (char ***)malloc(MAX_LINHAS * sizeof(char **));
    for (int i = 0; i < MAX_LINHAS; ++i) {
        cardapioM->mat[i] = (char **)malloc(MAX_COLUNAS * sizeof(char *));
        for (int j = 0; j < MAX_COLUNAS; ++j) {
            cardapioM->mat[i][j] = (char *)malloc(MAX_TAM_CEL * sizeof(char));
        }
    }

    cardapioM->prioridade = (int *)malloc(MAX_LINHAS * sizeof(int));

    char line[1024]; 

    while (fgets(line, sizeof(line), file) && *(cardapioM->linhas) < MAX_LINHAS) {
        int col = 0;
        char *cell = strtok(line, &delimitador); 

        while (cell != NULL && col < MAX_COLUNAS) {
            strncpy(cardapioM->mat[*(cardapioM->linhas)][col], cell, MAX_TAM_CEL - 1); 
            cardapioM->mat[*(cardapioM->linhas)][col][MAX_TAM_CEL - 1] = '\0'; 
            col++;
            cell = strtok(NULL, &delimitador); 
        }

        (*(cardapioM->linhas))++; 
        
        //printf("Número de linhas lidas até agora: %d\n", *(cardapioM->linhas));
    
    }

    definePrioridade(cardapioM);

    //fclose(file);
}



// Ordenar - BUBBLE SORT _________________________________________________________________________________________________

void bSortT(cardapioM *mat, int limL) {
    int i, j;

    for (i = 0; i < *(mat->linhas) - 1; i++) {
        for (j = 0; j < *(mat->linhas) - i - 1; j++) {
       
            if (atoi(mat->mat[j][0]) > atoi(mat->mat[j + 1][0])) {

                char *temp = mat->mat[j];
                mat->mat[j] = mat->mat[j + 1];
                mat->mat[j + 1] = temp;
            }
        }
    }
   // printf("ok");
    truncaExibeCSV(mat, limL);
}

//________________________________________________________________________________________________________________

void bSort(cardapioM *mat) {
    int i, j;

    for (i = 0; i < *(mat->linhas) - 1; i++) {
        for (j = 0; j < *(mat->linhas) - i - 1; j++) {

            if (atoi(mat->mat[j][0]) > atoi(mat->mat[j + 1][0])) {

                char *temp = mat->mat[j];
                mat->mat[j] = mat->mat[j + 1];
                mat->mat[j + 1] = temp;
            }
        }
    }
   // printf("ok");
    exibeCSV(mat);
}

//TEMPO EXECUÇÂO BUBBLE SORT________________________________________________________________________________

// Ordena a matriz
void qSort(cardapioM *mat) {
    qsOrdena(mat, 0, *(mat->linhas) - 1);
    exibeCSV(mat);
}

void qSortT(cardapioM *mat, int limL) {
    qsOrdena(mat, 0, *(mat->linhas) - 1);
    truncaExibeCSV(mat, limL);
}



// Define as prioridades com base na coluna especificada
void definePrioridade(cardapioM *mat) {
    for (int i = 0; i < *(mat->linhas); i++) {
        mat->prioridade[i] = atoi(mat->mat[i][0]);  //Forçando a coluna zero como prioridade.
                                                     //poderia ser gerneralizado
    }
}

// Função recursiva para o QuickSort
void qsOrdena(cardapioM *mat, int esq, int dir) {
    int i, j;

    qsParticiona(mat, esq, dir, &i, &j);

    if (esq < j) {
        qsOrdena(mat, esq, j);
    }
    if (i < dir) {
        qsOrdena(mat, i, dir);
    }
}

// Particiona o array para o QuickSort
void qsParticiona(cardapioM *mat, int esq, int dir, int *i, int *j) {
    int pivo, auxPrioridade;
    char **auxLinha;

    *i = esq;
    *j = dir;

    pivo = mat->prioridade[(esq + dir) / 2]; // valor central

    do {
        while (mat->prioridade[*i] < pivo) (*i)++;
        while (mat->prioridade[*j] > pivo) (*j)--;
        if (*i <= *j) {
            
            auxPrioridade = mat->prioridade[*i];
            mat->prioridade[*i] = mat->prioridade[*j];
            mat->prioridade[*j] = auxPrioridade;

           
            auxLinha = mat->mat[*i];
            mat->mat[*i] = mat->mat[*j];
            mat->mat[*j] = auxLinha;

            (*i)++;
            (*j)--;
        }
    } while (*i <= *j);

}



void desalocarMatriz(cardapioM *cardamioM) {
    if (cardamioM->mat) {
        for (int i = 0; i < *(cardamioM->linhas); i++) {
            if (cardamioM->mat[i]) {
                for (int j = 0; j < MAX_COLUNAS; j++) {
                    free(cardamioM->mat[i][j]); 
                }
                free(cardamioM->mat[i]); 
            }
        }
        free(cardamioM->mat); 
    }

    free(cardamioM->prioridade); 
    free(cardamioM->linhas); 
}