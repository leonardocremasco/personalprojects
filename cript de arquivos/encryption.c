#include <stdio.h>
#include <gmp.h>
#include <string.h>
#include <time.h>

// Funções de geração de chaves, criptografia e conversão
void generate_large_prime(mpz_t prime, gmp_randstate_t state, int bits) {
    mpz_urandomb(prime, state, bits);
    if (mpz_even_p(prime)) {
        mpz_add_ui(prime, prime, 1);
    }
    while (!mpz_probab_prime_p(prime, 25)) {
        mpz_add_ui(prime, prime, 2);
    }
}

void rsa_generate_keys(mpz_t n, mpz_t e, mpz_t d, int bits) {
    gmp_randstate_t state;
    gmp_randinit_default(state);
    gmp_randseed_ui(state, time(NULL));

    mpz_t p, q, phi, p_minus_1, q_minus_1;
    mpz_inits(p, q, phi, p_minus_1, q_minus_1, NULL);

    generate_large_prime(p, state, bits / 2);
    generate_large_prime(q, state, bits / 2);

    mpz_mul(n, p, q);

    mpz_sub_ui(p_minus_1, p, 1);
    mpz_sub_ui(q_minus_1, q, 1);
    mpz_mul(phi, p_minus_1, q_minus_1);

    mpz_set_ui(e, 65537);
    mpz_invert(d, e, phi);

    mpz_clears(p, q, phi, p_minus_1, q_minus_1, NULL);
    gmp_randclear(state);
}

void rsa_encrypt_message(mpz_t ciphertext, mpz_t message, mpz_t e, mpz_t n) {
    mpz_powm(ciphertext, message, e, n);
}

void string_to_mpz(mpz_t result, const char *str) {
    mpz_import(result, strlen(str), 1, sizeof(str[0]), 0, 0, str);
}

void read_file_content(const char *filename, char **content, size_t *length) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        perror("Erro ao abrir o arquivo");
        return;
    }

    fseek(file, 0, SEEK_END);
    *length = ftell(file);
    fseek(file, 0, SEEK_SET);

    *content = malloc(*length + 1);
    fread(*content, 1, *length, file);
    (*content)[*length] = '\0';

    fclose(file);
}

void write_encrypted_content(const char *filename, mpz_t encrypted) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        perror("Erro ao abrir o arquivo de saída");
        return;
    }

    mpz_out_raw(file, encrypted);
    fclose(file);
}

int main() {
    mpz_t n, e, d, message_num, ciphertext;
    char *file_content;
    size_t file_length;

    mpz_inits(n, e, d, message_num, ciphertext, NULL);

    // Gerar chaves RSA (2048 bits)
    rsa_generate_keys(n, e, d, 2048);

    // Exibir as chaves geradas
    gmp_printf("Chave pública (n, e):\n n = %Zd\n e = %Zd\n", n, e);
    gmp_printf("Chave privada (n, d):\n n = %Zd\n d = %Zd\n", n, d);

    // Ler o conteúdo do arquivo
    read_file_content("input.txt", &file_content, &file_length);
    printf("Conteúdo do arquivo: %s\n", file_content);

    // Converter o conteúdo do arquivo para um número grande
    string_to_mpz(message_num, file_content);

    // Criptografar o conteúdo do arquivo
    rsa_encrypt_message(ciphertext, message_num, e, n);
    gmp_printf("\nConteúdo criptografado: %Zd\n", ciphertext);

    // Escrever o conteúdo criptografado em um novo arquivo
    write_encrypted_content("encrypted.txt", ciphertext);

    // Limpar as variáveis
    free(file_content);
    mpz_clears(n, e, d, message_num, ciphertext, NULL);

    return 0;
}
