#ifndef CLASES_H_INCLUDED
#define CLASES_H_INCLUDED

class productos
{
private:
    int id_producto;
    float precio_x_metro;
    char modelo[50];
    char color[50];
    bool estado;
    float stock;
public:
    ///============GETS====================================================
    float get_stock()
    {
        return stock;
    }
    int get_id_producto()
    {
        return id_producto;
    }
    bool get_estado()
    {
        return estado;
    }
    char *get_modelo()
    {
        return modelo;
    }
    char *get_color()
    {
        return color;
    }
    float get_precio_x_metro()
    {
        return precio_x_metro;
    }
    ///=======================SETS=========================================
    void set_stock(float nuevo_stock)
    {
        stock=nuevo_stock;
    }
    void set_estado(bool nuevo_estado)
    {
        estado= nuevo_estado;
    }
    void set_modelo(char *nuevo_modelo)
    {
        strcpy(modelo, nuevo_modelo);
    }
    void set_precio_x_metro(float nuevo_precio)
    {
        precio_x_metro = nuevo_precio;
    }
    void set_id_producto(int nueva_id)
    {
        id_producto= nueva_id;
    }
    void set_color(char *_color)
    {
        strcpy(color,_color);
    }
    ///====================CARGAR/MOSTRAR/GUARDAR==================
    void cargar_producto();
    void mostrar_producto();
    bool guardar_producto();
    bool leer_producto(int);
    void sobreescribir_producto(int);
    void decrementar_stock(int, float);
};

class persona
{
protected:
    char nombre[50];
    char apellido[50];
    char dni[9];
    char e_mail[50];
    char direccion[50];
public:
    ///====================SETS==================
    void set_nombre(char *nuevo_nombre)
    {
        strcpy(nombre, nuevo_nombre);
    }
    void set_direccion(char *nueva_direccion)
    {
        strcpy(direccion, nueva_direccion);
    }
    void set_apellido(char *nuevo_apellido)
    {
        strcpy(apellido, nuevo_apellido);
    }
    void set_dni(char *nuevo_dni)
    {
        strcpy(dni, nuevo_dni);
    }
    void set_email(char *nuevo_email)
    {
        strcpy(e_mail, nuevo_email);
    }
    ///============GETS========================
    char *get_email()
    {
        return e_mail;
    }
    char *get_direccion()
    {
        return direccion;
    }
    char *get_nombre()
    {
        return nombre;
    }
    char *get_apellido()
    {
        return apellido;
    }
   const char *get_dni()
    {
        return dni;
    }
    ///======================CARGAR/MOSTRAR====================
    void cargar_persona();
    void mostrar_persona();
};

class empleado:public persona
{
private:
    int codigo_empleado;
    float sueldo;
    bool estado;
public:
    ///====================CARGAR/MOSTRAR/GUARDAR/LEER==================
    void Cargar_empleado();
    void Mostrar_empleado();
    bool guardar_empleado();
    void leer_empleado(int);
    void sobreescribir_empleado(int);
    ///====================SETS==================
    void set_codigo_empleado(int nuevo_codigo)
    {
        codigo_empleado = nuevo_codigo;
    }
    void set_estado(bool nuevo_estado)
    {
        estado = nuevo_estado;
    }
    void set_sueldo(float nuevo_sueldo)
    {
        sueldo = nuevo_sueldo;
    }
    void set_id(int nueva_id) {}
    ///====================GETS==================
    bool get_estado()
    {
        return estado;
    }
    int get_codigo_empleado()
    {
        return codigo_empleado;
    }
    float get_sueldo()
    {
        return sueldo;
    }

};

class cliente:public persona
{
private:
    bool estado;
    int codigo_cliente;
public:
    ///============================SETS=================================
    void set_codigo_cliente(int nuevo_codigo)
    {
        codigo_cliente=nuevo_codigo;
    }
    void set_estado_cliente(bool nuevo_estado)
    {
        estado=nuevo_estado;
    }
    ///=============================GETS======================================
    int get_codigo_cliente()
    {
        return codigo_cliente;
    }
    bool get_estado_cliente()
    {
        return estado;
    }
    ///====================CARGAR/MOSTRAR/GUARDAR==================
    bool guardar_cliente();
    void mostrar_cliente();
    void cargar_cliente();
    void leer_cliente(int);
    bool sobreescribir_cliente(int);
    bool leerDeDisco(int);
};


class venta
{
private:
    Fecha fecha_venta;   /// se genera automaticamente con el constructor de fecha
    int id_venta;       ///se genera automaticamente en base a el archivo fecha
    float importe;      ///se obtiene desde el detalle de la venta
    int forma_pago;     ///se ingresa una sola vez
    bool estado;        ///se setea por defecto en true
    int id_cliente;     ///se ingresa una sola vez
public:
    ///==================SETS=====================================
    void set_id_venta(int nueva_id)
    {
        id_venta = nueva_id;
    }
    void set_importe(float nuevo_importe)
    {
        importe = nuevo_importe;
    }
    void set_forma_pago(int nueva_forma_pago)
    {
        forma_pago=nueva_forma_pago;
    }
    void set_estado(bool nuevo_estado)
    {
        estado = nuevo_estado;
    }
    void set_id_cliente(int nueva_id)
    {
        id_cliente = nueva_id;
    }
    void setFecha_venta(Fecha f)
    {
        fecha_venta =f;
    }

    ///====================GETS====================================
    Fecha getFecha()
    {
        return fecha_venta;
    }
    int get_id_venta()
    {
        return id_venta;
    }
    int get_id_cliente()
    {
        return id_cliente;
    }
    float get_importe()
    {
        return importe;
    }
    int get_forma_pago()
    {
        return forma_pago;
    }
    bool get_estado()
    {
        return estado;
    }
    ///====================CARGAR/MOSTRAR/GUARDAR==================
    void cargar_venta();
    void guardar_venta();
    void mostrar_venta();
    void leer_venta(int);
    void sobreescribir_venta(int );
    bool leerDeDisco(int);

};

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

    void set_id_cliente(int nueva_id)
    {
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
    int get_id_cliente()
    {
        return id_cliente;
    }

    ///====================CARGAR/MOSTRAR/GUARDAR==================
    int cargar_pago();
    void mostrar_pago();
    bool guardar_pago();
    void leer_pago(int);
    bool leerDeDisco(int);
    int modificar_en_disco(int);
    ///=====================OTROS==================================
    void generar_pago_total(int, int, int );
};

#endif // CLASES_H_INCLUDED
