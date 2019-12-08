#ifndef MENUPRINCIPAL_H_INCLUDED
#define MENUPRINCIPAL_H_INCLUDED

void menu_empleados();
void Menu_Principal();
void menu_clientes();
void menu_ventas();
void menu_productos();
void menu_pagos();

void Menu_Principal()
{
    int opc;
    system("cls");
    while(true)
    {
        system("cls");
        cout<<"MENU PRINCIPAL"<<endl;
        cout<<"=========="<<endl;
        cout<<"1)MENU EMPLEADOS"<<endl;
        cout<<"2)MENU CLIENTES"<<endl;
        cout<<"3)MENU VENTAS"<<endl;
        cout<<"4)MENU PAGOS"<<endl;
        cout<<"5)MENU PRODUCTOS"<<endl;
        cout<<"========="<<endl;
        cout<<"0)SALIR DEL PROGRAMA"<<endl;
        cin>>opc;
        switch(opc)
        {
        case 1:
            menu_empleados();
            break;

        case 2:
            menu_clientes();
            break;

        case 3:
            menu_ventas();
            break;

        case 4:
            system("cls");
            menu_pagos();
            system("cls");
            break;

        case 5:
            system("cls");
            menu_productos();
            system("cls");
            break;

        case 0:
            return;

        default: cout<<"INGRESE UNA OPCION VALIDA"<<endl; system("pause"); break;

        }




    }







}



void menu_empleados()
{

    int opc;
    system("cls");
    while(true)
    {
        system("cls");
        int opc;
        cout<<"MENU EMPLEADOS"<<endl;
        cout<<"======="<<endl;
        cout<<"1)NUEVO EMPLEADO"<<endl;
        cout<<"2)LISTAR EMPLEADO POR DNI"<<endl;
        cout<<"3)LISTAR TODOS LOS EMPLEADOS"<<endl;
        cout<<"4)MODIFICAR EMPLEADO"<<endl;
        cout<<"5)ELIMINAR EMPLEADO"<<endl;
        cout<<"6)RESTAURAR EMPLEADO"<<endl;
        cout<<"========"<<endl;
        cout<<"0) VOLVEr AL MENU ANTERIOR"<<endl;
        cin>>opc;
        switch(opc)
        {

        case 1:
            system("cls");
            alta_empleado();
            system("cls");
            break;


        case 2:
            system("cls");
            listar_empleado_x_dni();
            system("cls");
            break;

        case 3:
            system("cls");
            listar_todos_empleados();
            system("cls");
            break;

        case 4:
            system("cls");
            modificar_empleado();
            system("cls");
            break;

        case 5:
            system("cls");
            eliminar_empleado();
            system("cls");
            break;

        case 6:
            system("cls");
            restaurar_empleado();
            system("cls");
            break;

        case 0:
            system("cls");
            return;
            break;

            default: cout<<"INGRESE UNA OPCION VALIDA"<<endl; system("pause"); break;
        }

    }


}



void menu_clientes()
{
    int opc;
    system("cls");
    while(true)
    {
        cout<<"MENU CLIENTES"<<endl;
        cout<<"============"<<endl;
        cout<<"1)CARGAR CLIENTE"<<endl;
        cout<<"2)MODIFICAR EL CORREO DEL CLIENTE"<<endl;
        cout<<"3)LISTAR TODOS LOS CLIENTES"<<endl;
        cout<<"4)ELIMINAR CLIENTE"<<endl;
        cout<<"5)RESTAURAR CLIENTE"<<endl;
        cout<<"==========="<<endl;
        cout<<"0)Volver a el menu anterior"<<endl;
        cin>>opc;
        switch(opc)
        {

        case 1:
            system("cls");
            alta_cliente();
            system("cls");
            break;

        case 2:
            system("cls");
            modificar_cliente();
            system("cls");
            break;

        case 3:
            system("cls");
            listar_todos_clientes();
            system("cls");
            break;

        case 4:
            system("cls");
            eliminar_cliente();
            system("cls");
            break;

        case 5:
            restaurar_cliente();
            system("cls");
            break;

        case 0:
            system("cls");
            return;

            default: cout<<"INGRESE UNA OPCION VALIDA"<<endl; system("pause"); break;

        }


    }


}



void menu_ventas()
{

    int opc;
    system("cls");
    while(true)
    {
        cout<<"MENU VENTAS"<<endl;
        cout<<"==============================="<<endl;
        cout<<"1)NUEVA VENTA"<<endl;
        cout<<"2)LISTAR TODAS LAS VENTAS"<<endl;
        cout<<"3)LISTAR VENTA POR ID"<<endl;
        cout<<"4)LISTAR VENTA POR CLIENTE"<<endl;
        cout<<"5)LISTAR VENTA POR MES"<<endl;
        cout<<"6)LISTAR VENTA POR A�O"<<endl;
        cout<<"7)MODIFICAR VENTA"<<endl;
        cout<<"8)ELIMINAR VENTA"<<endl;
        cout<<"9)RESTAURAR VENTA"<<endl;
        cout<<"==============================="<<endl;
        cout<<"0)VOLVER AL MENU ANTERIOR"<<endl;
        cin>>opc;
        switch(opc)
        {

        case 1:
            system("cls");
            alta_venta();
            system("cls");
            break;

        case 2:
            system("cls");
            listar_ventas();
            system("cls");
            break;

        case 3:
            system("cls");
            listar_ventas_x_id();
            system("cls");
            break;

        case 4:
            system("cls");
            listar_venta_x_cliente();
            system("cls");
            break;

        case 5:
            system("cls");
            listar_venta_x_mes();
            system("cls");
            break;

        case 6:
            system("cls");
            listar_venta_x_anio();
            system("cls");
            break;

        case 7:
            system("cls");
            modificar_venta();
            system("cls");
            break;

        case 8:
            system("cls");
            eliminar_venta();
            system("cls");

        case 9:
            system("cls");
            restaurar_venta();
            system("cls");
            break;
        case 0:
            system("cls");
            return;
            break;

            default: cout<<"INGRESE UNA OPCION VALIDA"<<endl; system("pause");
            system("cls"); break;
        }
    }

}

void menu_productos()
{

    int opc;
    system("cls");
    while(true)
    {

        cout<<"MENU PRODUCTOS "<<endl;
        cout<<"========================"<<endl;
        cout<<"1)NUEVO PRODUCTO"<<endl;
        cout<<"2)LISTAR PRODUCTO POR ID"<<endl;
        cout<<"3)MODIFICAR PRECIO PRODUCTO"<<endl;
        cout<<"4)LISTAR TODOS LOS PRODUCTOS"<<endl;
        cout<<"5)ELIMINAR PRODUCTO"<<endl;
        cout<<"6)RESTAURAR PRODUCTO"<<endl;
        cout<<"7)AUMENTAR STOCK"<<endl;
        cout<<"========================"<<endl;
        cout<<"0)VOLVER AL MENU ANTERIOR"<<endl;
        cin>>opc;

        switch(opc)
        {

        case 1:
            system("cls");
            alta_producto();
            system("cls");
            break;


        case 2:
            system("cls");
            listar_producto_x_id();
            system("cls");
            break;

        case 3:
            system("cls");
            modificar_precio_producto();
            system("cls");
            break;

        case 4:
            system("cls");
            listar_todos_productos();
            system("cls");
            break;

        case 5:
            system("cls");
            eliminar_producto();
            system("cls");
            break;

        case 6:
            system("cls");
            cout<<"OPCION EN DESARROLLO"<<endl;
            system("pause");
            system("cls");
            break;

        case 7:
            system("cls");
            aumentar_stock();
            system("cls");
            break;

        case 0:
            system("cls");
            return;
            break;

            default: cout<<"INGRESE UNA OPCION VALIDA"<<endl; system("pause");  break;
        }

    }





}



void menu_pagos(){
    pago obj;
        int opc;
    system("cls");
    while(true)
    {

cout<<"MENU DE PAGOS"<<endl;
cout<<"==================="<<endl;
cout<<"1)NUEVO PAGO"<<endl;
cout<<"2)LISTAR TODOS LOS PAGOS"<<endl;
cout<<"3)LISTAR PAGO POR TIPO"<<endl;
cout<<"4)LISTAR PAGO POR CLIENTE"<<endl;
cout<<"5)LISTAR PAGO POR ID"<<endl;
cout<<"6)CANCELAR PAGO"<<endl;
cout<<"==================="<<endl;
cout<<"0)VOLVER AL MENU ANTERIOR"<<endl;
cout<<"INGRESE UNA OPCION"<<endl;
cin>>opc;

switch(opc){
case 1:
    system("cls");
    alta_pago();
    system("cls");
break;

case 2:
break;

case 3:
break;

case 4:
break;

case 5:
break;

case 6:
break;

case 0:
return;
break;

cout<<"INGRESE UNA OPCION VALIDA"<<endl; system("pause");
            system("cls"); break;

    }

}

}


#endif // MENUPRINCIPAL_H_INCLUDED
