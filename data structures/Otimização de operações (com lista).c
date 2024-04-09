//---------------------------------------------------------------------------
#include <stdlib.h>
#include <stdio.h>
#define clrscr system("cls")
//---------------------------------------------------------------------------

/* -----------------------------------------------------------------------------
Estrutura LISTA ENCADEADA SIMPLES
------------------------------------------------------------------------------*/

typedef struct no_ls {
	int dado;
	struct no_ls *prox;
}  Tno_ls;


/* -----------------------------------------------------------------------------
Prototipos das funcoes
------------------------------------------------------------------------------*/
int Inicializar_LS (Tno_ls **inicio);
int Inserir_inicio_LS (Tno_ls **inicio, int info);
int Inserir_fim_LS (Tno_ls **inicio, int info);
int Inserir_meio_LS (Tno_ls **inicio, int info);
int Remover_inicio_LS (Tno_ls **inicio);
int Remover_meio_LS (Tno_ls **inicio);
int Remover_fim_LS (Tno_ls **inicio);
int Listar_LS (Tno_ls *inicio);
int Obter_dado_LS (Tno_ls *inicio, int pos, int *dado);
int Obter_pos_LS (Tno_ls *inicio, int dado, int *pos);


/* Variaveis global */
// OTIMIZACAO DE MANIPULACAO DE MEMORIA
Tno_ls *estoque = NULL; // lista encadeada de estoque de n�s liberados para reutilizacao



/* -----------------------------------------------------------------------------
PRINCIPAL
------------------------------------------------------------------------------*/
int main(void)
{

	int info;

	int erro; /* valor de erro retornado pelas funcoes */
	Tno_ls *ini;
	Inicializar_LS (&ini);
	int q;  /* receber a opcao do usuario */
	do {
	    clrscr;
	    printf("LISTA ENCADEADA SIMPLES - LES");
		printf("\n\nOpcoes: \n\n");
		printf("1 -> Inserir no inicio \n");
		printf("2 -> Inserir no final\n");
		printf("3 -> Remover no inicio\n");
		printf("4 -> Mostrar toda a lista \n");
		printf("5 -> Inicializar a lista \n");
		printf("6 -> Sair \n:");
		scanf("%d", &q);     /* Le a opcao do usuario */
		switch(q) {
			case 1: printf("Dado para insercao na lista: ");
                    scanf("%d",&info);
                    Inserir_inicio_LS (&ini, info);
					break;
			case 2: printf("Dado para insercao na lista: ");
                    scanf("%d",&info);
                    Inserir_fim_LS (&ini, info);
			        break;
            case 3: Remover_inicio_LS (&ini);
                    break;
			case 4: erro=Listar_LS (ini);
                    if (erro==1)
                    {
                        printf("\nLista vazia");
                    }
                    getchar();
					break;
			case 5: erro=Inicializar_LS (&ini);
                    printf("\nInicializacao realizada com sucesso !\n");
                    printf("\nLISTA VAZIA !\n");

                    getchar();
					break;
			case 6: break;
			default: printf("\n\n Opcao nao valida");
		}
		getchar();    /* Limpa o buffer de entrada */
	} while ((q != 6) );

}


 /* ------------------------------------------------------------------------------------
LISTAR todos os elementos presentes na lista encadeada
--------------------------------------------------------------------------------------*/
int Listar_LS (Tno_ls *inicio)
{
	int i;
	if (inicio == NULL)
	{
        return 1;  /* lista vazia */
	}
    printf("LISTA ::  ");
	while (inicio != NULL) {
		   printf("%d  ",inicio->dado);
		   inicio = inicio->prox;
    }
    printf("\n");
	return 0; /* sem erro */
} /* Fim da fun��o de MOSTRAR */



/* ------------------------------------------------------------------------------------
INICIALIZAR
--------------------------------------------------------------------------------------*/
int Inicializar_LS (Tno_ls **inicio)
{
	*inicio= NULL;
	return 0; /* sem erro */
} /* Fim da fun��o de INICIALIZAR */




/* -------------------------------------------------------------------------------------
INSER��O NO INICIO da lista com otimiza��o de memoria
---------------------------------------------------------------------------------------*/
int Inserir_inicio_LS (Tno_ls **inicio, int info)
{
    Tno_ls *no_novo;

   // OTIMIZACAO DE MEMORIA*************************************************
    // A remocao de n�s liberados pela insercao ocorre sempre no inicio da lista de estoque
    // A logica deste trecho � a mesma da remocao no inicio de uma lista
    if (estoque == NULL)
    {
        /* Criacao do novo no - Aloca��o de memoria */
        no_novo = (Tno_ls *) malloc(sizeof(Tno_ls));
        printf("\ncriei um novo no");
        getchar();
    }
    else {
        no_novo = estoque;
        estoque = estoque->prox;
    }
    // *********************************************************************
    no_novo -> dado = info;
	if (*inicio==NULL)
	{
	    no_novo -> prox = NULL;
	}
	else {
	    no_novo -> prox = *inicio;
	}
	*inicio = no_novo;
    return 0;
}

/* ----------------------------------------------------------------------------------------
INSER��O NO FIM da lista com otimiza��o de memoria
------------------------------------------------------------------------------------------*/
int Inserir_fim_LS (Tno_ls **inicio, int info)
{
    Tno_ls *no_novo, *percorre;

    // OTIMIZACAO DE MEMORIA*******************************************
    // A remocao de nós liberados pela insercao ocorre sempre no inicio da lista de estoque
    // A logica deste trecho � a mesma da remocao no inicio de uma lista
    if (estoque == NULL)
    {
        /* Criacao do novo no - Aloca��o de memoria */
        no_novo = (Tno_ls *) malloc(sizeof(Tno_ls));
    }
    else {
        no_novo = estoque;
        estoque = estoque->prox;
    }
    // ***************************************************************

    no_novo -> dado = info;
    no_novo -> prox = NULL;
	if (*inicio==NULL)
	{

	    *inicio = no_novo;
	}
	else {
	     percorre = *inicio;
	     while (percorre->prox != NULL)
	     {
	         percorre = percorre -> prox;
	     }
	    percorre->prox = no_novo;
	}
	return 0;
}

/* -------------------------------------------------------------------------
REMOCAO de elementos da lista Com otimiza��o de memoria
-------------------------------------------------------------------------*/
int Remover_inicio_LS (Tno_ls **inicio)

{
    Tno_ls *aux;
    if (*inicio == NULL)
    {
         printf("\nLISTA VAZIA ! \nRemocao Impossivel\n");
        return 1;  /* lista vazia, impossivel remover primeiro */
    }
    else {
        aux = *inicio;
        *inicio = (*inicio)->prox;
        // OTIMIZACAO DE MEMORIA*******************************************
        // A insercao de n�s liberados pela remocao ocorre sempre no inicio da lista de estoque
        // A logica deste trecho � a mesma da insercao no inicio de uma lista
        if (estoque==NULL)
	    {
           estoque = aux;
	       estoque -> prox = NULL;
	    }
	    else {
	       aux -> prox = estoque;
	       estoque = aux;
        }
	     //****************************************************************
    }
    return 0;
}

