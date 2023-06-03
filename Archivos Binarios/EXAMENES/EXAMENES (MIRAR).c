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


int main()
{
		FILE * FP , *FP2;
		struct INGRESO X ;
        struct EXAMEN Y ;
        int INSCRIPTOS = 0, PRESENTES = 0, APROBADOS = 0;

		if ( (FP = fopen ("INGRESO","rb")) == NULL ) {
				printf("\n\n ERROR APERTURA DE ARCHIVO \n\n") ;
				exit(1);
		};

        if ( (FP2 = fopen ("EXAMEN","rb")) == NULL ) {
				printf("\n\n ERROR APERTURA DE ARCHIVO \n\n") ;
				exit(1);
		};

		printf("\n\n\t %-10s %-10s \n\n" ,"LEGAJO", "CARRERA");
		fread ( &X , sizeof(X) , 1 , FP );
        fread ( &Y , sizeof(Y) , 1 , FP2 );
		while ( ! feof(FP)) {
				printf("\n\n\t %-10d %-10s" , X.LEGAJO, X.CARRERA);

                if(!strcmp(X.CARRERA, "INGENIERIA" )){
                    INSCRIPTOS++;
                    if(Y.NOTA > 0){
                        PRESENTES++;
                        if(Y.NOTA >= 6)
                            APROBADOS++;
                    }

                }
				fread ( &X , sizeof(X) ,1 , FP );
                fread ( &Y , sizeof(Y) , 1 , FP2 );

		}

        fclose(FP2);
		printf("\n\n\n\n");



        if ( (FP2 = fopen ("EXAMEN","rb")) == NULL ) {
				printf("\n\n ERROR APERTURA DE ARCHIVO \n\n") ;
				exit(1);
		};

		printf("\n\n\t %-10s %-10s \n\n" ,"LEGAJO", "NOTA");
		fread ( &Y , sizeof(Y) , 1 , FP2 );
		while ( ! feof(FP2)) {

                if(Y.NOTA == 0)
                    printf("\n\n\t %-10d %-10s " , Y.LEGAJO, "AUSENTE");
                else
                    printf("\n\n\t %-10d %-10d" , Y.LEGAJO, Y.NOTA);


				fread ( &Y , sizeof(Y) ,1 , FP2 );
		}




		fclose(FP2);
		fclose(FP);


printf("\n\n\n\nINSCRIPTOS = %d \t\t PRESENTES = %d \t\t APROBADOS = %d", INSCRIPTOS, PRESENTES, APROBADOS);

		printf("\n\n");
		return 0 ;
}
