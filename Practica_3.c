#include <stdio.h>
#include <math.h>
int main(){
    int rad;
    float Area;
    printf("Dame el valor del radio: ");
    scanf("%i",&rad);
    Area = M_PI * (pow(rad,2));
    printf("El area es: %.2f\n",Area);

    return 0;
}