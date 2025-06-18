#include <stdio.h>
#include <stdlib.h>
int main()
{
    void *p;
    printf("%p", &p);
    p = (int *)malloc(sizeof(int));
    printf("\nafter allocation: %p\n", &p);
    free(p);
}