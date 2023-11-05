#include <stdio.h>
#include <stdlib.h>
int main()
{
    // lets say we have two 5 bit binary integers 01101 and 10001
    int a[] = {1, 1, 1, 0, 1}; //{0, 1, 1, 0, 1};
    int b[] = {1, 0, 0, 0, 1};

    int c[6];
    int carry = 0;
    for (int i = 4; i >= 0; i--)
    {
        int key = (a[i] + b[i] + carry);
        key = key % 2;
        c[i + 1] = key;
        if ((a[i] + b[i] + carry) >= 2)
        {
            carry = 1;
        }
        else
        {
            carry = 0;
        }
    }

    c[0] = carry;
    printf("\n");
    for (int i = 0; i < 6; i++)
    {
        printf("%d", c[i]);
    }
    printf("\n");
    return 0;
}