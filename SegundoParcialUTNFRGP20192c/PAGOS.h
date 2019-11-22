#ifndef PAGOS_H_INCLUDED
#define PAGOS_H_INCLUDED

int contar_pagos();

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

    void set_id_cliente()

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
    void cargar_pago();
    void mostrar_pago();
    bool guardar_pago();
    ///=====================OTROS==================================
    void generar_pago_total();
};

void pago::cargar_pago(){

    cout<<"ID DE PAGO: "<<endl;
    cin>>id_pago;
    cout<<"ID DE VENTA: "<<endl;
    cin>>id_venta;
    cout<<"FORMA DE PAGO: "<<endl;
    cin>>forma_pago;
    cout<<"IMPORTE: "<<endl;
    cin>>importe;
    estado = true;
    cin>>fecha_pago;
    return;
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

///
///cout<<"1)NUEVO PAGO"<<endl;
///cout<<"2)LISTAR TODOS LOS PAGOS"<<endl;
///cout<<"3)LISTAR PAGO POR TIPO"<<endl;
///cout<<"4)LISTAR PAGO POR CLIENTE"<<endl;
///cout<<"5)LISTAR PAGO POR ID"<<endl;
///cout<<"6)CANCELAR PAGO"<<endl

void alta_pago(){
int id_cliente;
pago obj;
cout<<"INGRESE LA ID DEL CLIENTE QUE REALIZA EL PAGO"<<endl;
cin>>id_cliente;
if(buscar_id_cliente(id_cliente)==false){cout<<"NO SE ENCONTRO EL CLIENTE , INTENETLO NUEVAMENTE "
                                            system("pause"); return;}
if(buscar_estado_cliente(id_cliente)==false){cout<<"LOS CLIENTES DADOS DE BAJA NO PUEDEN REALIZAR PAGOS"<<endl;
                                                        system("pause"); return;}
pago.set_
}


#endif // PAGOS_H_INCLUDED
