#include <stdio.h>

int main(void) 
{
    int x = 0, a = 0, i = 0;
    
    while (scanf("%d", &x) != EOF) {
        i++;
    }

    printf("%d\n", i);
    return 0;
}