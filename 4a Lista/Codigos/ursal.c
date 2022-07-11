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
    int num_s, num_df, num_de;
    int qt_p = 0, qt_s = 0, qt_df = 0, qt_de = 0, qt_in = 0;
    int presidente[1000], senador[1000], df[1000], de[1000];

    scanf("%d %d %d", &num_s, &num_df, &num_de);

    int i = 0;
    int voto;
    while (scanf("%d", &voto) != EOF)
    {
        if(voto < 100 && voto >= 10)
        {
            presidente[i] = voto;
            qt_p++;
        }
        else if(voto >= 100 && voto < 1000)
        {
            senador[i] = voto;
            qt_s++;
        }
        else if(voto >= 1000 && voto < 10000)
        {
            df[i] = voto;
            qt_df++;
        }
        else if(voto >= 10000 && voto < 100000)
        {
            de[i] = voto;
            qt_de++;
        }
        else
            qt_in = 0;
        
        i++;
    }

    quicksortM3(presidente, 0, qt_p - 1);
    quicksortM3(senador, 0, qt_s - 1);
    quicksortM3(df, 0, qt_df - 1);
    quicksortM3(de, 0, qt_de - 1);

    int votos_val = i - qt_in;

    printf("%d %d\n", votos_val, qt_in);

    return 0;
}