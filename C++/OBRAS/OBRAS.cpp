#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>

using namespace std;

class MATERIAL
{
  public:
        char NOM[20];
        int PRECIO;
        int CANTIDAD;
        MATERIAL * SIG;
        MATERIAL(char *);
};

MATERIAL::MATERIAL(char * N)
{
    strcpy(NOM,N);
    PRECIO = 5000+rand()%5000;
    CANTIDAD = 1 + rand()%10;
    SIG = NULL;

}

class ACCION
{
  public:
        char DESCRIPCION[20];
        int PRECIO;
        int CANTIDAD;
        ACCION * SIG;
        ACCION(char *);
};

ACCION::ACCION(char * D)
{
    strcpy(DESCRIPCION,D);
    PRECIO = 20000+rand()%20000;
    CANTIDAD = 1 + rand()%5;
    SIG = NULL;

};

class OBRA
{
  public:
        char NOMBRE_OBRA[20];
        MATERIAL * PRIMER_MAT;
        ACCION * PRIMER_ACCION;
        OBRA * SIG;
        OBRA(char * );
        int TOTAL_MAT_GASTADO();
        int TOTAL_ACC_TRABAJADAS();
};

OBRA::OBRA(char * NO)
{
    strcpy(NOMBRE_OBRA,NO);
    PRIMER_MAT = NULL;
    PRIMER_ACCION = NULL;

    int I;
    MATERIAL * M;
    ACCION * A;

    char LISTA_MATERIALES [] [20] = {"CEMENTO", "ARENA", "CAL", "CABLES", "MADERA", "CLAVOS", "CHAPA", "LADRILLOS", "PIEDRA"};

    for (I=rand()%9; I<9; I++)
    {
        M = new MATERIAL(LISTA_MATERIALES[I]);
        M->SIG = PRIMER_MAT;
        PRIMER_MAT = M;
    }

    char LISTA_ACCIONES [] [20] = {"FIJAR PISO", "LEVANTAR PARED", "CONSTRUIR VEREDA", "RELLENAR POZO", "FIJAR VIGA", "RELLENAR BASE", "TENDER CABLE"};
    for (I=rand()%7; I<7; I++)
    {
        A = new ACCION(LISTA_ACCIONES[I]);
        A->SIG = PRIMER_ACCION;
        PRIMER_ACCION = A;
    }


}



class TRABAJO
{
    private:
        OBRA * INICIO;
    public:
        TRABAJO();
        void AGREGAR_OBRA(char *);
        void MIRAR();
        void MAYOR_PROPORCION_GANANCIA();
        //OBRA QUE MAYOR PROPORCION DE MATERIAL USADO TIENE.
        //ESTO SURGE DE HACER (MONTO DE MATERIAL GASTADO*100/GANANCIA DE ACCIONES)
};

TRABAJO::TRABAJO()
{
    INICIO = NULL;
}

void TRABAJO::AGREGAR_OBRA(char * NO)
{
    OBRA * O;
    O = new OBRA(NO);

    O->SIG = INICIO;
    INICIO = O;
}

void TRABAJO::MIRAR()
{
    OBRA * O;
    MATERIAL * M;
    ACCION * A;

    O = INICIO;
    while(O)
    {
        cout<<"\n\n\n\n\t\t\t\tOBRA: "<<O->NOMBRE_OBRA;
        cout<<"\n\n\n\t\tMATERIALES USADOS:\n";
        M = O->PRIMER_MAT;
        while(M)
        {
            cout<<"\n\t\t\tNOMBRE:    "<<M->NOM<<"  \t\t CANT: "<<M->CANTIDAD<<"\t\t PRECIO: $"<<M->PRECIO;
            M = M->SIG;
        }
        cout<<"\n\n\t\tACCIONES REALIZADAS:\n";
        A = O->PRIMER_ACCION;
        while(A)
        {
            cout<<"\n\t\t\tDESCRIPCION: "<<A->DESCRIPCION<<" \t\t  CANT: "<<A->CANTIDAD<<" \t\tPRECIO: $"<<A->PRECIO;
            A = A->SIG;
        }
        O = O->SIG;
    }
}


int OBRA::TOTAL_MAT_GASTADO(){

MATERIAL * MAT;

int ACUMULADOR= 0;

MAT = PRIMER_MAT;

while(MAT){
    ACUMULADOR = ACUMULADOR + (MAT->CANTIDAD * MAT->PRECIO);
    MAT = MAT->SIG;

}

return ACUMULADOR;
}



int OBRA::TOTAL_ACC_TRABAJADAS(){

ACCION * ACC;

int ACUMULADOR= 0;

ACC = PRIMER_ACCION;

while(ACC){
    ACUMULADOR = ACUMULADOR + (ACC->CANTIDAD * ACC->PRECIO);
    ACC = ACC->SIG;

}




return ACUMULADOR;

}


void TRABAJO::MAYOR_PROPORCION_GANANCIA(){

    OBRA * O;
    MATERIAL * M;
    ACCION * A;

    int MAYOR = 0, ACTUAL;
    char NOM_MAX[20];


    O = INICIO;

    while(O){
        ACTUAL = (O->TOTAL_MAT_GASTADO() * 100) / O->TOTAL_ACC_TRABAJADAS();
        if(ACTUAL>MAYOR ){
            MAYOR = ACTUAL;
            strcpy(NOM_MAX, O->NOMBRE_OBRA);
        }
        O = O->SIG;
    }


cout << "\n\n\n\nLA QUE MAS PROPORCION DE GANANCIA ES " << NOM_MAX << " CON UN TOTAL DE " << MAYOR;

}



int main()
{
    TRABAJO * T;
    int I;
    T = new TRABAJO();
    srand(43);

    char LISTA_OBRAS [] [20] = {"BARRIO AERONAUTICO", "ESCUELA PRIMARIA 7","HOTEL SHERATON", "MUNICIPALIDAD MORON","CASA DE PEPE", "AVENGERS TOWER", "LA BOMBONERA"};
    for (I=0; I<7 ; I++)
        T->AGREGAR_OBRA(LISTA_OBRAS[I]);

    T->MIRAR();

    T->MAYOR_PROPORCION_GANANCIA();
    cout<<"\n\n";
    return 0;
}





