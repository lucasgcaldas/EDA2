#include <stdio.h>

int checa(char str[], int j, int vetor[]) 
{
    int tamanho = 0;
    for (int i = 0; str[i] != '\0'; i++){
        tamanho++;
    }

    for (int i = 0; i < tamanho; i++) {
        if (str[i] == '1') {
                vetor[j] += 1;
            }
            if (str[i] == '2') {
                vetor[j] += 2;
            }
            if (str[i] == '3') {
                vetor[j] += 3;
            }
            if (str[i] == '4') {
                vetor[j] += 4;
            }
            if (str[i] == '5') {
                vetor[j] += 5;
            }
            if (str[i] == '6') {
                vetor[j] += 6;
            }
            if (str[i] == '7') {
                vetor[j] += 7;
            }
            if (str[i] == '8') {
                vetor[j] += 8;
            }
            if (str[i] == '9') {
                vetor[j] += 9;
            }
    }
}


int main(void) 
{
    int num;
    int sum = 0;

    scanf("%d", &num);

    char str[101];
    int vetor[num];

    for (int i = 0; i < num; i++){
        scanf(" %s", str);
        checa(str, i, vetor);
    }

    for (int i = 0; i < num; i++){
        printf("%d\n", vetor[i]);
    }
}