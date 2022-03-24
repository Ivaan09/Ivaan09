#include <stdio.h>

int main(){
    int a,b,numval;
    long int c;
    printf("Introduce 3 números: ");
    numval = scanf("%d,%u,%ld",&a,&b,&c);
    printf("El resultado es: %d,%u,%ld\n",a,b,c);
    printf("El numero de valores introducidos son: %d\n",numval);

    return 0;
}