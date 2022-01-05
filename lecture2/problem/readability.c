#include <cs50.h>
#include <math.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main()
{
    string text = get_string("Text:");
    int length = strlen(text);
    int letters = 0;
    int words = 0;
    int sentences = 0;

    for (int i = 0; i < length; i++) {
        if (isspace(text[i]))
            words++;
        else if(text[i + 1] == '\0') 
            words++;
        else
            words += 0;

        if (text[i] == 33 || text[i] == 46 || text[i] == 63)
            sentences++;

        if (isalpha(text[i]))
            letters++;
    }
    
    float L = ((float) letters / words) * 100;
    float S = ((float) sentences / words) * 100;
    float index = 0.0588 * L - 0.296 * S - 15.8;
    int roundedIndex = round(index);

    if (roundedIndex >= 16)
        printf("Grade 16+\n");
    else if (roundedIndex < 1)
        printf("Before Grade 1\n");
    else
        printf("Grade %d\n", roundedIndex);
    return 0;
}
