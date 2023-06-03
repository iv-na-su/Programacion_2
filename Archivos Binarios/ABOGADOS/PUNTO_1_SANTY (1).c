#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct HONORARIOS {
		char CLIENTE[20];
		char CAUSA[20];
		float PAGO;
		int MESDEPAGO;
};

struct ACUM{
    char ACUM_C[20];
    int PLATA;
};

int main()
{
    FILE * FP;
    int CANT = ftell(FP)/sizeof(struct HONORARIOS);
    struct HONORARIOS H; struct ACUM A[CANT]; int I, ACUM_F = 0;

    if((FP = fopen("HONORARIOS 2020","rb")) == NULL){
        printf("\n\n\n\t ERRO DE LECTURA DE ARCHIVO HONORARIOS 2020\n\n\n");
        system("pause");
        exit(1);
    };

    fseek(FP,0,SEEK_SET);
    printf("\n\t CANT = %d", CANT);

    for(I = 0; I <= CANT; I++){
        strcpy(A[I].ACUM_C,H.CLIENTE);
    }

    /*
    fread(&H,sizeof(H),1,FP);
    while(! feof(FP)){

    }
*/

    fclose(FP);
    printf("\n\n\n\n\n\n");
}
