#include <cs50.h>
#include <stdio.h>

int main()
{
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j <= i; j++) {
            printf("#");
        }
        printf("\n");
    }
}
