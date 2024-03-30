#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


// enumerando todos os tipos de token
typedef enum {
    INT,
    IDENTIFICADOR,
    NUMERO,
    OPERADOR,
    IF,
    ELSE,
    ABRE_PARENTESES,
    FECHA_PARENTESES,
    ABRE_CHAVES,
    FECHA_CHAVES,
    IGUAL,
    PONTO_VIRGULA,
    FIM
} TipoToken;

// Estrutura para representar um token
typedef struct {
    TipoToken tipo;
    char lexema[50]; // Assumindo que o tamanho máximo do lexema é 50
} Token;

// Função para verificar se um caractere é uma letra
int is_letra(char c) {
    return isalpha(c);
}

/*---------------------------------------------------*/
// Função para verificar se um caractere é um dígito
/*---------------------------------------------------*/
int is_digito(char c) {
    return isdigit(c);
}

/*------------------------------------------*/
// Função para verificar se um caractere é um operador
/*------------------------------------------*/
int is_operador(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}

/*------------------------------------------*/
// Função para obter o próximo token do programa
/*------------------------------------------*/
Token obter_proximo_token(char *programa, int *posicao) {
    Token token;
    int i = *posicao;
    char c = programa[i];

    // Ignorar espaços em branco
    while (c == ' ' || c == '\t' || c == '\n') {
        c = programa[++i];
    }

    // Fim do programa
    if (c == '\0') {
        token.tipo = FIM;
        token.lexema[0] = '\0';
        *posicao = i;
        return token;
    }

    // Analisar o token
    if (is_letra(c)) {
        // Identificador
        int j = 0;
        while (is_letra(c) || is_digito(c)) {
            token.lexema[j++] = c;
            c = programa[++i];
        }
        token.lexema[j] = '\0';
        token.tipo = IDENTIFICADOR;
    } else if (is_digito(c)) {
        // Número
        int j = 0;
        while (is_digito(c)) {
            token.lexema[j++] = c;
            c = programa[++i];
        }
        token.lexema[j] = '\0';
        token.tipo = NUMERO;
    } else if (is_operador(c)) {
        // Operador
        token.lexema[0] = c;
        token.lexema[1] = '\0';
        token.tipo = OPERADOR;
        i++;
    } else {
        // Outros tokens
        switch (c) {
            case 'i':
                token.tipo = IF;
                break;
            case 'e':
                token.tipo = ELSE;
                break;
            case '(':
                token.tipo = ABRE_PARENTESES;
                break;
            case ')':
                token.tipo = FECHA_PARENTESES;
                break;
            case '{':
                token.tipo = ABRE_CHAVES;
                break;
            case '}':
                token.tipo = FECHA_CHAVES;
                break;
            case '=':
                token.tipo = IGUAL;
                break;
            case ';':
                token.tipo = PONTO_VIRGULA;
                break;
            default:
                // Token inválido
                fprintf(stderr, "Erro: Caractere inválido encontrado: %c\n", c);
                exit(EXIT_FAILURE);
        }
        token.lexema[0] = c;
        token.lexema[1] = '\0';
        i++;
    }

    *posicao = i;
    return token;
}

/*---------------------------------------------------------------------------------*/
// função para verificar se um identificador(ID) está dentro dos caracteres permitidos (alfabeto e números)
/*---------------------------------------------------------------------------------*/
int validar_identificador(char *identificador) {
    int i = 0;
    while (identificador[i] != '\0') {
        if (!is_letra(identificador[i]) && !is_digito(identificador[i])) {
            return 0; // Identificador inválido
        }
        i++;
    }
    return 1; // Identificador válido
}

/*------------------------------------------*/
// função para analisar uma declaração
/*------------------------------------------*/

int analisar_declaracao(char *programa, int *posicao) {
    Token token = obter_proximo_token(programa, posicao);
    if (token.tipo == INT) {
        token = obter_proximo_token(programa, posicao);
        if (token.tipo == IDENTIFICADOR && validar_identificador(token.lexema)) {
            token = obter_proximo_token(programa, posicao);
            if (token.tipo == IGUAL) {
                if (!analisar_expressao(programa, posicao)) {
                    return 0; // Expressão inválida
                }
                token = obter_proximo_token(programa, posicao);
                if (token.tipo == PONTO_VIRGULA) {
                    return 1; // Declaração válida
                }
            }
        }
    }
    return 0; // logo, será uma declaração inválida
}

/*------------------------------------------*/
// função para analisar uma expressão numérica
/*------------------------------------------*/

int analisar_expressao(char *programa, int *posicao) {
    Token token = obter_proximo_token(programa, posicao);
    if (token.tipo == NUMERO || token.tipo == IDENTIFICADOR) {
        token = obter_proximo_token(programa, posicao);
        if (token.tipo == OPERADOR) {
            if (!analisar_expressao(programa, posicao)) {
                return 0; // Expressão inválida
            }
        }
        return 1; // Expressão válida
    }
    return 0; // Expressão inválida
}

/*------------------------------------------*/
// Função para analisar uma condicional
/*------------------------------------------*/
int analisar_condicional(char *programa, int *posicao) {
    Token token = obter_proximo_token(programa, posicao);
    if (token.tipo == IF) {
        token = obter_proximo_token(programa, posicao);
        if (token.tipo == ABRE_PARENTESES) {
            if (!analisar_expressao(programa, posicao)) {
                return 0; // Expressão inválida
            }
            token = obter_proximo_token(programa, posicao);
            if (token.tipo == FECHA_PARENTESES) {
                token = obter_proximo_token(programa, posicao);
                if (token.tipo == ABRE_CHAVES) {
                    if (!analisar_declaracao(programa, posicao)) {
                        return 0; // Declaração inválida
                    }
                    token = obter_proximo_token(programa, posicao);
                    if (token.tipo == FECHA_CHAVES) {
                        token = obter_proximo_token(programa, posicao);
                        if (token.tipo == ELSE) {
                            token = obter_proximo_token(programa, posicao);
                            if (token.tipo == ABRE_CHAVES) {
                                if (!analisar_declaracao(programa, posicao)) {
                                    return 0; // Declaração inválida
                                }
                                token = obter_proximo_token(programa, posicao);
                                if (token.tipo == FECHA_CHAVES) {
                                    return 1; // Condicional válida
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return 0; // Condicional inválida
}

/*------------------------------------------*/
// Função principal
/*------------------------------------------*/
int main() {
    
    char programa[5000]; // Assumindo que o tamanho máximo do programa é 1000 caracteres
    
    printf("Digite o programa:\n");
    fgets(programa, sizeof(programa), stdin);

    int posicao = 0;
    while (1) {
        int resultado = analisar_declaracao(programa, &posicao);
        if (resultado) {
            printf("Declaração válida.\n");
        } else {
            resultado = analisar_condicional(programa, &posicao);
            if (resultado) {
                printf("Condicional válida.\n");
            } else {
                printf("Erro de sintaxe.\n");
                break;
            }
        }

        Token token = obter_proximo_token(programa, &posicao);
        if (token.tipo == FIM) {
            break;
        }
    }

    return 0;
}
