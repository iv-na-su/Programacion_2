#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct DOCENTE {
		int LEGAJO;
		char NOM[20];
};

struct MATERIA{
        char NOM[20];
        int NIVEL;
        int LEGAJO_DOCENTE;
};

#define N 12

int main()
{
		FILE * FP, *FP2 ;
		struct DOCENTE X ;
		struct MATERIA Y ;
		struct DOCENTE A, B;
		int I , J, CANT;
		int LEGAJOS[N];
		srand(88);

        char MATERIAS[N][20] = {"FISICA","MATEMATICAS","LITERATURA","INFORMATICA","INGLES","ED FISICA","BIOLOGIA","GEOGRAFIA","ECONOMIA","ARTES","HISTORIA","QUIMICA"};
        char NOMBRES[N][20] = {"PEPE","LUIS","GERMAN","RAMIRO","NAHUEL","GERARDO","MENEM","LUCAS","ELIAS","DIEGO", "JUAN", "MARCELO"};

		if ( (FP = fopen ("DOCENTES","wb")) == NULL ) {
				printf("\n\n ERROR APERTURA DE ARCHIVO \n\n") ;
				exit(1);
		};
        if ( (FP2 = fopen ("MATERIAS","wb")) == NULL ) {
                printf("\n\n ERROR APERTURA DE ARCHIVO \n\n") ;
                exit(1);
		};

        for(I = 0 ; I<N ; I++)
            LEGAJOS[I] = 1000+rand()%9999;

		for(I = 0 ; I<N ; I++) {
            X.LEGAJO = LEGAJOS[I];
            strcpy(X.NOM , NOMBRES[I]);
            strcpy(Y.NOM , MATERIAS[I]);
            for(J= 1 ; J<=4 ; J++){
                Y.NIVEL = J;
                Y.LEGAJO_DOCENTE = LEGAJOS[rand()%N];
                fwrite ( &Y , sizeof(Y) , 1 , FP2 );

		}
            fwrite ( &X , sizeof(X) , 1 , FP );
		}

		fclose(FP);
		fclose(FP2);


printf("\n\n\n\n\n");

// ORDENAMIENTO

        if ( (FP = fopen ("DOCENTES","r+b")) == NULL ) {
            printf("\n\n ERROR APERTURA DE ARCHIVO \n\n") ;
            exit(1);
		};


        fseek(FP, 0L, SEEK_END);
		CANT = ftell(FP)/sizeof(struct DOCENTE);
		printf("\n\n\t\tCantidad de datos: %d", CANT);


    for(I=0; I<CANT-1; I++)
        for(J=0; J<CANT-I-1; J++)
        {

            fseek(FP,(long)(J*sizeof(A)),SEEK_SET);


            fread(&A,sizeof(A),1,FP);

            fread(&B,sizeof(A),1,FP);

            if(A.LEGAJO>B.LEGAJO)
            {

                fseek(FP,(long)(J*sizeof(A)),SEEK_SET);

                fwrite(&B, sizeof(B), 1 ,FP);

                fwrite(&A ,sizeof(A) ,1 ,FP);
            }

        }


		fclose(FP);
		printf("\n\n\n\n\n");
		return 0 ;
}
