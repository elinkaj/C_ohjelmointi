#include <stdio.h>
#include <string.h>

int count_words(const char* str, const char *word) {
    int count = 0;
    const char *ptr = str;

    while ((ptr = strstr(ptr, word)) != NULL) {
        count++;
        ptr++;
    }
    return count;
}

int main() {
    char input[100];
    char search_word[20];

    while (1) {
        printf("Enter a string: ");
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = '\0';

        printf("Enter a word to search: ");
        fgets(search_word, sizeof(search_word), stdin);
        search_word[strcspn(search_word, "\n")] = '\0';

        if (strcmp(search_word, "stop") == 0) {
            printf("Program stopped.\n");
            break;
        }

        int word_count = count_words(input, search_word);
        printf("Number of occurrences of '%s': %d\n", search_word, word_count);
    }

    return 0;
}
