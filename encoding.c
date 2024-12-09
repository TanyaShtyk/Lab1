#include <stdio.h>
#include <string.h>

int shift = 4; // Зсув << 4

const char rotor0[] = "BDFHJLCPRTXVZNYEIWGAKMUSQO";
const char rotor1[] = "AJDKSIRUXBLHWTMCQGZNPYFVOE";
const char rotor2[] = "EKMFLGDQVZNTOWYHXUSPAIBRCJ";
const char alphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

// Знаходження символу в алфавіті
int findIndex(char c, const char *array) {
    for (int i = 0; i < 26; i++) {
        if (array[i] == c) return i;
         
    }
    return -1;
}

// Шифрування
void encrypt(const char *message, char *cipher) {
    for (int i = 0; message[i] != '\0'; i++) {
        char c = alphabet[(findIndex(message[i], alphabet) + shift + i) % 26];
        
        c = rotor0[findIndex(c, alphabet)];
        c = rotor1[findIndex(c, alphabet)];
        c = rotor2[findIndex(c, alphabet)];
        cipher[i] = c;
    }
}

int main() {
    const char *message = "AAA";
    char cipher[100];

    printf("Повідомлення для шифрування: %s\n", message);

    encrypt(message, cipher);
    printf("Зашифроване повідомлення: %s\n", cipher);

    return 0;
}