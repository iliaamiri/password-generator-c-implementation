#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "lib.h"

int main(int argc, char* argv[]) {

    printf(">>>> Welcome to Ilia's password generator little CLI. <<<<\n");
    printf("How long do you wish your password to be? (the longer, the better but more painful (obviously))\n");

    char buffer[100];
    char* endptr;
    int len;
    fgets(buffer, sizeof(buffer), stdin);

    if (strlen(buffer) <= 1) {
        printf("Invalid argument for length. Enter a number.");
        return 1;
    }

    len = strtol(buffer, &endptr, 10);

    if (len < 1) {
        printf("Password cannot have 0 length.");
        return 1;
    }

    printf("number: %d\n", len);

    // reuse the buffer
    memset(buffer, 0, strlen(buffer));

    int difficultyLevel;

    printf("How difficult do you want your password to be?\n");
    printf("for Beta, enter 0\n");
    printf("for Mid, enter 1\n");
    printf("for Based, enter 2\n");

    fgets(buffer, sizeof(buffer), stdin);

    if (strlen(buffer) <= 1) {
        printf("Invalid difficulty level. Enter a valid difficulty number from 0 to 2");
        return 1;
    }

    difficultyLevel = strtol(buffer, &endptr, 10);

    char difficulty[6];
    switch (difficultyLevel) {
        case 0:
           strcpy(difficulty, "beta");
           break; 
        case 1:
           strcpy(difficulty, "mid");
           break;
        case 2:
           strcpy(difficulty, "based");
           break;
        default:
           printf("Invalid difficulty level. Enter a valid difficulty number from 0 to 2");
           return 1;
           break;
    };

    printf("Generating a %i character long %s password...\n", len, difficulty);

    char* password = generatePassword(&len, &difficultyLevel);

    printf("%s\n", password);

    free(password);

    return 0;
}

