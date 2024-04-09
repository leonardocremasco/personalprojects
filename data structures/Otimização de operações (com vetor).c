//---------------------------------------------------------------------------
#include <stdlib.h>
#include <stdio.h>
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

// ESTRUTURA DE VETOR PARA GERENCIAMENTO DE MEMORIA ************
struct no_ls *vet[50]; // estoque de nós liberados da lista
int control_estoque =0; // indicativo da posicao livre em estoque para armazenamento
// *************************************************************


/* -----------------------------------------------------------------------------
PRINCIPAL
------------------------------------------------------------------------------*/
int main(void)
{

	int info;
	int erro; /* valor de erro retornado pelas funcoes */
	Tno_ls *ini;
	int q;  /* receber a opcao do usuario */
	do {
	    system("cls");
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
INICIALIZAR lista
--------------------------------------------------------------------------------------*/
int Inicializar_LS (Tno_ls **inicio)
{
	*inicio= NULL;
	return 0; /* sem erro */
} /* Fim da fun��o de INICIALIZAR */


/* -------------------------------------------------------------------------------------
INSER��O NO INICIO na lista com otimiza��o de memoria
---------------------------------------------------------------------------------------*/
int Inserir_inicio_LS (Tno_ls **inicio, int info)
{
    Tno_ls *no_novo;

    // GERENCIAMENTO DE MEMORIA ********************************************
    if ( control_estoque == 0)
    {
       /* Criacao do novo no - Aloca��o de memoria */
       no_novo = (Tno_ls *) malloc(sizeof(Tno_ls));
    }
    else {
       control_estoque--;
       no_novo = vet[control_estoque];
    }
    // **********************************************************************

    no_novo -> dado = info;
	if (*inicio==NULL)
	{
	    no_novo -> prox = NULL;
	    *inicio = no_novo;
	}
	else {
	     no_novo -> prox = *inicio;
	    *inicio = no_novo;
	}
    return 0;
}

/* ----------------------------------------------------------------------------------------
INSER��O NO FIM na lista com otimiza��o de memoria
------------------------------------------------------------------------------------------*/
int Inserir_fim_LS (Tno_ls **inicio, int info)
{
    Tno_ls *no_novo, *percorre;

     // GERENCIAMENTO DE MEMORIA ********************************************
    if ( control_estoque == 0)
    {
       /* Criacao do novo no - Aloca��o de memoria */
       no_novo = (Tno_ls *) malloc(sizeof(Tno_ls));
    }
    else {
        control_estoque--;
        no_novo = vet[control_estoque];
    }
    // **********************************************************************

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
         // GERENCIAMENTO DE MEMORIA ********************************************
         if (control_estoque > 50)
          {
              free (aux);
          }
         else {
              vet[control_estoque] = aux;
              control_estoque++;
         }
        // ***********************************************************************
        *inicio = (*inicio)->prox;
        return 0;
    }
}
