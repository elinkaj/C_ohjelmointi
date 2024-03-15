#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINES 100
#define MAX_LENGTH 80

int main() {
    char lines[MAX_LINES][MAX_LENGTH+1];
    char filename[100];
    FILE *file;
    int line_count = 0;
    int i;

    printf("Enter the filename: ");
    scanf("%99s", filename);

    file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Error opening a file %s\n", filename);
        exit(1);
    }

    while (line_count < MAX_LINES && fgets(lines[line_count], MAX_LENGTH+1, file) != NULL) {
        line_count++;
    }

    fclose(file);

    for (i = 0; i < line_count; i++) {
        int j;
        for (j = 0; lines[i][j] != '\0'; j++) {
            lines[i][j] = toupper(lines[i][j]);
        }
    }

    file = fopen(filename, "w");
    if (file == NULL) {
        fprintf(stderr, "Error opening file %s\n", filename);
        exit(1);
    }

    for (i = 0; i < line_count; i++) {
        fputs(lines[i], file);
    }

    fclose(file);

    printf("File is successfully processed.\n");

    return 0;
}
