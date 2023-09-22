#include <stdio.h>
#include <string.h>

int contarOcorrencias(char *S, char *T) {
    
    int count = 0;
    int lenS = strlen(S);
    int lenT = strlen(T);

    for (int i = 0; i <= lenS - lenT; i++) {
        int j;
        for (j = 0; j < lenT; j++) {
            if (S[i + j] != T[j]) {
                break;
            }
        }

        if (j == lenT) {
            count++;
        }
    }

    return count;
}

int main() {
    char S[100], T[100];

    printf("Digite a string S: ");
    scanf("%s", S);

    printf("Digite a substring T: ");
    scanf("%s", T);
    

    int resultado = contarOcorrencias(S, T);

    printf("A substring T ocorre %d vezes em S.\n", resultado);

    return 0;
}
