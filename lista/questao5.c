#include <stdio.h>

int MDC(int x, int y)
{
    if(y == 0){
        return x;
    }
    
       return MDC(y, x % y);
    
}

int main() 
{
    int x, y;
    
    scanf("%d %d", &x, &y);
    
    printf("MDC(%d,%d) = %d\n", x, y, MDC(x, y)); 
    
    return 0;
}
