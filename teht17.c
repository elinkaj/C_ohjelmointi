#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

bool generatePassword(char *password, int size, const char *word) {
    int wordLength = strlen(word);
    int totalLength = wordLength * 2 + 1;

    if (totalLength >= size)
        return false;

    srand(time(NULL));
    password[0] = rand() % 94 + 33;
    int j = 1;
    for (int i = 0; i < wordLength; i++) {
        password[j++] = word[i];
        password[j++] = rand() % 94 + 33;
    }
    password[j] = rand() % 94 + 33;
    password[totalLength] = '\0';

    return true;
}

int main() {
    char password[65];
    char word[32];

    while (1) {
        printf("Enter a word to place in the password or 'stop' if you would like to quit: ");
        scanf("%s", word);
        if (strcmp(word, "stop") == 0)
            break;
        if (generatePassword(password, sizeof(password), word))
            printf("Generated password: %s\n", password);
        else
            printf("Error: Word too long. Password generation failed. \n");
    }

    return 0;
}
