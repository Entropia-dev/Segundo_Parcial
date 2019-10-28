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
        void guardar_detalle_venta();

    };



#endif // DETALLE_VENTA_H_INCLUDED
