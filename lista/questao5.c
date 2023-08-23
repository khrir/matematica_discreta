#include <stdio.h>

int mdc_euclides(int num1, int num2) {
    
    if (num2 == 0) return num1;                // funcao recusiva para encontrar o MDC a partir do algoritmo de Euclides 
                                                    
    return mdc_euclides(num2, num1 % num2);
}

int calc_mmc(int num1, int num2){
    
    return (num1 * num2) / mdc_euclides(num1,num2); // funcao para encontrar o mmc a partir do mdc (EXPLICACAO NA APRESENTACAO 6 DO SITE DO PIMENTAS)
}

int main(){

    int numA, numB, mmc, mdc;

    scanf("%d %d",&numA,&numB);

    mdc = mdc_euclides(numA,numB);
    mmc = calc_mmc(numA,numB);

    printf("O MDC de %d e %d = %d\n",numA,numB,mdc);
    printf("O MMC de %d e %d = %d\n",numA,numB,mmc);

    return 0;
}