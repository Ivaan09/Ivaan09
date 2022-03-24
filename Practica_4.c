#include <stdio.h>
#include <math.h>

void pideDiagonal(float *dia){
    scanf("%f", dia);
}

float perimetro(float dia1, float dia2){
    return 2 * dia2 + dia1;
}

float area(float dia1, float dia2){
    return dia2 * dia1 * 0.5;
}

int main(){
    float dia1,dia2;
    printf("Dame el valor de la diagonal mayor: ");
    pideDiagonal(&dia1);
    printf("Dame el valor de la diagonal menor: ");
    pideDiagonal(&dia2);
    printf("El perimetro es: %g\n", perimetro(dia1,dia2));
    printf("El area es: %g\n", area(dia1, dia2));


    return 0;
}