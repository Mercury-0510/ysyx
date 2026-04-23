#include <stdio.h>
#include <stdarg.h>

static void print_uint(unsigned int value)
{
     if (value >= 10) {
          print_uint(value / 10);
     }
     putchar((int)('0' + value % 10));
}

static void print_int(int n)
{
     unsigned int value;

     if (n < 0) {
          putchar('-');
          value = (unsigned int)(-(n + 1)) + 1;
     } else {
          value = (unsigned int)n;
     }

     print_uint(value);
}

static void print_double(double n)
{
     int integer_part;
     double fractional_part;
     int i;

     if (n < 0) {
          putchar('-');
          n = -n;
     }

     integer_part = (int)n;
     fractional_part = n - integer_part;

     print_int(integer_part);
     putchar('.');

     for (i = 0; i < 6; i++) {
          fractional_part *= 10;
          putchar((int)('0' + (int)fractional_part));
          fractional_part -= (int)fractional_part;
     }
}

void myprintf(const char *format, ...)
{
     va_list ap;
     char c;

     va_start(ap, format);
     while ((c = *format++) != '\0') {
          switch(c) {
          case '%':
               c = *format++;
               switch(c) {
               case 'c': {
                    /* char is promoted to int when passed through '...' */
                    char ch = va_arg(ap, int);
                    putchar(ch);
                    break;
               }
               case 's': {
                    char *p = va_arg(ap, char *);
                    fputs(p, stdout);
                    break;
               }
               case 'd': {
                    int n = va_arg(ap, int);
                    print_int(n);
                    break;
               }
               case 'f': {
                    double n = va_arg(ap, double);
                    print_double(n);
                    break;
               }
               case '%':
                    putchar('%');
                    break;
               case '\0':
                    putchar('%');
                    format--;
                    break;
               default:
                    putchar('%');
                    putchar(c);
                    break;
               }
               break;
          default:
               putchar(c);
          }
     }
     va_end(ap);
}

int main(void)
{
     myprintf("%c\t%s\t%d\t%f\t%%\n", '1', "hello", -123, 3.14);
     return 0;
}
