#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>

using namespace std ;

                                                                            //CLASES


class PELICULA {
	public:
	    PELICULA (char *);
		char NOM[20];
		char DIRECTOR[20];
		float VALORACION;
		PELICULA * SIG;
};


class GENERO {
	public:
	    GENERO(char* , PELICULA*);
		char NOM [20];
		GENERO * SIG;
		PELICULA * PRIMER_PELICULA;
        float PROMEDIO_VALORACION();
};


class CARTELERA {
    private:
    GENERO * INICIO;

	public:

        GENERO * BUSCAR(char *);
	    CARTELERA();
	    void ACOMODAR(char *);
		void MEJOR_GENERO( );
		void MOSTRAR_PELICULA_DE(   char   * );
		void MIRAR();
};






                                                            //CONSTRUCTORES DE CLASES





GENERO::GENERO(char* S, PELICULA* PRIM){

strcpy(NOM, S);
PRIMER_PELICULA = PRIM;


}

PELICULA::PELICULA(char * P){
char * GENERA_NOM_D();


strcpy(NOM, P);
strcpy(DIRECTOR, GENERA_NOM_D());
VALORACION = (float)(rand()%1000) / 100;
SIG = NULL;
}

CARTELERA::CARTELERA(){

INICIO = NULL;

}


                                                                //FUNCIONES NECESARIAS DE LAS CLASES



void CARTELERA::ACOMODAR(char * P){

char * GENERA_NOM_G();

char BUF[20];

PELICULA *P_PEL, *PUN;
GENERO *P_GEN;

P_PEL = new PELICULA(P);

strcpy(BUF, GENERA_NOM_G());

P_GEN = BUSCAR(BUF);


if (!P_GEN){
    /*GENERO NUEVO*/
    P_GEN = new GENERO(BUF, P_PEL);

    P_GEN->SIG = INICIO;
    INICIO = P_GEN;
    return;
}
/*GENERO EXISTENTE*/

PUN= P_GEN->PRIMER_PELICULA;

while(PUN->SIG)
    PUN = PUN->SIG;

PUN->SIG = P_PEL;


}


GENERO * CARTELERA::BUSCAR(char * S){

GENERO * P_GEN;

P_GEN = INICIO;

while (P_GEN){

    if(! strcmp(P_GEN->NOM, S))// =    if( strcmp(P_GEN->NOM, S)==0)
        return P_GEN;

    P_GEN = P_GEN->SIG;



}

return NULL;

}




void CARTELERA::MIRAR(){

PELICULA *P_PEL;
GENERO *P_GEN;

cout << "\n\n\t\tCONTENIDO DE LA CARTELERA:";

P_GEN = INICIO;

while(P_GEN){

    cout << "\n\n\n\n\n\t\t\tGENERO: " << P_GEN->NOM << "\n\n\n\n";

    P_PEL = P_GEN->PRIMER_PELICULA;
    printf("%-20s %-20s %-20s\n\n", "NOMBRE", "DIRECTOR", "VALORACION");

    while(P_PEL){

        printf("\n%-20s %-20s %-20.2f", P_PEL->NOM, P_PEL->DIRECTOR, P_PEL->VALORACION);

        P_PEL = P_PEL->SIG;



    }
    //getchar();
    P_GEN = P_GEN->SIG;


}


}

                                                                            //PUNTOS DE TAREA


float GENERO::PROMEDIO_VALORACION(){//PUNTO A

    PELICULA * PELI;
    float ACUM = 0, CONT = 0;

    PELI = PRIMER_PELICULA;
    while(PELI){
        ACUM = ACUM + PELI->VALORACION;

        PELI = PELI->SIG;
        CONT++;
    }
    ACUM = ACUM / CONT;
    return ACUM;


}


void CARTELERA::MEJOR_GENERO(){//PUNTO B

    GENERO * G;
    PELICULA * P;

    float MAYOR = 0, ACTUAL, CONT;
    char NOM[20];



    G = INICIO;

    while(G){
        ACTUAL = 0;
        CONT = 0;
        P = G->PRIMER_PELICULA;
        while(P){
            ACTUAL = ACTUAL + P->VALORACION;
            CONT++;
            P = P->SIG;
        }
        ACTUAL = ACTUAL/CONT;
        if(ACTUAL > MAYOR){
            MAYOR = ACTUAL;
            strcpy(NOM, G->NOM);
        }
        G = G->SIG;

    }

    cout << "\n\nEL GENERO CON MEJOR PROMEDIO ES " << NOM << " CON UNA VALORACION DE " << MAYOR;


}


void CARTELERA::MOSTRAR_PELICULA_DE(char * NOM_DIR){//PUNTO C

    GENERO * G ;
    PELICULA * P1, * P2;

    float PROM, CONT;


    G = INICIO;
    cout << "\n\nPELICULAS DE " << NOM_DIR << "\n\n";
    printf("\n\t\t%-20s %-20s %-20s\n\n", "NOMBRE", "VALORACION", "GENERO");

    while(G){
        P1 = G->PRIMER_PELICULA;
        while(P1){
            if(! strcmp(P1->DIRECTOR, NOM_DIR)){
                PROM= 0;
                CONT = 0;
                P2 = G->PRIMER_PELICULA;
                while(P2){
                    PROM = PROM + P2->VALORACION;
                    CONT++;
                    P2 = P2->SIG;

                }
                PROM = PROM/CONT;
                printf("\n\t\t%-20s %-20.2f %-20s", P1->NOM, P1->VALORACION, G->NOM);

                if(P1->VALORACION > PROM)
                    cout << "\tSUPERA EL PROMEDIO DE SU GENERO\n";
                else
                    cout << "\tNO SUPERA EL PROMEDIO DE SU GENERO\n";



            }
            P1 = P1->SIG;
        }

        G = G->SIG;
    }




}




                                                                                //MAIN




char * GENERA_NOM_P();

int main(){

CARTELERA C;


srand(11);

int ACCION = 1;
char NOM_P[20];



strcpy(NOM_P, GENERA_NOM_P());


while (strcmp(NOM_P, "FIN")){

    C.ACOMODAR(NOM_P);


    strcpy(NOM_P, GENERA_NOM_P());

}


C.MIRAR();

while(ACCION != 0){
    cout << "\n\n\n0-> SALIR\t1-> PROMEDIO DEL GENERO A ELECCION\t2-> GENERO CON MAYOR VALORACION EN PROMEDIO\t3-> PELICULAS DEL DIRECTOR A ELECCION\t";
    cout << "\n\t\tQUE QUIERE HACER A CONTINUACION?: ";
    cin >> ACCION;


    if(ACCION == 1){

        char G_ELEGIDO[20];
        float PROMEDIO;

        cout << "\n\nINGRESAR EL GENERO DEL QUE QUIERE SABER EL PROMEDIO: ";
        cin >> G_ELEGIDO;


        PROMEDIO = C.BUSCAR(G_ELEGIDO)->PROMEDIO_VALORACION();
        cout << "\n\nEL PROMEDIO DE LAS PELICULAS DEL GENERO " << G_ELEGIDO << " ES: " << PROMEDIO;
        getchar();


    }

    if(ACCION == 2){

        C.MEJOR_GENERO();

    }

    if(ACCION == 3){

        char NOM_DIR[20];

        cout << "\n\nINGRESAR NOMBRE DEL DIRECTOR QUE DESEA CONOCER SUS PELICULAS: ";
        cin >> NOM_DIR;

        C.MOSTRAR_PELICULA_DE(NOM_DIR);


    }

}




}




                                                                        //GENERADORES AUTOMATICOS




char * GENERA_NOM_P(){

static int I = 0;
static char NOM[][20] = {"LUCY","SCREAM","RAPIDO Y FURIOSO","YOUR NAME","TOC TOC","JACKASS",
                        "FRAGMENTADO","EL PADRINO","DIVERGENTE","HUNGER GAMER","TED","SILENT HILL",
                        "E.T","GUERRA MUNDIAL Z","50 SOMBRAS DE GRAY","DRAGON BALL: BROLY","PROYECTO X",
                        "SHREK","MEGAMENTE","POCAHONTAS","LA QUINTA OLA","ANIQUILACION","NO MIREN ARRIBA",
                        "LOS ILUSIONISTAS","MINIONS","CORRE","CREPUSCULO","YO ANTES DE TI","SON COMO NIÑOS",
                        "MEN IN BLACK","SAW","ESCUADRON 6","CORAZONES DE HIERRO","FRACTURA","HIPNOTICO","MATILDA",
                        "NEMO","FIN"};


return NOM[I++];
}


char * GENERA_NOM_D(){


static char NOM[][20] = {"PEPE","MARTIN","NAHUEL","PEDRO","MARIA","JULIETA","EMA","SANTIAGO","VANESA","AILEN",
                        "AGUSTINA","RICARDO","JULIAN","MENEM","JORGE","FIDEL"};


return NOM[rand()%16];
}



char * GENERA_NOM_G(){


static char NOM[][20] = {"TERROR","COMEDIA","ROMANCE","SUSPENSO","ACCION","FANTASIA","DOCUMENTAL","MUSICAL","AVENTURAS","CIENCIA FICCION"};


return NOM[rand()%10];
}
