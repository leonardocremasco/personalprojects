
#include <stdio.h>
#include <limits.h>

#define V 5  // Número de vértices no grafo

// Função para encontrar o vértice com a menor distância ainda não processado
int minDistance(int dist[], int processed[]) {
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++) {
        if (!processed[v] && dist[v] <= min) {
            min = dist[v];
            min_index = v;
        }
    }
    return min_index;
}

// Implementação do Algoritmo de Dijkstra
void dijkstra(int graph[V][V], int src) {
    int dist[V];        // Array para armazenar a distância mais curta de cada vértice
    int processed[V];   // Array para marcar os vértices processados (visitados)

    // Inicializar todas as distâncias como INFINITO e processed como 0
    for (int i = 0; i < V; i++) {
        dist[i] = INT_MAX;
        processed[i] = 0;
    }

    dist[src] = 0; // A distância do vértice de origem para si mesmo é sempre 0

    for (int count = 0; count < V - 1; count++) {
        int u = minDistance(dist, processed);
        processed[u] = 1;

        for (int v = 0; v < V; v++) {
            if (!processed[v] && graph[u][v] && dist[u] != INT_MAX 
                && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    printSolution(dist);
}

// Função para imprimir as distâncias calculadas
void printSolution(int dist[]) {
    printf("Vertice: \t Distancia da Origem:\n");
    for (int i = 0; i < V; i++) {
        printf("%d \t\t %d\n", i, dist[i]);
    }
}

int main() {
    // Exemplo de grafo representado por matriz de adjacência
    int graph[V][V] = {
        {0, 2, 4, 0, 0 }, // cidade A
        {0, 0, 1, 7, 0}, // cidade B
        {0, 0, 0, 2, 10}, // cidade C
        {0, 0, 0, 0, 2}, // cidade D
        {0, 0, 0, 0, 0} // cidade E
    };

    dijkstra(graph, 0); // Calcula os caminhos mais curtos a partir do vértice 0

    return 0;
}
