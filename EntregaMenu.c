/**Nombre del programa: EntregaMenu
 * Descripcion: este programa, dependiendo la opcion que escojas, ejecuta una funcion u otra
 * Organizacion: Universidad de Burgos
 * Autor: Ivan Estepar Rebollo
 * Fecha: 05/04/2022
 * Version: 1.1
 * Lista de versiones: 1.0 (realiza las operaciones pero hay un fallo en el menu)
 *                     1.1 (soluciono el fallo del menu omitiendo la funcion pideNumero que no necesitaba)
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//Escribo los prototipos
int factorial();
void divisores();
void nPerfecto();

//Esta funcion limpia el buffer
void limpiarBuffer(){
    char c;
    do{
        c = getchar();
    } 
    while (c != '\n');
    
}

/**Nombre del modulo: factorial
 * Descripicion: esta funcion realiza el factorial de un numero
 * Argumentos: n
 * Retorno: f
*/
int factorial(int n){
    int f=1,i;
    for ( i = 1; i <= n; i++){
        f = f * i;
    }
    return f;
}


/**Nombre del modulo: divisores
 * Descripicion: esta funcion calcula los divisores de un numero
 * Argumentos: nada
 * Retorno: nada
*/
void divisores(){
    int i,n;

    printf("Introduzca un numero: ");
    scanf("%d", &n);
    printf("Los divisores de %d son: ", n);
    if (n>=0){
        for ( i = 1; i <= n/2; i++){
            if (n%i == 0){
                printf("%d, ", i);
            }
            
        }
        
    }
    printf("%d\n", n);
    
}


/**Nombre del modulo: nPerfecto
 * Descripicion: esta funcion dice si el numero introducido es perfecto o no
 * Argumentos: nada
 * Retorno: nada
*/
 void nPerfecto(int num){
   int sumaDivisor=0;

   for (int i = 1; i < num; i++){
       if (num % i == 0) sumaDivisor+=i;
       else continue; 
   }
   printf("El numero %d %s perfecto\n", num, (sumaDivisor == num) ?"es" : "no es");
}

int main(){

    int opcion,num,valido; //se definen las vsariables
    valido = 1;
    do {
        printf("\tMENU DE OPCIONES\n");
        printf("\n");
        printf("\t1.Calcular el factorial de un numero\n");
        printf("\t2.Calcular los divisores de un numero\n");
        printf("\t3.Comprobar si un numero es perfecto\n");
        printf("\t0.Salir\n\n");

        if (valido == 0) {
            printf("\tError, elige otra opcion: ");
        } else {
            printf("\tElige una opcion: "); //se debe introducir un numero del 1 al 3
        }
        valido = scanf("%d", &opcion);
        limpiarBuffer();


        switch (opcion){ //dependiendo el numero que elijas del 1 al 3, ejecutará una opcion u otra del menu
        case 1:
            printf("Introduce un numero: ");
            scanf("%d", &num);
            printf("El factorial de %d es %d\n", num,factorial(num));
            break;

        case 2:
            divisores(); //llamada a la funcion divisores
            break;

        case 3:
            printf("Introduce un numero: ");
            scanf("%d", &num);
            nPerfecto(num); //llamada a la funcion nPerfecto
            break;

        case 4:
            exit(-1);
            break;
        
        default:
            printf("El numero que introdujiste es incorrecto\n"); //si el numero introducido no es 1, 2 o 3, aparece este mensaje
            valido = 0;
            break;
        }
    } while(!((opcion >= 1 && opcion <= 3) && valido == 1)); 

    return 0;
}