#include <stdio.h>

void decompor_em_numeros_primos(int numero) 
{
    int contador;
    while (numero % 2 == 0) {
        printf("2 ");
        numero /= 2;
    }
    
    for (contador = 3; (contador * contador) <= numero; contador += 2) {
        while (numero % contador == 0) {
            printf("%d ", contador);
            numero /= contador;
        }
    }
    
    if (numero > 2) {
        printf("%d ", numero);
    }
}

int main() 
{
    int numero;
    printf("Entre com um numero inteiro: ");
    scanf("%d", &numero);
    
    printf("Fatores primos de %d: ", numero);
    decompor_em_numeros_primos(numero);
    
    return 0;
}
