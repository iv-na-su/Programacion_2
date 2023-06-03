#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct HONORARIOS {
		char CLIENTE[20];
		char CAUSA[20];
		float PAGO;
		int MESDEPAGO;
};

struct ABOGADOS{
        char CLIENTE[20];
		char CAUSA[20];
		char ABOGADO[20];
};


#define N 40

int main()
{
		FILE * FP , *FP2;
		struct HONORARIOS X ;
        struct ABOGADOS Y ;
		int I ;
		srand(68);
		char CLIENTES[][20] = {"PEPE","LUIS","GERMAN","RAMIRO","NAHUEL","GERARDO","MENEM","LUCAS","ELIAS", "JUAN", "MARCELO", "JULIO", "CRISTIAN"};
		char CAUSAS[][20] = {"ROBO","HURTO","FRAUDE","HOMICIDIO","SEPARACION","CONSPIRACION","IGNORANCIA", "DEUDA", "ABUSO", "BORRACHO", "ACCIDENTE"};
		char ABOGADOS[][20] = {"Lic. JULIA","Lic. TAMARA","Lic. MARIA","Lic. ANALIA","Lic. AGUSTINA","Lic. REINA","Lic. PILAR","Lic. MILAGROS","Lic. PAULA","Lic. CANDELA","Lic. CAMILA","Lic. JUANA","Lic. ZOE","Lic. NOELIA","Lic. MARIANA",};

		if ( (FP = fopen ("HONORARIOS 2020","wb")) == NULL ) {
				printf("\n\n ERROR APERTURA DE ARCHIVO \n\n") ;
				exit(1);
		};

		for ( I = 0 ; I < N ; I++ ) {
				strcpy(X.CLIENTE , CLIENTES[rand()%13]);
				strcpy(X.CAUSA , CAUSAS[rand()%11]);
				X.PAGO = (20000+rand()%80000);
				X.MESDEPAGO = 1+rand()%12;


				fwrite ( &X , sizeof(X) , 1 , FP );
		}

		fclose(FP);

    //COPIAR ARCHIVOS

        if ( (FP = fopen ("HONORARIOS 2020","rb")) == NULL ) {
				printf("\n\n ERROR APERTURA DE ARCHIVO \n\n") ;
				exit(1);
		};
        if ( (FP2 = fopen ("ABOGADOS 2020","wb")) == NULL ) {
                printf("\n\n ERROR APERTURA DE ARCHIVO \n\n") ;
                exit(1);
		};


        fread ( &X , sizeof(X) , 1 , FP );
		while(!feof(FP)) {
            strcpy(Y.CLIENTE , X.CLIENTE);
            strcpy(Y.CAUSA , X.CAUSA);
            strcpy(Y.ABOGADO, ABOGADOS[rand()%14]);
            fwrite ( &Y , sizeof(Y) , 1 , FP2 );

            fread ( &X , sizeof(X) , 1 , FP );
		}

		fclose(FP);
		fclose(FP2);




		return 0 ;
}
