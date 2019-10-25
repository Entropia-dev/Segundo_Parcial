#ifndef CLASES_H_INCLUDED
#define CLASES_H_INCLUDED


class persona{
protected:
char nombre[50];
char apellido[50];
char dni[9];
char e_mail[50];
char direccion[50];
public:
                ///====================SETS==================
void set_nombre(char *nuevo_nombre){strcpy(nombre , nuevo_nombre);}
void set_direccion(char *nueva_direccion){strcpy(direccion, nueva_direccion);}
void set_apellido(char *nuevo_apellido){strcpy(apellido, nuevo_apellido);}
void set_dni(char *nuevo_dni){strcpy(dni, nuevo_dni);}
void set_email(char *nuevo_email){strcpy(e_mail, nuevo_email);}
            ///============GETS========================
char *get_email(){return e_mail;}
char *get_direccion(){return direccion;}
char *get_nombre(){return nombre;}
char *get_apellido(){return apellido;}
char *get_dni(){return dni;}
        ///======================CARGAR/MOSTRAR====================
void cargar_persona();
void mostrar_persona();
};

class empleado:public persona {
	 private:
		int codigo_empleado;
		float sueldo;
		bool estado;
	 public:
        ///====================CARGAR/MOSTRAR/GUARDAR==================
		void Cargar_empleado();
		void Mostrar_empleado();
		bool guardar_empleado();
            ///====================SETS==================
		void set_codigo_empleado(int nuevo_codigo){codigo_empleado = nuevo_codigo;}
		void set_estado(bool nuevo_estado){estado = nuevo_estado;}
		void set_sueldo(float nuevo_sueldo){sueldo = nuevo_sueldo;}
                    ///====================GETS==================
		bool get_estado(){return estado;}
		int get_codigo_empleado(){return codigo_empleado;}
		float get_sueldo(){return sueldo;}

	 };

	 class cliente : public persona{
        private:
        int codigo_cliente;
        public:
            ///============================SETS=================================
            void set_codigo_cliente(int nuevo_codigo){codigo_cliente=nuevo_codigo;}
            ///=============================GETS======================================
            int get_codigo_cliente(){return codigo_cliente;}
            ///====================CARGAR/MOSTRAR/GUARDAR==================
            bool guardar_cliente();
            void mostrar_cliente();
            void cargar_cliente();
	 };

	 class productos {
        private:
    int id_producto;
	 float precio_x_metro;
	 char modelo[9];
	 bool estado;
        public:
            ///========================GETS====================================================
            int get_id_producto(){return id_producto;}
            bool get_estado(){return estado;}
            char *get_modelo(){return modelo;}
            float get_precio_x_metro(){return precio_x_metro;}
            ///=======================SETS====================================================
            void set_estado(bool nuevo_estado){estado= nuevo_estado;}
            void set_modelo(char *nuevo_modelo){strcpy(modelo, nuevo_modelo);}
             void set_precio_x_metro(float nuevo_precio){precio_x_metro = nuevo_precio;}
            void set_id_producto(int nueva_id){id_producto= nueva_id;}
            ///====================CARGAR/MOSTRAR/GUARDAR==================
            void cargar_producto();
            void mostrar_producto();
            bool guardar_producto();
	 };


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
        ///==================SETS=====================================
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

#endif // CLASES_H_INCLUDED

