#include <stdio.h>
#include <string.h>

typedef struct {
    int code;
    char key[15];
}Item;

#define less(A,B) ((A) < (B))
#define lesseq(A,B) ((A) <= (B))
#define exch(A,B) { Item t; t=A;A=B;B=t; }
#define cmpexch(A,B) { if (less(B,A)) exch(A,B); }


Item insertion_sort (Item *v, int l, int r) 
{
    int aux = 0;
    for (int i = r; i > l; i--) {
        if (v[i].code < v[i - 1].code)
        {
            exch(v[i - 1], v[i]);
        }
    }

    for(int i = l + 2; i <= r; i++) {
        
        int j = i;
        int tmp_code = v[j].code;
        char temp_key[15];
        strcpy(temp_key, v[j].key);

        while(less(tmp_code, v[j - 1].code)) {
            v[j] = v[j -1];
            j--;
        }

        v[j].code = tmp_code;
        strcpy(v[j].key , temp_key);
    }

    return *v;
}

int busca_binaria(Item *item, int insert_code, int l, int r)
{
    while (l <= r)
    {
        int meio = l + (r - l)/2;

        if(item[meio].code == insert_code)
        {
            return meio;
        }
        else if (item[meio].code < insert_code)
        {
            l = meio + 1;
        }
        else 
        {
            r = meio - 1;
        }
    }

    return -1;
}

int main()
{
    int num;

    scanf("%d", &num);

    Item *item = malloc(num*sizeof(Item));

    for (int i = 0; i < num; i++) 
    {
        scanf("%d %s", &item[i].code, item[i].key);
    }

    *item = insertion_sort(item, 0, num -1);

    int insert_code;
    int value;
    while (scanf("%d", &insert_code) != EOF)
    {
        value = busca_binaria(item, insert_code, 0, num);

        if (value == -1) {  
            printf("undefined\n");
        }
        else
        {
            printf("%s\n", item[value].key);
        }
    }

    return 0;
}