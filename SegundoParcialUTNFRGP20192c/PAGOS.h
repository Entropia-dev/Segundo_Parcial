#ifndef PAGOS_H_INCLUDED
#define PAGOS_H_INCLUDED

   class pago{
    private:
    int id_pago;
    int id_venta;
    int forma_pago;
    Fecha fecha_pago;
    float importe;
    bool estado;
    public:
    ///==================SETS=====================================
    void set_id_pago(int nueva_id){id_pago=nueva_id;}
    void set_id_venta(int nueva_id){id_venta=nueva_id;}
    void set_forma_pago(int nueva_forma_pago){forma_pago = nueva_forma_pago;}
    void set_importe(float nuevo_importe){importe = nuevo_importe;}
    void set_estado(bool nuevo_estado){estado  = nuevo_estado;}
    void setFecha_venta(Fecha f){fecha_pago =f;}

        ///==================GETS=====================================
    Fecha getFecha(){return fecha_pago;}
    int get_id_pago(){return id_pago;}
    int get_id_venta(){return id_venta;}
    int get_forma_pago(){return forma_pago;}
    float get_importe(){return importe;}
    bool get_estado(){return estado;}
        ///====================CARGAR/MOSTRAR/GUARDAR==================
        void cargar_pago();
        void mostrar_pago();
        void guardar_pago();
    };

    void pago::cargar_pago(){
        Fecha nueva_fecha;
        int dia,mes,anio;
        cout<<"INGRESE EL DIA DEL PAGO"<<endl;
        cin>>dia;
        cout<<"INGRESE EL MES DEL PAGO"<<endl;
        cin>>mes;
        cout<<"INGRESE EL ANIO DEL PAGO"<<endl;
        cin>>anio;
    }

#endif // PAGOS_H_INCLUDED
