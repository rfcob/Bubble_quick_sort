# Bubble_quick_sort

## Bubble Sort Vs Quick Sort

-A sequência de exemplos ao final do texto ilustrará a difereça de efiência dos dois algoritmos. 

- Apesar de simples para se entender e implementar o  método bubble é da ordem de 10² a 10⁴ mais lento nos testes realizados.


## Quick - A escolha do pivô

- A desvantagem no método quick sort está na escolha do pivô. Na implementação realizada foi escolhido o valor central da lista de dados. Contudo, escolher a mediana de ttês valores ou partição de Lomuto (pivô timpicamente do inicio ou final dos dados) poderia ser utilizado. 

- O problema aparece se o pivô escolhido for o menor ou maior valor dos dados, o que claramente irá desbalancear o algoritmo levando-o ao pior cenário de ordenamento que não diferirá do bubble.

- Para a implementação realizada, não houve "aparente" problema com a escolha do pivô adotado. A saber:

~~~C
        pivo = mat->prioridade[(esq + dir) / 2]; // valor central
~~~


# Exemplos de Saída

## Saída - 3000

- Bubble Sort

        Número de linhas lidas: 30000

        Os 4 pratos com maiores prioridades são: 

        prioridade       tempo      nome
            
        221             622        steak-and-ale-pie-953
        
        416             530        ploughman's-lunch-390
        
        706             106        poitin-154
        
        747             338        steak-and-ale-pie-239
        
        o tempo de excecução do bubble sort foi em segundos: 0.22884900

- Quick Sort 

        Os 4 pratos com maiores prioridades são: 

        prioridade       tempo      nome
            
        221              622        steak-and-ale-pie-953
        
        416              530        ploughman's-lunch-390
        
        706              106        poitin-154
        
        747              338        steak-and-ale-pie-239
        
        o tempo de excecução do quick sort foi em segundos: 0.00043900


## Saída - 150000

- Bubble Sort

        Número de linhas lidas: 150000

        Os 4 pratos com maiores prioridades são: 

        prioridade tempo      nome
            
        2          806        fish-and-chips-280
        
        2          952        cottage-pie-5
        
        5          893        poitin-745
        
        5          551        steak-and-ale-pie-929
        
        o tempo de excecução do bubble sort foi em segundos: 1135.34514500
    

 - Quick Sort

        
        Os 4 pratos com maiores prioridades são: 
        prioridade tempo      nome
            
        2          806        fish-and-chips-280
        
        2          952        cottage-pie-5
        
        5          551        steak-and-ale-pie-929
        
        5          893        poitin-745
 
        o tempo de excecução do quick sort foi em segundos: 0.02432600