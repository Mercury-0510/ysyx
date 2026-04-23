#include <stdio.h>
#include <string.h>
#include <malloc.h>

struct pair {
    char *key;
    char *value;
    struct pair *next_pair;
};

struct pair *url_decode(char *url);
struct pair *add_pair(char *key_str, char *value_str, struct pair *rear_pair);
void print_table(struct pair *pair);
void free_table(struct pair *pair);

int main()
{
    char *url = malloc(1000);
    struct pair *pair;
    printf("type the url:\n");
    scanf("%s", url);
    pair = url_decode(url);
    if (pair == NULL) {
        printf("invalid url input\n");
        return -1;
    }
    print_table(pair);
    free_table(pair);
    return 0;
}

struct pair *url_decode(char *url)
{
    if (url == NULL)
        return NULL;
    char delim_adr[] = "?";
    char delim_pair[] = "&";
    char delim_key[] = "=";
    char *qst;
    char *adr = strtok_r(url, delim_adr, &qst);
    if (*qst == '\0')
        return NULL;
    char *qst_next;
    struct pair *pair = malloc(sizeof(struct pair));
    pair->next_pair = NULL;
    struct pair *rear_pair = pair;
    char *pair_str = strtok_r(qst, delim_pair, &qst_next);
    while (pair_str != NULL) {
        char *key_pos = strchr(pair_str, (int)delim_key[0]);
        if (key_pos != NULL) {
            char *key_str = strtok(pair_str, delim_key);
            char *value_str = key_pos + 1;
            rear_pair = add_pair(key_str, value_str, rear_pair);
        }
        qst = qst_next;
        pair_str = strtok_r(qst, delim_pair, &qst_next);
    }
    return pair;
}

struct pair *add_pair(char *key_str, char *value_str,
                      struct pair *rear_pair)
{
    rear_pair->key = key_str;
    rear_pair->value = value_str;
    rear_pair->next_pair = malloc(sizeof(struct pair));
    rear_pair->next_pair->next_pair = NULL;
    return rear_pair->next_pair;
}


void print_table(struct pair *pair)
{
    while (pair->next_pair != NULL) {
        printf("key:%-20s",pair->key);
        if (!strlen(pair->value))
            printf("value:NULL\n");
        else
            printf("value:%s\n", pair->value);
        pair = pair->next_pair;
    }
    return;
}

void free_table(struct pair *pair)
{
    struct pair *temp;
    while (pair->next_pair != NULL) {
        temp = pair->next_pair;
        free(pair);
        pair = temp;
    }
    free(pair);
    return;
}
