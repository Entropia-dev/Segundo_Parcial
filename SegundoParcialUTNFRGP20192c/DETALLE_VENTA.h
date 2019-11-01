#ifndef DETALLE_VENTA_H_INCLUDED
#define DETALLE_VENTA_H_INCLUDED

class detalle_venta{
    private:
    float importe_prdocuto; /// se obtiene el  importe del producto listado en el detalle y para la venta se obitnene el detalle final.
    int id_producto;
    int id_venta;
    bool estado;
    int forma_pago;
        char dni_cliente[9];
    float metros_vendidos;
    float precio_x_metro;
    public:
        ///==================SETS=====================================
        void set_id_producto(int nueva_id){id_producto = nueva_id;}
        void set_precio_x_metro(float nuevo_precio){precio_x_metro = nuevo_precio;}
        void set_id_venta(int nueva_id){id_venta = nueva_id;}
        void set_metros_vendidos(float cant_vendida){metros_vendidos = cant_vendida;}
        void set_dni_cliente(char *nuevo_dni){strcpy(dni_cliente, nuevo_dni);}
        void set_forma_pago(int nueva_forma_pago){forma_pago = nueva_forma_pago;}
        void set_estado(bool nuevo_estado){forma_pago = nuevo_estado;}
        ///====================GETS====================================
        int get_id_producto(){return id_producto;}
        float get_precio_x_metro(){return precio_x_metro;}
        float get_metros_vendidos(){return metros_vendidos;}
        int get_id_venta(){return id_venta;}
        bool get_estado(){return estado;}
        int get_forma_pago(){return forma_pago;}
        char *get_dni_cliente(){return dni_cliente;}
        ///====================CARGAR/MOSTRAR/GUARDAR==================
        void cargar_detalle_venta();
        void mostrar_detalle_venta();
        bool guardar_detalle_venta();

    };

    void detalle_venta::cargar_detalle_venta(){
    cout<<"INGRESE LA ID DE PRODUCTO"<<endl;
    cin>>id_producto;
    cout<<"INGRESE LA ID DE LA VENTA"<<endl;
    cin>>id_venta;
    cout<<"INGRESE LA FORMA DE PAGO"<<endl;
    cin>>forma_pago;
    cout<<"INGRESE LOS METROS VENDIDOS"<<endl;
    cin>>metros_vendidos;
    cout<<"INGRESE EL PRECIO POR METRO"<<endl; ///despues hay que hacer que se auto
    cin>>precio_x_metro;                       ///obtenga en base al archivo prodcutos
    cout<<"INGRESE EL DNI DEL CLIENTE"<<endl;
    cin>>dni_cliente;         ///el dni del cliente luego sera solicitado solamente
                                ///seleccionando un metodo de pago que lo requiera
    estado=true;
    return;
    }

    void detalle_venta::mostrar_detalle_venta(){
    cout<<"ID DE VENTA"<<id_venta;
    cout<<"ID DEL PRODUCTO"<<id_producto;
    cout<<"DNI CLIENTE"<<dni_cliente;
    cout<<"PRECIO POR METRO"<<precio_x_metro;
    cout<<"METROS VENDIDOS"<<metros_vendidos;
    cout<<"FORMA DE PAGO"<<forma_pago;
    cout<<"INGRESE EL IMPORTE"<<importe_prdocuto;
    }

    bool detalle_venta::guardar_detalle_venta(){
    bool grabo;
    FILE *p;
    p=fopen("detalle_ventas.dat","ab");
    if(p==NULL){cout<<"ERROR DE ARCHIVO EN DETALLE_VENTA::GUARDAR_DETALLE"<<endl;
                            exit(1);}
    grabo=fwrite(this,sizeof *this , 1 ,p);
    fclose(p);
    return grabo;
    }


#endif // DETALLE_VENTA_H_INCLUDED
