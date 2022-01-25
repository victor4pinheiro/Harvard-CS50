#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    if (argc > 2)
    {
        printf("Usage: ./recover IMAGE\n");
        return 1;
    }

    if (!fopen(argv[1], "r"))
    {
        printf("Usage: ./recover IMAGE\n");
        return 1;
    }

    FILE *raw_file = fopen(argv[1], "r");
    FILE *new_image = NULL;
    BYTE header[3] = {0xff, 0xd8, 0xff};
    BYTE buffer[512];
    int count = 0;
    int block_size = 512;
    char text[8];

    while (fread(buffer, block_size, 1, raw_file) == 1)
    {
        if (memcmp(buffer, header, 3) == 0 && (buffer[3] & 0xf0) == 0xe0)
        {
            if (new_image != NULL) {
                fclose(new_image);
                new_image = NULL;
            }

            sprintf(text, "%03d.jpg", count);
            new_image = fopen(text, "w");

            if (new_image == NULL)
                return 1;

            fwrite(buffer, block_size, 1, new_image);
            count++;
        }
        else if (new_image != NULL)
        {
            fwrite(buffer, block_size, 1, new_image);
        }
    }

    fclose(raw_file);
    fclose(new_image);

    return 0;
}