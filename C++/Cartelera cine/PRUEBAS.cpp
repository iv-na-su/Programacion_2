#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>

using namespace std ;


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
		char NOM [20];
		GENERO * SIG;
		PELICULA * PRIMER_PELICULA;
        float PROMEDIO_VALORACION(  );
};


class CARTELERA {
	private:
		GENERO * INICIO;
		GENERO * BUSCAR(char *);
	public:
	    CARTELERA();
	    void ACOMODAR(char *);
		void MEJOR_GENERO( );
		void MOSTRAR_PELICULA_DE(   char   * );
};



PELICULA::PELICULA(char * P){
char * GENERA_NOM_D();


strcpy(NOM, P);
strcpy(DIRECTOR, GENERA_NOM_D());
VALORACION = (float)(rand()%100) / 10;
SIG = NULL;
}

CARTELERA::CARTELERA(){

INICIO = NULL;

}

void CARTELERA::ACOMODAR(char * P){

char * GENERA_NOM_G();

char BUF[20];

PELICULA *P_PEL;
GENERO *P_GEN;

P_PEL = new PELICULA(P);

strcpy(BUF, GENERA_NOM_G());

//P_GEN = BUSCAR(BUF);




}

/*
GENERO * CARTELERA::BUSCAR(char * S){






}
*/

char * GENERA_NOM_P();
char * GENERA_NOM_D();

int main(){

CARTELERA C;

srand(11);

char NOM_P[20];


strcpy(NOM_P, GENERA_NOM_P());


while (strcmp(NOM_P, "FIN")){

    C.ACOMODAR(NOM_P);


    strcpy(NOM_P, GENERA_NOM_P());

}





}

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

