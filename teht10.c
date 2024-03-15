#include <stdio.h>
#include <string.h>

#define MAX_LENGHT 100

int main(){
    char input[MAX_LENGHT];

    while(1){
        printf("Enter a string: ");
        fgets(input, MAX_LENGHT, stdin);

        if (input[strlen(input) - 1] == '\n'){
            input[strlen(input) - 1] = '\0';
        }
        printf("Lenght of the string is: %ld\n", strlen(input));

        if(strcmp(input, "stop") == 0){
            printf("You entered 'stop'.Program stopped.\n");
            break;
        }
    }
    return 0;
}