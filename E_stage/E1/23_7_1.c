#include <stdio.h>

int main()
{
    char a[4][3][2] = 
          {{{'a', 'b'}, {'c', 'd'}, {'e', 'f'}},
		   {{'g', 'h'}, {'i', 'j'}, {'k', 'l'}},
		   {{'m', 'n'}, {'o', 'p'}, {'q', 'r'}},
		   {{'s', 't'}, {'u', 'v'}, {'w', 'x'}}};

    char (*pa)[2] = &a[1][0];
    char (*ppa)[3][2] = &a[1];
    char m, n, u, v;
    m = *(*(pa+5)+1);
    n = *(*(*(ppa+1)+2)+1);
    u = pa[5][1];
    v = ppa[1][2][1];
    printf("%c,%c\n",m ,n);
    printf("%c,%c\n",u ,v);
    return 0;
}
