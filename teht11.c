#include <stdio.h>
#include <string.h>

int replace_char(char *str, const char *repl) {
    if (strlen(repl) != 2) {
        return 0;
    }

    char search_char = repl[0];
    char replace_char = repl[1];
    int count = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == search_char) {
            str[i] = replace_char;
            count++;
        }
    }

    return count;
}

int main() {
    char input[100];
    char replacement[3];

    printf("Enter a string: ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = '\0';

    printf("Enter two characters to replace: ");
    fgets(replacement, sizeof(replacement), stdin);
    replacement[strcspn(replacement, "\n")] = '\0';

    int count = replace_char(input, replacement);

    if (count > 0) {
        printf("Modified string: %s\n", input);
        printf("Number of characters replaced: %d\n", count);
    } else {
        printf("String was not modified!\n");
    }

    return 0;
}
