#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int partition(int *a, int start, int end);
void quicksort(int *a, int start, int end);
void print_array(int *a, int start, int end);

int main()
{
    srand((unsigned)time(NULL));
    printf("type the range and size of nums to sort('int,int'):\n");
    int range, size;
    if (scanf("%d,%d", &range, &size) != 2 || range <= 0 || size <= 0) {
        printf("invalid input\n");
        return 1;
    }
    int *a = calloc(size, sizeof *a);
    if (a == NULL) {
        printf("allocation failed\n");
        return 1;
    }
    for (int i = 0; i < size; i++) {
        a[i] = rand()%range;
    }
    printf("origin:\n");
    print_array(a, 0, size - 1);
    quicksort(a, 0, size - 1);
    printf("sorted:\n");
    print_array(a, 0, size - 1);
    free(a);
    return 0;
}

int partition(int *a, int start, int end)
{
	int pivot = a[start];
    int head = start + 1;
    int tail = end;

    while (head <= tail) {
        while (head <= end && a[head] <= pivot) {
            head++;
        }
        while (tail > start && a[tail] >= pivot) {
            tail--;
        }
        if (head < tail) {
            int temp = a[head];
            a[head] = a[tail];
            a[tail] = temp;
        }
    }

    a[start] = a[tail];
    a[tail] = pivot;
    return tail;
}

void quicksort(int *a, int start, int end)
{
	int mid;
	if (end > start) {
		mid = partition(a, start, end);
		quicksort(a, start, mid-1);
		quicksort(a, mid+1, end);
	}
}

void print_array(int *a, int start, int end)
{
    for (int i = start; i <= end; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}
