#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// funcao para encontrar a menor dist de 2 pontos
int min_Distancia(int points[], int left, int right) {
    if (right - left <= 1) {
        // caso houver apenas dois pontos ou menos, retorna a distância entre eles
        if (right == left) {
            return INT_MAX;  // Nenhuma distância para calcular
        }
        return abs(points[right] - points[left]);
    }

    int mid = left + (right - left) / 2;

    // Rutilizera recursao para encontrar a distância mínima à esquerda e à direita do ponto médio
    int leftMin = minDistance(points, left, mid);
    int rightMin = minDistance(points, mid + 1, right);

    // A distância mínima será a menor das distâncias calculadas
    int minDist = (leftMin < rightMin) ? leftMin : rightMin;

    // Verifica a distância mínima cruzando o ponto médio
    int crossMin = abs(points[mid + 1] - points[mid]);
    if (crossMin < minDist) {
        minDist = crossMin;
    }

    return minDist;
}

int main() {
    int points[] = {3, 6, 9, 19, 25, 40, 43, 55, 58, 71, 73, 79, 82, 84, 90, 96, 100};
    int n = sizeof(points) / sizeof(points[0]);

    // Chama a função para encontrar a menor distância
    int resultado = min_Distancia(points, 0, n - 1);

    printf("A menor distancia entre dois pontos eh: %d\n", resultado);

    return 0;
}
