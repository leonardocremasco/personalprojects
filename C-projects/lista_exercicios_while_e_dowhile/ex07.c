// ex. 7

#include <ctype.h>
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char lc_meu_nome[] = "Carlos Henrique Rodrigues Sarro";
	char lc_sexo = 'M';
	int li_i = 0;
	int li_t = strlen(lc_meu_nome);

	printf("Meu nome eh %s e meu sexo eh %c", lc_meu_nome, lc_sexo);
	printf("\n");
	printf("O tamanho da variavel lc_meu_nome %d", li_t);
	printf("\n printando cada letra do nome:");

	while (li_i < li_t)
	{
		printf("\n %da letra: %c", (li_i + 1), toupper(lc_meu_nome[li_i]));
		li_i++;
	}
}