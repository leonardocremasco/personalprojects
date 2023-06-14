// ex. com functions

#include <stdio.h>  // biblioteca padrão



void funcao_listar_um_vetor(){   // Funcao sem parâmetro


    int li_vetor[10]={1,2,3,4,5,6,7,8,9,10};
    int li_linha;

    printf("Na funcao lista um vetor\n");
    printf("************************\n");
    for (li_linha=0;li_linha < 10;li_linha++){
        printf("Vetor[%d]=%d\n",li_linha,li_vetor[li_linha]);

    }
    printf("************************\n");
}

void funcao_listar_uma_matriz_inteiro(){   // Funcao sem parâmetro


    int  lc_matriz[2][4]={
                          {1 ,2 ,3 ,4},  // linha 1
                          {10,20,30,40}, // linha 2
                         };

    int li_linha;
    int li_coluna;

    printf("Na funcao lista uma matriz\n");
    printf("************************\n");

    for (li_linha=0;li_linha < 2;li_linha++){    // percorrer as linhas
        printf("{");
        for (li_coluna=0;li_coluna < 4;li_coluna++){   // percorrer as colunas
            //printf("Matriz[%d,%d]=%d",li_linha,li_coluna,lc_matriz[li_linha,li_coluna]);
            printf("%d,",lc_matriz[li_linha][li_coluna]);
        }
        printf("}\n");

    }
    printf("************************\n");
}

void funcao_listar_uma_matriz_car(){   // Funcao sem parâmetro

/*
    char lc_matriz[3][5]={{'A','B','C','D','E'},
                          {'G','H','I','J','K'},
                          {'L','M','N','O','P'}
                         };
 */
    char lc_matriz[3][5]={{'A','B','C','D','E'},
                          {'G','H','I','J','K'},
                          {'L','M','N','O','P'}};


    int li_linha;
    int li_coluna;

    printf("Na funcao lista um vetor tipo char\n");
    printf("************************\n");

    for (li_linha=0;li_linha < 3;li_linha++){
        printf("{");
        for (li_coluna=0;li_coluna < 5;li_coluna++){
            //printf("Matriz[%d,%d]=%d",li_linha,li_coluna,lc_matriz[li_linha,li_coluna]);
            printf("%c,",lc_matriz[li_linha][li_coluna]);
        }
        printf("}\n");

    }
    printf("************************\n");
}


int main() {

   int li_opcao=1;   // declarando uma variável local tipo inteira
                     // forçando o primeiro valor para satisfazer a entrada no looping

   while (li_opcao != 0){

        printf("\n***********************");
        printf("\nBem-vindo ao MENU PRINCIPAL DA EMPRESA XYZ\n");
        printf("\n*   ENTRE COM AS OPCOES DO MENU");
        printf("\n*   1- Listar um vetor de 10 elementos");
        printf("\n*   2- Listar uma matriz tipo inteiros, com 3 linha e 5 colunas");
        printf("\n*   3- Listar uma matriz char, com 3 linha e 5 colunas");
        printf("\n*   0- Para Sair ");
        printf("\n***********************");
        printf("\nOpcao: ");

        scanf("%d", &li_opcao);
        //scanf("%d%*c",&li_opcao);

        switch (li_opcao) {   // testando a entrada digitada
          case 1:
            funcao_listar_um_vetor();
            break;
          case 2:
            funcao_listar_uma_matriz_inteiro();
            break;
          case 3:
            funcao_listar_uma_matriz_car();
            break;
          case 0:
            printf("Fim");
            break;
          default:
            printf("Escolha a opção do Menu entre 1 a 3 ou 0(zero) para sair");

        }
   }
   printf("\nObrigado !!! Volte sempre!!!");
 return 0;
}