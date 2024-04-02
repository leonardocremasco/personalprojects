

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>

/* ------------------------------------------------------------------------*/
// definindo os tokens de verificação
/* ------------------------------------------------------------------------*/

typedef enum
{
    INT,
    IDENTIFIER,
    NUMBER,
    PLUS,
    MINUS,
    MULTIPLY,
    DIVIDE,
    IF,
    ELSE,
    ASSIGN,
    SEMICOLON,
    LPAREN,
    RPAREN,
    LBRACE,
    RBRACE,
    END,
    ERROR
} TokenType;

/* ------------------------------------------------------------------------*/
// struct do token para manipulação
/* ------------------------------------------------------------------------*/

typedef struct
{
    TokenType type;
    char *lexeme;
} Token;

/* ------------------------------------------------------------------------*/
// protótipos das funções booleanas de retorno
/* ------------------------------------------------------------------------*/

Token getNextToken(char *programa);

bool declaracao(Token *token);
bool programa_validar(Token *token);
bool variavel(Token *token);
bool identificador(Token *token);
bool expressao(Token *token);
bool condicional(Token *token);

/* ------------------------------------------------------------------------*/
// Função principal
/* ------------------------------------------------------------------------*/

int main()
{   
    char programa[] = "int x = 5; if (x > 0) { x = x - 1; } else { x = x + 1; }";
    Token token;
    
    if (programa_validar(token))
    {
        printf("Programa válido!\n");
    }
    else
    {
        printf("Erro encontrado na análise sintática.\n");
    }
    return 0;
}

/* ------------------------------------------------------------------------*/
// Obtém o próximo token do programa
/* ------------------------------------------------------------------------*/

Token getNextToken(char *programa)
{

    Token token;
    // Ignora espaços em branco
    while (isspace(*programa))
    {
        programa++;
    }
    token.lexeme = malloc(sizeof(char) * 2);
    token.lexeme[0] = *programa;
    token.lexeme[1] = '\0';
    switch (*programa)
    {
    case 'i':
        token.type = IF;
        break;
    case 'e':
        token.type = ELSE;
        break;
    case '=':
        token.type = ASSIGN;
        break;
    case ';':
        token.type = SEMICOLON;
        break;
    case '(':
        token.type = LPAREN;
        break;
    case ')':
        token.type = RPAREN;
        break;
    case '{':
        token.type = LBRACE;
        break;
    case '}':
        token.type = RBRACE;
        break;
    case '+':
        token.type = PLUS;
        break;
    case '-':
        token.type = MINUS;
        break;
    case '*':
        token.type = MULTIPLY;
        break;
    case '/':
        token.type = DIVIDE;
        break;
    default:
        if (isdigit(*programa))
        {
            token.type = NUMBER;
            while (isdigit(*++programa))
            {
            }
            programa--;
        }
        else if (isalpha(*programa))
        {
            token.type = IDENTIFIER;
            while (isalnum(*++programa))
            {
            }
            programa--;
        }
        else
        {
            token.type = ERROR;
        }
        break;
    }
    programa++;
    return token;
}

/* ------------------------------------------------------------------------*/
// função para verificar se é uma declaração válida
/* ------------------------------------------------------------------------*/

bool declaracao(Token *token)
{
    if (variavel(token))
    {
        if (token->type == ASSIGN)
        {
            *token = getNextToken(token->lexeme);
            if (expressao(token))
            {
                if (token->type == SEMICOLON)
                {
                    *token = getNextToken(token->lexeme);
                    return true;
                }
            }
        }
    }
    else if (condicional(token))
    {
        return true;
    }
    return false;
}

/* ------------------------------------------------------------------------*/
// Função para verificar se o programa está correto
/* ------------------------------------------------------------------------*/
bool programa_validar(Token *token)
{
    *token = getNextToken(token->lexeme);
    if (declaracao(token))
    {
        if (token->type != END)
        {
            return programa(token);
        }
        return true;
    }
    return false;
}

/* ------------------------------------------------------------------------*/
// Função para verificar se é uma variável válida
/* ------------------------------------------------------------------------*/

bool variavel(Token *token)
{
    if (token->type == INT)
    {
        *token = getNextToken(token->lexeme);
        if (identificador(token))
        {
            return true;
        }
    }
    return false;
}

/* ------------------------------------------------------------------------*/
// Função para verificar se é um identificador válido
/* ------------------------------------------------------------------------*/

bool identificador(Token *token)
{
    if (token->type == IDENTIFIER)
    {
        *token = getNextToken(token->lexeme);
        return true;
    }
    return false;
}

/* ------------------------------------------------------------------------*/
// Função para verificar se é uma expressão válida
/* ------------------------------------------------------------------------*/

bool expressao(Token *token)
{
    if (token->type == NUMBER || token->type == IDENTIFIER)
    {
        *token = getNextToken(token->lexeme);
        if (token->type == PLUS || token->type == MINUS || token->type == MULTIPLY || token->type == DIVIDE)
        {
            *token = getNextToken(token->lexeme);
            if (expressao(token))
            {
                return true;
            }
        }
        else
        {
            return true;
        }
    }
    return false;
}

/* ------------------------------------------------------------------------*/
// Função para verificar se é uma condição válida
/* ------------------------------------------------------------------------*/

bool condicional(Token *token)
{
    if (token->type == IF)
    {
        *token = getNextToken(token->lexeme);
        if (token->type == LPAREN)
        {
            *token = getNextToken(token->lexeme);
            if (expressao(token))
            {
                if (token->type == RPAREN)
                {
                    *token = getNextToken(token->lexeme);
                    if (token->type == LBRACE)
                    {
                        *token = getNextToken(token->lexeme);
                        if (declaracao(token))
                        {
                            if (token->type == RBRACE)
                            {
                                *token = getNextToken(token->lexeme);
                                if (token->type == ELSE)
                                {
                                    *token = getNextToken(token->lexeme);
                                    if (token->type == LBRACE)
                                    {
                                        *token = getNextToken(token->lexeme);
                                        if (declaracao(token))
                                        {
                                            if (token->type == RBRACE)
                                            {
                                                *token = getNextToken(token->lexeme);
                                                return true;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return false;
}
