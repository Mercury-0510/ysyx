#include<stdio.h>

void print_digit(int n);

int main(){
    printf("type int n:\n");
    int n;
    scanf("%d", &n);
    print_digit(n);
    return 0;
}

void print_digit(int n){
    printf("digit 0: %d, digit 1: %d\n", n%10, (n/10)%10);
}
