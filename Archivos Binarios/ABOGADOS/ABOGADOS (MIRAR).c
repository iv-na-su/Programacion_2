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
		FILE * FP , *FP2;
		struct HONORARIOS X ;
        struct ABOGADOS Y ;

		if ( (FP = fopen ("HONORARIOS 2020","rb")) == NULL ) {
				printf("\n\n ERROR APERTURA DE ARCHIVO \n\n") ;
				exit(1);
		};

        if ( (FP2 = fopen ("ABOGADOS 2020","rb")) == NULL ) {
				printf("\n\n ERROR APERTURA DE ARCHIVO \n\n") ;
				exit(1);
		};

		printf("\n\n\t %-15s %-15s %-10s %15s\n\n" ,"CLIENTE", "CAUSA", "PAGO", "MES DE PAGO");
		fread ( &X , sizeof(X) , 1 , FP );
		while ( ! feof(FP)) {
				printf("\n\n\t %-15s %-15s $%8.2f %8d" ,
				X.CLIENTE, X.CAUSA, X.PAGO, X.MESDEPAGO);

				fread ( &X , sizeof(X) ,1 , FP );
		}

		printf("\n\n\n\n");

		printf("\n\n\t %-15s %-15s %-15s \n\n" ,"CLIENTE", "CAUSA", "ABOGADO");
		fread ( &Y , sizeof(Y) , 1 , FP2 );
		while ( ! feof(FP2)) {
				printf("\n\n\t %-15s %-15s %-15s" ,
				Y.CLIENTE, Y.CAUSA, Y.ABOGADO);

				fread ( &Y , sizeof(Y) ,1 , FP2 );
		}




		fclose(FP2);
		fclose(FP);




		printf("\n\n");
		return 0 ;
}
