#include <cs50.h>
#include <stdio.h>

int main()
{
    int start_population, end_population, years = 0;
    start_population = get_int("Start size: ");
    while (start_population < 9) {
        start_population = get_int("Start size: ");
    }

    end_population = get_int("End size: ");
    while (end_population < 9 || end_population < start_population) {
        end_population = get_int("End size: ");
    }

    while (start_population < end_population) {
        start_population = start_population - (start_population/4) + (start_population/3);
        years++;
    }

    printf("Years: %d\n", years);
    return 0;
}
