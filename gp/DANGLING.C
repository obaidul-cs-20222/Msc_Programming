#include <stdio.h>
#include <stdlib.h>
int *fun()
{
    static int b = 700;
    // int b = 700;
    return &b;
}
int main()
{
    int a = 600;
    int *ptr = NULL;
    printf("\n Adress of a: %p\n", &a);
    ptr = fun();
    printf("\nvalue of pointer:%d\n", *ptr);
    return 0;
}