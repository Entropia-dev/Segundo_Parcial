#ifndef MENUES_H_INCLUDED
#define MENUES_H_INCLUDED

int c1=201, c2=187, c3=188, c4=200, RH=205, RV=186, PD=203, PU=202, PR=204, PL=185;

///declaro los prototipos de las funciones para un correcto funcionamiento de los menues.

void menu_principal();
void menu_empleados();
void menu_clientes();
void menu_pagos();
void menu_ventas();
void menu_productos();

    /*void MenuPrincipal (){
    int opcion;
system("cls");
    cout << char (c1);
    for (int x=0; x<77; x++)
    {
        cout << char(RH);
    }
    cout << char (c2) << endl;
cout << char (RV) << "                                                                              " << char (RV) << endl;
cout << char (RV) << "                     REVESTIMIENTOS A\46TI                                   " << char (RV) << endl;
cout << char (RV) << "                                                                              " << char (RV) << endl;
cout << char (RV) << "                  1-  CLIENTES                                                 " << char (RV) << endl;
cout << char (RV) << "                  2-  VENTAS                                                   " << char (RV) << endl;
cout << char (RV) << "                  3-  PAGOS                                                    " << char (RV) << endl;
cout << char (RV) << "                  4-  EMPLEADOS                                                " << char (RV) << endl;
cout << char (RV) << "                  5-  PRODUCTOS                                                " << char (RV) << endl;
cout << char (RV) << "                                                                               " << char (RV) << endl;
cout << char (RV) << "                  0- Salir                                                     " << char (RV) << endl;
cout << char (RV) << "                                                                               " << char (RV) << endl;
   cout << char (c4);
    for (int x=0; x<77; x++)
    {
        cout << char(RH);
    }
    cout << char (c3)<<endl;
    cout<<endl;
    cout<<"INGRESE UNA OPCION"<<endl;
    cin>>opcion;
    switch(opcion){
case 1:
    menuClientes();
    break;

    case 2:
    menuVentas();
    break;

    case 3:
    menu_pagos();
    break;

    case 4:
        break;
            ///cierre de switch opcion
    }

}

void menuClientes()
{
    int opc;
    empleado obj_empleado;
    system("cls");
        cout << char (c1);
    for (int x=0; x<77; x++)
    {
        cout << char(RH);
    }
    cout << char (c2) << endl;
cout << char (RV) << "                                                                             " << char (RV) << endl;
cout << char (RV) << "                     MENU CLIENTES                                           " << char (RV) << endl;
cout << char (RV) << "                                                                             " << char (RV) << endl;
cout << char (RV) << "                  1-  CARGAR                                                 " << char (RV) << endl;
cout << char (RV) << "                  2-  MOSTRAR TODOS                                          " << char (RV) << endl;
cout << char (RV) << "                  3-  BUSQUEDA                                               " << char (RV) << endl;
cout << char (RV) << "                  4-  MODIFICAR                                              " << char (RV) << endl;
cout << char (RV) << "                                                                             " << char (RV) << endl;
cout << char (RV) << "                  0- Volver atras                                            " << char (RV) << endl;
cout << char (RV) << "                                                                             " << char (RV) << endl;
   cout << char (c4);
    for (int x=0; x<77; x++)
    {
        cout << char(RH);
    }
    cout << char (c3)<<endl;

cin>>opc;
switch(opc){
case 1:
    obj_empleado.Cargar_empleado();
    obj_empleado.guardar_empleado();
    break;
}
}

void menuModelos()
{
    system("cls");
        cout << char (c1);
    for (int x=0; x<77; x++)
    {
        cout << char(RH);
    }
    cout << char (c2) << endl;
cout << char (RV) << "                                                                             " << char (RV) << endl;
cout << char (RV) << "                       MENU MODELOS                                          " << char (RV) << endl;
cout << char (RV) << "                                                                             " << char (RV) << endl;
cout << char (RV) << "                  1-  CARGAR                                                 " << char (RV) << endl;
cout << char (RV) << "                  2-  LISTAR                                                 " << char (RV) << endl;
cout << char (RV) << "                  3-  MODIFICAR                                              " << char (RV) << endl;
cout << char (RV) << "                  4-                                                         " << char (RV) << endl;
cout << char (RV) << "                                                                             " << char (RV) << endl;
cout << char (RV) << "                  0- Volver atras                                            " << char (RV) << endl;
cout << char (RV) << "                                                                             " << char (RV) << endl;
   cout << char (c4);
    for (int x=0; x<77; x++)
    {
        cout << char(RH);
    }
    cout << char (c3)<<endl;
}

void menuVentas()
{
    system("cls");
        cout << char (c1);
    for (int x=0; x<77; x++)
    {
        cout << char(RH);
    }
    cout << char (c2) << endl;
cout << char (RV) << "                                                                             " << char (RV) << endl;
cout << char (RV) << "                       MENU VENTAS                                           " << char (RV) << endl;
cout << char (RV) << "                                                                             " << char (RV) << endl;
cout << char (RV) << "                  1-  CARGAR                                                 " << char (RV) << endl;
cout << char (RV) << "                  2-  LISTAR TODOS                                           " << char (RV) << endl;
cout << char (RV) << "                  3-  LISTAR POR NOMBRE                                      " << char (RV) << endl;
cout << char (RV) << "                  4-  MODIFICAR VENTA                                        " << char (RV) << endl;
cout << char (RV) << "                                                                             " << char (RV) << endl;
cout << char (RV) << "                  0- Volver atras                                            " << char (RV) << endl;
cout << char (RV) << "                                                                             " << char (RV) << endl;
   cout << char (c4);
    for (int x=0; x<77; x++)
    {
        cout << char(RH);
    }
    cout << char (c3)<<endl;
}

void mostrarMetodoCapt()
{
    cout<<endl;
    cout<<"----------------------------"<<endl;
    cout<<"-   1-FACEBOOK             -"<<endl;
    cout<<"-   2-MERCADO LIBRE        -"<<endl;
    cout<<"-   3-VOLANTES             -"<<endl;
    cout<<"-   4-CARTELES             -"<<endl;
    cout<<"-   5-OTRO                 -"<<endl;
    cout<<"----------------------------"<<endl;
}
int strLen(char *Cad)
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
}


    */

void menu_principal(){
int opc;
while(true){
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
switch(opc){
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
menu_pagos();
break;

case 5:
menu_productos();
break;
case 0:
return;
}       ///fin switch
            }    ///fin del while
                }





void menu_pagos(){
    system("cls");
    int opc;
cout<<"MENU PAGOS"<<endl;
cout<<"======="<<endl;
cout<<"1)NUEVO PAGO"<<endl;
cout<<"2)LISTAR PAGO POR CLIENTE"<<endl;
cout<<"3)LISTAR TODOS LOS PAGOS"<<endl;
cout<<"4)MODIFICAR PAGO"<<endl;
cout<<"5)ELIMINAR PAGO"<<endl;
cout<<"========"<<endl;
cout<<"0) VOLVEr AL MENU ANTERIOR"<<endl;
cin>>opc;
switch(opc){
case 1:
break;

case 2:
break;

case 3:
break;

case 4:
break;

case 5:
break;

case 0:
return;
break;
}
}

void menu_empleados(){
     system("cls");
    int opc;
    empleado obj;
cout<<"MENU EMPLEADOS"<<endl;
cout<<"======="<<endl;
cout<<"1)NUEVO EMPLEADO"<<endl;
cout<<"2)LISTAR EMPLEADO POR DNI"<<endl;
cout<<"3)LISTAR TODOS LOS EMPLEADOS"<<endl;
cout<<"4)MODIFICAR EMPLEADO"<<endl;
cout<<"5)ELIMINAR EMPLEADO"<<endl;
cout<<"========"<<endl;
cout<<"0) VOLVEr AL MENU ANTERIOR"<<endl;
cin>>opc;
switch(opc){
case 1:
    obj.Cargar_empleado();
    if(obj.Guardar_empleado()==true)
        cout<<"EL EMPLEADO CARGADO !!! ";
        system("pause");
    break;

case 2:
    listar_empleado_x_dni();
    system("pause");
break;

case 3:
break;

case 4:
break;

case 5:
break;

case 0:
return;
break;
}
}

void menu_clientes(){
     system("cls");
int opc;
cout<<"MENU CLIENTES"<<endl;
cout<<"====="<<endl;
cout<<"1)NUEVO CLIENTE"<<endl;
cout<<"2)LISTAR TODOS LOS CLIENTES"<<endl;
cout<<"3)LISTAR CLIENTE POR ID"<<endl;
cout<<"4)ELIMINAR CLIENTE"<<endl;
cout<<"5)MODIFICAR CLIENTE"<<endl;
cout<<"====="<<endl;
cout<<"0)VOLVER AL MENU ANTERIOR"<<endl;
cin>>opc;
switch(opc){
case 1:
break;

case 2:
break;

case 3:
break;

case 4:
break;

case 5:
break;

case 0:
return;
break;
}

}


void menu_ventas(){
     system("cls");
    int opc;
cout<<"MENU VENTAS"<<endl;
cout<<"======"<<endl;
cout<<"1)NUEVA VENTA"<<endl;
cout<<"2) LISTAR VENTAS POR CLIENTE"<<endl;
cout<<"3)LISTAR TODAS LAS VENTAS"<<endl;
cout<<"4)MODIFICAR VENTA"<<endl;
cout<<"5)ELIMINAR VENTA"<<endl;
cout<<"==============================="<<endl;
cout<<"0)VOLVER AL MENU ANTERIOR"<<endl;
cin>>opc;
switch(opc){
case 1:
break;

case 2:
break;

case 3:
break;

case 4:
break;

case 5:
break;

case 0:
return;
break;
}

}

void menu_productos(){
     system("cls");
int opc;
cout<<"MENU EMPLEADOS"<<endl;
cout<<"======"<<endl;
cout<<"1)NUEVO PRODUCTO"<<endl;
cout<<"2)LISTAR EMPLEADO POR DNI"<<endl;
cout<<"3)MODIFICAR PRODUCTO"<<endl;
cout<<"4)LISTAR TODOS LOS PRODUCTOS"<<endl;
cout<<"4)ELIMINAR PRODUCTO"<<endl;
cout<<"=============="<<endl;
cout<<"0)VOLVER AL MENU ANTERIOR"<<endl;
cin>>opc;
switch(opc){
case 1:
break;

case 2:
break;

case 3:
break;

case 4:
break;

case 5:
break;

case 0:
return;
break;
}

}

#endif // MENUES_H_INCLUDED
