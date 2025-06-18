#include <stdio.h>
#include <stdlib.h>
int main()
{
    for (int i = 0; i < 5; i++)
    {
        if (i == 3)
        {
            break;
        }
        printf("\t%d", i);
    }
    printf("\noutside loop\n");

    for (int j = 0; j < 5; j++)
    {
        if (j == 3)
        {
            continue;
        }
        printf("\t%d", j);
    }
    printf("\noutside loop");
    return 0;
}