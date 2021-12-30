#include <cs50.h>
#include <stdio.h>

int count_digit(long long number)
{
    int count = 0;
    while (number != 0) {
        number = number/10;
        count++;
    }

    return count;
}

int check_last_second_digit(int number_card, int numbers[], int length)
{
    int status = 0;
    for (int i = 0; i < length; i ++) {
        if (number_card == numbers[i]) {
            status = 1;
            break;
        }
    }

    return status;
}

int main()
{
    long int card = get_long("Number: ");
    int numbers = count_digit(card);
    int card_array[numbers];
    int product = 0;

    for(int i = 0; i < numbers; i++, card /= 10) {
	    card_array[i] = card % 10;
    }

    for (int i = 0; i < numbers; i++) {
        if (i % 2 == 1) {
            if (card_array[i] * 2 >= 10)
                product += (2 * card_array[i]) % 10 + (2 * card_array[i]) / 10;
            else
                product += 2 * card_array[i];
        } else {
            product += card_array[i];
        }
    }

    if (product % 10 == 0) {
        int mastercard[] = {1,2,3,4,5};
        int amex[] = {3,7};

        if (card_array[numbers - 1] == 4 && (numbers == 16 || numbers == 13))
            printf("VISA\n");
        else if (card_array[numbers - 1] == 3 && check_last_second_digit(card_array[numbers - 2], amex, 2) && numbers == 15)
            printf("AMEX\n");
        else if (card_array[numbers - 1] == 5 && check_last_second_digit(card_array[numbers - 2], mastercard, 5) && numbers == 16)
            printf("MASTERCARD\n");
        else
            printf("INVALID\n");
    }
    else {
        printf("INVALID\n");
    }

    return 0;
}
