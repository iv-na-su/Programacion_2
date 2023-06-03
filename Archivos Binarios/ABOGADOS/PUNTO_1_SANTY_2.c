/*
1.	 Cuál es el cliente que más dinero aportó al bufete en el año.
2.	 Cuál es el abogado que generó más ingresos al bufete.
*/
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
    float PLATA;
};

int main()
{


    FILE * FP;

        if((FP = fopen("HONORARIOS 2020","rb")) == NULL){
        printf("\n\n\n\t ERRO DE LECTURA DE ARCHIVO HONORARIOS 2020\n\n\n");
        system("pause");
        exit(1);
    };

    int CANT = 100;
    struct HONORARIOS H; struct ACUM A[CANT]; int I, ACUM_F = 0, CONT = 0, MAX = 0; char MAX_CLI[20];



    fseek(FP,0,SEEK_SET);
    printf("\n\t CANT = %d", CANT);

    fread(&H, sizeof(H), 1, FP);
    while(!feof(FP)){

        if(I == CONT){
           strcpy(A[I].ACUM_C,H.CLIENTE);
           CONT++;
           A[I].PLATA = H.PAGO;
           I = -1;
           fread(&H, sizeof(H), 1, FP);
        }

        if(! strcmp(A[I].ACUM_C,H.CLIENTE)){
            A[I].PLATA += H.PAGO;
            I = -1;
           fread(&H, sizeof(H), 1, FP);
        }
       I++;
    }


    for(I = 0 ; I< CONT ; I++){
        printf("\n\n%-20s \t %-20.2f", A[I].ACUM_C, A[I].PLATA);
    }


    for(I = 0; I < CONT; I++){
        if(A[I].PLATA > MAX){
           MAX = A[I].PLATA;
           strcpy(MAX_CLI,A[I].ACUM_C);
        }
    }
    printf("\n\n\t EL CLIENTE QUE MAS DINERO APORTO FUE: %s", MAX_CLI);

    fclose(FP);
    printf("\n\n\n\n\n\n");
}
