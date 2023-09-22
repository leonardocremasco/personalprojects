
#include <stdio.h>

int encontrarNotaDaOutraProva(int notaConhecida, int media) {
    return 2 * media - notaConhecida;
}

int main() {
    int notaConhecida, media;

    
    printf("Digite uma das notas: ");
    scanf("%d", &notaConhecida);

    printf("Digite a media das duas notas: ");
    scanf("%d", &media);

    
    int nota2 = encontrarNotaDaOutraProva(notaConhecida, media);

    
    if (nota2 >= 0 && nota2 <= 100) {
        printf("A outra nota eh: %d\n", nota2);
    } else {
        printf("A media e a nota fornecidas nao sao consistentes.\n");
    }

    return 0;
}
