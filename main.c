#include "sieve.h"
#include <stdio.h>

int main()
{
    Circle c1 = {{0.0f,0.0f}, 1.0f};
    Circle c2 = {{1.0f,0.0f}, 1.0f};

    printf("surface %f \n",sieve(&c1,&c2));
    return 0;
}