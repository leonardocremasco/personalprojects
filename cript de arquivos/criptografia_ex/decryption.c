#include <stdio.h>
#include <gmp.h>
#include <stdlib.h>

// Função para descriptografar usando RSA
void rsa_decrypt_message(mpz_t message, mpz_t ciphertext, mpz_t d, mpz_t n) {
    mpz_powm(message, ciphertext, d, n);
}

void write_decrypted_content(const char *filename, mpz_t decrypted) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        perror("Erro ao abrir o arquivo de saída");
        return;
    }

    size_t count;
    char *str = (char *)mpz_export(NULL, &count, 1, 1, 0, 0, decrypted);
    fwrite(str, 1, count, file);

    fclose(file);
}

void read_encrypted_content(const char *filename, mpz_t encrypted) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        perror("Erro ao abrir o arquivo");
        return;
    }

    mpz_inp_raw(encrypted, file);
    fclose(file);
}

int main() {
    mpz_t n, d, ciphertext, decrypted_message;

    mpz_inits(n, d, ciphertext, decrypted_message, NULL);

    // Defina manualmente a chave privada RSA usada na criptografia
    // Assegure-se de usar as mesmas chaves geradas no programa de criptografia
    // Valores de exemplo (substitua pelos valores reais)
    mpz_set_str(n, "1401274202013641197111548666394719818277044548952886367137602482728286465877169029870728819109225100322535801771023583044144971931804240295457049151353127041906379182372454094173490821663401471698601122477253538409530720497480770482814217119968864114432207592000402602705199112020203543609044412666976711259403639456547002490549712906798881923414738859744348854450010210665253255681486898075808342740573736619103464509607340003498707824091653114496766409725307611007390655106024746748766366362726595564235287046497100368755698973803339204689428718935564053689349466409328676480925785544557388949826170293745737866643", 10);
    mpz_set_str(d, "554163674989541061487970434039067217756449648591801712978506510022609039513625385907038001948104065644742403684962528424220659818552913620972211115931006098419664245368711799636671424018066730907492620845712455689125489629578812111838791511899431162821825173100179053922415590969065343901295651120782190250053789893371839467517564105033846441105650384155883254558611014966034675638875559428375319428099240692452993233958591459441917928942093068797060773917071676587813082736644061692452876908938613703337284378918541113613942821964913611142626743685766628825170765088540258852328336495151786956950918887992081238385", 10);

    // Ler o conteúdo criptografado
    read_encrypted_content("encrypted.txt", ciphertext);

    // Descriptografar o conteúdo
    rsa_decrypt_message(decrypted_message, ciphertext, d, n);
    gmp_printf("Conteúdo descriptografado: %Zd\n", decrypted_message);

    // Escrever o conteúdo descriptografado em um arquivo
    write_decrypted_content("decrypted.txt", decrypted_message);

    // Limpar as variáveis
    mpz_clears(n, d, ciphertext, decrypted_message, NULL);

    return 0;
}
