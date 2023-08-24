#include <stdio.h>

int calcular_mdc_estendido(int a, int b, int *x, int *y)
{
    if(b == 0) {
        *x = 1;
        *y = 0;
        return a;
    }

    int x1, y1;
    int mdc = calcular_mdc_estendido(b, a % b, &x1, &y1);

    *x = y1;
    *y = x1 - (a / b) * y1;

    return mdc;
}

int main()
{
    int a, b;

    printf("Entre com o valor e o modulo\n");
    scanf("%d %d", &a, &b);

    int x, y;

    if (calcular_mdc_estendido(a, b, &x, &y) == 1) {
        printf("O inverso de %d mod %d é %d\n", a, b, ((x % b + b) % b));
    } else {
        printf("Nao sao primos entre si\n");
    }

    return 0;
}