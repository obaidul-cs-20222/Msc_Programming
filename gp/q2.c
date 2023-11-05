#include <stdio.h>
#include <stdlib.h>
int main()
{
    char text[3];
    text[0] = 'H';
    text[1] = 'I';
    text[2] = '!';

    int len = 3;
    for (int i = 0; i < len; i++)
    {
        printf("%i ", text[i]);
    }

    int k = 013;
    // printf is reading the number as octal no matter what the specifier is
    printf("\nj: %d", k);
    printf("\nj: %i", k);
    int x, d;
    printf("\n");
    scanf("%i", &x);
    printf("\n");
    scanf("%d", &k);
    printf("\nas integer with a given format: %i", x);
    printf("\nas a signed decimal integer: %d", k);
    return 0;
}

/*

%d takes an integer value as a signed decimal integer i.e.it takes negative values along with positive values
but values should be in decimal otherwise it will print garbage value.
(Note If the input is in the octal format like 012 then % d will ignore 0 and take input as 12)

%i takes an integer value as an integer value with decimal,
hexadecimal, or octal type.To enter a value in hexadecimal format,
the value should be provided by preceding “0x” and to enter a value in value in octal format,
the value should be provided by preceding “0”.


    */