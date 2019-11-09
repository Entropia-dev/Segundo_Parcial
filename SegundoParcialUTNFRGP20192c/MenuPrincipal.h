#ifndef MENUPRINCIPAL_H_INCLUDED
#define MENUPRINCIPAL_H_INCLUDED

void menu_empleados();
void Menu_Principal();


void Menu_Principal(){
int opc;
    system("cls");
while(true){

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
//        MenuCuentas();
    break;

    case 3:
  //      menuMovimientos();
            break;

    case 4:
        system("cls");
    //    menuparcial();
        system("cls");
            break;


    case 0:
    return;


    }




    }







}



void menu_empleados(){
int opc;
system("cls");
while(true){
 system("cls");
    int opc;
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
//eliminar_empleado();
    system("cls");
break;

case 0:
system("cls");
return;
break;
        }

}


}



void MenuCuentas(){
    int opc;
    system("cls");
    while(true){
        cout<<"Menu Cuentas"<<endl;
        cout<<"============"<<endl;
        cout<<"1)Nueva Cuenta"<<endl;
        cout<<"2)Listar Cuenta Por Codigo"<<endl;
        cout<<"3)Listar Todas Las Cuentas"<<endl;
        cout<<"==========="<<endl;
        cout<<"0)Volver a el menu anterior"<<endl;
        cin>>opc;
        switch(opc){

    case 1:
        system("cls");
      //  altaCuenta();
        system("cls");
        break;

        case 2:
            system("cls");
        //   listarCategoriaxCodigo();
           system("cls");
        break;

    case 3:
        system("cls");
       // listarCuentas();
        system("cls");
        break;

    case 0:
        system("cls");
        return;
        }


    }


}



void menuMovimientos(){

int opc;
    system("cls");
    while(true){
        cout<<"Menu Movimientos"<<endl;
        cout<<"============"<<endl;
        cout<<"1)Nuevo movimiento"<<endl;
        cout<<"2)Modificar movimiento"<<endl;
        cout<<"3)Listar movimiento por fecha"<<endl;
        cout<<"4)Listar movimiento por idcuenta"<<endl;
        cout<<"5)Listar movimientos"<<endl;
        cout<<"==========="<<endl;
        cout<<"0)Volver a el menu anterior"<<endl;
        cin>>opc;
        switch(opc){

    case 1:
        system("cls");
       // altaMovimiento();
        system("cls");
    break;

    case 2:
        system("cls");
       // modificarMovimiento();
        system("cls");
    break;

    case 3:
        system("cls");
        //listarMovimientosXfecha();
        system("cls");
    break;

    case 4:
        system("cls");
        //listarMovimiento_IDcuenta();
        system("cls");
        break;

    case 5:
        system("cls");
        //listarMovimientos();
        system("cls");
    break;

    case 0:
        system("cls");
    return;
    break;
                }
        }

}

void menuparcial(){

    int opc;
    system("cls");
    while(true){

        cout<<"menu parcial"<<endl;
        cout<<endl;
        cout<<"1)Punto 1"<<endl;
        cout<<"2)Punto 2"<<endl;
        cout<<"3)punto 3"<<endl;
        cout<<endl;
        cout<<"0)volver al menu anterior"<<endl;
        cin>>opc;

        switch(opc){

    case 1:
    system("cls");
   // Mesconmasmovimientos();
    system("cls");
        break;


    case 2:
    system("cls");
   // Mesesconmasingresos();
    system("cls");
        break;

    case 3:
     //   listarCuentaxNombre();
    break;


    case 0:
        return;



        }

    }





}

#endif // MENUPRINCIPAL_H_INCLUDED
