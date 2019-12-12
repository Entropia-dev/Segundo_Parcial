#ifndef BACK_UP_H_INCLUDED
#define BACK_UP_H_INCLUDED

///archivos que restaurar
///empleados == TERMINADO
///clientes == TERMINADO
///ventas == TERMINADO
///pagos    == TERMINADO
///productos


void generar_backup_empleados()
{
    empleado reg;
    FILE  *pback,*p;
    p=fopen("empleados.dat","rb");
    if(p==NULL)
    {
        cout<<"El archivo empleados.dat no existe"<<endl;
        return ;
    }
    pback=fopen("bck/backupEmpleados.dat","wb");


    if(pback==NULL)
    {
        return ;
    }

    fclose(pback);
    pback=fopen("bck/backupEmpleados.dat","ab");


    if(pback==NULL)
    {
        return ;
    }


    while(fread(&reg,sizeof(empleado),1,p)==1)
    {

        fwrite(&reg,sizeof(empleado),1,pback);
    }

    cout<<"Se Realizo Backup del Archivo clientes.dat Con Exito!"<<endl;
    fclose(p);
    fclose(pback);
    return;
}


void restaurar_backup_empleados()
{
    empleado reg;

    FILE  *pback,*p;
    pback=fopen("bck/backupEmpleados.dat","rb");
    if(pback==NULL)
    {
        cout<<"No existe archivo para poder realizar el backup de empleados"<<endl;
        return ;
    }
    p=fopen("empleados.dat","wb");
    if(p==NULL)
    {
        return ;
    }
    fclose(p);
    p=fopen("empleados.dat","ab");
    if(p==NULL)
    {
        return ;
    }
    while(fread(&reg,sizeof(empleado),1,pback)==1)
    {

        fwrite(&reg,sizeof(empleado),1,p);
    }


    fclose(p);
    fclose(pback);

    cout<<"Se cargo el backup de empleados con exito"<<endl;
    return;
}


void generar_backup_clientes()
{
    cliente reg;
    FILE  *pback,*p;
    p=fopen("clientes.dat","rb");
    if(p==NULL)
    {
        cout<<"El archivo clientes.dat no existe"<<endl;
        return ;
    }
    pback=fopen("bck/backupclientes.dat","wb");


    if(pback==NULL)
    {
        return ;
    }

    fclose(pback);
    pback=fopen("bck/backupclientes.dat","ab");


    if(pback==NULL)
    {
        return ;
    }


    while(fread(&reg,sizeof(cliente),1,p)==1)
    {

        fwrite(&reg,sizeof(cliente),1,pback);
    }

    cout<<"Se Realizo Backup del Archivo clientes.dat Con Exito!"<<endl;
    fclose(p);
    fclose(pback);
    return;
}

void restaurar_backup_clientes()
{
    cliente reg;

    FILE  *pback,*p;
    pback=fopen("bck/backupclientes.dat","rb");
    if(pback==NULL)
    {
        cout<<"No existe archivo para poder realizar el backup de clientes"<<endl;
        return ;
    }
    p=fopen("clientes.dat","wb");
    if(p==NULL)
    {
        return ;
    }
    fclose(p);
    p=fopen("clientes.dat","ab");
    if(p==NULL)
    {
        return ;
    }
    while(fread(&reg,sizeof(cliente),1,pback)==1)
    {

        fwrite(&reg,sizeof(cliente),1,p);
    }


    fclose(p);
    fclose(pback);

    cout<<"Se cargo el backup de clientes con exito"<<endl;
    return;
}



void generar_backup_ventas()
{
    venta reg;
    FILE  *pback,*p;
    p=fopen("ventas.dat","rb");
    if(p==NULL)
    {
        cout<<"El archivo ventas.dat no existe"<<endl;
        return ;
    }
    pback=fopen("bck/backupventas.dat","wb");


    if(pback==NULL)
    {
        return ;
    }

    fclose(pback);
    pback=fopen("bck/backupventas.dat","ab");


    if(pback==NULL)
    {
        return ;
    }


    while(fread(&reg,sizeof(venta),1,p)==1)
    {

        fwrite(&reg,sizeof(venta),1,pback);
    }

    cout<<"Se Realizo Backup del Archivo ventas.dat Con Exito!"<<endl;
    fclose(p);
    fclose(pback);
    return;
}


void restaurar_backup_ventas()
{
    venta reg;

    FILE  *pback,*p;
    pback=fopen("bck/backupventas.dat","rb");
    if(pback==NULL)
    {
        cout<<"No existe archivo para poder realizar el backup de ventas"<<endl;
        return ;
    }
    p=fopen("ventas.dat","wb");
    if(p==NULL)
    {
        return ;
    }
    fclose(p);
    p=fopen("ventas.dat","ab");
    if(p==NULL)
    {
        return ;
    }
    while(fread(&reg,sizeof(venta),1,pback)==1)
    {

        fwrite(&reg,sizeof(venta),1,p);
    }


    fclose(p);
    fclose(pback);

    cout<<"Se cargo el backup de ventas con exito"<<endl;
    return;
}


void generar_backup_pagos(){
  pago reg;
    FILE  *pback,*p;
    p=fopen("pagos.dat","rb");
    if(p==NULL)
    {
        cout<<"El archivo pagos.dat no existe"<<endl;
        return ;
    }
    pback=fopen("bck/backuppagos.dat","wb");


    if(pback==NULL)
    {
        return ;
    }

    fclose(pback);
    pback=fopen("bck/backuppagos.dat","ab");


    if(pback==NULL)
    {
        return ;
    }


    while(fread(&reg,sizeof(pago),1,p)==1)
    {

        fwrite(&reg,sizeof(pago),1,pback);
    }

    cout<<"Se Realizo Backup del Archivo pagos.dat Con Exito!"<<endl;
    fclose(p);
    fclose(pback);
    return;
}

void restaurar_backup_pagos(){
   pago reg;

    FILE  *pback,*p;
    pback=fopen("bck/backuppagos.dat","rb");
    if(pback==NULL)
    {
        cout<<"No existe archivo para poder realizar el backup de pagos"<<endl;
        return ;
    }
    p=fopen("pagos.dat","wb");
    if(p==NULL)
    {
        return ;
    }
    fclose(p);
    p=fopen("pagos.dat","ab");
    if(p==NULL)
    {
        return ;
    }
    while(fread(&reg,sizeof(pago),1,pback)==1)
    {

        fwrite(&reg,sizeof(pago),1,p);
    }


    fclose(p);
    fclose(pback);

    cout<<"Se cargo el backup de pago con exito"<<endl;
    return;
}

void generar_backup_productos(){
   productos reg;
    FILE  *pback,*p;
    p=fopen("productos.dat","rb");
    if(p==NULL)
    {
        cout<<"El archivo productos.dat no existe"<<endl;
        return ;
    }
    pback=fopen("bck/backupproductos.dat","wb");


    if(pback==NULL)
    {
        return ;
    }

    fclose(pback);
    pback=fopen("bck/backupproductos.dat","ab");


    if(pback==NULL)
    {
        return ;
    }


    while(fread(&reg,sizeof(productos),1,p)==1)
    {

        fwrite(&reg,sizeof(productos),1,pback);
    }

    cout<<"Se Realizo Backup del Archivo productos.dat Con Exito!"<<endl;
    fclose(p);
    fclose(pback);
    return;
}

void restaurar_backup_productos(){
   productos reg;

    FILE  *pback,*p;
    pback=fopen("bck/backupproductos.dat","rb");
    if(pback==NULL)
    {
        cout<<"No existe archivo para poder realizar el backup de productos"<<endl;
        return ;
    }
    p=fopen("productos.dat","wb");
    if(p==NULL)
    {
        return ;
    }
    fclose(p);
    p=fopen("productos.dat","ab");
    if(p==NULL)
    {
        return ;
    }
    while(fread(&reg,sizeof(productos),1,pback)==1)
    {

        fwrite(&reg,sizeof(productos),1,p);
    }


    fclose(p);
    fclose(pback);

    cout<<"Se cargo el backup de productos con exito"<<endl;
    return;
}

void generar_backup_detalles()
{
    detalle_venta reg;
    FILE  *pback,*p;
    p=fopen("detalle_ventas.dat","rb");
    if(p==NULL)
    {
        cout<<"El archivo detalle_ventas.dat no existe"<<endl;
        return ;
    }
    pback=fopen("bck/detalle_ventas.dat","wb");


    if(pback==NULL)
    {
        return ;
    }

    fclose(pback);
    pback=fopen("bck/detalle_ventas.dat","ab");


    if(pback==NULL)
    {
        return ;
    }


    while(fread(&reg,sizeof(detalle_venta),1,p)==1)
    {

        fwrite(&reg,sizeof(detalle_venta),1,pback);
    }

    cout<<"Se Realizo Backup del Archivo detalle_ventas.dat Con Exito!"<<endl;
    fclose(p);
    fclose(pback);
    return;
}

void restaurar_detalle_ventas(){
  detalle_venta reg;

    FILE  *pback,*p;
    pback=fopen("bck/detalle_ventas.dat","rb");
    if(pback==NULL)
    {
        cout<<"No existe archivo para poder realizar el backup de detalle_ventas"<<endl;
        return ;
    }
    p=fopen("detalle_ventas.dat","wb");
    if(p==NULL)
    {
        return ;
    }
    fclose(p);
    p=fopen("detalle_ventas.dat","ab");
    if(p==NULL)
    {
        return ;
    }
    while(fread(&reg,sizeof(detalle_venta),1,pback)==1)
    {

        fwrite(&reg,sizeof(detalle_venta),1,p);
    }


    fclose(p);
    fclose(pback);

    cout<<"Se cargo el backup de detalle_venta con exito"<<endl;
    return;
}

#endif // BACK_UP_H_INCLUDED
