// alocação dinãmica -> concatenação de strings

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char * concatena (char *s1, char *s2)
{
    char *sres = NULL;
    int t1, t2, i;

    t1 = strlen(s1);
    t2 = strlen(s2);
    sres = malloc((t1+t2+1)*sizeof(char));

    // para s1
    for (i = 0; i<t1; i++){
        sres[i] = s1[i];
    }
    
    //para s2   
    for ( i = 0; i<t2; i++){
        sres[i+t1] = s2[i];
    }
    
    sres[t1+t2] = '\0';
    return sres;
}

int main () 
{
    char s1[100], s2[100], *s3;

    fgets(s1, 100, stdin);
    s1[strlen(s1)-1] = '\0'; // remove o /n

    fgets(s2 , 100, stdin);
    s2[strlen(s2)-1] = '\0'; //remove o /n

    s3 = concatena(s1, s2);
    printf("%s\n", s3);
    free(s3);
}