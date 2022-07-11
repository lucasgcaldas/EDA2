#include <stdio.h>

int main(void) 
{
    int x = 0, a = 0, sum = 0;
    scanf("%d", &x);
    
    for (int i = 0; i < x; i++)
    {
        scanf("%d", &a);
        sum = sum + a;
    }

    printf("%d\n", sum);
    return 0;
}