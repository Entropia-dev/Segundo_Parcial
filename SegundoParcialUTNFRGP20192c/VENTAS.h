#ifndef VENTAS_H_INCLUDED
#define VENTAS_H_INCLUDED

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

#endif // VENTAS_H_INCLUDED
