#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ordenando.c"
#include <time.h>


int main() {
    // Criar uma instância de cardapioM
    cardapioM meuCardapio;

    cardapioM meuCardapio_2;

    // Abrir o arquivo e contar o numero de linhas
    openCSV("restaurante_pratos_red.csv", ',', &meuCardapio);

    openCSV("restaurante_pratos_red.csv", ',', &meuCardapio_2);

    // Chamar a função numero_linhas para obter o número de linhas
    printf("Número de linhas lidas: %d\n", numero_linhas(&meuCardapio));

    //Imprimir na tela o cardapio
    //exibeCSV(&meuCardapio);


 //_______________________________BUBBLE_______________________________________

    clock_t t, t2;

    //Ordenar por bolha
   // bSort(&meuCardapio);
    //bSort truncado - numero de linhas a ser impressa
    printf("Os 4 pratos com maiores prioridades são: \n");
    t=clock();
    bSortT(&meuCardapio,5);
    t=clock()-t;

    double tempo = ((double)t) / CLOCKS_PER_SEC;

    printf("o tempo de excecução do bubble sort foi em segundos: %.8f\n", tempo);
    


    printf("Os 4 pratos com maiores prioridades são: \n");
    t2=clock();
    bSortT(&meuCardapio,5);
    t2=clock()-t2;

    double tempo2 = ((double)t2) / CLOCKS_PER_SEC;

    printf("o tempo de excecução do quick sort foi em segundos: %.8f\n", tempo2);

    qSortT(&meuCardapio_2, 5);

    return 0;

 //_______________________________QUICK_______________________________________





}