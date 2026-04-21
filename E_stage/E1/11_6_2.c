#include <math.h>
#include <stdio.h>
#define EPSILON 1e-8

double mysqrt(double num);
double halfsearch(double floor, double ceil, double target);

int main()
{
    printf("get sqrt of:\n");
    double num;
    scanf("%lf", &num);
    if (num < 0) {
        printf("number should not less than 0\n");
        return -1;
    }
    printf("%.8lf\n", mysqrt(num));
    return 0;
}

double mysqrt(double num)
{
    if (num < 1)
        return halfsearch(0, 1, num);
    else
        return halfsearch(0, num, num);
}

double halfsearch(double floor, double ceil, double target)
{
    double mid = (floor + ceil)/2;
    if (fabs(mid * mid - target) < EPSILON) {
        return mid;
    } else if (mid * mid > target) {
        return halfsearch(floor, mid, target);
    } else {
        return halfsearch(mid, ceil, target);
    }
}
