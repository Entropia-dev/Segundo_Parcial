#ifndef VENTAS_H_INCLUDED
#define VENTAS_H_INCLUDED

///si tenes un cin y luego del cin un cin.getline entre medio va cin.ignore
///o algo que libere el buffer y si tenes dos ignores juntos entre medio no va nada

 class venta{
        private:
       Fecha fecha_venta;
        int id_venta;
        float importe;
        int forma_pago;
        bool estado;
        int id_cliente;
        public:
            ///==================SETS=====================================
        void set_id_venta(int nueva_id){id_venta = nueva_id;}
        void set_importe(float nuevo_importe){importe = nuevo_importe;}
        void set_forma_pago(int nueva_forma_pago){forma_pago=nueva_forma_pago;}
        void set_estado(bool nuevo_estado){estado = nuevo_estado;}
        void set_id_cliente(int nueva_id){id_cliente = nueva_id;}
	void setFecha_venta(Fecha f){fecha_venta =f;}

            ///====================GETS====================================
		Fecha getFecha(){return fecha_venta;}
            int get_id_venta(){return id_venta;}
            int get_id_cliente(){return id_cliente;}
            float get_importe(){return importe;}
            int get_forma_pago(){return forma_pago;}
            bool get_estado(){return estado;}
        ///====================CARGAR/MOSTRAR/GUARDAR==================
        void cargar_venta();
        void guardar_venta();
        void mostrar_venta();
    };

    void venta::cargar_venta(){
       cout<<"INGRESE LA FECHA DE VENTA"<<endl; ///tiene que setear la venta del dia auto.
    cin>>fecha_venta;   ///consultar como funciona esto
    cout<<"INGRESE LA ID DE LA VENTA"<<endl;    ///tiene que ser auto_numerico
    cin>>id_venta;
    cout<<"INGRESE EL IMPORTE"<<endl;
    cin>>importe;
    cout<<"INGRESE LA ID DEL CLIENTE"<<endl;    ///tiene que validar en archivo clientes
    cin>>id_cliente;

    }

    void venta::mostrar_venta(){

    cout<<"ID DE VENTA"<<id_venta<<endl;
    cout<<"ID DE CLIENTE"<<id_cliente<<endl;
    cout<<"IMPORTE DE LA VENTA"<<endl;
    cout<<"FECHA DE VENTA: "<<endl;
    cout<<fecha_venta; ///consultar como funciona esto
    }

#endif // VENTAS_H_INCLUDED
