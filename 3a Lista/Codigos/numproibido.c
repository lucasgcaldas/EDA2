#include <stdio.h>

typedef int Item;
#define less(A,B) ((A) < (B))
#define lesseq(A,B) ((A) <= (B))
#define exch(A,B) { Item t; t=A;A=B;B=t; }
#define cmpexch(A,B) { if (less(B,A)) exch(A,B); }

void merge(Item *V, int l, int m, int r)
{
    Item *R = malloc(sizeof(Item)*(r-l+1));
    int i = l, j = m + 1, k = 0;

    while(i <= m && j <= r)
    {
    if(lesseq(V[i], V[j]))
        R[k++] = V[i++];
    else
        R[k++] = V[j++];
    }

    while(i <= m)
        R[k++] = V[i++];
    while(j <= r)
        R[k++] = V[j++];

    k = 0;
    for(i = l; i <= r; i++)
    V[i] = R[k++];
    free(R);
}

void mergesort(Item *V, int l, int r)
{
    if (l >= r) return;

    int meio = (l+r) / 2;
    mergesort(V, l, meio);
    mergesort(V, meio + 1, r);
    merge(V, l, meio, r);
}

int buscabinaria(int *v, int l, int r, int b) 
{ 
    int meio = 0;
    while (l <= r) 
    {
    meio =  l + (r - l) / 2;

    if(v[meio] == b)
        return meio;
    if(v[meio] < b)
        l = meio + 1;
    else
        r = meio - 1;
    }

    return -1;
}

int main()
{
    int quant;
    scanf("%d", &quant);
    
    int v[quant];
    for (int i = 0; i < quant; i++)
    {
        scanf("%d", &v[i]);
    }

    mergesort(v, 0, quant - 1);

    int num, posic;
    while (scanf("%d", &num) != EOF)
    {
        posic = buscabinaria(v, 0, quant, num);

        if (posic == -1)
            printf("nao\n");
        else 
            printf("sim\n");
    }

    return 0;
}