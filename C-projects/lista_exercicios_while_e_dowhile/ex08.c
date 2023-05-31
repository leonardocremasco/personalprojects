// ex. 8

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    
    int votosJose = 0;
    int votosCarlos = 0;
    int votosAntonio = 0;
    int votosNulos = 0;
    int votosBrancos = 0;
    int totalVotos = 0;
    int voto;

    printf("------- URNA ELETRÔNICA -------\n");
    printf("1. Candidato Jose\n");
    printf("2. Candidato Carlos\n");
    printf("3. Candidato Antonio\n");
    printf("4. Nulo\n");
    printf("5. Branco\n");
    printf("Entre com o seu voto (6 para encerrar): \n");

    while (1) {
        scanf("%d", &voto);

        if (voto == 1) {
            votosJose++;
            totalVotos++;
        } else if (voto == 2) {
            votosCarlos++;
            totalVotos++;
        } else if (voto == 3) {
            votosAntonio++;
            totalVotos++;
        } else if (voto == 4) {
            votosNulos++;
            totalVotos++;
        } else if (voto == 5) {
            votosBrancos++;
            totalVotos++;
        } else if (voto == 6) {
            break;
        } else {
            printf("Opcao invalida. Tente novamente.\n");
        }
    }

    float percentualNulos = (float)votosNulos / totalVotos * 100;
    float percentualBrancos = (float)votosBrancos / totalVotos * 100;

    printf("\nResultado da votacao:\n");
    printf("Numero de votos do Candidato Jose: %d\n", votosJose);
    printf("Numero de votos do Candidato Carlos: %d\n", votosCarlos);
    printf("Numero de votos do Candidato Antonio: %d\n", votosAntonio);
    printf("Percentual de votos nulos: %.2f%%\n", percentualNulos);
    printf("Percentual de votos brancos: %.2f%%\n", percentualBrancos);

    // Determinar o candidato vencedor
    if (votosJose > votosCarlos && votosJose > votosAntonio) {
        printf("O candidato vencedor eh Jose!\n");
    } else if (votosCarlos > votosJose && votosCarlos > votosAntonio) {
        printf("O candidato vencedor eh Carlos!\n");
    } else if (votosAntonio > votosJose && votosAntonio > votosCarlos) {
        printf("O candidato vencedor eh Antonio!\n");
    } else {
        printf("Nao houve um candidato claro vencedor.\n");
    }

    return 0;
}
