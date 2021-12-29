#include <cs50.h>
#include <stdio.h>

int main()
{
    for (int i = 0; i < 8; i++) {
        for (int j = 7; j >= 0; j--) {
            if (j <= i) {
                printf("#");
            } else {
                printf(" ");
            }
        }
        printf(" ");

        for (int j = 0; j <= i; j++) {
            printf("#");
        }
        printf("\n");
    }
}
