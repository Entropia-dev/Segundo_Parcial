#ifndef PAGOS_H_INCLUDED
#define PAGOS_H_INCLUDED

int contar_pagos();
float buscar_total_pagado(int);

class pago
{
private:
    int id_cliente; ///HAY QUE INGRESAR
    int id_pago;    /// SE AUTO GENERA
    int id_venta;   ///HAY QUE INGRESAR
    int forma_pago; /// VENTA
    Fecha fecha_pago;   ///TIENE CONSTRUCTORES PARA OBTENER LA FECHA DEL DIA
    float importe;  /// EN CASO DE QUE SEA CUENTA CORRIENTE HAY QUE INGRESARLO
    bool estado;    /// SE OBTIENE POR DEFECTO EN TRUE
public:
    ///==================SETS=====================================
    void set_id_pago(int nueva_id)
    {
        id_pago=nueva_id;
    }
    void set_id_venta(int nueva_id)
    {
        id_venta=nueva_id;
    }
    void set_forma_pago(int nueva_forma_pago)
    {
        forma_pago = nueva_forma_pago;
    }
    void set_importe(float nuevo_importe)
    {
        importe = nuevo_importe;
    }
    void set_estado(bool nuevo_estado)
    {
        estado  = nuevo_estado;
    }
    void setFecha_venta(Fecha f)
    {
        fecha_pago =f;
    }

    void set_id_cliente(int nueva_id){
    id_cliente=nueva_id;
    }

    ///==================GETS=====================================
    Fecha getFecha()
    {
        return fecha_pago;
    }
    int get_id_pago()
    {
        return id_pago;
    }
    int get_id_venta()
    {
        return id_venta;
    }
    int get_forma_pago()
    {
        return forma_pago;
    }
    float get_importe()
    {
        return importe;
    }
    bool get_estado()
    {
        return estado;
    }
    ///====================CARGAR/MOSTRAR/GUARDAR==================
    int cargar_pago();
    void mostrar_pago();
    bool guardar_pago();
    void leer_pago(int);
    ///=====================OTROS==================================
    void generar_pago_total();
};

int pago::cargar_pago(){
    system("cls");
    cout<<"=============================MENU PAGOS==============================="<<endl;
    float resto;
    /// cada pago se tendria que generar y guardar en un archivo por ejemplo "pagos.dat"
    /// para que puedas saber si a algun cliente le falta por pagar.

    cout<<"INGRESE LA ID CLIENTE QUE EFECTUA EL PAGO"<<endl;
    cin>>id_cliente;
    if(buscar_id_cliente(id_cliente)==false){cout<<"no se encontro la id de cliente , intentelo nuevamente"<<endl;}
    if(buscar_estado_cliente(id_cliente)==false){cout<<"el cliente se encuenta dado de baja , intentelo nuevamente"<<endl; system("pause"); return -1;} /// hay que validar que exista  y no este dado de baja.
    id_pago=contar_pagos()+1;
    cout<<"INGRESE ID DE VENTA A PAGAR: "<<endl;
    cin>>id_venta;
     if(buscar_id_venta(id_venta)==false){cout<<"no se encontro la venta , intentelo nuevamente"<<endl; system("pause"); return -1;}           ///para saber cuanto es el total a pagar. falta validar la venta

    forma_pago = obtener_forma_pago(id_venta);
    if(forma_pago == -1){cout<<"error al obtener la forma de pago !"; system("pause"); return -1;}

    ///========================================================================================================================
    if(obtener_importe_venta(id_venta) - buscar_total_pagado(id_venta)==0){cout<<"ESTA VENTA FUE SALDADA POR COMPLETO "<<endl; system("pause"); return -1;}
    cout<<"RESTA ABONAR "<<obtener_importe_venta(id_venta) - buscar_total_pagado(id_venta)<<"$"<<endl;
    resto = obtener_importe_venta(id_venta) - buscar_total_pagado(id_venta);
    ///========================================================================================================================

    cout<<"TOTAL ABONADO: "<<endl;
    cin>>importe;
    if(importe < 0){cout<<"EL TOTAL ABONADO NO PUEDE SER UN NUMERO NEGATIVO , INTENTELO NUEVAMENTE"<<endl;
                        system("pause"); return -1;}
    if(resto < importe){cout<<"vuelto: "<<importe - resto <<"$"<<endl;}
    if(resto < importe){importe = obtener_importe_venta(id_venta);} ///esto es para que se registre la venta efectuada por el total
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
    if(p==NULL){
            cout<<"ERROR DE ARCHIVO EN LEER_PAGO"<<endl;
        exit(1);
    }
    fseek(p, sizeof *this*pos,0);
    fread(this, sizeof *this, 1, p);
    fclose(p);
    return;
}



void alta_pago(){
int id_cliente;
pago obj;
        if(obj.cargar_pago()==-1){return;}
    if(obj.guardar_pago()){cout<<"PAGO GUARDADO CON EXITO"<<endl; system("pause"); return;}

}


float buscar_total_pagado(int id_venta) ///busca todos los pagos en referencia a una id de venta para saber cuanto falta pagar.
{
pago obj;
float total_abonado=0;
int cantidad_pagos = contar_pagos();
for(int i=0;i<cantidad_pagos;i++){
    obj.leer_pago(i);
    total_abonado+=obj.get_importe();
    }
    return total_abonado;
}

#endif // PAGOS_H_INCLUDED
