#include <stdio.h>

#define MAX 1000

int vetor[MAX];
// NAO SEI AINDA
// Algoritmo de ordenacao nao estavel, pois ele nao mantem a ordem relativa
// dos elementos da mesma maneira que ele aparece no vetor
void insertion_sort (int v[], int l, int r) 
{
    int aux = 0;
    for (int i = l + 1; i < r; i++) {
        for (int j = i; j > l; j--) {
            if (v[j] < v[j - 1]) {
                aux = v[j];
                v[j] = v[j - 1];
                v[j - 1] = aux;
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

    insertion_sort(vetor, 0, r);


    for(int j = 0; j < r; j++){
        printf("%d ", vetor[j]);
    }
    printf("\n");

    return 0;
}