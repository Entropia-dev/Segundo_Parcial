#include <iostream>
#include <cstring>
#include <stdio.h>
#include <time.h>
#include <cstdlib>

using namespace std;


#include "fecha.h"
#include "Clases.h"
#include "productos.h"
#include "personas.h"
#include "empleados.h"
#include "clientes.h"
#include "pagos.h"
#include "ventas.h"
#include "back_up.h"




#include "MenuPrincipal.h"

#include <locale.h>

void inicializar_archivos()
{
    FILE *p;
    p=fopen("inicio.dat","rb");

    if(p==NULL)
    {
        FILE *a=fopen("empleados.dat","ab");
        fclose(a);
        FILE *b=fopen("clientes.dat","ab");
        fclose(b);
        FILE *c=fopen("ventas.dat","ab");
        fclose(c);
        FILE *p=fopen("inicio.dat","ab");
        fclose(p);
        FILE *k=fopen("productos.dat","ab");
        fclose(k);
        FILE *g=fopen("detalle_ventas.dat","ab");
        fclose(g);
        FILE *h=fopen("pagos.dat","ab");
        fclose(h);
        return;
    }
    else
    {
        return;
    }

}

int main()
{

    system("COLOR 5f");
    setlocale(LC_ALL, "spanish");
    inicializar_archivos();
    Menu_Principal();
    return 0;
}

///en "pagos.h" se encuentran dos funciones que faltan terminar.
///falta darle alguna funcionalidad a los empleados

/*int strLen(char *Cad)
{
    int T =0;
    while(Cad[T]!='\0')
    {
        T++;
    }
    return T;
}
int strToIntAll(char *Cad)
{
    int x=(strLen(Cad)-1), NE=0, M=1;
    while(x!=-1)
    {
        if(Cad[x]>=48 && Cad[x]<=57)
        {
            NE+=((Cad[x]-48)*M);
            x--;
            M*=10;
        }
        else
        {
            NE+=Cad[x]*M;
            x--;
            M*=10;
        }
    }
    return NE;
}*/
