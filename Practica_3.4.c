#include <stdio.h>

void leerFraccion(int *num,int *den){
    printf("Introduzca el numerador: ");
    scanf("%i",num);
    printf("Introduzca el denominador: ");
    scanf("%i",den);
}

void escribirFraccion(int num,int den) {
    printf("El resultado es: %i / %i\n",num,den);
}

void sumarFracciones(int num1,int den1,int num2,int den2,int *resultado_numerador,int *resultado_denominador){
    *resultado_numerador = (den2 * num1) + (den1 * num2);
    *resultado_denominador = den1 * den2;
}

void restarFracciones(int num1, int den1, int num2, int den2, int *resultado_numerador, int *resultado_denominador){
    *resultado_numerador = (den2 * num1) - (den1 * num2);
    *resultado_denominador = den1 * den2;
}

void multiplicarFracciones(int num1, int den1, int num2, int den2, int *resultado_numerador, int *resultado_denominador){
    *resultado_numerador = num1 * num2;
    *resultado_denominador = den1 * den2;
}

void dividirFracciones(int num1, int den1, int num2, int den2, int *resultado_numerador, int *resultado_denominador){
    *resultado_numerador = num1 * den2;
    *resultado_denominador = num2 * den1;
}

int main(){
    int num1,den1,num2,den2,resultado_numerador,resultado_denominador;

    leerFraccion(&num1,&den1);
    leerFraccion(&num2,&den2);
    sumarFracciones(num1,den1,num2,den2,&resultado_numerador,&resultado_denominador);
    escribirFraccion(resultado_numerador,resultado_denominador);
    restarFracciones(num1,den1,num2,den2,&resultado_numerador,&resultado_denominador);
    escribirFraccion(resultado_numerador,resultado_denominador);
    multiplicarFracciones(num1,den1,num2,den2,&resultado_numerador,&resultado_denominador);
    escribirFraccion(resultado_numerador,resultado_denominador);
    dividirFracciones(num1,den1,num2,den2,&resultado_numerador,&resultado_denominador);
    escribirFraccion(resultado_numerador,resultado_denominador);
    
    return 0;
}