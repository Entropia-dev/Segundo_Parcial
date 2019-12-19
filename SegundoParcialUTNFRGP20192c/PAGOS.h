#ifndef PAGOS_H_INCLUDED
#define PAGOS_H_INCLUDED

#include "ventas.h"

int contar_pagos();
float buscar_total_pagado(int);
bool buscar_id_venta(int id_buscada);
int obtener_forma_pago(int id_venta);
float obtener_importe_venta(int id_venta);
int contar_ventas();


bool pago::leerDeDisco(int pos)
{
    FILE*p=fopen("pagos.dat","rb");
    if(p==NULL)
    {
        cout<<" ERROR DE LECTURA ! "<< endl;
        exit(1);
    }
    fseek(p,sizeof*this*pos,0);
    bool leyo = fread(this,sizeof*this,1,p);
    fclose(p);
    return leyo;
}


int pago::cargar_pago()
{
    system("cls");
    cout<<"=============================MENU PAGOS==============================="<<endl;
    float resto;
    /// cada pago se tendria que generar y guardar en un archivo por ejemplo "pagos.dat"
    /// para que puedas saber si a algun cliente le falta por pagar.

    cout<<"INGRESE LA ID CLIENTE QUE EFECTUA EL PAGO"<<endl;
    cin>>id_cliente;
    if(buscar_id_cliente(id_cliente)==false)
    {
        cout<<"no se encontro la id de cliente , intentelo nuevamente"<<endl;
    }
    if(buscar_estado_cliente(id_cliente)==false)
    {
        cout<<"el cliente se encuenta dado de baja , intentelo nuevamente"<<endl;
        system("pause");
        return -1;
    }
    /// hay que validar que exista  y no este dado de baja.
    id_pago=contar_pagos()+1;
    cout<<"INGRESE ID DE VENTA A PAGAR: "<<endl;
    cin>>id_venta;
    if(buscar_id_venta(id_venta)==false)
    {
        cout<<"no se encontro la venta , intentelo nuevamente"<<endl;    ///para saber cuanto es el total a pagar. falta validar la venta
        system("pause");
        return -1;
    }

    forma_pago = obtener_forma_pago(id_venta);
    if(forma_pago == -1)
    {
        cout<<"error al obtener la forma de pago !";
        system("pause");
        return -1;
    }

    ///========================================================================================================================
    if(obtener_importe_venta(id_venta) - buscar_total_pagado(id_venta)==0)
    {
        cout<<"ESTA VENTA FUE SALDADA POR COMPLETO "<<endl;
        system("pause");
        return -1;
    }
    cout<<"RESTA ABONAR "<<obtener_importe_venta(id_venta) - buscar_total_pagado(id_venta)<<"$"<<endl;
    resto = obtener_importe_venta(id_venta) - buscar_total_pagado(id_venta);
    //cout<<"RESTO: "<<resto<<endl;
    ///========================================================================================================================

    cout<<"TOTAL ABONADO: "<<endl;
    cin>>importe;
    if(importe == 0 )
    {
        cout<<"EL IMPORTE NO PUEDE SER NULO , INTENTELO NUEVAMENTE"<<endl;
        system("pause");
        return -1;
    }
    if(importe < 0)
    {
        cout<<"EL TOTAL ABONADO NO PUEDE SER UN NUMERO NEGATIVO , INTENTELO NUEVAMENTE"<<endl;
        system("pause");
        return -1;
    }
    if(resto < importe)
    {
        cout<<"vuelto: "<<importe - resto <<"$"<<endl;
    }
    if(resto < importe)
    {
        importe = obtener_importe_venta(id_venta);   ///esto es para que se registre la venta efectuada por el total
    }
    ///del importe correspondiente y no guardar el pago con vuelto incluido
    estado = true;
    return 1;

}

void pago::mostrar_pago()
{
    cout<<"ID DE PAGO: "<<id_pago<<endl;
    cout<<"ID DE VENTA: "<<id_venta<<endl;
    cout<<"FORMA DE PAGO: "<<forma_pago<<endl;
    cout<<"IMPORTE: "<<importe<<endl;
    cout<<fecha_pago<<endl;
    return;
}

bool pago::guardar_pago()
{
    bool grabo;
    FILE *p;
    p=fopen("pagos.dat","ab");
    if(p==NULL)
    {
        cout<<"ERROR DE ARCHIVO EN PAGO::GUARDAR_PAGO"<<endl;
        exit(1);
    }
    grabo=fwrite(this, sizeof *this,1,p);
    fclose(p);
    return grabo;
}

int contar_pagos()
{
    FILE *p;
    p=fopen("pagos.dat","rb");
    if(p==NULL)
    {
        cout<<"ERROR DE ARCHIVO EN CONTAR_PAGOS"<<endl;
    }
    long int bytes_arch;
    int cant_pagos;
    fseek(p,0,SEEK_END);
    bytes_arch=ftell(p);
    cant_pagos=bytes_arch/sizeof(pago);
    fclose(p);
    return cant_pagos;
}

void pago::leer_pago(int pos)
{
    FILE *p;
    p=fopen("pagos.dat","rb");
    if(p==NULL)
    {
        cout<<"ERROR DE ARCHIVO EN LEER_PAGO"<<endl;
        exit(1);
    }
    fseek(p, sizeof *this*pos,0);
    fread(this, sizeof *this, 1, p);
    fclose(p);
    return;
}

int pago::modificar_en_disco(int pos)
{
    FILE *p;
    p=fopen("pagos.dat", "rb+");
    if(p==NULL)
        return -1;
    fseek(p, sizeof *this*pos,0);
    fwrite(this, sizeof *this, 1,p);
    fclose(p);
    return 0;

}

void alta_pago()
{
    pago obj;
    if(obj.cargar_pago()==-1)
    {
        return;
    }
    if(obj.guardar_pago())
    {
        cout<<"PAGO GUARDADO CON EXITO"<<endl;
        system("pause");
        return;
    }

}

float buscar_total_pagado(int id_venta) ///busca todos los pagos en referencia a una id de venta para saber cuanto falta pagar.
{
    pago obj;
    float total_abonado=0;
    int cantidad_pagos = contar_pagos();
    for(int i=0; i<cantidad_pagos; i++)
    {
        obj.leer_pago(i);
        if(obj.get_id_venta()==id_venta && obj.get_estado()==true)
        total_abonado+=obj.get_importe();
    }
    return total_abonado;
}

void pago::generar_pago_total(int nueva_id, int id_cliente, int forma_pago )
{
    pago obj;
    venta venta_realizada;
    obj.set_id_venta(nueva_id);
    obj.set_id_cliente(id_cliente);
    obj.set_forma_pago(forma_pago);
    obj.set_importe(obtener_importe(nueva_id));
    obj.set_estado(true);
    obj.set_id_pago(contar_pagos()+1);
    obj.guardar_pago();
}

bool buscar_id_venta(int id_buscada)
{
    venta obj;
    int cantidad_ventas=contar_ventas();
    for(int i=0; i<cantidad_ventas; i++)
    {
        obj.leer_venta(i);
        if(obj.get_estado()==true && obj.get_id_venta()==id_buscada)//valide que exista la venta a eliminar
        {
            return true;
        }
    }
    return false;
}


float obtener_importe_venta(int id_venta)   ///obtiene el importe de una venta mediante id para poder calcular cuanto falta pagar.
{
    venta obj;
    int cantidad_ventas = contar_ventas();
    for(int i=0; i<cantidad_ventas; i++)
    {
        obj.leer_venta(i);
        if(obj.get_estado()==true && obj.get_id_venta() == id_venta)
        {
            return obj.get_importe();
        }

    }
    return -1;
}


void listar_todos_pagos()
{
    pago obj;
    system("cls");
    int cant_regs;
    cant_regs=contar_pagos();

    for(int i=0; i<cant_regs; i++)
    {
        obj.leer_pago(i);
        if(obj.get_estado() == true)
        {

            obj.mostrar_pago();
            cout<<"================"<<endl;
        }
    }
    cout<<"================"<<endl;
    cout<<"FIN DEL LISTADO"<<endl;
    system("pause");
}


void listar_pago_x_tipo()
{
    int tipo_pago;
    int cantidad_registros;
    pago obj;
    cout<<"INGRESE EL TIPO DE PAGO QUE DESEA LISTAR"<<endl;
    cin>>tipo_pago;
    cantidad_registros=contar_pagos();
    for(int i=0; i<cantidad_registros; i++)
    {
        obj.leer_pago(i);
        if(obj.get_forma_pago()==tipo_pago && obj.get_estado() == true )
        {
            obj.mostrar_pago();
            system("pause");
            return;
        }
    }
    cout<<"no se encontro ningun pago en esa forma "<<endl;
    return;
    system("pause");
}


void listar_pago_x_cliente()
{
    pago obj;
    int comparador;
    int cantidad_registros;
    cout<<" INGRESE ID DEL CLIENTE: "<<endl;
    cin>>comparador;
    cantidad_registros=contar_pagos();
    for(int i=0; i<cantidad_registros; i++)
    {
        obj.leer_pago(i);
        if(obj.get_id_cliente()==comparador)
        {
            obj.mostrar_pago();
            system("pause");
            return;

        }
    }

    cout<<" NO SE ENCONTRO  ID. "<<endl;
    return;
    system("pause");
}


void listar_pago_x_id()
{
    pago obj;
    int comparador;
    int cantidad_registros;
    cout<<" INGRESE ID DEL PAGO: "<<endl;
    cin>>comparador;
    cantidad_registros=contar_pagos();
    for(int i=0; i<cantidad_registros; i++)
    {
        obj.leer_pago(i);
        if(obj.get_id_pago()==comparador)
        {
            obj.mostrar_pago();
            system("pause");
            return;

        }
    }

    cout<<" NO SE ENCONTRO  ID. "<<endl;
    return;
    system("pause");
}


void cancelar_pago()
{
    pago obj;
    int comparador;
    int cantidad_registros;
    cout<<" INGRESE ID DEL PAGO A CANCELAR: "<<endl;
    cin>>comparador;
    cantidad_registros=contar_pagos();
    for(int i=0; i<cantidad_registros; i++)
    {
        obj.leer_pago(i);
        if(obj.get_id_pago()==comparador)
        {
            obj.set_estado(false);
            obj.modificar_en_disco(i);
            cout<<" PAGO CANCELADO CON EXITO. "<<endl;
            system("pause");
            return;

        }
    }

    cout<<" NO SE ENCONTRO  ID. "<<endl;
    return;
    system("pause");
}


float buscar_pagos(int id)
{
    pago obj;
    int pos=0;
    float acum=0;
    while(obj.leerDeDisco(pos++))
    {
        if(obj.get_id_cliente()==id)
        {
            acum+=obj.get_importe();
        }

    }
   // cout<<"ACUMULACION DE PAGOS: "<<acum<<endl;
    return acum;
}

bool buscar_deudor (int id)
{
    venta obj;
    int pos=0;
    float deuda;
    float acum=0;
    while(obj.leerDeDisco(pos++))
    {
        if(obj.get_id_cliente()==id && obj.get_estado()==true)
        {
            //if(obj.get_forma_pago()==4){
            acum+=obj.get_importe();
            //}
        }
    }

    deuda = buscar_pagos(obj.get_id_cliente())-acum;
   // cout<<"DEUDA:   "<<acum<<endl;
    if(deuda!=0)
    {
        return true;
    }
    return false;
}

void listar_deudores()
{
    cout<<"LOS CLIENTES QUE REGISTRAN DEUDA SON"<<endl;

    cliente obj;
    int pos=0;
    while(obj.leerDeDisco(pos++))
    {
        if(obj.get_estado_cliente()==true)
        {
            if(buscar_deudor(obj.get_codigo_cliente())==true)
            {
                obj.mostrar_cliente();
                cout<<endl;
                cout<<"****************************"<<endl;
                cout<<endl;


            }

        }
    }
    system("pause");
    return;
///dentro de esta funcion iria listar deudas una vez que se encuentre funcional
}

void listar_deudas()
{
    ///tengo que evaluar venta por venta.(la tengo que leer).
    ///por cada venta reviso los pagos para ver si acumulan el total del valor de la venta.
    ///resto el moento de venta con los pagos acumulados que hagan referencia a esa venta.
    ///si la resta da un numero posivivo distinto de ser

}

#endif // PAGOS_H_INCLUDED
