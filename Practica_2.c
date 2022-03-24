#include <stdio.h>

int main(){
    int num1,num2,num3,numvalores;
    printf("Introduzca 3 datos separados por comas: ");
    numvalores = scanf("%i,%i,%i\n",&num1,&num2,&num3);
    printf("El numero de valores introducidos es: %d\n",numvalores);
    printf("Los valores introducidos son: %d,%d,%d\n",num1,num2,num3);
    
    return 0;
}