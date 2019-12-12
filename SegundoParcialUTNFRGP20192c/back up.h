#ifndef BACK_UP_H_INCLUDED
#define BACK_UP_H_INCLUDED



void  restaurar_empleado();
void  restaurar_venta();
void  restaurar_clientes();
void  restaurar_pagos();
void  restaurar_productos();
void  bckEmpleados ();
void  bckVentas();
void  bckClientes ();
void  bckPagos ();
void  bckProductos ();




void  restaurar_empleado()
{


    recuadro ( 20 , 1 , 75 , 25 );

    gotoxi ( 45 , 2 );
    cout << " **** REVESTIMIENTOS AyTi **** " ;
    gotoxi ( 45 , 3 );
    cout << "       RESTAURAR BACKUP      " ;



    empleado reg;

    ARCHIVO   * pback, * p;
    pback = fopen ( " bck / backupEmpleados.dat " , " rb " );
    if (pback == NULL )
    {
        cout << " No existe archivo para poder realizar la restauración de empleados " << endl;
        return ;
    }
    p = fopen ( " empleados.dat " , " wb " );
    si (p == NULL )
    {
        return ;
    }
    fclose (p);
    p = fopen ( " empleados.dat " , " ab " );
    si (p == NULL )
    {
        return;
    }
    while ( fread (& reg, sizeof (empleado), 1 , pback) == 1 )
    {

        fwrite (& reg, sizeof (empleado), 1 , p);
    }

    gotoxi ( 21 , 5 );
    cout << " Se Restauro El Archivo Empleados.dat Con Exito! " << endl;

    fclose (p);
    fclose (pback);
    volver ;
}


void restaurar_venta()
{
    venta reg;

    ARCHIVO   * pback, * p;
    pback = fopen ( " bck / backupVenta.dat " , " rb " );
    if (pback == NULL )
    {
        cout << " No existe archivo para poder realizar la restauración de venta " << endl;
         return;
    }
    p = fopen ( " ventas.dat " , " wb " );
    if (p == NULL )
    {
        return ;
    }
    fclose (p);
    p = fopen ( " venta.dat " , " ab " );
    if (p == NULL )
    {
        return ;
    }
    while ( fread (& reg, sizeof (venta), 1 , pback) == 1 )
    {

        fwrite (& reg, sizeof (venta), 1 , p);
    }

    gotoxi ( 21 , 6 );
    cout << " Se Restauro El Archivo Ventas.dat Con Exito! " << endl;
    fclose (p);
    fclose (pback);
     return;
}


void restaurar_clientes ()
{
    cliente reg;

    ARCHIVO   * pback, * p;
    pback = fopen ( " bck / backupClientes.dat " , " rb " );
    if (pback == NULL )
    {
        cout << " No existe archivo para poder realizar la restauración de clientes " << endl;
        return;
    }
    p = fopen ( " clientes.dat " , " wb " );
    if (p == NULL )
    {
        return ;
    }
    fclose (p);
    p = fopen ( " clientes.dat " , " ab " );
    if (p == NULL )
    {
       return ;
    }
    while ( fread (& reg, sizeof (cliente), 1 , pback) == 1 )
    {

        fwrite (& reg, sizeof (cliente), 1 , p);
    }

    gotoxi ( 21 , 7 );
    cout << " Se Restauro El Archivo clientes.dat Con Exito! " << endl;
    fclose (p);
    fclose (pback);
    return ;
}


void restaurar_pagos()
{
    pago reg;

    ARCHIVO *pback, * p;
    pback = fopen ( " bck / backupPagos.dat " , " rb " );
    if (pback == NULL )
    {
        cout << " No existe archivo para poder realizar la restauración de Pagos " << endl;
        volver ;
    }
    p = fopen ( " pagos.dat " , " wb " );
    if (p == NULL )
    {
        return ;
    }
    fclose (p);
    p = fopen ( " pagos.dat " , " ab " );
    if (p == NULL )
    {
      return ;
    }
    while ( fread (& reg, sizeof (pago), 1 , pback) == 1 )
    {

        fwrite (& reg, sizeof (pago), 1 , p);
    }

    gotoxi ( 21 , 7 );
    cout << " Se Restauro El Archivo clientes.dat Con Exito! " << endl;
    fclose (p);
    fclose (pback);
    return ;
}


void restaurar_productos()
{
    productos reg;

    ARCHIVO   * pback, * p;
    pback = fopen ( " bck / backupProductos.dat " , " rb " );
    if (pback == NULL )
    {
        cout << " No existe archivo para poder realizar la restauración de Productos " << endl;
        return ;
    }
    p = fopen ( " productos.dat " , " wb " );
    if (p == NULL )
    {
        return;
    }
    fclose (p);
    p = fopen ( " productos.dat " , " ab " );
    if(p == NULL )
    {
        return;
    }
    while ( fread (& reg, sizeof (productos), 1 , pback) == 1 )
    {

        fwrite (& reg, sizeof (productos), 1 , p);
    }

    gotoxi ( 21 , 7 );
    cout << " Se Restauro El Archivo productos.dat Con Exito! " << endl;
    fclose (p);
    fclose (pback);
    return ;
}



void bckEmpleados ()
{

    recuadro ( 20 , 1 , 75 , 25 );

    gotoxi ( 45 , 2 );
    cout << " **** REVESTIMIENTOS AyTi **** " ;
    gotoxi ( 45 , 3 );
    cout << "        MENÚ DE COPIA DE SEGURIDAD      " ;

    empleado reg;
    ARCHIVO   * pback, * p;
    p = fopen ( " empleado.dat " , " rb " );
    if (p == NULL )
    {
        cout << " El archivo empleado.dat no existe " << endl;
      return;
    }
    pback = fopen ( " bck / backupEmpleados.dat " , " wb " );


    if (pback == NULL )
    {
        return ;
    }

    fclose (pback);
    pback = fopen ( " bck / backupEmpleados.dat " , " ab " );


    if (pback == NULL )
    {
        return ;
    }


    while ( fread (& reg, sizeof (empleado), 1 , p) == 1 )
    {

        fwrite (& reg, sizeof (empleado), 1 , pback);
    }


    gotoxi ( 21 , 5 );
    cout << " Se Realizo Backup del Archivo Empleados.dat Con Exito! " << endl;
    fclose (p);
    fclose (pback);
    return;
}



void bckVentas ()
{
    venta reg;
    ARCHIVO   * pback, * p;
    p = fopen ( " ventas.dat " , " rb " );
    if (p == NULL )
    {
        cout << " El archivo ventas.dat no existe " << endl;
     return ;
    }
    pback = fopen ( " bck / backupVentas.dat " , " wb " );
    if (pback == NULL )
    {
        return ;
    }
    fclose (pback);
    pback = fopen ( " bck / backupVentas.dat " , " ab " );
    if (pback == NULL )
    {
        return ;
    }
    while ( fread (& reg, sizeof (venta), 1 , p) == 1 )
    {

        fwrite (& reg, sizeof (venta), 1 , pback);
    }
    gotoxi ( 21 , 6 );
    cout << " Se Realizo Backup del Archivo Ventas.dat Con Exito! " << endl;

    fclose (p);
    fclose (pback);
    return;
}

void bckClientes ()
{
    cliente reg;
    ARCHIVO   * pback, * p;
    p = fopen ( " clientes.dat " , " rb " );
    if (p == NULL )
    {
        cout << " El archivo cliente.dat no existe " << endl;
        return;
    }
    pback = fopen ( " bck / backupClientes.dat " , " wb " );
    if (pback == NULL )
    {
        return;
    }
    fclose (pback);
    pback = fopen ( " bck / backupClientes.dat " , " ab " );
    if (pback == NULL )
    {
        return;
    }
    while ( fread (& reg, sizeof (cliente), 1 , p) == 1 )
    {

        fwrite (& reg, sizeof (cliente), 1 , pback);
    }

    gotoxi ( 21 , 7 );
    cout << " Se Realizo Backup del Archivo Clientes.dat Con Exito! " << endl;
    fclose (p);
    fclose (pback);
    return;
}


void bckPagos()
{
    pago reg;
    ARCHIVO   * pback, * p;
    p = fopen ( " pagos.dat " , " rb " );
    if (p == NULL )
    {
        cout << " El archivo pagos.dat no existe " << endl;
        return ;
    }
    pback = fopen ( " bck / backupPagos.dat " , " wb " );
    if (pback == NULL )
    {
        return ;
    }
    fclose (pback);
    pback = fopen ( " bck / backupPagos.dat " , " ab " );
    if (pback == NULL )
    {
        return ;
    }
    while ( fread (& reg, sizeof (pago), 1 , p) == 1 )
    {

        fwrite (& reg, sizeof (pago), 1 , pback);
    }

    gotoxi ( 21 , 7 );
    cout << " Se Realizo Backup del Archivo Pagos.dat Con Exito! " << endl;
    fclose (p);
    fclose (pback);
    return;
}


void bckProductos ()
{
    productos reg;
    ARCHIVO   * pback, * p;
    p = fopen ( " productos.dat " , " rb " );
    if (p == NULL )
    {
        cout << " El archivo Productos.dat no existe " << endl;
      return ;
    }
    pback = fopen ( " bck / backupProductos.dat " , " wb " );
    if (pback == NULL )
    {
    return ;
    }
    fclose (pback);
    pback = fopen ( " bck / backupProductos.dat " , " ab " );
    if (pback == NULL )
    {
        return ;
    }
    while ( fread (& reg, sizeof (productos), 1 , p) == 1 )
    {

        fwrite (& reg, sizeof (productos), 1 , pback);
    }

    gotoxi ( 21 , 7 );
    cout << " Se Realizo Backup del Archivo Productos.dat Con Exito! " << endl;
    fclose (p);
    fclose (pback);
    return;
}

#endif // BACK_UP_H_INCLUDED
