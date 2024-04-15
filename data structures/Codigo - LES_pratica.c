
/*---------------------------------------------------------------------------*/
#include <stdlib.h>
#include <stdio.h>
/*---------------------------------------------------------------------------*/

/* -----------------------------------------------------------------------------
Estrutura LISTA ENCADEADA SIMPLES
------------------------------------------------------------------------------*/

struct no_ls {
	int dado;
	struct no_ls *prox; // ponteiro alocando memória apontando para o próximo dado
};

typedef struct no_ls Tno_ls; // "apelidando" a struct de Tipo de nó de lista simples

/* Tabela de codigo de erros
// 0 - sem erro
// 1 - ...
// 2 - ...
*/

/* -----------------------------------------------------------------------------
Prototipos das funcoes
------------------------------------------------------------------------------*/
int Inicializar_LS     (Tno_ls **p_inicio); // -> FEITO
int Inicializar2_LS    (Tno_ls **p_inicio); // -> FEITO
int Inserir_inicio_LS  (Tno_ls **p_inicio, int info); // 
int Inserir_fim_LS     (Tno_ls **p_inicio, int info);
int Inserir_meio_LS    (Tno_ls **p_inicio, int info, int pos);
int Remover_inicio_LS  (Tno_ls **p_inicio);

int Listar_LS          (Tno_ls *c_inicio); // copia do inicio - FEITA
int Obter_pos_LS       (Tno_ls *c_inicio, int dado, int *pos);
int Obter_Tamanho_LS   (Tno_ls *c_inicio, int *tam); // -> FEITO

int Inverte_LS         (Tno_ls **p_inicio);
int Inverte_LS_2       (Tno_ls **p_inicio);

int Repete_Dado_LS     (Tno_ls *c_inicio, int info, int *resp);
/* verifica se o dado esta repetido na estrutura
// resp = 1 - sim
// resp = 0 - nao */

int Remover_meio_LS (Tno_ls **p_inicio, int pos);
/* FAZER int Remover_fim_LS     (Tno_ls **p_inicio); */
/* FAZER int Obter_dado_LS      (Tno_ls *c_inicio, int pos, int *dado); */

int Maiorque_Dado_LS (Tno_ls *c_inicio, int info, int *quant);
/* obtem a quantidade de dados maior que info */

int Inverter_LS_2 (Tno_ls **p_inicio);
/* inverter a lista encadeada usando as rotinas prontas */


/* Variaveis global
NENHUMA */


/* -----------------------------------------------------------------------------
PRINCIPAL
------------------------------------------------------------------------------*/
int main(void)
{

	int info;
	int resp, pos;
	int erro; /* valor de erro retornado pelas funcoes */

	Tno_ls *ini;
	int q;  /* receber a opcao do usuario */
	erro=Inicializar_LS (&ini);
    
	system("pause");
	do {
	    system("cls");
	    printf("LISTA ENCADEADA SIMPLES - LES");
		printf("\n\nOpcoes: \n\n");

		printf("1 -> Inserir no inicio \n");
		printf("2 -> Inserir no final\n");
		printf("3 -> Remover no inicio\n");
		printf("4 -> Mostrar toda a lista \n");
		printf("5 -> Inicializar a lista (versao 2)\n");
		printf("6 -> Inverter a lista\n");
		printf("7 -> Verifica a repeticao de um dado\n");
		printf("9 -> Sair \n:");
		scanf("%d", &q);     /* Ler a opcao do usuario */
		switch(q) {
			case 1: printf("Dado para insercao na lista: ");
                    scanf("%d",&info);
                    erro=Inserir_inicio_LS (&ini, info);
                    if (erro == 0) printf("Insercao realizada com sucesso\n");
                    system("pause");
					break;
            case 10: printf("Dado para insercao na lista: ");
                    scanf("%d",&info);
                    printf("Posicao de insercao: ");
                    scanf("%d",&pos);
                    erro=Inserir_meio_LS (&ini, info, pos);
                    if (erro == 0) printf("Insercao realizada com sucesso\n");
                    system("pause");
					break;
			case 2: printf("Dado para insercao na lista: ");
                    scanf("%d",&info);
                    Inserir_fim_LS (&ini, info);
			        break;
            case 3: erro = Remover_inicio_LS (&ini);
                    if (erro==1)
                    {
                        printf("\nLista vazia. Impossivel remover");
                    }
                    system("pause");
                    break;
			case 4: erro=Listar_LS (ini);
                    if (erro==1)
                    {
                        printf("\nLista vazia. Impossivel listar");
                    }
                    system("pause");
					break;
			case 5: erro=Inicializar2_LS (&ini);
                    printf("\nInicializacao realizada com sucesso !\n");
                    printf("\nLISTA VAZIA !\n");
                    system("pause");
					break;
			case 6: erro=Inverter_LS_2 (&ini);
                    if (erro == 1)
                        printf("\nLista vazia. Inversao nao realizada !\n");
                    else
                        printf("\nInversao realizada !\n");
                    system("pause");
					break;
			case 7:
			        // FAZER
                    system("pause");
					break;
            case 8:
			        // FAZER
                    system("pause");
					break;
			case 9: break;
			default: printf("\n\n Opcao nao valida");
		}
		getchar();    /* Limpa o buffer de entrada */
	} while ((q != 9) );

}

/*--------------------------------------------------------------------
LISTAR todos os elementos presentes na lista encadeada
----------------------------------------------------------------------*/

int Listar_LS (Tno_ls *c_inicio)
{
    // check de erro
    if (c_inicio == NULL)
    {
        return 1; // lista está vazia
    }

    printf("LISTA => ");
    while (c_inicio != NULL)
    {
        printf("%d", c_inicio->dado); // enquanto a lista não for nula, então printamos os dados para onde c_inicio aponta
        c_inicio = c_inicio->prox;
    }

    printf("\n");
    return 0;
}

/*--------------------------------------------------------------------
INICIALIZAR A LISTA
----------------------------------------------------------------------*/

int Inicializar_LS  (Tno_ls **p_inicio)
{
    *p_inicio = NULL;
    return 0;
}

/*--------------------------------------------------------------------
INICIALIZAR A LISTA 2 - "APAGAR" A LISTA ANTERIOR E CRIA UMA NOVA
----------------------------------------------------------------------*/

int Inicializar2_LS   (Tno_ls **p_inicio)
{
    Tno_ls *percorre, *aux; // nós para auxiliar á percorrer a lista e uma auxiliar para guardar os dados e apgá-los

    // inicio da lista não pode ser null
    if (*p_inicio != NULL)
    {
        // para percorrer a lista, jogamos o valor de percorre para onde p_inicio aponta
        percorre = *p_inicio;
        while (percorre != NULL)
        {
            // auxiliar recebe o valor de p_inicio para armazenar e deletar aquele nó da lista
            aux = percorre;
            percorre = percorre ->prox; // aponta para o próximo nó
            free(aux); // deleta o nó
        }
        *p_inicio = NULL;
        return 1; // inicializa apagando tudo da lista
    }
    else
    {
        // Inicializar_LS(p_inicio);
        return 0;
    }
}

/*--------------------------------------------------------------------
OBTENDO O TAMANHO DA LISTA ENCADEADA
----------------------------------------------------------------------*/

int Obter_Tamanho_LS   (Tno_ls *c_inicio, int *tam)
{
    Tno_ls *percorre; // struct para percorrer a lista 
    *tam = 0; // irá armazenar o tamanho da lista

    // c_inicio NÃO pode ser nulo
    if (c_inicio != NULL)
    {
        //apontar o percorre para o início da lista
        percorre = c_inicio;
        while (percorre != NULL)
        {
            //enquanto tiver dado [diferente de NULL], aumentaremos em 1 a variável tam (tamanho)
            (*tam++);
            // apontar o percorre para o próximo elemento da lista
            percorre = percorre->prox;
        } 
    }
    else
    {
        // caso a o início for NULL (sem dados), tam continuará sendo 0, pois não tem lista.
           *tam = 0;
    }

}

/*--------------------------------------------------------------------
FUNÇÃO QUE INSERE NO INÍCIO DA LISTA ENCADEADA
----------------------------------------------------------------------*/

int Inserir_inicio_LS  (Tno_ls **p_inicio, int info)
{
    






}