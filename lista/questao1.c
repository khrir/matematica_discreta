#include <stdio.h>

int primo(int n, int divisor)
{
   
    if (n < 2) return 0;
        
    if (divisor == 1) return 1;
        
    if (n % divisor == 0) return 0;
        
    return primo(n, divisor - 1);
}

int main()
{

    int num;

    scanf("%d",&num);

    int result = primo(num, num-1);

    if(result == 1) printf("E primo\n");

    else printf("Nao e primo\n");

    return 0;
}   