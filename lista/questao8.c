#include <stdio.h>;


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


void determinar_congruencia(int a, int b, int modulo) // a * x = b mod(m)
{
    if (modulo == 0) {
        printf("O módulo não pode ser zero.\n");
        return;
    }

    int coefS, coefT;
    int mdc = calcular_mdc_estendido(a, modulo, &coefS, &coefT);

    if (b % mdc == 0) {
        int x0 = (coefS * (b / mdc)) % modulo;

        if (x0 < 0)
            x0 += modulo; 
            
        printf("Solução(s) da congruência %dx ≡ %d mod %d:\n", a, b, modulo);

        int i;
        for (i = 0; i < mdc; i++) {
            int solution = (x0 + i * (modulo / mdc)) % modulo;
            printf("x = %d\n", solution);
        }
    } else {
        printf("Não há solução para a congruência %dx ≡ %d mod %d.\n", a, b, modulo);
    }
}


int main()
{
    int a, b, modulo;

    printf("Entre com o valor de 'a', 'b' e o modulo: ");
    scanf("%d %d %d", &a, &b, &modulo);

    determinar_congruencia(a, b, modulo);

    return 0;
}