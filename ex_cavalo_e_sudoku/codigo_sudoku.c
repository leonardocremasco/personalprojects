#include <stdio.h>
#include <stdbool.h>

#define N 9

/*Criando a função que imprime o tabuleiro*/
void imprimirTabuleiro(int tabuleiro[N][N]){
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; i++)
        {
            printf("%d", tabuleiro[i][j]);
        }
        printf("\n");
        
    }   
}

/*Criando a função que verifica se o número pode entrar na linha*/
bool LinhaValida(int tabuleiro[N][N], int linha, int num){
    for (int coluna = 0; coluna < N; coluna++)
    {
        if (tabuleiro[linha][coluna] == num)
        {
            return false;
        }
        
    }
    return true;

}

/*Criando a função que verifica se o número pode entrar na coluna*/
bool ColunaValida(int tabuleiro[N][N], int coluna, int num){
    for (int linha = 0; linha < N; linha++)
    {
        if(tabuleiro[linha][coluna] == num){
            return false;
        }
    }
    return true;
}

/*Função para verificar se o numero pode ser colocado no tabuleiro 3x3*/
bool tabuleiroValido(int tabuleiro[N][N], int ComecoLinha, int ComecoColuna, int num){
    for (int linha = 0; linha < 3; linha++)
    {
        for (int coluna = 0; coluna < 3; coluna++)
        {
            if(tabuleiro[linha + ComecoLinha][coluna + ComecoColuna] == num)
            return false;
        }
        
    }
    return true;
}

/*Criando função para verificar se o número pode ser colocado na posição específica*/
bool posicao(int tabuleiro[N][N], int linha, int coluna, int num){
    return LinhaValida(tabuleiro, linha, num) && ColunaValida(tabuleiro, coluna, num) && 
           tabuleiroValido(tabuleiro, linha - linha % 3, coluna - coluna % 3, num);
}


/*Criando uma função para encontrar células vazias no tabuleiro*/
bool CelulaVazia(int tabuleiro[N][N], int *linha, int *coluna){
    for (*linha = 0; *linha < N; (*linha)++)
    {
        for (*coluna = 0; *coluna < N; (*coluna)++)
        {
            if(tabuleiro[*linha][*coluna] == 0){
                return true;
            }
        }
        
    }
    return false;
}
/*Usando a recursividade na função para resolver o Sudoku usando Backtracking*/
bool Sudoku(int tabuleiro[N][N]){
    int linha, coluna;

    if(!CelulaVazia(tabuleiro, &linha, &coluna)){
        return true;
    }

/*Preenchendo a célula vazia com números de 1 a 9*/
for (int num = 1; num <= 9; num++)
{
    if(posicao(tabuleiro, linha, coluna, num)){
        tabuleiro[linha][coluna] = num;

        if (Sudoku(tabuleiro))
        {
            return true;
        }
        //Desfazer a atribuição se falhar
        tabuleiro[linha][coluna] = 0;
        
    }
}
return false;
}
int main() {
    int tabuleiro[N][N] = {
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9}
    };
if(Sudoku(tabuleiro)){
    imprimirTabuleiro(tabuleiro);
} else {
    printf("Nao existe solucao para o tabuleiro fornecido.\n");
}
return 0;
}

/****Explicação****

O algoritmo resolve o Sudoku se houver uma solução válida. Caso contrário, será retornado uma mensagem 
indicando que não existe uma solução para o tabuleiro fornecido.

O que a função backtracking faz? 
-> Encontra uma célula vazia e tenta preenche-la com números de 1 a 9
-> Caso o número for inserido, a função chamará a sí mesma de forma recursiva afim de resolver o resto do tabuleiro
-> Caso não seja possível prosseguir, o valor é removido e outra tentativa será executada

Funções principais utilizadas:
-> LinhaValida(): Verifica se o número já está presente na linha
-> ColunaValida(): Verifica se o número já está presente na coluna
-> TabuleiroValido(): Verifica se o numero já está presente no bloco 3x3
-> posicao(): Verifica se é seguro colocar um determinado número em uma célula.

*/