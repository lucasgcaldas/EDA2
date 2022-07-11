#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

    int num, qtd_questoes_reprovado, qtd_questoes_aluno;
    char nome_aluno[21], nome_aluno_reprovado[21];

    int i = 1;
    while(scanf("%d", &num) != EOF){
        qtd_questoes_reprovado = 11;
        while(num != 0){
            scanf("%s %d", nome_aluno, &qtd_questoes_aluno);
            if(qtd_questoes_aluno < qtd_questoes_reprovado) 
            {
                qtd_questoes_reprovado = qtd_questoes_aluno;
                strcpy(nome_aluno_reprovado, nome_aluno);
            }
            else if((qtd_questoes_aluno == qtd_questoes_reprovado) && (strcmp(nome_aluno, nome_aluno_reprovado) > 0)) 
            {
                strcpy(nome_aluno_reprovado, nome_aluno);
            }
            num--;
        }

        printf("Instancia %d\n", i++);
        printf("%s\n\n", nome_aluno_reprovado);
    }

    return 0;
}