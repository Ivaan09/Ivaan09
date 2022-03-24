#include <stdio.h>

void pideLado(int *l){
    printf("Dame el numero de lados: ");
    scanf("%d",l);
}

int perimetro(int lado){
    int perim = 4 * lado;
    return perim;
}

int area(int lado){
    int ar = lado * lado;
    return ar;
}

int main(){
    int lado;

    pideLado(&lado);
    printf("%d\n", perimetro(lado));
    printf("%d\n", area(lado));


    return 0;
}