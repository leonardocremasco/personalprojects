 // Ex05) structs para informações

 #include <stdio.h>
 #include <stdlib.h>

 struct Aluno{
    
    char nome[50];
    int idade;
    float nota1;
    float nota2;
 };
 
 void dadosAluno(struct Aluno *aluno) {
    printf("Digite o nome do aluno: ");
    scanf("%s", aluno->nome);

    printf("Digite a idade do aluno: ");
    scanf("%d", &aluno->idade);

    printf("Digite a nota 1 do aluno: ");
    scanf("%f", &aluno->nota1);

    printf("Digite a nota 2 do aluno: ");
    scanf("%f", &aluno->nota2);
}

// Função para calcular a média das notas de um aluno
float calcularMedia(struct Aluno *aluno) {
    return (aluno->nota1 + aluno->nota2) / 2.0;
}   

void exibirAluno(struct Aluno *aluno) {
    printf("Nome: %s\n", aluno->nome);
    printf("Idade: %d\n", aluno->idade);
    printf("Nota 1: %.2f\n", aluno->nota1);
    printf("Nota 2: %.2f\n", aluno->nota2);
}

int main() {
    
    const int numAlunos = 10;

    // array de structs Aluno para armazenar informações dos alunos
    struct Aluno alunos[numAlunos];

    // Loop para preencher as informações de cada aluno, calcular e exibir a média e mostrar todos os dados do aluno
    for (int i = 0; i < numAlunos; ++i) {
        printf("\nDigite as informacoes para o aluno %d:\n", i + 1);

        // Preencher as informações do aluno
        dadosAluno(&alunos[i]);

        // Calcular a média das notas do aluno
        float media = calcularMedia(&alunos[i]);

        // Exibir os dados do aluno
        printf("\nMedia das notas do aluno %d: %.2f\n", i + 1, media);
        exibirAluno(&alunos[i]);
    }

    return 0;
}
