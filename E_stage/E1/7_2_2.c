#include <stdio.h>

struct rational{
    int a;
    int b;
};

struct rational make_ra(int a, int b);
struct rational add_ra(struct rational x, struct rational y);
struct rational sub_ra(struct rational x, struct rational y);
struct rational mul_ra(struct rational x, struct rational y);
struct rational div_ra(struct rational x, struct rational y);
void print_ra(struct rational r);

int main() {
    struct rational a = make_ra(1, 8);
    struct rational b = make_ra(-1, 8);
    print_ra(add_ra(a, b));
    print_ra(sub_ra(a, b));
    print_ra(mul_ra(a, b));
    print_ra(div_ra(a, b));
    
    return 0;
}

void euclid(int *a, int *b) {
    int ta = *a < 0 ? -*a : *a;
    int tb = *b < 0 ? -*b : *b;
    int temp;

    if (tb == 0) {
        return;
    }

    while (tb != 0) {
        temp = ta % tb;
        ta = tb;
        tb = temp;
    }

    if (ta != 0) {
        *a /= ta;
        *b /= ta;
    }
}

struct rational make_ra(int a, int b) {
    struct rational r;
    if (b >= 0) {
        r.a = a;
        r.b = b;
    } else {
        r.a = -a;
        r.b = -b;
    }
    euclid(&r.a, &r.b);
    return r;
}

struct rational add_ra(struct rational x, struct rational y) {
    int a, b;
    a = x.a * y.b + y.a * x.b;
    b = x.b * y.b;
    return make_ra(a, b);
}

struct rational sub_ra(struct rational x, struct rational y) {
    int a, b;
    a = x.a * y.b - y.a * x.b;
    b = x.b * y.b;
    return make_ra(a, b);
}

struct rational mul_ra(struct rational x, struct rational y) {
    int a, b;
    a = x.a * y.a;
    b = x.b * y.b;
    return make_ra(a, b);
}

struct rational div_ra(struct rational x, struct rational y) {
    int a, b;
    a = x.a * y.b;
    b = x.b * y.a;
    return make_ra(a, b);
}

void print_ra(struct rational r) {
    if (r.b == 0) {
        if (r.a == 0) {
            printf("NaN\n");
            return;
        }
        if (r.a < 0)
            printf("-");
        printf("Inf\n");
        return;
    }
    if (r.b == 1)
        printf("%d\n", r.a);
    else
        printf("%d/%d\n", r.a, r.b);
}
