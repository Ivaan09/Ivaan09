#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char *str = "temporal";

int main(){
    const char* filename = "prueba.txt";

    FILE* output_file = fopen(filename,"wt");
    if (!output_file){
        perror("fopen");
        exit(EXIT_FAILURE);
    }

    fwrite(str,1,strlen(str),output_file);
    printf("LA TABLA DEL 5 EN DECIMAL\n");
    for (int i = 0; i < 11; i++){
        printf("%d\n", 5 * i);
    }

    printf("LA TABLA DEL 5 EN HEXADECIMAL\n");
    for (int i = 0; i < 11; i++){
        printf("%X\n", 5 * i);
    }

    printf("LA TABLA DEL 5 EN OCTAL\n");
    for (int i = 0; i < 11; i++){
        printf("%o\n", 5 * i);
    }

    fclose(output_file);
    exit(EXIT_SUCCESS);

}
    