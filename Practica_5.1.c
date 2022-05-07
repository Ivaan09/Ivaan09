#include<stdio.h>
#include<math.h>

int main(){
    double a,b,c,d;

    printf("Introduce los coeficientes pow(a,2)+b*x+c: ");
    scanf("%lf,%lf,%lf", &a,&b,&c);
    printf("Ecuacion (%.2fx%+.2f)x%+.2f=0\n", a,b,c);
    if (a==0.0 && b==0.0){
        printf("Ecuación degenerada\n");
    }
    if (a==0.0 && b!=0){
        printf("Ec. primer orden\n""x=%lg\n", -c/b);
    }
    if (a!=0.0){
        d = b*b-4*a*c;
        if (d==0.0){
            printf("Solucion doble x=%lg\n", -b/a/2);
        }
        if (d>0.0){
            printf("2 soluciones x1=%lg, x2=%lg\n", (-b+sqrt(d))/a/2, (-b-sqrt(d))/a/2);
        }
        if (d<0.0){
            printf("Soluciones complejas x1=%lg+%lgi, x2=%lg-%lgi\n", -b/a/2, sqrt(-d)/a/2, -b/a/2, sqrt(-d)/a/2);
        }
        
        
        
    }
    return 0;
}