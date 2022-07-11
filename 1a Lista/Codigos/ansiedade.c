#include <stdio.h>

int main(){

    char resposta[3];
    int qtd_sim = 0, qtd_triagem = 0, i = 0;

    while(scanf(" %s", resposta) != EOF){
        if(i < 10) {
            if (resposta[0] == 's') {
                qtd_sim++;
            }
            i++;
        }
        
        if (i == 10) {
            if (qtd_sim >= 2) {
                qtd_triagem++;
            }
            
            i = 0;
            qtd_sim = 0;
        }
    }

    printf("%d\n", qtd_triagem);

    return 0;
}