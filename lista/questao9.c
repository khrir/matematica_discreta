#include <stdio.h>

int MDC(int x, int y)
{
    if(y == 0){
        return x;
    }
    
    return MDC(y, x % y); 
    
}


void calcular_mdc_estendido(int a, int b, int *mdc, int *x, int *y) 
{
    if (a == 0) {
        *mdc = b;
        *x = 0;
        *y = 1;
    } else {
        int temp_mdc, temp_x, temp_y;
        calcular_mdc_estendido(b % a, a, &temp_mdc, &temp_x, &temp_y);
        *mdc = temp_mdc;
        *x = temp_y - (b / a) * temp_x;
        *y = temp_x;
    }
}


int teorema_chines(int congruencias[][2], int num_congruencias)
{
    for (int i = 0; i < num_congruencias; i++) {
        for (int j = i + 1; j < num_congruencias; j++) {
            if (MDC(congruencias[i][1], congruencias[j][1]) != 1) {
                printf("Módulos não são coprimos.\n");
                return -1;
            }
        }
    }

    int M = 1;
    for (int i = 0; i < num_congruencias; i++) {
        M *= congruencias[i][1];
    }

    int x = 0;
    for (int i = 0; i < num_congruencias; i++) {
        int a = congruencias[i][0];
        int m = congruencias[i][1];
        int Mi = M / m;
        int temp_mdc, t, _;
        calcular_mdc_estendido(Mi, m, &temp_mdc, &t, &_);
        x += a * t * Mi;
    }

    x %= M;
    if (x < 0) {
        x += M;
    }

    return x;
}


int main()
{
    int num_congruencias = 3;

    int congruencias[num_congruencias][2];

    for (int i = 0; i < num_congruencias; i++) {
        printf("Insira a congruência %d (a m): ", i + 1);
        scanf("%d %d", &congruencias[i][0], &congruencias[i][1]);
    }

    int resultado = teorema_chines(congruencias, num_congruencias);

    if (resultado != -1) {
        printf("A solução única é: %d\n", resultado);
    }

    return 0;
}