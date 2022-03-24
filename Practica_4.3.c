#include <stdio.h>
#include <math.h>

int main(){
    float R,r,area,perimetro;

    printf("Escribe el radio mayor: ");
    scanf("%f",&R);

    printf("Escribe el radio menor: ");
    scanf("%f",&r);

    area = M_PI * pow(R - r,2);
    perimetro = 2 * M_PI * R + 2 * M_PI * r;

    printf("El area es : %g\n", area);
    printf("El perimetro es: %g\n", perimetro);

    /* OTRA FORMA
    printf("El area es : %g\n", M_PI * pow(R - r,2);
    printf("El perimetro es: %g\n", 2 * M_PI * R + 2 * M_PI * r); */

    return 0;
}