#include <stdio.h>

int main(void) 
{
    char cmd[9];
    char frase[10000][101];
    int top = -1;
    int i = 0;

    while (scanf("%s", cmd) != EOF)
    {
        if (cmd[0] == 'i') 
        {
            top++;
            scanf(" %[^\n]s", frase[top]);
        }
        else
        {
            if (top == -1)
            {
                printf("NULL\n");
            }
            else
            {
                printf("%s\n", frase[top--]);
            }
        }
    }
    return 0;
}