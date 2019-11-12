#include <iostream>
#include <cstring>
#include <stdio.h>
#include <time.h>
#include <cstdlib>

using namespace std;

#include "fecha.h"
#include "productos.h"

#include "personas.h"
#include "empleados.h"
#include "clientes.h"
#include "pagos.h"

#include "ventas.h"
#include "MenuPrincipal.h"

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
        return;
    }
    else
    {
        return;
    }

}

///EL MENU DE CLIENTES QUEDO PROBADO Y FUNCIONAL    TIENE LOS FLAGS DE EMPLEADOS NO ENCONTRADOS EN ELIMINAR/RESTAURAR
///EL MENU DE EMPLEADOS QUEDO PROBADO Y FUNCIONAL   TIENE LOS FLAGS DE EMPLEADOS NO ENCONTRADOS EN ELIMINAR/RESTAURAR
///EL MENU DE PRODUCTOS QUEDO PROBADO Y FUNCIONAL
///EL MENU DE VENTAS QUEDO PROBADO Y FUNCIONAL

int main()
{
    inicializar_archivos();
    Menu_Principal();
    return 0;
}
