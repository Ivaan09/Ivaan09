#include <stdio.h>

int main(){
    enum diasSemana {Lunes,Martes,Miercoles,Jueves,Viernes,Sabado,Domingo} diaActual;
    for (diaActual = Lunes; diaActual <= Domingo; diaActual++){
        switch (diaActual)
        {
        case Lunes:
            printf("Lunes\n");
            break;
        case Martes:
            printf("Martes\n");
            break;
        case Miercoles:
            printf("Miercoles\n");
            break;
        case Jueves:
            printf("Jueves\n");
            break;
        case Viernes:
            printf("Viernes\n");
            break;
        case Sabado:
            printf("Sabado\n");
            break;
        case Domingo:
            printf ("Domingo\n");
            break;
        
        default:
            printf("Ese dia no existe");
        }
    }
    return 0;
}