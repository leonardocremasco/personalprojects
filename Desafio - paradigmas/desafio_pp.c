

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>

// Definição dos tokens
typedef enum {
    INT,
    IDENTIFICADOR,
    NUMERO,
    OPERADOR,
    IF,
    ELSE,
    ABRE_CHAVES,
    FECHA_CHAVES,
    ATRIBUICAO,
    PONTO_VIRGULA,
    FIM,
    ERRO
} Token;

// Estrutura para armazenar o token e seu valor (se aplicável)
typedef struct {
    Token token;
    char lexema[100]; // para armazenar identificadores e números
} TokenInfo;

// Função para obter o próximo token do programa
TokenInfo getNextToken(char *programa, int *posicao) {
    TokenInfo tokenInfo;
    int i = *posicao;

    // Ignora espaços em branco
    while (isspace(programa[i])) {
        i++;
    }

    // Verifica o fim do programa
    if (programa[i] == '\0') {
        tokenInfo.token = FIM;
        strcpy(tokenInfo.lexema, "");
        *posicao = i;
        return tokenInfo;
    }

    // Verifica identificadores e palavras-chave
    if (isalpha(programa[i])) {
        int j = 0;
        while (isalnum(programa[i])) {
            tokenInfo.lexema[j++] = programa[i++];
        }
        tokenInfo.lexema[j] = '\0';

        if (strcmp(tokenInfo.lexema, "int") == 0) {
            tokenInfo.token = INT;
        } else if (strcmp(tokenInfo.lexema, "if") == 0) {
            tokenInfo.token = IF;
        } else if (strcmp(tokenInfo.lexema, "else") == 0) {
            tokenInfo.token = ELSE;
        } else {
            tokenInfo.token = IDENTIFICADOR;
        }

        *posicao = i;
        return tokenInfo;
    }

    // Verifica números
    if (isdigit(programa[i])) {
        int j = 0;
        while (isdigit(programa[i])) {
            tokenInfo.lexema[j++] = programa[i++];
        }
        tokenInfo.lexema[j] = '\0';
        tokenInfo.token = NUMERO;
        *posicao = i;
        return tokenInfo;
    }

    // Verifica operadores e símbolos especiais
    switch (programa[i]) {
        case '=':
            tokenInfo.token = ATRIBUICAO;
            break;
        case '+':
        case '-':
        case '*':
        case '/':
            tokenInfo.token = OPERADOR;
            break;
        case '{':
            tokenInfo.token = ABRE_CHAVES;
            break;
        case '}':
            tokenInfo.token = FECHA_CHAVES;
            break;
        case ';':
            tokenInfo.token = PONTO_VIRGULA;
            break;
        default:
            tokenInfo.token = ERRO;
            break;
    }

    tokenInfo.lexema[0] = programa[i];
    tokenInfo.lexema[1] = '\0';
    *posicao = i + 1;
    return tokenInfo;
}

// Protótipos das funções para análise sintática
bool programa(TokenInfo tokens[], int *posicao);
bool declaracao(TokenInfo tokens[], int *posicao);
bool variavel(TokenInfo tokens[], int *posicao);
bool identificador(TokenInfo tokens[], int *posicao);
bool expressao(TokenInfo tokens[], int *posicao);
bool condicional(TokenInfo tokens[], int *posicao);

// Função principal
int main() {
    char programa[] = "int x = 5 + 8; if (x > 10) { x = x + 1; } else { x = x - 1; }";

    TokenInfo tokens[100];
    int posicao = 0;
    TokenInfo token;

    // Análise léxica: obter todos os tokens
    int i = 0;
    while ((token = getNextToken(programa, &posicao)).token != FIM) {
        tokens[i++] = token;
    }
    tokens[i] = token;

    // Análise sintática: verificar se o programa está na gramática BNF
    if (programa(tokens, &posicao)) {
        printf("O programa está na gramática BNF.\n");
    } else {
        printf("O programa NÃO está na gramática BNF.\n");
    }

    return 0;
}

// Função para analisar a regra <programa>
bool programa(TokenInfo tokens[], int *posicao) {
    return declaracao(tokens, posicao) && programa(tokens, posicao);
}

// Função para analisar a regra <declaracao>
bool declaracao(TokenInfo tokens[], int *posicao) {
    if (variavel(tokens, posicao)) {
        if (tokens[*posicao].token == ATRIBUICAO) {
            (*posicao)++;
            return expressao(tokens, posicao) && tokens[*posicao].token == PONTO_VIRGULA;
        }
        return false;
    }
    return condicional(tokens, posicao);
}

// Função para analisar a regra <variavel>
bool variavel(TokenInfo tokens[], int *posicao) {
    if (tokens[*posicao].token == INT) {
        (*posicao)++;
        return identificador(tokens, posicao);
    }
    return false;
}

// Função para analisar a regra <identificador>
bool identificador(TokenInfo tokens[], int *posicao) {
    if (tokens[*posicao].token == IDENTIFICADOR) {
        (*posicao)++;
        return true;
    }
    return false;
}

// Função para analisar a regra <expressao>
bool expressao(TokenInfo tokens[], int *posicao) {
    if (tokens[*posicao].token == NUMERO || tokens[*posicao].token == IDENTIFICADOR) {
        (*posicao)++;
        if (tokens[*posicao].token == OPERADOR) {
            (*posicao)++;
            return expressao(tokens, posicao);
        }
        return true;
    }
    return false;
}

// Função para analisar a regra <condicional>
bool condicional(TokenInfo tokens[], int *posicao) {
    if (tokens[*posicao].token == IF) {
        (*posicao)++;
        if (tokens[*posicao].token == '(') {
            (*posicao)++;
            if (expressao(tokens, posicao)) {
                if (tokens[*posicao].token == ')') {
                    (*posicao)++;
                    if (tokens[*posicao].token == ABRE_CHAVES) {
                        (*posicao)++;
                        if (declaracao(tokens, posicao)) {
                            if (tokens[*posicao].token == FECHA_CHAVES) {
                                (*posicao)++;
                                if (
