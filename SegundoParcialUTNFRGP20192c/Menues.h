#ifndef MENUES_H_INCLUDED
#define MENUES_H_INCLUDED

int c1=201, c2=187, c3=188, c4=200, RH=205, RV=186, PD=203, PU=202, PR=204, PL=185;

void MenuPrincipal (){
system("cls");
    cout << char (c1);
    for (int x=0; x<77; x++)
    {
        cout << char(RH);
    }
    cout << char (c2) << endl;
cout << char (RV) << "                                                                             " << char (RV) << endl;
cout << char (RV) << "                     REVESTIMIENTOS A\46TI                                     " << char (RV) << endl;
cout << char (RV) << "                                                                             " << char (RV) << endl;
cout << char (RV) << "                  1-  VENTAS                                                 " << char (RV) << endl;
cout << char (RV) << "                  2-  CLIENTES                                               " << char (RV) << endl;
cout << char (RV) << "                  3-  BUSQUEDAS                                              " << char (RV) << endl;
cout << char (RV) << "                  4-  MODELOS                                                " << char (RV) << endl;
cout << char (RV) << "                                                                             " << char (RV) << endl;
cout << char (RV) << "                  0- Salir                                                   " << char (RV) << endl;
cout << char (RV) << "                                                                             " << char (RV) << endl;
   cout << char (c4);
    for (int x=0; x<77; x++)
    {
        cout << char(RH);
    }
    cout << char (c3)<<endl;
    }

void menuClientes()
{system("cls");
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


#endif // MENUES_H_INCLUDED
