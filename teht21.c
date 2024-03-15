#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 256

int calculateChecksum(const char *line) {
    int checksum = 0;
    for (int i = 1; line[i] != '*' && line[i] != '\0'; i++) {
        checksum ^= line[i];
    }
    return checksum;
}

int main() {
    char filename[100];
    FILE *file;
    char line[MAX_LINE_LENGTH];

    printf("Enter the filename: ");
    scanf("%99s", filename);

    file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Error opening a file %s\n", filename);
        exit(1);
    }

    while (fgets(line, sizeof(line), file) != NULL) {
        if (line[0] == '$') {
            int checksum;
            if (sscanf(line, "%*[^*]*%x", &checksum) == 1) {
                int calculatedChecksum = calculateChecksum(line);
                if (checksum == calculatedChecksum) {
                    printf("[ OK ] %s", line);
                } else {
                    printf("[FAIL!] %s", line);
                }
            } else {
                printf("[FAIL!] %s", line);
            }
        }
    }

    fclose(file);
    return 0;
}
