
#include <stdio.h>
#include <string.h>

int main() {
    
    char s[50];
    char sexo;
    int idade;

    printf("Digite o nome : ");
    fgets(s, 50, stdin);

    printf("Digite o sexo (M/F): ");
    scanf("%c", &sexo); 

    printf("Digite a idade: ");
    scanf("%d", &idade);

    if (sexo == 'F' && idade < 25) {
        printf("%s ACEITA\n", s);
    } else {
        printf("NÃO ACEITA\n");
    }

    return 0;
}
