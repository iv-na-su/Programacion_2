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



int main()
{
		FILE * FP ;
		struct ABOGADOS Y ;

		if ( (FP = fopen ("ABOGADOS 2020","rb")) == NULL ) {
				printf("\n\n ERROR APERTURA DE ARCHIVO \n\n") ;
				exit(1);
		};

		printf("\n\n\t %-15s %-15s %-15s \n\n" ,"CLIENTE", "CAUSA", "ABOGADO");
		fread ( &Y , sizeof(Y) , 1 , FP );
		while ( ! feof(FP)) {
				printf("\n\n\t %-15s %-15s %-15s" ,
				Y.CLIENTE, Y.CAUSA, Y.ABOGADO);

				fread ( &Y , sizeof(Y) ,1 , FP );
		}

		fclose(FP);

		printf("\n\n");
		return 0 ;
}
