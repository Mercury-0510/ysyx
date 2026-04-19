#include<stdio.h>
int main(){
    int a, b;
    printf("type a and b(int)\n");
    scanf("%d %d", &a, &b);
    printf("a/b in ceiling is %d\n", a/b + !(a == a/b * b));
    return 0;
}
