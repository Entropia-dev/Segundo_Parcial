#include <iostream>
#include <cstring>
#include <stdio.h>
#include <time.h>
#include <cstdlib>
using namespace std;

#include "fecha.h"
#include "clases.h"
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


int main()
{
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
       char opc[20],opcventas[20],opcclientes[20];
     int opswitch,OPCVENTAS,OPCCLIENTES;
     int pos=0,NUMVMODIF;
     bool salir=false;

        MenuPrincipal();
        cout<<"INGRESE UNA OPCION: ";
        cin.getline(opc,20);
     opswitch=strToIntAll(opc);
     while(!salir)
     {
         switch(opswitch)
         {
           case 1:{ menuVentas();
           cout<<"INGRESE UNA OPCION: ";
           cin.getline(opcventas,20);
           OPCVENTAS=strToIntAll(opcventas);
           switch(OPCVENTAS)
           {
              case 1: {
                 // v.cargar();
                  cin.get();
                      }break;
              case 2: {
             // v.mostrar();
              cin.get();
                      }break;
              case 3: {
                  cout<<"Ingrese el numero de la venta a modificar: ";
                  cin>>NUMVMODIF;
              //actualizarSaldo(NUMVMODIF);
              }break;
              case 4:{
              //ModificarVenta();
              }break;
        default: cout<<"OPCION INCORRECTA";
        //Sleep(1000);
           }//cierra case 1
         case 2:{
           menuClientes();
           cout<<"INGRESE UNA OPCION: ";
           cin.getline(opcclientes,20);
           OPCCLIENTES=strToIntAll(opcclientes);
           switch(OPCCLIENTES)
           {
             case 1: {
             //cli.cargar();
             //cli.mostrar();
            cin.get();
            }break;

           }
         case 3:
            {
               // menuModelos();
                cin.get();
            }break;
         case 0:{
         salir=true;
         exit(1);
         }break;
        default: cout<<"OPCION INCORRECTA";
        //Sleep(1000);
        }
        }//cierra switch principal
     MenuPrincipal();
     cout<<"INGRESE UNA OPCION: ";
     cin.getline(opc,20);
     }//cierra while
     }

    return 0;
//cierra main
}

