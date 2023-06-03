//                                              MODELO DE "MUSEO"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<iostream>
using namespace std;

class VISITANTE{
	public:
			char NOM [20];
			VISITANTE * SIG;
			VISITANTE(char *);
};

VISITANTE::VISITANTE(char * V)
{
    strcpy(NOM, V);
    SIG = NULL;
}

class MUSEO{
	public:
			char NOM [20];
			VISITANTE * PVIS;
			MUSEO * SIG;
			MUSEO(char *);
};

MUSEO::MUSEO(char * N)
{
    strcpy(NOM,N);

    PVIS = NULL;
    SIG = NULL;
}

class REGISTROVISITAS{	//GUIRNALDA
    public:
            MUSEO * INICIO;
            void NUEVOMUSEO(char *);
            void MIRAR();
            REGISTROVISITAS();
            void REGISTRARVISITA(char *, char *);
            void VER_VISITANTES_PERFECTOS();
            void BORRAR_MUSEOS_MENOS_VISITADOS();
};

REGISTROVISITAS::REGISTROVISITAS()
{
    INICIO = NULL;
}

void REGISTROVISITAS::NUEVOMUSEO(char * N)
{
    MUSEO * NM; //Nuevo Museo
    NM = new MUSEO(N);

    NM->SIG = INICIO;
    INICIO = NM;
}

void REGISTROVISITAS::REGISTRARVISITA(char * M, char * V) //PUNTO B)
{
    MUSEO * MUS;
    VISITANTE * NV;

    MUS = INICIO;
    while(MUS){
          if(! strcmp(MUS->NOM,M)){
             NV = new VISITANTE(V);

             NV->SIG = MUS->PVIS;
             MUS->PVIS = NV;
           }
       MUS = MUS->SIG;
    }
}

void REGISTROVISITAS::VER_VISITANTES_PERFECTOS()
{
MUSEO * MUS, *AUX_MUS;
VISITANTE * VIS, *AUX_VIS;

int CONT_V = 1, CANT_M = 0, FLAG = 0;
char VISIT_P[20];

MUS = INICIO;

while(MUS){
    CANT_M++;
    MUS = MUS->SIG;
}

MUS = INICIO;

while(MUS){
    VIS = MUS->PVIS;
    while(VIS){
        AUX_MUS = MUS->SIG;
        while(AUX_MUS && FLAG == 0){
            AUX_VIS = MUS->PVIS;
            while(AUX_VIS){
                if(!strcmp(AUX_VIS->NOM, VIS->NOM)){
                    CONT_V++;
                    cout << "A";

                }

                AUX_VIS = AUX_VIS->SIG;
            }

            AUX_MUS = AUX_MUS->SIG;
        }


        if(CONT_V == CANT_M)
            strcpy(VISIT_P, VIS->NOM);
        else
            CONT_V =1 ;

        VIS = VIS->SIG;
    }
    FLAG = 1;
    MUS = MUS->SIG;
}


cout << "\n\n\nEL VISITANTE PERFECTO ES " << VISIT_P;


}

void REGISTROVISITAS::BORRAR_MUSEOS_MENOS_VISITADOS()
{






}

void REGISTROVISITAS::MIRAR()
{
    VISITANTE * VIS;
    MUSEO * MUS;

    MUS = INICIO;
    while(MUS){
            cout << "\n\n\n\n\t MUSEO: ";
            cout << "\n\t\t " << MUS->NOM;
            VIS = MUS->PVIS;
                while(VIS){
                        cout << "\n\t\t\t " << VIS->NOM;
                VIS = VIS->SIG;
            }
        MUS = MUS->SIG;
    }
}

int main()
{
    REGISTROVISITAS * LISTA = new REGISTROVISITAS;

	LISTA->NUEVOMUSEO("MALBA");
	LISTA->NUEVOMUSEO("MUSEO HISTORICO NAC.");
	LISTA->NUEVOMUSEO("MUSEO DE CS. NATURALES");

	//LISTA->MIRAR();

	LISTA->REGISTRARVISITA("MALBA", "PEPE");
    LISTA->REGISTRARVISITA("MUSEO HISTORICO NAC.", "PEPE");
	LISTA->REGISTRARVISITA("MALBA", "MARIA ALVAREZ");
	LISTA->REGISTRARVISITA("MUSEO DE CS. NATURALES", "PEPE");
	LISTA->REGISTRARVISITA("MUSEO DE CS. NATURALES", "ROBERTO SANCHEZ");

	LISTA->MIRAR();

	LISTA->VER_VISITANTES_PERFECTOS();
	LISTA->BORRAR_MUSEOS_MENOS_VISITADOS(); //borra el historico nacional

	//LISTA->MIRAR();

    cout << "\n\n\n";
    system("pause");
}
