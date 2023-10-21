
#include <stdio.h>

//variavel global
int id = 0;

struct data{
    int dia;
    int mes;
    int ano;
};
struct cadastro{
   char nome[50];
   float peso;
   struct data datanascimento;
};

void incluir(struct cadastro p[10]){
   fflush(stdin);

   printf("\nDigite seu nome:"); fgets(p[id].nome,50,stdin);
   printf("\nDigite seu peso:"); scanf("%f",&p[id].peso);
   printf("\nDigite o dia do seu nascimento: ");scanf("%d",&p[id].datanascimento.dia);
   printf("\nDigite o mes do seu nascimento: ");scanf("%d",&p[id].datanascimento.mes);
   printf("\nDigite o ano do seu nascimento: ");scanf("%d",&p[id].datanascimento.ano);
   printf("\nCadastro realizado");

   id++;
};
void exibir(struct cadastro p[10]){
    int id;
    printf("\nDigite o id da pessoa:"); scanf("%d",&id);
   printf("\nNome: %s ",p[id].nome);
   printf("\nPeso: %0.2f", p[id].peso);
   printf("\nData nascimento: %d/%d/%d",p[id].datanascimento.dia, p[id].datanascimento.mes, p[id].datanascimento.ano);
   system("pause");
};
void alterar(struct cadastro p[10]){
   
   int id;
   fflush(stdin);

   printf("\nDigite o id da pessoa: "); scanf("%d", &id);
   fflush(stdin);
   printf("\nAltere seu nome:"); fgets(p[id].nome,50,stdin);
   printf("\nAltere seu peso:"); scanf("%f",&p[id].peso);
   printf("\nAltere o dia do seu nascimento: ");scanf("%d",&p[id].datanascimento.dia);
   printf("\nAltere o mes do seu nascimento: ");scanf("%d",&p[id].datanascimento.mes);
   printf("\nAlteree o ano do seu nascimento: ");scanf("%d",&p[id].datanascimento.ano);
   printf("\nAlteração realizada");
   system("pause");

   id++; 
};
void excluir(){};

int main(){

   int opcao;
   struct cadastro p[10];
   opcao = 0;

   while(opcao != 5){
        system("cls");
    printf("\nMenu Principal\n\n1-Incluir\n2-Alterar\n3-Excluir\n4-Exibir\n5-Sair");
    printf("\nOpcao: ");
    scanf("%d",&opcao);

   switch (opcao) {
    case 1:
        incluir(p);
        break;
    case 2:
        alterar(p);
        break;
    case 3:
        excluir();
        break;
    case 4:
        exibir(p);
        break;
    case 5:
        printf("\nSaindo do programa");
        break;
    default:
        printf("\nOpcao invalida");
   }

   }

return  0;
}
