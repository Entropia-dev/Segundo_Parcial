#include <iostream>
#include <cstring>
#include <stdio.h>
#include <time.h>
#include <cstdlib>
using namespace std;

#include "fecha.h"
#include "productos.h"
#include "ventas.h"
#include "personas.h"
#include "empleados.h"
#include "clientes.h"
#include "pagos.h"
#include "detalle_venta.h"
#include "detalle_venta.h"
#include "Menues.h"



/**

    POR HACER EN EL TP:
    -EMPROLIJAR LOS MENUES PRINCIPALES. (TAMBIEN DEJARLOS FUNCIONALES ALMENOS SIN FUNCIONES)
    -REALIZAR LOS METODOS DE GUARDAR DE TODAS LAS CLASES.
    -REALIZAR LOS METODOS DE CARGAR DE TODAS LAS CLASES.
    -REALIZAR LOS METODOS DE MOSTRAR DE TODAS LAS CLASES.

      || PARA EL PROTOTIPO SE NECESITA EL ABML AL MENOS SIN NINGUNA VALIDACION  ||


	el trabajo terminado es la nota del segundo parcial

	paso 1 definir grupo y tema -----------------------------------------TERMINADO

	Paso 2 presentacion del informe (INFORME APROVADO)----------------------TERMINADO
	hay dos tipos 1 para un sistema de gestion y otro para un juego en el campus

	cuando traemos el prototipo tenemos que traer el informe.   ------------- EL LUNES 1/11 SE NECESITA EL PROTOTIPO

	para la entrega del prototipo se necesita el informe aprobado
	si llega el 22 de noviemre y no tenes el prototipo aprobado ,

	o el programa terminado no se consigue y se terminaron estan las mesas de final

	en las mesas de final se puede venir con el prototipo o con el programa terminado

	se viene a las 8 am y despues de que los compañeros rindan se ve lo que trajiste para corregir.

	recuperatorios del primero va a haber uno en noviempre y uno en febrero.

	en el final lo que van a tomar es el programa terminado del segundo parcial con alguna mejora en el medio.4

	que se solicita en la revision del programa.

	el final y la presentacion del programa terminado es individual

	se le hacen preguntas al grupo con respecto a el trabajo final terminado, una vez que esta completo.



	====================================================

      //////////////////////////////////  ejemplo de clase: /////////////////////////////////////////////////

        class Articulo{
        private:
        char codArticulo[5];
        char descripcion[30];
        float pu;
        int stock;
        public:
        void Cargar(void);
        void Mostrar(void);
        };

                void Articulo::Cargar(){
        cout<<”INGRESE EL CODIGO: “;
        cin>>codArt;
        cout<<”INGRESE LA DESCRIPCION: ”;
        cin>>descripcion;
        cout<<”INGRESE EL PRECIO UNITARIO: “;
        cin>>pu;
        cout<<”INGRESE EL STOCK”;
        cin>>stock;
        }
        void Articulo::Mostrar(){
        cout<<” CODIGO: “;
        cout<<codArt<<endl;
        cout<<” DESCRIPCION: ”;
        cout<<descripcion<<endl;
        cout<<” PRECIO UNITARIO: “;
        cout<<pu<<endl;
        cout<<” STOCK”;
        cout<<stock<<endl;
        }
        ===========================================================
**/


#include <iostream>
#include <cstring>
#include <stdio.h>
#include <time.h>
#include <cstdlib>

using namespace std;

#include "fecha.h"
#include "VENTAS.h"
#include "PAGOS.h"
#include "PRODUCTOS.h"
#include "CLIENTES.h"
#include "EMPLEADOS.h"
#include "DETALLE_VENTA.h"
#include "PERSONAS.h"
#include "Menues.h"


/**
    POR HACER EN EL TP:
    -EMPROLIJAR LOS MENUES PRINCIPALES. (TAMBIEN DEJARLOS FUNCIONALES ALMENOS SIN FUNCIONES)---TERMINADO
    -REALIZAR LOS METODOS DE GUARDAR DE TODAS LAS CLASES. --- TERMINADO
    -REALIZAR LOS METODOS DE CARGAR DE TODAS LAS CLASES.    --- TERMINADO
    -REALIZAR LOS METODOS DE MOSTRAR DE TODAS LAS CLASES.       --- TERMINADO
    -IR COMPLETANDO LAS FUNCIONES DE LOS MENUES PRINCIPALES.
        EMPLEADOS -----SIN EMPEZAR
        CLIENTES  -----SIN EMPEZAR
        VENTAS -----SIN EMPEZAR
        PAGOS -----SIN EMPEZAR
        PRODUCTOS -----SIN EMPEZAR
      || PARA EL PROTOTIPO SE NECESITA EL ABML AL MENOS SIN NINGUNA VALIDACION  ||
	el trabajo terminado es la nota del segundo parcial
	paso 1 definir grupo y tema -----------------------------------------TERMINADO
	Paso 2 presentacion del informe (INFORME APROBADO)----------------------TERMINADO
	hay dos tipos 1 para un sistema de gestion y otro para un juego en el campus
	cuando traemos el prototipo tenemos que traer el informe.   ------------- EL VIERNES 1/11 SE NECESITA EL PROTOTIPO
	para la entrega del prototipo se necesita el informe aprobado
	si llega el 22 de noviemre y no tenes el prototipo aprobado ,
	o el programa terminado no se consigue y se terminaron estan las mesas de final
	en las mesas de final se puede venir con el prototipo o con el programa terminado
	se viene a las 8 am y despues de que los compañeros rindan se ve lo que trajiste para corregir.
	recuperatorios del primero va a haber uno en noviempre y uno en febrero.
	en el final lo que van a tomar es el programa terminado del segundo parcial con alguna mejora en el medio.4
	que se solicita en la revision del programa.
	el final y la presentacion del programa terminado es individual
	se le hacen preguntas al grupo con respecto a el trabajo final terminado, una vez que esta completo.
	====================================================
      //////////////////////////////////  ejemplo de clase: /////////////////////////////////////////////////
        class Articulo{
        private:
        char codArticulo[5];
        char descripcion[30];
        float pu;
        int stock;
        public:
        void Cargar(void);
        void Mostrar(void);
        };
                void Articulo::Cargar(){
        cout<<”INGRESE EL CODIGO: “;
        cin>>codArt;
        cout<<”INGRESE LA DESCRIPCION: ”;
        cin>>descripcion;
        cout<<”INGRESE EL PRECIO UNITARIO: “;
        cin>>pu;
        cout<<”INGRESE EL STOCK”;
        cin>>stock;
        }
        void Articulo::Mostrar(){
        cout<<” CODIGO: “;
        cout<<codArt<<endl;
        cout<<” DESCRIPCION: ”;
        cout<<descripcion<<endl;
        cout<<” PRECIO UNITARIO: “;
        cout<<pu<<endl;
        cout<<” STOCK”;
        cout<<stock<<endl;
        }
        ===========================================================
**/

void inicializar_archivos()
{
    FILE *p;
    p=fopen("inicio.dat","rb");

    if(p==NULL)
    {
        FILE *a=fopen("empleados.dat","ab");
        fclose(a);
   //     FILE *b=fopen("clientes.dat","ab");
    //    fclose(b);
     //   FILE *c=fopen("ventas.dat","ab");
      //  fclose(c);
        FILE *p=fopen("inicio.dat","ab");
        fclose(p);
        return;
    }
    else
    {
        return;
    }

}


int main()
{
    inicializar_archivos();
    menu_principal();
    return 0;
}

/*
int anio = 1000;
    int mes = 1 ;
    int dia = 1;
    cliente cli;
    venta v;
    Fecha Nueva_fecha;
   /// se carga un objeto de tipo fecha para enviarlo y que sea el objeto de la clase venta
    Nueva_fecha.setAnio(anio);
    Nueva_fecha.setDia(dia);
    Nueva_fecha.setMes(mes);
    /// seteo la fecha de venta mediante el objeto previamente cargado
    v.setFecha_venta(Nueva_fecha);
      ///obtengo el dia de la fecha de venta
        cout<<v.getFecha().getDia();
*/
