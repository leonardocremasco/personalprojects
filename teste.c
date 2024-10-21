#include <stdio.h>
#include <gmp.h>
#include <time.h>

// Função para gerar primos grandes
void generate_prime(mpz_t prime, gmp_randstate_t state, int bits) {
    mpz_urandomb(prime, state, bits); // Gera número aleatório de 'bits' bits
    mpz_nextprime(prime, prime); // Encontra o próximo número primo
}

// Função de exponenciação modular: result = (base^exp) % mod
void modExp(mpz_t result, mpz_t base, mpz_t exp, mpz_t mod) {
    mpz_powm(result, base, exp, mod);
}

// Função para gerar as chaves RSA
void generate_rsa_keys(mpz_t n, mpz_t e, mpz_t d, int bits) {
    gmp_randstate_t state;
    gmp_randinit_mt(state); // Inicializa estado do gerador de números aleatórios
    gmp_randseed_ui(state, time(NULL)); // Semente aleatória baseada no tempo

    mpz_t p, q, phi, p_minus_1, q_minus_1;
    mpz_inits(p, q, phi, p_minus_1, q_minus_1, NULL);

    // Gerar primos p e q
    generate_prime(p, state, bits / 2);
    generate_prime(q, state, bits / 2);

    // n = p * q
    mpz_mul(n, p, q);

    // φ(n) = (p-1)*(q-1)
    mpz_sub_ui(p_minus_1, p, 1);
    mpz_sub_ui(q_minus_1, q, 1);
    mpz_mul(phi, p_minus_1, q_minus_1);

    // Definir e como 65537 (valor comum para RSA)
    mpz_set_ui(e, 65537);

    // Calcular d tal que (d * e) % φ(n) = 1 (inverso modular de e)
    mpz_invert(d, e, phi);

    // Limpar variáveis temporárias
    mpz_clears(p, q, phi, p_minus_1, q_minus_1, NULL);
    gmp_randclear(state);
}

// Função para criptografar a mensagem: ciphertext = message^e % n
void rsa_encrypt(mpz_t ciphertext, mpz_t message, mpz_t e, mpz_t n) {
    modExp(ciphertext, message, e, n);
}

// Função para descriptografar a mensagem: message = ciphertext^d % n
void rsa_decrypt(mpz_t message, mpz_t ciphertext, mpz_t d, mpz_t n) {
    modExp(message, ciphertext, d, n);
}

int main() {
    mpz_t n, e, d, message, ciphertext, decrypted_message;
    mpz_inits(n, e, d, message, ciphertext, decrypted_message, NULL);

    // Gerar chaves RSA (2048 bits)
    generate_rsa_keys(n, e, d, 2048);

    // Exibir as chaves geradas
    gmp_printf("Chave pública (n, e):\n n = %Zd\n e = %Zd\n", n, e);
    gmp_printf("Chave privada (n, d):\n n = %Zd\n d = %Zd\n", n, d);

    // Definir uma mensagem (número a ser criptografado)
    mpz_set_ui(message, 123456); // Exemplo de mensagem numérica

    // Criptografar a mensagem com a chave pública
    rsa_encrypt(ciphertext, message, e, n);
    gmp_printf("\nMensagem criptografada: %Zd\n", ciphertext);

    // Descriptografar a mensagem com a chave privada
    rsa_decrypt(decrypted_message, ciphertext, d, n);
    gmp_printf("Mensagem descriptografada: %Zd\n", decrypted_message);

    // Limpar as variáveis
    mpz_clears(n, e, d, message, ciphertext, decrypted_message, NULL);

    return 0;
}
