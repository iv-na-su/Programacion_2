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
    VISITANTE * VIS, * AUX_VIS;
    MUSEO * MUS;
    int CONT = 0, MAX = 0;

    MUS = INICIO;
    while(MUS){
          VIS = MUS->PVIS;
          if(VIS){
             CONT++;
             VIS = VIS->SIG;
          }
          if(MAX == 0){
             MAX = CONT;
          }
          if(CONT >= MAX){
             MAX = CONT;
             AUX_VIS = VIS;
          }
      MUS = MUS->SIG;
    }
    cout << "\n\n\t\t EL VISITANTE PERFECTO ES: " << AUX_VIS->NOM;
}

void REGISTROVISITAS::BORRAR_MUSEOS_MENOS_VISITADOS()
{
    VISITANTE * VIS;
    MUSEO * MUS, * AUX;
    int CONT = 0, MIN = 0;

    MUS = INICIO;
    while(MUS){
            CONT = 0;
            VIS = MUS->PVIS;
            while(VIS){
                CONT++;
                VIS = VIS->SIG;
            }
            if(MIN == 0){
                MIN = CONT;
            }
            if(CONT < MIN){
                MIN = CONT;
                cout << "\n\n\t\t ELIMINANDO AL MUSEO: " << MUS->NOM;
                getchar();
                VIS = MUS->PVIS;
                while(VIS){
                      MUS->PVIS = VIS->SIG;
                            delete(VIS);
                      VIS = MUS->PVIS;
                    }
                AUX = INICIO;
                while(AUX->SIG != MUS){
                        AUX = AUX->SIG;
                }
                AUX->SIG = MUS->SIG;
                delete(MUS);
           }
       MUS = MUS->SIG;
    }
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
    LISTA->REGISTRARVISITA("MUSEO HISTORICO NAC.", "MARIA ALVAREZ");
	LISTA->REGISTRARVISITA("MALBA", "MARIA ALVAREZ");
	LISTA->REGISTRARVISITA("MUSEO DE CS. NATURALES", "MARIA ALVAREZ");
	LISTA->REGISTRARVISITA("MUSEO DE CS. NATURALES", "ROBERTO SANCHEZ");

	LISTA->MIRAR();

	LISTA->VER_VISITANTES_PERFECTOS();
	LISTA->BORRAR_MUSEOS_MENOS_VISITADOS(); //borra el historico nacional

	LISTA->MIRAR();

    cout << "\n\n\n";
    system("pause");
}
