#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <time.h>

enum Rotation {
    LowerAlpha,
    UpperAlpha,
    Numbers,
    SpecialBeta,
    SpecialMid,
    SpecialBased,
};

char* generatePassword(int* len, int* difficultyLevel) {
    char* password = (char*) malloc(sizeof(char) * (unsigned long) *len);

    char* alphabets = "abcdefghijklmnopqrstuvwxyz";
    int alphLen = strlen(alphabets);

    char* capitalizedAlphabets = malloc(alphLen);
    if (capitalizedAlphabets == NULL) {
        printf("Failed to allocate memory for capitalizedAlphabets");
        exit(1);
    }

    for (int i = 0; i < alphLen; i++) {
        capitalizedAlphabets[i] = toupper(alphabets[i]);
    }
    capitalizedAlphabets[alphLen] = '\0';

    char* numbers = "0123456789";

    char* specialCharactersLevel0 = "()-+=";
    char* specialCharactersLevel1 = "!@#$";
    char* specialCharactersLevel2 = "%^&*;:/\\?\"'[]";

    for (int i = 0; i < *len; i++) {
        srand(time(NULL) + i);
        enum Rotation rotationptr = rand() % (3 + *difficultyLevel);
    
        switch (rotationptr) {
            case 0:
                srand(time(NULL) + i + rotationptr); 
                password[i] = alphabets[rand() % alphLen];
                break;
            case 1:
                srand(time(NULL) + i + rotationptr); 
                password[i] = capitalizedAlphabets[rand() % alphLen];
                break;
            case 2:
                srand(time(NULL) + i + rotationptr); 
                password[i] = numbers[rand() % (strlen(numbers) - 1)];
                break;
            case 3:
                srand(time(NULL) + i + rotationptr); 
                password[i] = specialCharactersLevel0[rand() % (strlen(specialCharactersLevel0) - 1)];
                break;
            case 4:
                srand(time(NULL) + i + rotationptr); 
                password[i] = specialCharactersLevel1[rand() % (strlen(specialCharactersLevel1) - 1)];
                break;
            case 5:
                srand(time(NULL) + i + rotationptr); 
                password[i] = specialCharactersLevel2[rand() % (strlen(specialCharactersLevel2) - 1)];
                break;
            default:
                srand(time(NULL) + i + rotationptr); 
                password[i] = alphabets[rand() % alphLen];
                break;
        }
    }

    free(capitalizedAlphabets);

    return password;
}
