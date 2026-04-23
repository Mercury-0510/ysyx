#include <stdio.h>
#include <malloc.h>

int is_delim(char c, const char *delim);
char *mystrtok(char *restrict str, const char *restrict delim);
char *mystrtok_r(char *restrict str, const char *restrict delim,
                 char **restrict saveptr);

int main()
{
    char *str = malloc(100);
    printf("test mystrtok, type a string that will delimited by ',':\n");
    scanf("%s", str);
    char *token = mystrtok(str, ",");
    while (token != NULL)
    {
        printf("%s\n", token);
        token = mystrtok(NULL, ",");
    }
    free(str);

    char *str_2 = malloc(100);
    char *str_save;
    printf("test mystrtok_r, type a string that will delimited by ',':\n");
    scanf("%s", str_2);
    char *token_2 = mystrtok_r(str_2, ",", &str_save);
    while (token_2 != NULL)
    {
        printf("%s\n", token_2);
        token_2 = mystrtok_r(NULL, ",", &str_save);
    }
    free(str_2);
    return 0;
}

int is_delim(char c, const char *delim)
{
    while (*delim != '\0') {
        if (c == *delim) {
            return 1;
        }
        delim++;
    }
    return 0;
}

char *mystrtok(char *restrict str, const char *restrict delim)
{
    static char *last_str = NULL;
    char *str_start = str;
    if (str_start == NULL) {
        str_start = last_str;
        if (str_start == NULL) {
            return NULL;
        }
    }
    for (int i = 0; *(str_start+i) != '\0'; i++) {
        if(is_delim(*(str_start+i), delim)) {
            last_str = str_start + i + 1;
            *(str_start+i) = '\0';
            return str_start;
        }
    }
    last_str = NULL;
    return str_start;
}

char *mystrtok_r(char *restrict str, const char *restrict delim,
                 char **restrict saveptr)
{
    char *str_start = str;
    if (str_start == NULL) {
        if (*saveptr != NULL) {
            str_start = *saveptr;
        } else {
            return NULL;
        }
    }
    for (int i = 0; *(str_start+i) != '\0'; i++) {
        if (is_delim(*(str_start+i), delim)) {
            *saveptr = str_start + i + 1;
            *(str_start+i) = '\0';
            return str_start;
        }
    }
    *saveptr = NULL;
    return str_start;
}
