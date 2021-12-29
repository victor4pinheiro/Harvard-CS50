#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>

int count_digit(long long number)
{
    int count = 0;
    while (number != 0) {
        number = number/10;
        count++;
    }

    return count;
}

int main()
{
    long long card = 4003600000000014;
    int numbers = count_digit(card);
    int card_array[numbers];
    int product = 0;

    int i = 0;
    while (card != 0) {
        card_array[i] = card % 10;
        card = card / 10;
        i++;
    }

    for (int i = numbers - 1; i >= 0; i--) {
        if (i % 2 == 1) {
            if (card_array[i] * 2 >= 10) {
                product += (2 * card_array[i]) % 10 + (2 * card_array[i]) / 10;
            }
            else {
                product += 2 * card_array[i];
            }
            printf("Product: %d\n", product);
        } else {
            product += card_array[i];
        }
    }
    return 0;
}
