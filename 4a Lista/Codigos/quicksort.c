#include <stdio.h>

#define less(A,B) ((A) < (B))
#define lesseq(A,B) ((A) <= (B))
#define exch(A,B) { Item t; t=A;A=B;B=t; }
#define cmpexch(A,B) { if (less(B,A)) exch(A,B); }

typedef int Item;

int separa(Item *V, int l, int r)
{
  int i = l-1, j = r; Item v = V[r];
  
  for(;;)
  {
    while(less(V[++i], v));

    while(less(v, V[--j])) 
        if(j==l) 
            break;
    
    if(i>=j) 
        break;
    
    exch(V[i],V[j]);
  }
  
  exch(V[i],V[r])
  
  return i;
}

void quicksortM3(Item *V, int l, int r)
{
    if (r<=l) return;

    cmpexch(V[(l+r)/2],V[r]);
    cmpexch(V[l],V[(l+r)/2]);
    cmpexch(V[r],V[(l+r)/2]);

    int j = separa(V,l,r);
    quicksortM3(V,l,j-1);
    quicksortM3(V,j+1,r);
}

int main()
{
    int tam;

    scanf("%d", &tam);

    int v[tam];

    for (int i = 0; i < tam; i++)
    {
        scanf("%d", &v[i]);
    }

    quicksortM3(v, 0, tam - 1);

    for (int i = 0; i < tam; i++)
    {
        printf("%d ", v[i]);
    }
    printf("\n");
}