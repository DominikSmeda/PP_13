
#include <stdio.h>

#define plus_i(X) a##X
#define M_1(X) printf(#X " = %d\n", X)
#define M_2(X, Y) (1 / (float)X + 1 / (float)Y)

int main(void)
{
    int plus_i(1), plus_i(3);
    a1 = 1;
    a3 = 3;
    printf("%d %d \n", a1, a3);
    plus_i(1) = 2;
    plus_i(3) = 6;
    printf("%d %d \n", plus_i(1), plus_i(3));

    M_1(4 + 12);
    M_1(3 + 2);

    float s1 = M_2(1, 2);
    float s2 = M_2(2, 3);
    float s3 = M_2(4, 4);
    printf("%f ", s1);
    printf("%f ", s2);
    printf("%f ", s3);
    printf("\n-----\n");
    return 0;
}
