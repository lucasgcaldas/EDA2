#include <stdio.h>

#define less(A,B) ((A) < (B))
#define lesseq(A,B) ((A) <= (B))
#define exch(A,B) { int t; t=A;A=B;B=t; }
#define cmpexch(A,B) { if (less(B,A)) exch(A,B); }
#define MAX 50000

int vetor[MAX];
// NAO SEI AINDA
// Algoritmo de ordenacao nao estavel, pois ele nao mantem a ordem relativa
// dos elementos da mesma maneira que ele aparece no vetor
void insertion_sort (int v[], int l, int r) 
{
    int aux = 0;
    for (int i = r; i > l; i--) {
        cmpexch(v[i - 1], v[i]);
    }

    for(int i = l + 2; i <= r; i++) {
        int j = i, tmp = v[j];
        while(less(tmp, v[j - 1])) {
            v[j] = v[j -1];
            j--;
        }
        v[j] = tmp;
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

    insertion_sort(vetor, 0, r -1);


    for(int j = 0; j < r; j++){
        printf("%d ", vetor[j]);
    }
    printf("\n");

    return 0;
}