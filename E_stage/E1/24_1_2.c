#include <stdio.h>
#include <stdlib.h>
int main()
{
    long int i = 0;
    while(malloc(1024*1024)) {
        printf("%ld\n",i);
        i+=1024*1024;
    }
    return 0;
}
