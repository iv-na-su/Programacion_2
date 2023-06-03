#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct INGRESO {
		int LEGAJO;
		char CARRERA[20];
};

struct EXAMEN{
        int LEGAJO;
        int NOTA;
};

#define N 200

int main()
{
		FILE * FP, *FP2 ;
		struct INGRESO X ;
		struct EXAMEN Y ;
		int I ;
		srand(87);

        char CARRERAS[][20] = {"FISICA","INGENIERIA","ARTES","INFORMATICA","MEDICINA","DEPORTES","CS. EXACTAS","BIOQUIMICA","ASTRONOMIA","HUMANIDADES","PSICOLOGIA","BIOLOGIA"};

		if ( (FP = fopen ("INGRESO","wb")) == NULL ) {
				printf("\n\n ERROR APERTURA DE ARCHIVO \n\n") ;
				exit(1);
		};
        if ( (FP2 = fopen ("EXAMEN","wb")) == NULL ) {
                printf("\n\n ERROR APERTURA DE ARCHIVO \n\n") ;
                exit(1);
		};



		for(I = 0 ; I<N ; I++) {
            X.LEGAJO = 1000+rand()%9000;
            Y.LEGAJO = X.LEGAJO;
            strcpy(X.CARRERA , CARRERAS[rand()%12]);
            Y.NOTA = rand()%11;

            fwrite ( &Y , sizeof(Y) , 1 , FP2 );
            fwrite ( &X , sizeof(X) , 1 , FP );

		}

		fclose(FP);
		fclose(FP2);

		return 0 ;
}
