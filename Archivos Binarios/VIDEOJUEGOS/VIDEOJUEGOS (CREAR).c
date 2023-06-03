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
		int I , J, CANT;
		srand(116);

        char JUEGOS[N][30] = {"LEAGUE OF LEGENDS","MINECRAFT","VALORANT","THE BINDING OF ISAAC","CALL OF DUTY","COUNTER STRIKE",
                                "RESIDENT EVIL","ROCKET LEAGUE","FALL GUYS","TERRARIA","PORTAL","SILENT HILL","SOMA" ,"TOMB RIDER" ,
                                "AMOUNG US" ,"HOLLOW KNIGHT" ,"GEOMETRY DASH" ,"LIMBO" ,"OUTLAST" ,"XCOM","FIFA" ,"GOD OF WAR" ,"DARK SOULS"
                                ,"HADES" ,"STRAY" ,"STARDEW VALLEY" ,"THE FOREST" ,"POKEMON" ,"FALLOUT" ,"ARK"   };

        char PROVEEDORES[M][20] = {"RIOT GAMES" ,"MOJANG" ,"STEAM" ,"EPIC GAMES" ,"UBISOFT" ,"EA SPORTS" ,"NINTENDO" ,"CAPCOM" };

		if ( (FP = fopen ("MERCADERIA","wb")) == NULL ) {
				printf("\n\n ERROR APERTURA DE ARCHIVO \n\n") ;
				exit(1);
		};
        if ( (FP2 = fopen ("AUMENTOS","wb")) == NULL ) {
                printf("\n\n ERROR APERTURA DE ARCHIVO \n\n") ;
                exit(1);
		};


		for(I = 0 ; I<N ; I++) {
            strcpy(X.JUEGO, JUEGOS[I]);
            X.PRECIO = (float)(1000+rand()%9999)/10;
            strcpy(X.PROVEEDOR, PROVEEDORES[rand()%M]);
            fwrite ( &X , sizeof(X) , 1 , FP );
		}

        for(I= 0 ; I<M ; I++){
            strcpy(Y.PROVEEDOR, PROVEEDORES[I]);
            Y.PORCENTAJE = (float)(rand()%1000)/10;
            fwrite ( &Y , sizeof(Y) , 1 , FP2 );

		}

		fclose(FP);
		fclose(FP2);




		//ORDENAMIENTO

        if ( (FP = fopen ("AUMENTOS","r+b")) == NULL ) {
            printf("\n\n ERROR APERTURA DE ARCHIVO \n\n") ;
            exit(1);
		};


        fseek(FP, 0L, SEEK_END);
        CANT = ftell(FP)/sizeof(struct INCREMENTO);
		printf("\n\n\t\tCantidad de datos: %d", CANT);


    for(I=0; I<CANT-1; I++)
        for(J=0; J<CANT-I-1; J++)
        {

            fseek(FP,(long)(J*sizeof(A)),SEEK_SET);


            fread(&A,sizeof(A),1,FP);

            fread(&B,sizeof(A),1,FP);

            if(strcmp(A.PROVEEDOR, B.PROVEEDOR)> 0 )
            {

                fseek(FP,(long)(J*sizeof(A)),SEEK_SET);

                fwrite(&B, sizeof(B), 1 ,FP);

                fwrite(&A ,sizeof(A) ,1 ,FP);
            }

        }

		fclose(FP);
}
