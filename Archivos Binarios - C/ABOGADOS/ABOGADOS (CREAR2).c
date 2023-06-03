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
		FILE * FP, *FP2 ;
		struct HONORARIOS X ;
		struct ABOGADOS Y ;
		int I ;
		srand(87);


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

            fwrite ( &Y , sizeof(Y) , 1 , FP2 );

            fread ( &X , sizeof(X) , 1 , FP );
		}

		fclose(FP);
		fclose(FP2);

		return 0 ;
}

