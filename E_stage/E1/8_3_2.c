#include <stdio.h>

void total_sort(int *n, int *used, int *str, int picked, int size, int select);
void combine(int *n, int flag, int *str, int picked, int size, int select);

int main() {
    printf("type total num:\n");
    int size;
    scanf("%d", &size);
    printf("type select num:\n");
    int select;
    scanf("%d", &select);
    printf("type sort(1) or combine(other):\n");
    int sort;
    scanf("%d", &sort);
    if(select > size) {
        printf("should not select more than %d!\n", size);
        return -1;
    }
    int nums[size];
    int used[size];
    int str[size];
    for(int i = 0; i < size; i++) {
        nums[i] = i + 1;
        used[i] = 0;
    }
    // main loop function
    if(sort)
        total_sort(nums, used, str, 0, size, select);
    else
        combine(nums, 0, str, 0, size, select);
    return 0;
}

void total_sort(int *n, int *used, int *str, int picked, int size, int select) {
    if(picked == select) {    
        for(int i = 0; i < select; i++) {
            printf("%d ", str[i]);
        }
        printf("\n");
        return;
    }
    for(int i = 0; i < size; i++) {
        if(used[i] == 0) {
            used[i] = 1;
            str[picked] = n[i];
            total_sort(n, used, str, picked + 1, size, select);
            used[i] = 0;
        }
    }
}


void combine(int *n, int flag, int *str, int picked, int size, int select) {
    if(picked == select) {    
        for(int i = 0; i < select; i++) {
            printf("%d ", str[i]);
        }
        printf("\n");
        return;
    }
    for(int i = flag; i < size; i++) {
            str[picked] = n[i];
            combine(n, i + 1, str, picked + 1, size, select);
    }
}
