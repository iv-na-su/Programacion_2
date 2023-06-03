#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct ARTICULO {
		char JUEGO[30];
		float PRECIO;
		char PROVEEDOR[20];
};

struct INCREMENTO{
        char PROVEEDOR[20];
        float PORCENTAJE;
};

#define N 30
#define M 8

int main()
{
		FILE * FP, *FP2 ;
		struct ARTICULO X ;
		struct INCREMENTO Y ;
		struct INCREMENTO A, B;
		int I , J, CANT, ELECCION = 1, PRINCIPIO = 0, MEDIO= 0 , FINAL  = 0, ENCONTRADO = 1;
		char BUSQ_PROV[20], JUEGO_MAX[30];
		float PRECIO_MAX = 0;

		srand(88);



while(ELECCION != 5){
    if(ELECCION == 1){
        if ( (FP = fopen ("MERCADERIA","rb")) == NULL ) {
				printf("\n\n ERROR APERTURA DE ARCHIVO \n\n") ;
				exit(1);
		};

        if ( (FP2 = fopen ("AUMENTOS","rb")) == NULL ) {
				printf("\n\n ERROR APERTURA DE ARCHIVO \n\n") ;
				exit(1);
		};

		printf("\n\n\t %-30s %-20s %-20s\n\n" ,"JUEGO", "PRECIO", "PROVEEDOR");
		fread ( &X , sizeof(X) , 1 , FP );
		while ( ! feof(FP)) {
				printf("\n\n\t %-30s $%-20.2f %-20s" , X.JUEGO, X.PRECIO, X.PROVEEDOR);

                fread ( &X , sizeof(X) , 1 , FP );

		}

		printf("\n\n\n\n");


		printf("\n\n\t %-20s %-20s\n\n" ,"PROVEEDOR", "PORCENTAJE DE AUMENTO");
		fread ( &Y , sizeof(Y) , 1 , FP2 );
		while ( ! feof(FP2)) {

                    printf("\n\n\t %-20s %% %-20.2f " , Y.PROVEEDOR, Y.PORCENTAJE);


				fread ( &Y , sizeof(Y) ,1 , FP2 );
		}



        printf("\n\n\n\n");
		fclose(FP2);
		fclose(FP);
    }


        printf("\n\n\n\t\tSELECCIONE QUE QUIERE HACER A CONTINUACION:\n\n1: MOSTRAR DATOS\n2: ACTUALIZAR PRECIOS DE LOS JUEGOS\n3: BUSCAR UN PROVEEDOR\n4: MOSTRAR EL JUEGO MAS CARO\n5: SALIR DEL PROGRAMA");
        printf("\n\n\tQUE DESEA HACER?  ");
        scanf("%d", &ELECCION);

        if(ELECCION == 2){


            if ( (FP = fopen ("MERCADERIA","r+b")) == NULL ) {
				printf("\n\n ERROR APERTURA DE ARCHIVO \n\n") ;
				exit(1);
            };

            if ( (FP2 = fopen ("AUMENTOS","rb")) == NULL ) {
				printf("\n\n ERROR APERTURA DE ARCHIVO \n\n") ;
				exit(1);
            };




            fseek(FP2, 0L, SEEK_END);
            CANT = ftell(FP2)/sizeof(struct INCREMENTO);

            fread(&X, sizeof(X), 1, FP );
            for(I = 0 ;!feof(FP) ; I++, ENCONTRADO = 1){
                FINAL = CANT;
                PRINCIPIO = 0;
                while(ENCONTRADO == 1){
                    MEDIO = (PRINCIPIO + FINAL)/2;
                    fseek(FP2, MEDIO*sizeof(Y), SEEK_SET);
                    fread(&Y, sizeof(Y), 1, FP2 );

                    if(strcmp(X.PROVEEDOR, Y.PROVEEDOR)== 0)
                        ENCONTRADO = 0;
                    if(strcmp(X.PROVEEDOR, Y.PROVEEDOR)> 0)
                        PRINCIPIO = MEDIO+1;
                    if(strcmp(X.PROVEEDOR, Y.PROVEEDOR)< 0)
                        FINAL = MEDIO-1;




                }
                X.PRECIO = X.PRECIO + (X.PRECIO*(Y.PORCENTAJE/100));
                fseek(FP,(long)(I*sizeof(X)), SEEK_SET);
                fwrite(&X, sizeof(X), 1, FP );

                fseek(FP, 0L, SEEK_CUR);
                fread(&X, sizeof(X), 1, FP );

            }


        printf("\n\n\n\n");
		fclose(FP2);
		fclose(FP);
        }

        if(ELECCION == 3){



            if ( (FP = fopen ("MERCADERIA","rb")) == NULL ) {
				printf("\n\n ERROR APERTURA DE ARCHIVO \n\n") ;
				exit(1);
            };

            J = 0;
            fflush(stdin);
            printf("\n\nINGRESAR EL NOMBRE DEL PROVEEDOR: ");
            gets(BUSQ_PROV);
            printf("\n\nJUEGOS DE %s:\n", BUSQ_PROV);

            while(!feof(FP)){
                fread(&X, sizeof(X), 1, FP);
                if(strcmp(X.PROVEEDOR, BUSQ_PROV) == 0){
                    printf("\n\t%s", X.JUEGO);
                    J++;
                }
            }
            if(J == 0)
                printf("\n\nNO TENEMOS NINGUN JUEGO DE %s AUN", BUSQ_PROV);

        printf("\n\n\n\n");
		fclose(FP);

        }

        if(ELECCION == 4){


            if ( (FP = fopen ("MERCADERIA","rb")) == NULL ) {
				printf("\n\n ERROR APERTURA DE ARCHIVO \n\n") ;
				exit(1);
            };

            while(!feof(FP)){
                fread(&X, sizeof(X), 1, FP);
                if(X.PRECIO > PRECIO_MAX){
                    PRECIO_MAX = X.PRECIO;
                    strcpy(JUEGO_MAX, X.JUEGO);
                }


            }

            printf("\n\nEL JUEGO MAS CARO ES %s CON UN VALOR TOTAL DE %.2f", JUEGO_MAX, PRECIO_MAX);





        printf("\n\n\n\n");
		fclose(FP);

        }





        printf("\n\n\n\n");
}
}
