#include <stdio.h>
#include <string.h>


int conta7(long int num, int qnt_algarimo, int count, int i) 
{
    char s_num[qnt_algarimo];
    sprintf(s_num, "%ld", num);   

    if (i < qnt_algarimo) 
    {
        if (s_num[i] == '7') 
        {
            count++;
        }
        i++;
        conta7(num, qnt_algarimo, count, i);
    } 
    else 
    {
        return count;
    }
}

int conta_algarismos(long int number, int qnt_algarimo) 
{

    number = number / 10;

    if (number != 0) {
        qnt_algarimo++;
        conta_algarismos(number, qnt_algarimo);
    } 
    else 
    {
        return qnt_algarimo;
    }
}

int main(void) 
{
    long int num = 0, qnt_algarimo = 1, count = 0, i = 0;

    scanf("%ld", &num);
    
    qnt_algarimo = conta_algarismos(num, qnt_algarimo);
    count = conta7(num, qnt_algarimo, count, i); 

    printf("%d\n", count);

    return 0;
}