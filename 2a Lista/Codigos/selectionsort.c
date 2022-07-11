#include <stdio.h>

#define MAX 1000

int vetor[MAX];

// Algoritmo de ordenacao nao estavel, pois ele nao mantem a ordem relativa
// dos elementos da mesma maneira que ele aparece no vetor
void selection_sort (int v[], int l, int r) 
{
    if(l == r) {
        return;
    }

    int min = l, aux =0;

    for (int j = l + 1; j < r; j++) {
        if(v[j] < v[min]) {
            min = j;
        }
    }
    aux = v[min];
    v[min] = v[l];
    v[l] = aux;

    selection_sort(v, l + 1, r);
}

int main()
{
    int aux;
    int r = 0;

    while(scanf("%d", &aux) != EOF){
        vetor[r] = aux;
        r++;
    }

    selection_sort(vetor, 0, r);


    for(int j = 0; j < r; j++){
        printf("%d ", vetor[j]);
    }
    printf("\n");

    return 0;
}