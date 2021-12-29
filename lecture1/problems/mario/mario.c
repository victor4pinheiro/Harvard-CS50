#include <cs50.h>
#include <stdio.h>

int main()
{
    int max_numbers = get_int("Height: ");

    if (max_numbers < 1 || max_numbers > 8) {
        max_numbers = get_int("Height: ");
    }

    for (int i = 0; i < max_numbers; i++) {
        for (int j = max_numbers - 1; j >= 0; j--) {
            if (j <= i) {
                printf("#");
            } else {
                printf(" ");
            }
        }
        printf("  ");

        for (int j = 0; j <= i; j++) {
            printf("#");
        }
        printf("\n");
    }
}
