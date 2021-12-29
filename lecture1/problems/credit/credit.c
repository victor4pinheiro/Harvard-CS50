#include <cs50.h>
#include <stdio.h>

int main()
{
    long int card = 4003600000000014;
    int count = 0;

    while (card != 0) {
        card = card/10;
        count++;
    }

    printf("%d", count);
}
