#include <stdio.h>
#include <stdlib.h>
int main()
{
    int a = 600;
    int *ptr = NULL;
    printf("address of a:\t%p\n", &a);
    {
        int b = 700;
        printf("\naddress of b:\t%p\n", ptr);
        ptr = &b;
        printf("\ncontent of ptr: %p\n", ptr);
    }
    printf("\ncontent of ptr: %p\n", ptr);
    printf("\npointing value of ptr(b): %d\n", *ptr);
}