#include <stdio.h>

#define key(A) (A.nota)
#define key2(A) (A.codigo)
#define less(A,B) ((key(A)) < (key(B)))
#define less2(A,B) ((key2(A)) < (key2(B)))
#define lesseq(A,B) ((A) <= (B))
#define exch(A,B) { Item t; t=A;A=B;B=t; }
#define cmpexch(A,B) { if (less(B,A)) exch(A,B); }

typedef struct Item {
    int codigo;
    int nota;
}Item;

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

int separa2(Item *V, int l, int r)
{
  int i = l-1, j = r; Item v = V[r];
  
  for(;;)
  {
    while(less2(V[++i], v));

    while(less2(v, V[--j])) 
        if(j==l) 
            break;
    
    if(i>=j) 
        break;
    
    exch(V[i],V[j]);
  }
  
  exch(V[i],V[r])
  
  return i;
}

void quicksortM32(Item *V, int l, int r)
{
    if (r<=l) return;

    cmpexch(V[(l+r)/2],V[r]);
    cmpexch(V[l],V[(l+r)/2]);
    cmpexch(V[r],V[(l+r)/2]);

    int j = separa2(V,l,r);
    quicksortM32(V,l,j-1);
    quicksortM32(V,j+1,r);
}

void quickselect(Item *v, int l, int r, int k)
{
    if (r<=l) return;
    printf("antes\n");
    int i = separa(v, l, r);
    printf("depois\n");
    if (i > k)
        quickselect(v, l, i - 1, k);
    if (i < k)
        quickselect(v, l, i + 1, k);
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

    for (int j = 0; j < k; j++)
    {
        quickselect(semente, j, i - 1, j);
    }

    quicksortM32(semente, 0, k - 1);

    printf("\n");
    for (int j = 0; j < k; j++)
    {
        printf("%d %d\n", semente[j].codigo, semente[j].nota);
    }

    free(semente);
    return 0;
}

// int main()
// {
//     int k, s, n, repetidos = 0;
//     scanf("%d", &k);

//     Item *semente;
//     semente = malloc(sizeof(Item) * 10000000);

//     int i = 0;
//     while (scanf("%d %d", &s, &n) != EOF)
//     {
//         semente[i].codigo = s;
//         semente[i].nota = n;        
//         i++;
//     }
    
//     quicksortM3(semente, 0, i - 1);
//     int j = 0;
//     while (j < i)
//     {
//         if (semente[j].nota == semente[j + 1].nota)
//             // printf("%d %d\n", semente[j].nota, semente[j + 1].nota);
//             repetidos++;
        
//         j++;
//     }

//     // printf("repetidos: %d\n", repetidos);

//     Item *semente_ordenado;

//     if (repetidos == 0)
//     {
//         semente_ordenado = malloc(sizeof(Item) * k);
//         for (int i = 0; i < k; i++)
//             semente_ordenado[i] = semente[i];

//         quicksortM32(semente_ordenado, 0, k - 1);
//     }
//     else    
//     {
//         semente_ordenado = malloc(sizeof(Item) * repetidos);
//         for (int i = 0; i < repetidos; i++)
//             semente_ordenado[i] = semente[i];

//         quicksortM32(semente_ordenado, 0, repetidos - 1);
//     }

//     // printf("\n");
//     for (int i = 0; i < k; i++)
//     {
//         printf("%d %d\n", semente_ordenado[i].codigo, semente_ordenado[i].nota);
//     }

//     free(semente);
//     free(semente_ordenado);
//     return 0;
// }