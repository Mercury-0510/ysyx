#include <stdio.h>
#include <malloc.h>
int main()
{
    char *str = malloc(100);
    printf("file:\n");
    scanf("%s", str);
    FILE *fd = fopen(str, "r");
    str = fgets(str, 100, fd);
    while (str != NULL) {
        printf("%s", str);
        str = fgets(str, 100, fd);
    }
    free(str);
    return 0;
}
