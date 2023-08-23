#include <stdio.h>
/*
Escolha os dois numeros para tirar MDC(x,y);
Divida x por y, se o resto não for zero divida y pelo resto até achar o resto "0";
Quando achar uma divisão com resto 0 o "y" dessa divisão será o MDC de x e y originais.

*/

int MDC(int x, int y)
{
    if(y == 0)
    {
        return x;
    }
    
    {
       return MDC(y, x % y); // O algoritmo de Euclides funciona dividindo sucessivamente o resto da divisão até que o resto seja "0", assim, caindo no caso base.
    }

}

int main() 
{
    int x, y;
    
    scanf("%d %d", &x, &y);
    
    printf("MDC(%d,%d) = %d\n", x, y, MDC(x, y)); 
    
    return 0;
}
