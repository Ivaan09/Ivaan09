/**Nombre del programa: Practica_final
 * Descripcion: este programa, dependiendo la opcion que escojas, ejecuta una funcion u otra
 * Organizacion: Universidad de Burgos
 * Autor: Ivan Estepar Rebollo
 * Fecha: 17/04/2022
 * Version: 1.0
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//esta funcion se utiliza para que la funcion sleep funcione independientemente de que estés en Windows o Linux
#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

//prototipos de las funciones
int solicitarOpcionMenu();
int numeroTotalFilas(FILE*);
int contarCaracteres(FILE*);
int filaMasLarga(FILE*);
void seleccionarOpcion(int);
int nuevaFila(FILE*,FILE*);
bool validarEntero(int,int,int,int,char);
bool validarReal(float,float,float,int,char);
int menuMarcasMovil();
int battery();
int blue();
float clockSpeed();
int dualSim();
int fc();
int intMemory();
int fourG();
float mDep();
int mobileWt();
int nCores();
int pc();
int ram();
int scH();
int scW();



void limpiarBuffer()
{
    char c;
    do
    {
        c = getchar();
    } while (c != '\n');
}

/**Nombre del modulo: solicitarOpcionMenu
 * Descripicion: esta funcion solicita un numero para ejecutar una de las opciones que se muestran
 * Argumentos:
 * Retorno: num
 */

int main(){
    int opcion;
    while (true){
        opcion = solicitarOpcionMenu();
        seleccionarOpcion(opcion);
    }

    return 0;
}


int solicitarOpcionMenu(){   
    int leido, num; // se definen las variables
    leido = 1;      // se inicializa la variable leida a 1
    do{
        system("clear");
        printf("\tMENU DE OPCIONES\n");
        printf("\n");
        printf("\t1.Numero total de caracteres alfanumericos\n");
        printf("\t2.Numero total de filas, sin contar la cabecera\n");
        printf("\t3.Fila mas larga\n");
        printf("\t4.Añadir una nueva fila (al final del archivo)\n");
        printf("\t0.Salir\n\n");

        if (leido == 0){
            printf("\tError, elige otra opcion: "); // si leida es 0 da error
        }
        else{
            printf("\tElige una opcion: "); // se debe introducir un numero del 0 al 3
        }
        leido = scanf("%d", &num);
        limpiarBuffer(); // llamada a la funcion limpiar buffer
    } while (num > 4 || num < 0 || leido != 1);
    return num;
}

/**Nombre del modulo: numeroTotalFilas
 * Descripicion: esta funcion cuenta el numero total de filas del documento
 * Argumentos: FILE* filas
 * Retorno: cont - 1
 */int numeroTotalFilas(FILE *filas)
{
    int cont = 0;
    int c = getc(filas);

    while (!feof(filas)){
        if (c == '\n')
        {
            cont++;
        }
        c = getc(filas);
    }

    return cont - 1;
}

/**Nombre del modulo: contarCaracteres
 * Descripicion: esta funcion rcuenta el numero de caracteres alfanumericos del documento
 * Argumentos: FILE* caracteres
 * Retorno: alfanumerico
 */
int contarCaracteres(FILE *caracteres){
    char c;
    int letr = 0;
    int nums = 0;

    while (!feof(caracteres)){
        c = getc(caracteres);
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')){
            letr++;
        }
        if (c >= (int)'0' && c <= (int)'9'){
            nums++;
        }
    }
    int alfanumerico = letr + nums;
    return alfanumerico;
}

/**Nombre del modulo: filaMasLarga
 * Descripicion: esta funcion muestra cuantos caracteres tiene la fila mas larga
 * Argumentos: FILE* larga
 * Retorno: longRow
 */
int filaMasLarga(FILE *larga){
    bool header = false;
    int longRow = 0;
    int currentRow = 0;
    int lastLongRowCharacters = 0;
    int currentRowCharacters = 0;

    while (!feof(larga)){
        char character = fgetc(larga);
        if ((character >= 48 && character <= 57) || (character >= 65 && character <= 90) || (character >= 97 && character <= 122)){
            currentRowCharacters++;
        }
        if (character == '\n' || character == EOF){
            currentRow++;
            if (header == false){
                header = true;
            }
            else{
                if (lastLongRowCharacters < currentRowCharacters){
                    lastLongRowCharacters = currentRowCharacters;
                    longRow = currentRow;
                }
            }
            currentRowCharacters = 0;
        }
    }
    return longRow;
}

/**Nombre del modulo: seleccionarOpcion
 * Descripicion: esta funcion realiza la seleccion de una de las 5 opciones
 * Argumentos: num
 * Retorno:
 */
void seleccionarOpcion(int num){
    FILE *archivo; //DatosTelefonosMoviles.csv
    archivo = fopen("DatosTelefonosMoviles.csv", "r"); //se abre el documento
    FILE* archivo2; //DatosTelefonosMoviles2.csv

    if (archivo == NULL){
        printf("No se puede abrir el archivo");
    }
    else{
        switch (num){
        case 0:
            exit(-1);
            break;

        case 1:
            printf("\tHay %d caracteres alfanumericos\n", contarCaracteres(archivo));
            break;

        case 2:
            printf("\tHay %d filas\n", numeroTotalFilas(archivo));
            break;

        case 3:
            printf("\tLa fila mas larga es la %d\n", filaMasLarga(archivo));
            break;

        case 4:
            printf("Eligió añadir una nueva fila\n");
            archivo2 = fopen("DatosTelefonosMoviles2.csv","r");

            if (archivo == NULL){
                printf("Error al abrir el archivo");
            }
            else{
                archivo2 = fopen("DatosTelefonosMoviles2","w");
                nuevaFila(archivo,archivo2);
            }
            if (fclose(archivo) == 0){
                printf("Se ha cerrado el archivo correctamente");
            }
            else{
                printf("No se ha cerrado el archivo correctamente");
            }
            if (fclose(archivo2) == 0){
                printf("Se ha cerrado el archivo correctamente");
            }
            else{
                printf("No se ha cerrado el archivo correctamente");
            }
            break;
        }
    }
    fclose(archivo); //se cierra el documento
    sleep(3); //pausa de 3 segundos
    system("clear");
}


/**Nombre del modulo: validarEntero
 * Descripicion: esta funcion solicita un numero para ejecutar una de las opciones que se muestran
 * Argumentos:
 * Retorno: num
 */
bool validarEntero(int num, int lim_inf, int lim_sup, int leidos, char enter){
    if (leidos != 2 || enter != '\n' || num < lim_inf || num > lim_sup){
        printf("Datos mal introducidos, intentelo otra vez (pulse enter)");
        limpiarBuffer();
        return 0;
    }
    else

    return 1;
}

/**Nombre del modulo: validarReal
 * Descripicion: esta funcion solicita un numero para ejecutar una de las opciones que se muestran
 * Argumentos:
 * Retorno: num
 */
bool validarReal(float num, float lim_inf, float lim_sup, int leidos, char enter){
    if (leidos != 2 || enter != '\n' || num < lim_inf || num > lim_sup){
        printf("Datos mal introducidos, intentelo otra vez (pulse enter)");
    }
    else

    return 1;
}


/**Nombre del modulo: nuevaFila
 * Descripicion: esta funcion solicita un numero para ejecutar una de las opciones que se muestran
 * Argumentos:
 * Retorno: num
 */
int nuevaFila(FILE* f, FILE* f2){
    char c;

    c = fgetc(f);

    while (!feof(f)){
        fprintf(f2,"%c",c);
        c = fgetc(f);
    }
    
    fprintf(f2,"%d,",battery());
    fprintf(f2,"%d,",blue());
    fprintf(f2,"%0.1f,",clockSpeed());
    fprintf(f2,"%d,",dualSim());
    fprintf(f2,"%d,",fc());
    fprintf(f2,"%d,",fourG());
    fprintf(f2,"%d,",intMemory());
    fprintf(f2,"%0.1f,",mDep());
    fprintf(f2,"%d,",mobileWt());
    fprintf(f2,"%d,",nCores());
    fprintf(f2,"%d",pc());
    fprintf(f2,"%d,",ram());
    fprintf(f2,"%d,",scH());
    fprintf(f2,"%d,",scW());

    int marca = menuMarcasMovil();

    switch (marca){
        case 1:
        return fprintf(f2,"Apple\n");
        break;

        case 2:
        return fprintf(f2,"HTC\n");
        break;

        case 3:
        return fprintf(f2,"LG\n");
        break;

        case 4:
        return fprintf(f2,"Nokia\n");
        break;

        case 5:
        return fprintf(f2,"Samsung\n");
        break;

        case 6:
        return fprintf(f2,"Xiaomi\n");
        break;

        case 7:
        return fprintf(f2,"ZTE\n");
        break;
    }
    return 0;
}


/**Nombre del modulo: menuMarcasMovil
 * Descripicion: esta funcion muestra el menu de las marcas de movil
 * Argumentos:
 * Retorno: num
 */
int menuMarcasMovil(){
    int num,lim_inf=1,lim_sup=7,leida;
    char enter;
    bool valida=0;

    do{
        printf("MENU DE MARCAS DE MOVILES\n\n");
        printf("1.Apple\n");
        printf("2.HTC\n");
        printf("3.LG\n");
        printf("4.Nokia\n");
        printf("5.Samsung\n");
        printf("6.Xiaomi\n");
        printf("7.ZTE\n");

        printf("Elija una opcion: ");
        leida = scanf("%d%c", &num, &enter);
        valida = validarEntero(num,lim_inf,lim_sup,leida,enter);

    } while (valida == 0);

    return num;  
}


/**Nombre del modulo: battery
 * Descripicion: en esta funcion se introduce un dato dentro de un rango establecido
 * Argumentos:
 * Retorno: num
 */
int battery(){
    int num,lim_inf=0,lim_sup=2000,leida;
    char enter;
    bool valida;

    do{
        printf("Introduzca la bateria (Su valor es entero y tiene que encontrarse entre 0-2000): ");
        leida = scanf("%d%c", &num, &enter);
        valida = validarEntero(num,lim_inf,lim_sup,leida,enter);

    } while (valida == 0);

    return num;  
}


/**Nombre del modulo: blue
 * Descripicion: en esta funcion se introduce un dato dentro de un rango establecido
 * Argumentos:
 * Retorno: num
 */
int blue(){
    int num,lim_inf=0,lim_sup=1,leida;
    char enter;
    bool valida;

    do{
        printf("Introduzca el blue (Su valor es entero y tiene que encontrarse entre 0-1): ");
        leida = scanf("%d%c", &num, &enter);
        valida = validarEntero(num,lim_inf,lim_sup,leida,enter);

    } while (valida == 0);

    return num;
}


/**Nombre del modulo: clockSpeed
 * Descripicion: en esta funcion se introduce un dato dentro de un rango establecido
 * Argumentos:
 * Retorno: num
 */
float clockSpeed(){
    float num,lim_inf=0,lim_sup=3,leida;
    char enter;
    bool valida=0;

    do{
        printf("Introduzca la velocidad del reloj (Su valor es real y tiene que encontrarse entre 0-3): ");
        leida = scanf("%f%c", &num, &enter);
        valida = validarEntero(num,lim_inf,lim_sup,leida,enter);

    } while (valida == 0);

    return num;
}


/**Nombre del modulo: dualSim
 * Descripicion: en esta funcion se introduce un dato dentro de un rango establecido
 * Argumentos:
 * Retorno: num
 */
int dualSim(){
    int num,lim_inf=0,lim_sup=1,leida;
    char enter;
    bool valida=0;

    do{
        printf("Introduzca si tiene SIM dual (Su valor es entero y tiene que encontrarse entre 0-1): ");
        leida = scanf("%d%c", &num, &enter);
        valida = validarEntero(num,lim_inf,lim_sup,leida,enter);

    } while (valida == 0);

    return num;
}


/**Nombre del modulo: fc
 * Descripicion: en esta funcion se introduce un dato dentro de un rango establecido
 * Argumentos:
 * Retorno: num
 */
int fc(){
    int num,lim_inf=0,lim_sup=20,leida;
    char enter;
    bool valida=0;

    do{
        printf("Introduzca el fc (Su valor es entero y tiene que encontrarse entre 0-20): ");
        leida = scanf("%d%c", &num, &enter);
        valida = validarEntero(num,lim_inf,lim_sup,leida,enter);

    } while (valida == 0);

    return num;
}


/**Nombre del modulo: fourG
 * Descripicion: en esta funcion se introduce un dato dentro de un rango establecido
 * Argumentos:
 * Retorno: num
 */
int fourG(){
    int num,lim_inf=0,lim_sup=1,leida;
    char enter;
    bool valida;

    do{
        printf("Introduzca si tiene four G (Su valor es entero y tiene que encontrarse entre 0-1): ");
        leida = scanf("%d%c", &num, &enter);
        valida = validarEntero(num,lim_inf,lim_sup,leida,enter);

    } while (valida == 0);

    return num;
}


/**Nombre del modulo: intMemory
 * Descripicion: en esta funcion se introduce un dato dentro de un rango establecido
 * Argumentos:
 * Retorno: num
 */
int intMemory(){
    int num,lim_inf=0,lim_sup=100,leida;
    char enter;
    bool valida=0;

    do{
        printf("Introduzca la memoria interna (Su valor es entero y tiene que encontrarse entre 0-100): ");
        leida = scanf("%d%c", &num, &enter);
        valida = validarEntero(num,lim_inf,lim_sup,leida,enter);

    } while (valida == 0);

    return num;
}


/**Nombre del modulo: pc
 * Descripicion: en esta funcion se introduce un dato dentro de un rango establecido
 * Argumentos:
 * Retorno: num
 */
int pc(){
    int num,lim_inf=0,lim_sup=20,leida;
    char enter;
    bool valida=0;

    do{
        printf("Introduzca el pc (Su valor es entero y tiene que encontrarse entre 0-20): ");
        leida = scanf("%d%c", &num, &enter);
        valida = validarEntero(num,lim_inf,lim_sup,leida,enter);

    } while (valida == 0);

    return num;
}


/**Nombre del modulo: mDep
 * Descripicion: en esta funcion se introduce un dato dentro de un rango establecido
 * Argumentos:
 * Retorno: num
 */
float mDep(){
    int num,lim_inf=0,lim_sup=1,leida;
    char enter;
    bool valida=0;

    do{
        printf("Introduzca el M Dep (Su valor es real y tiene que encontrarse entre 0-1): ");
        leida = scanf("%d%c", &num, &enter);
        valida = validarEntero(num,lim_inf,lim_sup,leida,enter);

    } while (valida == 0);

    return num;
}


/**Nombre del modulo: mobileWt
 * Descripicion: en esta funcion se introduce un dato dentro de un rango establecido
 * Argumentos:
 * Retorno: num
 */
int mobileWt(){
    int num,lim_inf=0,lim_sup=200,leida;
    char enter;
    bool valida;

    do{
        printf("Introduzca el peso del movil (Su valor es entero y tiene que encontrarse entre 0-200): ");
        leida = scanf("%d%c", &num, &enter);
        valida = validarEntero(num,lim_inf,lim_sup,leida,enter);

    } while (valida == 0);

    return num;
}


/**Nombre del modulo: nCores
 * Descripicion: en esta funcion se introduce un dato dentro de un rango establecido
 * Argumentos:
 * Retorno: num
 */
int nCores(){
    int num,lim_inf=0,lim_sup=10,leida;
    char enter;
    bool valida;

    do{
        printf("Introduzca el numero de cores (Su valor es entero y tiene que encontrarse entre 0-10): ");
        leida = scanf("%d%c", &num, &enter);
        valida = validarEntero(num,lim_inf,lim_sup,leida,enter);

    } while (valida == 0);

    return num;
}


/**Nombre del modulo: ram
 * Descripicion: en esta funcion se introduce un dato dentro de un rango establecido
 * Argumentos:
 * Retorno: num
 */
int ram(){
    int num,lim_inf=0,lim_sup=4000,leida;
    char enter;
    bool valida;

    do{
        printf("Introduzca la memoria RAM (Su valor es entero y tiene que encontrarse entre 0-4000): ");
        leida = scanf("%d%c", &num, &enter);
        valida = validarEntero(num,lim_inf,lim_sup,leida,enter);

    } while (valida == 0);

    return num;
}


/**Nombre del modulo: scH
 * Descripicion: en esta funcion se introduce un dato dentro de un rango establecido
 * Argumentos:
 * Retorno: num
 */
int scH(){
    int num,lim_inf=0,lim_sup=20,leida;
    char enter;
    bool valida;

    do{
        printf("Introduzca scH (Su valor es entero y tiene que encontrarse entre 0-20): ");
        leida = scanf("%d%c", &num, &enter);
        valida = validarEntero(num,lim_inf,lim_sup,leida,enter);

    } while (valida == 0);

    return num;
}


/**Nombre del modulo: scW
 * Descripicion: en esta funcion se introduce un dato dentro de un rango establecido
 * Argumentos:
 * Retorno: num
 */
int scW(){
    int num,lim_inf=0,lim_sup=20,leida;
    char enter;
    bool valida;

    do{
        printf("Introduzca scW (Su valor es entero y tiene que encontrarse entre 0-20): ");
        leida = scanf("%d%c", &num, &enter);
        valida = validarEntero(num,lim_inf,lim_sup,leida,enter);

    } while (valida == 0);
    system("clear");

    return num;
}