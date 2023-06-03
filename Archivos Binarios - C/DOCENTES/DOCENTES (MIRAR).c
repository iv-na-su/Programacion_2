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

int main()
{
		FILE * FP, *FP2 ;
		struct DOCENTE X ;
		struct MATERIA Y ;
		int CANT, FINAL = 0, ENCONTRADO = 1, PRINCIPIO = 0, MITAD = 0, MAT_MAX = 0, MAT_ACT = 0;
		char DOCENTE_MAX[20];

		if ( (FP = fopen ("DOCENTES","rb")) == NULL ) {
				printf("\n\n ERROR APERTURA DE ARCHIVO \n\n") ;
				exit(1);
		};

        if ( (FP2 = fopen ("MATERIAS","rb")) == NULL ) {
				printf("\n\n ERROR APERTURA DE ARCHIVO \n\n") ;
				exit(1);
		};

		printf("\n\n\t %-10s %-10s \n\n" ,"LEGAJO", "NOMBRE");
		fread ( &X , sizeof(X) , 1 , FP );
		while ( ! feof(FP)) {
				printf("\n\n\t %-10d %-10s" , X.LEGAJO, X.NOM);

                fread ( &X , sizeof(X) , 1 , FP );

		}

        fclose(FP);
		printf("\n\n\n\n");


		printf("\n\n\t %-15s %-10s %-20s \n\n" ,"NOMBRE", "NIVEL", "LEGAJO DEL PROFESOR");
		fread ( &Y , sizeof(Y) , 1 , FP2 );
		while ( ! feof(FP2)) {

                    printf("\n\n\t %-15s %-10d %-20d" , Y.NOM, Y.NIVEL, Y.LEGAJO_DOCENTE);


				fread ( &Y , sizeof(Y) ,1 , FP2 );
		}




		fclose(FP2);
		fclose(FP);

        printf("\n\n\n PUNTO A \n\n\n");

        //PUNTO A -  El nombre de todos los docentes que dictan materias en el nivel 3, y el nombre de la materia correspondiente.

            if ( (FP = fopen ("DOCENTES","rb")) == NULL ) {
				printf("\n\n ERROR APERTURA DE ARCHIVO \n\n") ;
				exit(1);
		};

            if ( (FP2 = fopen ("MATERIAS","rb")) == NULL ) {
				printf("\n\n ERROR APERTURA DE ARCHIVO \n\n") ;
				exit(1);
		};


        fseek(FP, 0L, SEEK_END);
		CANT = ftell(FP)/sizeof(struct DOCENTE);


        printf("\n\n\t %-15s %-20s %-10s \n\n" ,"DOCENTE", "MATERIA" ,"NIVEL");
        while (!feof(FP2)){

            fread(&Y , sizeof(Y), 1 ,FP2);
            if(Y.NIVEL == 3){
                FINAL = CANT;
                PRINCIPIO = 0;



                while(ENCONTRADO == 1){
                    MITAD = (PRINCIPIO + FINAL)/2;
                    fseek(FP, MITAD*sizeof(X), SEEK_SET);
                    fread(&X , sizeof(X), 1 ,FP);
                    if(X.LEGAJO == Y.LEGAJO_DOCENTE)
                        ENCONTRADO = 0;
                    if(Y.LEGAJO_DOCENTE < X.LEGAJO)
                        FINAL = MITAD - 1;
                    else
                        PRINCIPIO = MITAD + 1;



                }

                ENCONTRADO = 1;
                printf("\n\n\t %-15s %-20s %-10d \n\n" , X.NOM, Y.NOM , Y.NIVEL);



            }






        }



        fclose(FP);
        fclose(FP2);




        printf("\n\n\n PUNTO B \n\n\n");

        //PUNTO B -   El nombre del docente que más materias dicta.




        if ( (FP = fopen ("DOCENTES","rb")) == NULL ) {
				printf("\n\n ERROR APERTURA DE ARCHIVO \n\n") ;
				exit(1);
		};

        if ( (FP2 = fopen ("MATERIAS","rb")) == NULL ) {
				printf("\n\n ERROR APERTURA DE ARCHIVO \n\n") ;
				exit(1);
		};



        while(!feof(FP)){
            fread(&X, sizeof(X), 1, FP);
            fseek(FP2, 0L, SEEK_SET);
            while(!feof(FP2)){
                fread(&Y,  sizeof(Y), 1, FP2);
                if(Y.LEGAJO_DOCENTE == X.LEGAJO)
                    MAT_ACT++;

            }
            printf("\n%s  %d", X.NOM, MAT_ACT); /*SOLO SIRVE PARA VER CUANTAS MATERIAS TIENEN LOS DEMAS PROFESORES*/
            if(MAT_ACT > MAT_MAX){
                MAT_MAX = MAT_ACT;
                strcpy(DOCENTE_MAX, X.NOM);

            }
            MAT_ACT = 0;


        }

        printf("\n\nEL DOCENTE QUE DICTA MAS MATERIAS ES %s CON UN TOTAL DE %d MATERIAS", DOCENTE_MAX, MAT_MAX);

        fclose(FP);
        fclose(FP2);


		printf("\n\n");
		return 0 ;
}
