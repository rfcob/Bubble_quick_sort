#ifndef INCLUDES_H
#define INCLUDES_H


#define MAX_LINHAS 300001
#define MAX_COLUNAS 5 
#define MAX_TAM_CEL 51


typedef struct {
    char ***mat; 
    int *linhas;                        
    int *coluna;
    int *prioridade;               
} cardapioM;

void exibeCSV(cardapioM *cardapioM);

void openCSV(const char *nomeArquivo, char delimitador, cardapioM *cardapioM);

void bSort(cardapioM *mat);
void bSortT(cardapioM *mat, int limL);

void definePrioridade(cardapioM *mat);
void qSort(cardapioM *mat);
void qSortT(cardapioM *mat,int limL);
void qsOrdena(cardapioM *mat, int esq, int dir);
void qsParticiona(cardapioM *menu, int esq, int dir, int *i, int *j);


void timeComp();
int numero_linhas(cardapioM *cardapio);


#endif // INCLUDES_H
