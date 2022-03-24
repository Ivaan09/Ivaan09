#include <stdio.h>

void pideLado(int *lad){
    printf("Dame el lado: ");
    scanf("%d",lad);
}

int perimetro(int l, int L){
    float perim = 2 * L + 2 * l;
    printf("El perimetro es: %g\n", perim);
    return perim;
}

int area(int l, int L){
    float ar = L * l;
    printf("El area es: %g\n", ar);
    return ar;
}

int main(){
    int l,L;

    pideLado(&l);
    pideLado(&L);
    perimetro(l,L);
    area(l,L);




    return 0;
}