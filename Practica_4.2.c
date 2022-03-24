#include <stdio.h>
#include <math.h>

void cleanBuffer(){
    while(getchar() != '\n');
}

int pideLados(){
    int numlados;
    printf("Escribe el numero de lados del poligono: ");
    scanf("%i",&numlados);
    return numlados;
}


void pideRadio(float *radio){
    cleanBuffer();
    printf("Dame el radio: ");
    scanf("%f\n",radio);
}

float apotema(float lado){
    return sqrt(pow(lado,2) + pow(lado/2,2));
}

void area(float perimetro, float apotema){
    printf("El area es : %g\n", perimetro * apotema);
}

void perimetro(int numlados, float lado){
    printf("El perimetro es: %g\n", numlados * lado);
    area(numlados * lado, apotema(lado));
}

void longitudlado(int numlados, float radio){
    float longlado = sqrt(2 * pow(radio,2) * (1 - cos(360/numlados)));
    perimetro(numlados, longlado);
}

int main(){
    int numlados;
    float radio;

    numlados = pideLados();
    pideRadio(&radio);
    longitudlado(numlados,radio);

    return 0;
}