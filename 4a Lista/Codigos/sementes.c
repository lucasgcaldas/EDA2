#include <stdio.h>

#define key(A) (A.nota)
#define key2(A) (A.codigo)
#define less(A,B) ((key(A)) < (key(B)))
#define less2(A,B) ((key2(A)) < (key2(B)))
#define lesseq(A,B) ((key2(A)) <= (key2(B)))
#define exch(A,B) { Item t; t=A;A=B;B=t; }
#define cmpexch(A,B) { if (less(B,A)) exch(A,B); }
#define equal(A,B) ((key(A)) == (key(B)))

typedef struct Item {
    int codigo;
    int nota;
}Item;

int separa(Item *V, int l, int r)
{
  Item c=V[r];
  int j=l;
  for(int k=l;k<r;k++)
    if(less(V[k],c) || equal(V[k],c) && less2(V[k],c))
    {
      exch(V[k],V[j]);
      j++;
    }
  exch(V[j],V[r]);
  return j;
}

void quickselectM3(Item *v, int l, int r, int k)
{
    if (r <= l) return;

    cmpexch(v[(l+r)/2],v[r]);
    cmpexch(v[l],v[(l+r)/2]);
    cmpexch(v[r],v[(l+r)/2]);

    int i = separa(v, l, r);

    if (i > k)
        quickselectM3(v, l, i - 1, k);
    if (i < k)
        quickselectM3(v, l, i + 1, k);
}

void merge(Item *V, int l, int m, int r)
{
    Item *R = malloc(sizeof(Item)*(r-l+1));
    int i=l,j=m+1,k=0;

    while(i<=m && j<=r)
    {
    if(lesseq(V[i],V[j]))
        R[k++]=V[i++];
    else
        R[k++]=V[j++];
    }

    while(i<=m)
        R[k++]=V[i++];
    while(j<=r)
        R[k++]=V[j++];


    k=0;
    for(i=l;i<=r;i++)
    V[i]=R[k++];
    free(R);
}

void mergesort(Item *V,int l, int r)
{
  if (l>= r) return;
  int meio=(l+r)/2;
  mergesort(V,l,meio);
  mergesort(V,meio+1,r);
  merge(V,l,meio,r);
}

int main()
{
    int k, s, n, repetidos = 0;
    scanf("%d", &k);

    Item *semente;
    semente = malloc(sizeof(Item) * 10000000);

    int i = 0;
    while (scanf("%d %d", &s, &n) != EOF)
    {
        semente[i].codigo = s;
        semente[i].nota = n;        
        i++;
    }

    quickselectM3(semente, 0, i - 1, k - 1);

    mergesort(semente, 0, k - 1);

    for (int j = 0; j < k; j++)
    {
        printf("%d %d\n", semente[j].codigo, semente[j].nota);
    }

    free(semente);
    return 0;
}