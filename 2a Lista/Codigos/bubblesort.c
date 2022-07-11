#include <stdio.h>

#define MAX 1000

int vetor[MAX];

// Algoritmo de ordenacao estavel, pois ele mantem a ordem relativa
// dos elementos da mesma maneira que ele aparece no vetor
void bubble_sort (int vetor[], int r) 
{
    int k, j, aux;

    for (k = r - 1; k > 0; k--) {
        for (j = 0; j < k; j++) {
            if (vetor[j] > vetor[j + 1]) {
                aux = vetor[j];
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = aux;
            }
        }
    }
}

int main()
{
    int aux;
    int r = 0;

    while(scanf("%d", &aux) != EOF){
        vetor[r] = aux;
        r++;
    }

    bubble_sort(vetor, r);


    for(int j = 0; j < r; j++){
        printf("%d ", vetor[j]);
    }
    printf("\n");

    return 0;
}