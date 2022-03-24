/**Nombre del programa: Calculadora
 * Descripcion: Se piden 2 numeros enteros y devolvemos la suma, resta, multiplicacion y division de dichos numeros
 * Autor: Iván Estépar Rebollo
 * Fecha: 08/03/2022
 * Version: 1.0
*/

#include <stdio.h> //se introduce la biblioteca que se va a utilizar

//esta función se encarga de leer el numero introducido por teclado
void leerNumero(int *num){
    printf("Escribe un numero: ");
    scanf("%i", num); //se pide por pantalla un numero entero
}

//esta funcion escribe el resultado de las demas funciones
void escribirResultado(int num1,int num2,char operador,float resultado){
    printf("%i %c %i = %g\n",num1,operador,num2,resultado); /*muestra el resultado de las distintas operaciones*/
}

//esta funcion realiza la suma
void sumar(int num1,int num2,int *suma){
    *suma = num1 + num2; //se realiza la suma
}

//esta funcion realiza la resta
void restar(int num1,int num2,int *resta){
    *resta = num1 - num2; //se realiza la resta
}

//esta funcion realiza la multiplicacion
void multiplicar(int num1,int num2,int *multiplicacion){
    *multiplicacion = num1 * num2; //se realiza la multiplicacion
}

//esta funcion realiza la division
void dividir(int num1,int num2,float *division){
    *division = (float)num1 / (float)num2; //se realiza la division
}

int main(){
    int num1,num2,suma,resta,multiplicacion; //se inicializa las variables int
    float division; //se inicializa la variable float

    //llamadas a las funciones, se ejecutan en orden
    leerNumero(&num1);
    leerNumero(&num2);
    sumar(num1,num2,&suma);
    escribirResultado(num1,num2,'+',suma); //se escribe el resultado de la suma
    restar(num1,num2,&resta);
    escribirResultado(num1,num2,'-',resta); //se escribe el resultado de la resta
    multiplicar(num1,num2,&multiplicacion);
    escribirResultado(num1,num2,'*',multiplicacion);//se escribe el resultado de la multiplicacion
    dividir(num1,num2,&division);
    escribirResultado(num1,num2,'/',division); //se escribe el resultado de la division

    return 0;
}