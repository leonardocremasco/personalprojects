
#include <stdio.h>
#include <stdbool.h>

bool verificaSubstring(const char *str1, const char *str2) {
    const char *ptr1 = str1; 
    
    while (*ptr1 != '\0') {
        const char *tempPtr1 = ptr1; 
        const char *ptr2 = str2;    

        while (*ptr1 == *ptr2 && *ptr1 != '\0' && *ptr2 != '\0') {
            ptr1++;
            ptr2++;
        }

        if (*ptr2 == '\0') {
            return true; 
        }

        ptr1 = tempPtr1 + 1; 
    }
    
    return false; 
}

int main() {
    const char *string1 = "Isso é um exemplo de string de teste.";
    const char *string2 = "exemplo";

    if (verificaSubstring(string1, string2)) {
        printf("'%s' ocorre em '%s'\n", string2, string1);
    } else {
        printf("'%s' NÃO ocorre em '%s'\n", string2, string1);
    }

    return 0;
}
