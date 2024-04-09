//---------------------------------------------------------------------------
#include <stdlib.h>
#include <stdio.h>
#include <windows.h>
//---------------------------------------------------------------------------

/* -----------------------------------------------------------------------------
Estrutura LISTA ENCADEADA SIMPLES - Com Descritor
------------------------------------------------------------------------------*/

typedef struct no_ls {
	int dado;
	struct no_ls *prox;
}  Tno_ls;  // tipo de nó de lista simples

typedef struct descritor_ls {
	int tam;
	struct no_ls *prim;
	struct no_ls *ult;
} Tdescritorno_ls; // tipo de descritor de nó de lista simples, atua como um metadado -> informações sobre     outros dados


// Tabela de codigo de erros
// 0 - sem erro
// 1 - ...
// 2 - ...


/* -----------------------------------------------------------------------------
Prototipos das funcoes
------------------------------------------------------------------------------*/
int Inicializar_LS      (Tdescritorno_ls *pdesc);
int Inicializar2_LS     (Tdescritorno_ls *pdesc);
int Inserir_inicio_LS   (Tdescritorno_ls *pdesc, int info);
int Inserir_fim_LS      (Tdescritorno_ls *pdesc, int info);
int Inserir_meio_LS     (Tdescritorno_ls *pdesc, int info, int pos);
int Remover_inicio_LS   (Tdescritorno_ls *pdesc);
int Remover_meio_LS     (Tdescritorno_ls *pdesc, int pos);
int Remover_fim_LS      (Tdescritorno_ls *pdesc);
int Listar_LS           (Tdescritorno_ls cdesc); // cdesc = cópia do descritor
int Obter_dado_LS       (Tdescritorno_ls cdesc, int pos, int *dado);
int Obter_pos_LS        (Tdescritorno_ls cdesc, int dado, int *pos);
int Obter_Tamanho_LS    (Tdescritorno_ls cdesc, int *tam);

/* Variaveis global */



/* -----------------------------------------------------------------------------
PRINCIPAL
------------------------------------------------------------------------------*/
int main(void)
{

	int info;
	int erro; /* valor de erro retornado pelas funcoes */
	Tdescritorno_ls desc;
	int q;  /* receber a opcao do usuario */
	erro = Inicializar_LS  (&desc);
	do {
	    system("cls");
	    printf("1 -> Inserir no inicio \n");
		printf("2 -> Inserir no final\n");
		printf("3 -> Remover no inicio\n");
		printf("4 -> Mostrar toda a lista \n");
		printf("5 -> Inicializar a lista (versao 2)\n");
		printf("6 -> Sair \n:");
		scanf("%d", &q);     /* Ler a opcao do usuario */
		switch(q) {
			case 1: printf("Dado para insercao na lista: ");
                    scanf("%d",&info);
                    erro=Inserir_inicio_LS (&desc, info);
                    if (erro == 0) printf("Insercao realizada com sucesso\n");
                    system("pause");
					break;

			case 2: printf("Dado para insercao na lista: ");
                    scanf("%d",&info);
                    //Inserir_fim_LS (&desc, info);
			        break;

            case 3: //erro = Remover_inicio_LS (&desc);
                    if (erro==1)
                    {
                        printf("\nLista vazia. Impossivel remover");
                    }
                    system("pause");
                    break;

			case 4: //erro=Listar_LS (desc);
                    if (erro==1)
                    {
                        printf("\nLista vazia. Impossivel listar");
                    }
                    system("pause");
					break;

			case 5: //erro=Inicializar2_LS (&ini);
                    printf("\nInicializacao realizada com sucesso !\n");
                    printf("\nLISTA VAZIA !\n");
                    system("pause");
					break;
			case 6: break;
			default: printf("\n\n Opcao nao valida");
		}
		getchar();    /* Limpa o buffer de entrada */
	} while ((q != 6) );

}

int Inicializar_LS      (Tdescritorno_ls *pdesc)
{
    pdesc ->prim = NULL;
    pdesc ->ult = NULL;
    pdesc ->tam = 0;
}

int Inserir_inicio_LS   (Tdescritorno_ls *pdesc, int info)
{
    Tno_ls *no_novo, *aux;

    /* Criacao do novo no - Aloca��o de memoria */
    no_novo = (Tno_ls *) malloc(sizeof(Tno_ls));
    no_novo -> dado = info;

    if (pdesc -> tam ==0)
    { // lista vazia
        pdesc -> prim = no_novo;
        pdesc -> ult = no_novo;
        pdesc -> tam = 1;
    }
    else
    {  // lista n�o vazia
        aux = pdesc -> prim; // guarda o primeiro valor do primeiro nó (Dado)
        pdesc -> prim = no_novo; // prim agora aponta para nó novo
        no_novo -> prox = aux;    // ligando o novo com o 1o no
        pdesc -> tam = 1;
    }
    return 0;
}
