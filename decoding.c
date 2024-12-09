#include <stdio.h>
#include <string.h>

int shift = 9; // Зсув << 9

const char rotor0[] = "BDFHJLCPRTXVZNYEIWGAKMUSQO";
const char rotor1[] = "AJDKSIRUXBLHWTMCQGZNPYFVOE";
const char rotor2[] = "EKMFLGDQVZNTOWYHXUSPAIBRCJ";
const char alphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

int findIndex(char c, const char *array) {
    for (int i = 0; i < 26; i++) {
        if (array[i] == c) return i;
    }
    return -1;
}

// Дешифрування
void decrypt(const char *cipher, char *message) {
    for (int i = 0; cipher[i] != '\0'; i++) {
        char c = cipher[i];
        c = alphabet[findIndex(c, rotor2)];
        c = alphabet[findIndex(c, rotor1)];
        c = alphabet[findIndex(c, rotor0)];

        c = alphabet[(findIndex(c, alphabet) - shift - i + 26) % 26];

        message[i] = c;
    }
}

int main() {
    const char *cipher = "PQSACVVTOISXFXCIAMQEM";
    char decoded[100];

    printf("Зашифроване повідомлення: %s\n", cipher);

    // Дешифрування
    decrypt(cipher, decoded);
    printf("Розшифроване повідомлення: %s\n", decoded);

    return 0;
}
