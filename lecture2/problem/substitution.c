#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define ERROR 1

int main(int argc, string argv[])
{
    if (!argv[1] || argv[2]) {
        printf("Usage: ./substitution key\n");
        return ERROR;
    }

    int number_elements = strlen(argv[1]);

    if (number_elements != 26) {
        printf("Key must contain 26 characters. This contains %d\n", number_elements);
        return ERROR;
    }

    for (int i = 0; i < number_elements; i++) {
        if (!isalpha(argv[1][i])) {
            printf("Key must contain 26 characters, not numbers or punctuations.\n");
            return 1;
        }

        for (int j = i + 1; j < number_elements; j++) {
            if (argv[1][i] == argv[1][j]) {
                printf("Key must contain 26 distincts characters\n");
                return ERROR;
            }
        }
    }

    string text = get_string("plaintext: ");

    while (text == NULL) {
        text = get_string("plaintext:");
    }

    int length_text = strlen(text);
    int position;

    for (int i = 0; i < length_text; i++) {
        if (isupper(text[i])) {
            position = text[i] - 65;
                text[i] = toupper(argv[1][position]);
                continue;
        }
        if (islower(text[i])) {
            position = text[i] - 97;
            text[i] = tolower(argv[1][position]);
        }
    }

    printf("ciphertext: %s\n", text);
    return 0;
}
