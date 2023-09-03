#include <stdio.h>

#define maximo_de_fatores 100

int calcular_fatores(int numero, int fatores[])
{
    int fator = 2;
    int idx = 0;
    while (numero > 1) {
        if (numero % fator == 0) {
            fatores[idx++] = fator;
            numero /= fator;
        } else {
            fator++;
        }
    }
    return idx;
}

int calcular_mdc(int num1, int num2)
{
    int fatores1[maximo_de_fatores], fatores2[maximo_de_fatores];
    
    int num_fatores1 = calcular_fatores(num1, fatores1);
    int num_fatores2 = calcular_fatores(num2, fatores2);
    
    int mdc = 1;
    
    int idx1 = 0, idx2 = 0;
    while (idx1 < num_fatores1 && idx2 < num_fatores2) {
        if (fatores1[idx1] == fatores2[idx2]) {
            mdc *= fatores1[idx1];
            idx1++;
            idx2++;
        } else if (fatores1[idx1] < fatores2[idx2]) {
            idx1++;
        } else {
            idx2++;
        }
    }
    
    return mdc;
}

int calcular_mmc(int num1, int num2)
{
    int fatores1[maximo_de_fatores], fatores2[maximo_de_fatores];
    
    int num_fatores1 = calcular_fatores(num1, fatores1);
    int num_fatores2 = calcular_fatores(num2, fatores2);
    
    int mmc = 1;
    
    int idx1 = 0, idx2 = 0;
    while (idx1 < num_fatores1 || idx2 < num_fatores2) {
        if (idx1 < num_fatores1 && (idx2 >= num_fatores2 || fatores1[idx1] < fatores2[idx2])) {
            mmc *= fatores1[idx1];
            idx1++;
        } else {
            mmc *= fatores2[idx2];
            idx2++;
        }
    }
    
    return mmc;
}

int main()
{
    int numero1, numero2;
    printf("Digite dois números inteiros: ");
    scanf("%d %d", &numero1, &numero2);

    int fatores1[maximo_de_fatores], fatores2[maximo_de_fatores];

    printf("Fatores de %d: ", numero1);
    int num_fatores1 = calcular_fatores(numero1, fatores1);
    for (int i = 0; i < num_fatores1; i++) {
        printf("%d ", fatores1[i]);
    }
    printf("\n");

    printf("Fatores de %d: ", numero2);
    int num_fatores2 = calcular_fatores(numero2, fatores2);
    for (int i = 0; i < num_fatores2; i++) {
        printf("%d ", fatores2[i]);
    }
    printf("\n");

    printf("MDC de %d e %d: %d\n", numero1, numero2, calcular_mdc(numero1, numero2));
    printf("MMC de %d e %d: %d\n", numero1, numero2, calcular_mmc(numero1, numero2));

    return 0;
}