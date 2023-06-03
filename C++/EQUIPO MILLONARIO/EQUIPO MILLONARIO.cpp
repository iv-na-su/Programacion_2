/*
a)  Dibujar la estructura descripta, con sus enlaces y nombres de campos y clases de nodos.
b)	Construir la función void MILLONARIO( CAMPEONATO & ) que muestre en pantalla cual es el equipo que más gasta
mensualmente en sueldos de jugadores y cuál es ese monto.
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<iostream>
using namespace std;

class SUELDO{
    public:
        char NOM[20];
        int Sueldo;
        SUELDO * SIG;
        SUELDO(char *, int);
};

SUELDO::SUELDO(char * N, int S)
{
    strcpy(NOM,N);
    Sueldo = S;
    SIG = NULL;
}

class JUGADOR{
        public:
            char NOM[20];
            JUGADOR * SIG;
            JUGADOR(char *);
};

JUGADOR::JUGADOR(char * N)
{
    strcpy(NOM,N);
    SIG = NULL;
}

class EQUIPO{
        public:
            char NOM[20];
            JUGADOR * PUNJU; //Puntero a Inicio
            EQUIPO * SIG;
            EQUIPO(char *);
};

EQUIPO::EQUIPO(char * E)
{
    strcpy(NOM,E);
    PUNJU = NULL;
    SIG = NULL;
}

class CAMPEONATO{
        private:
            SUELDO * INISUELDO;
            EQUIPO * INIEQUIPO;
        public:
            CAMPEONATO();
            void friend MILLONARIO(CAMPEONATO & C);
            void AGREGAREQUIPO(char *);
            void AGREGARJUGADOR(char *, char *);
            void AGREGARSUELDO(char *, int);
            void MIRAR();
};

CAMPEONATO::CAMPEONATO(){

INISUELDO = NULL;
INIEQUIPO = NULL;

}

void CAMPEONATO::AGREGAREQUIPO(char * E)
{
    EQUIPO * EQPNUEVO;
    EQPNUEVO = new EQUIPO(E);

    EQPNUEVO->SIG = INIEQUIPO;
    INIEQUIPO = EQPNUEVO;
}

void CAMPEONATO::AGREGARJUGADOR(char * E, char * J)
{
    EQUIPO * EQP;
    JUGADOR * JUG;
    EQP = INIEQUIPO;
    JUG = EQP->PUNJU;

    while(EQP){
          if(! strcmp(EQP->NOM,E)){
             JUG = new JUGADOR(J);

             JUG->SIG = EQP->PUNJU;
             EQP->PUNJU = JUG;
          }
      EQP = EQP->SIG;
    }
}

void CAMPEONATO::AGREGARSUELDO(char * N, int S)
{
    EQUIPO * EQUI;
    JUGADOR * JUG;
    SUELDO * NS;

    EQUI = INIEQUIPO;
    while(EQUI){
            JUG = EQUI->PUNJU;
            while(JUG){
          if(! strcmp(JUG->NOM, N)){
             NS = new SUELDO(N,S);

             NS->SIG = INISUELDO;
             INISUELDO = NS;
          }
          JUG = JUG->SIG;
            }
          EQUI = EQUI->SIG;

    }
}

void CAMPEONATO::MIRAR()
{
    EQUIPO * EQIP;
    JUGADOR * JUG;
    SUELDO * SU;

    EQIP = INIEQUIPO;
    while(EQIP){
            cout << "\n\tEQUIPO: ";
            cout << "\n\t\t " << EQIP->NOM;
            JUG = EQIP->PUNJU;
            while(JUG){
                  cout << "\n\t\t\t " << JUG->NOM;
           JUG = JUG->SIG;
         }
    EQIP = EQIP->SIG;
  }
}

void MILLONARIO(CAMPEONATO &);

int main()
{
    CAMPEONATO CAMP;
    CAMP.AGREGAREQUIPO("BOCA");
    CAMP.AGREGAREQUIPO("RIVER");
    CAMP.AGREGAREQUIPO("SAN LORENZO");
    CAMP.AGREGAREQUIPO("RACING");

    CAMP.AGREGARJUGADOR("RACING", "JONATHAN");
    CAMP.AGREGARJUGADOR("RACING", "SPEEDWAGOON");
    CAMP.AGREGARJUGADOR("RACING", "ZEPELLI");
    CAMP.AGREGARJUGADOR("RACING", "DIO");
    CAMP.AGREGARJUGADOR("RIVER", "JOSEPH");
    CAMP.AGREGARJUGADOR("RIVER", "CAESAR");
    CAMP.AGREGARJUGADOR("RIVER", "LISA LISA");
    CAMP.AGREGARJUGADOR("RIVER", "STROHEIM");
    CAMP.AGREGARJUGADOR("SAN LORENZO", "JOTARO");
    CAMP.AGREGARJUGADOR("SAN LORENZO", "KAKOYIN");
    CAMP.AGREGARJUGADOR("SAN LORENZO", "POLNAREFF");
    CAMP.AGREGARJUGADOR("SAN LORENZO", "IGGY");
    CAMP.AGREGARJUGADOR("BOCA", "JOSUKE");
    CAMP.AGREGARJUGADOR("BOCA", "KOICHI");
    CAMP.AGREGARJUGADOR("BOCA", "ROHAN");
    CAMP.AGREGARJUGADOR("BOCA", "YUKAKO");

    CAMP.AGREGARSUELDO("JONATHAN", 1300);
    CAMP.AGREGARSUELDO("SPEEDWAGOON", 1200);
    CAMP.AGREGARSUELDO("ZEPELLI", 1290);
    CAMP.AGREGARSUELDO("DIO", 2390);
    CAMP.AGREGARSUELDO("JOSEPH", 1284);
    CAMP.AGREGARSUELDO("CAESAR", 3983);
    CAMP.AGREGARSUELDO("LISA LISA", 1200);
    CAMP.AGREGARSUELDO("STROHEIM", 1300);
    CAMP.AGREGARSUELDO("JOTARO", 1500);
    CAMP.AGREGARSUELDO("KAKOYIN", 4000);
    CAMP.AGREGARSUELDO("POLNAREFF", 2000);
    CAMP.AGREGARSUELDO("IGGY", 300);
    CAMP.AGREGARSUELDO("JOSUKE", 10000);
    CAMP.AGREGARSUELDO("KOICHI", 10000);
    CAMP.AGREGARSUELDO("ROHAN", 20000);
    CAMP.AGREGARSUELDO("YUKAKO", 50000);

    CAMP.MIRAR();


    MILLONARIO(CAMP);
    cout << "\n\n\n";
    system("pause");
}

void MILLONARIO(CAMPEONATO & C)
{
    EQUIPO * EQIP;
    SUELDO * SUEL;
    JUGADOR * JUG;
    int ACUM = 0 , MAX = 0;
    char EQUIPO_MAX[20];

    EQIP = C.INIEQUIPO;
    while(EQIP){
            ACUM = 0;
          JUG = EQIP->PUNJU;
          while(JUG){
                SUEL = C.INISUELDO;
                while(SUEL){
                      if(! strcmp(JUG->NOM,SUEL->NOM)){
                         ACUM = ACUM + SUEL->Sueldo;
                      }
                      SUEL = SUEL->SIG;
                    }
                JUG = JUG->SIG;
              }

            if (ACUM > MAX){
                MAX = ACUM;
                strcpy(EQUIPO_MAX , EQIP->NOM);

            }
      EQIP = EQIP->SIG;

    }
  cout << "\n\n\t\t EL EQUIPO MAS CARO ES: " << EQUIPO_MAX << " CON UN TOTAL DE $"<< MAX;
}
