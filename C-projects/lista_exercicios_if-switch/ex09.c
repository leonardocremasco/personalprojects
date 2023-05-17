// Ex. 9: Fazer um programa que recebe duas notas parciais de um aluno (0 a 100) e informa se ele está aprovado (média maior ou igual a 70), em exame final (média entre 40 e 69) ou reprovado (média menor do que 40). Caso esteja em exame o programa deve pedir a nota do exame (0 a 100) e informar se o aluno está aprovado (média mais nota do exame maior ou igual a 100) ou reprovado (média mais nota do exame menor do que 100).

#include <stdio.h>

int main() {
    
    float nota1, nota2, media, notaExame;

    // Pedindo as notas
    printf("Digite a primeira nota (0-100): ");
    scanf("%f", &nota1);

    printf("Digite a segunda nota (0-100): ");
    scanf("%f", &nota2);

    // Calculando a media
    media = (nota1 + nota2) / 2;

    // Exibindo os resultados
    if (media >= 70) {
        printf("APROVADO!\n");
    } else if (media >= 40 && media < 70) {
        printf("EM EXAME FINAL! Digite a nota do exame (0-100):");
        scanf("%f", &notaExame);

        media = (media + notaExame) / 2;

        if (media >= 50) {
            printf("APROVADO\n");
        } else {
            printf("REPROVADO\n");
        }
    } else {
        printf("REPROVADO\n");
    }

    return 0;
}


