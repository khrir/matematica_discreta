#include <stdio.h>

int calcular_mdc_estendido(int a, int modulo, int *coefS, int *coefT)
{
    if(modulo == 0) {
        *coefS = 1;
        *coefT = 0;
        return a;
    }

    int s1, t1;
    int mdc = calcular_mdc_estendido(modulo, a % modulo, &s1, &t1);

    *coefS = t1;
    *coefT = s1 - (a / modulo) * t1;

    return mdc;
}

int main()
{
    int a, modulo;
    int coefS, coefT;

    printf("Entre com o valor e o modulo: ");
    scanf("%d %d", &a, &modulo);

    if (calcular_mdc_estendido(a, modulo, &coefS, &coefT) == 1) {
        printf("O inverso de %d mod %d é %d\n", a, modulo, ((coefS % modulo + modulo) % modulo));
    } else {
        printf("Nao sao primos entre si\n");
    }

    return 0;
}