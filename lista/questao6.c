#include <stdio.h>;

int calcular_mdc_estendido(int a, int b, int *coefS, int *coefT)
{
    if(b == 0) {
        *coefS = 1;
        *coefT = 0;
        return a;
    }

    int s1, t1;
    int mdc = calcular_mdc_estendido(b, a % b, &s1, &t1);

    *coefS = t1;
    *coefT = s1 - (a / b) * t1;

    return mdc;
}

int main()
{
    int valorA, valorB;
    int coefS, coefT;

    printf("Entre com dois valores: ");
    scanf("%d %d", &valorA, &valorB);

    int mdc = calcular_mdc_estendido(valorA, valorB, &coefS, &coefT);
    printf("MDC: %d\ncoeficiente s: %d\ncoeficiente t: %d\n", mdc, coefS, coefT);
    
    return 0;
}