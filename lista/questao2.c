#include <stdio.h>
#include <time.h>
#include <math.h>

int findprimo(int n, int divisor) {
    if (divisor == 1) return 1;
    if (n % divisor == 0) return 0;
    return findprimo(n, divisor - 1); 
}

int checkprimo(int n) {
    if (n < 2) return 0;
    int maiordiv = sqrt(n);
    return findprimo(n, maiordiv);
}

int main() {
    time_t tempoInicio = time(NULL);
    int numero = 2;

    while (1) {
        if (checkprimo(numero)) printf("%d\n", numero);

        if (time(NULL) - tempoInicio >= 60) break;

        numero++;
    }
    
    return 0;
}
