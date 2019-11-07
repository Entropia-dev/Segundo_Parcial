#ifndef DETALLE_VENTA_H_INCLUDED
#define DETALLE_VENTA_H_INCLUDED

#include "ventas.h"

bool buscar_detalle_x_id_venta(int id_venta);
char buscar_dni_venta(int id_venta);
int buscar_forma_pago(int id_venta);
int contar_detalles_venta();

///!!!SOLUCIONAR BUSCAR DNI VENTA !!!

class detalle_venta{
    private:
    float importe_prdocuto; /// se obtiene el  importe del producto listado en el detalle y para la venta se obitnene el detalle final.
    int id_producto;        ///se ingresa una sola vez
    int id_venta;           /// se obtiene de la venta
    bool estado;        /// se setea en verdadero
    int forma_pago;         /// se obtiene desde la venta
        char dni_cliente[9];    /// se solicita en caso de que el medio de pago lo requiera
    float metros_vendidos;          ///se ingresa una vez sola
    float precio_x_metro;           /// se obtiene mediante la id de prodcuto
    int id_detalle;
    public:
        ///==================SETS=====================================
        void set_id_producto(int nueva_id){id_producto = nueva_id;}
        void set_precio_x_metro(float nuevo_precio){precio_x_metro = nuevo_precio;}
        void set_id_venta(int nueva_id){id_venta = nueva_id;}
        void set_metros_vendidos(float cant_vendida){metros_vendidos = cant_vendida;}
        void set_dni_cliente(char *nuevo_dni){strcpy(dni_cliente, nuevo_dni);}
        void set_forma_pago(int nueva_forma_pago){forma_pago = nueva_forma_pago;}
        void set_estado(bool nuevo_estado){forma_pago = nuevo_estado;}
        void set_id_detalle(int nuevo_detalle){id_detalle = nuevo_detalle;}
        ///====================GETS====================================
        int get_id_producto(){return id_producto;}
        float get_precio_x_metro(){return precio_x_metro;}
        float get_metros_vendidos(){return metros_vendidos;}
        int get_id_venta(){return id_venta;}
        bool get_estado(){return estado;}
        int get_forma_pago(){return forma_pago;}
        char *get_dni_cliente(){return dni_cliente;}
        int get_id_detalle(){return id_detalle;}
        ///====================CARGAR/MOSTRAR/GUARDAR==================
        void cargar_detalle_venta(int);
        void mostrar_detalle_venta();
        bool guardar_detalle_venta();
        void leer_detalle(int);
        void sobreescribir_detalle(int);

    };



    void detalle_venta::cargar_detalle_venta(int id_venta_final){

    cout<<"INGRESE LA ID DE PRODUCTO"<<endl;

    cin>>id_producto;

    if(buscar_id_producto(id_producto)==false){

        cout<<"INGRESE UNA ID DE PRODUCTO VALIDA"<<endl;

        cin>>id_producto;
    }

    if(buscar_detalle_x_id_venta(id_venta_final)==true){    ///setea valores obtenidos de la primer carga para no tener que
    forma_pago=buscar_forma_pago(id_venta_final);           ///ingresarlos cada vez que se carga un producto-
   /// strcpy(dni_cliente,buscar_dni_venta(id_venta_final))   ///consultar el problema con el buscar dni de venta
    }else{
    cout<<"INGRESE LA FORMA DE PAGO"<<endl;

    cin>>forma_pago;

    while(forma_pago > 6 || forma_pago < 1){cout<<"INGRESE LA FORMA DE PAGO"<<endl;
                                                cin>>forma_pago;}



        if(forma_pago == 4){
    cout<<"INGRESE EL DNI DEL CLIENTE"<<endl;
    cin>>dni_cliente;         ///el dni del cliente luego sera solicitado solamente
                                ///seleccionando un metodo de pago que lo requiera
    }
            }
    cout<<"INGRESE LOS METROS VENDIDOS"<<endl;
    cin>>metros_vendidos;
    precio_x_metro=buscar_precio_producto(id_producto);

    id_detalle=contar_detalles_venta()+1;
    estado=true;
    return;


    }

    void detalle_venta::mostrar_detalle_venta(){
    cout<<"ID DE VENTA: "<<id_venta<<endl;
    cout<<"ID DEL PRODUCTO: "<<id_producto<<endl;
    cout<<"DNI CLIENTE: "<<dni_cliente<<endl;
    cout<<"PRECIO POR METRO: "<<precio_x_metro<<endl;
    cout<<"METROS VENDIDOS: "<<metros_vendidos<<endl;
    cout<<"FORMA DE PAGO: "<<forma_pago<<endl;
  //  cout<<"ID DEL DETALLE"<<id_detalle<<endl;
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

int contar_detalles_venta(){
FILE *p;
int cant_registros;
long int bytes_arch;
p=fopen("detalle_ventas.dat","rb");
if(p==NULL){cout<<"ERROR DE ARCHIVO EN CONTAR_DETALLES_VENTA"<<endl;
                    exit(1);}
        fseek(p,0,SEEK_END);
        bytes_arch=ftell(p);
    cant_registros=bytes_arch/sizeof(detalle_venta);
    fclose(p);
    return cant_registros;
}

void detalle_venta::leer_detalle(int pos){
  FILE *p;
  p=fopen("detalle_ventas.dat","rb");
  if(p==NULL)exit(1);
  fseek(p, sizeof *this*pos,0);
  fread(this, sizeof *this, 1, p);
  fclose(p);
  return;
}
/**
 char buscar_dni_venta(int id_venta){
char auxiliar[9] = "err_busc";
FILE *p;
detalle_venta obj;
p=fopen("detalle_ventas.dat","rb");
if(p==NULL){cout<<"ERROR DE ARCHIVO EN BUSCAR DNI VENTAS"<<endl;
                        exit(1);}
int cant_registros;
cant_registros=contar_detalles_venta();
for(int i=0;i<cant_registros;i++){
    obj.leer_detalle(i);
    if(obj.get_id_venta()==id_venta);
    return obj.get_dni_cliente();

            }
    return auxiliar;
}
**/
bool buscar_detalle_x_id_venta(int id_venta){
detalle_venta obj;
FILE *p;
p=fopen("detalle_ventas.dat","rb");
if(p==NULL){cout<<"ERROR DE ARCHIVO EN BUSCAR DETALLE X ID VENTA"<<endl;}
int cant_detalles;
cant_detalles=contar_detalles_venta();
for(int i=0;i<cant_detalles;i++){
    obj.leer_detalle(i);
    if(obj.get_id_venta()==id_venta){
     return true;
    }
}
return false;
}


int buscar_forma_pago(int id_venta){
detalle_venta obj;
FILE *p;
int cant_detalles;
p=fopen("detalle_ventas.dat","rb");
if(p==NULL){cout<<"ERROR DE ARCHIVO EN BUSCAR FORMA PAGO"<<endl;
                                exit(1);}
cant_detalles=contar_detalles_venta();
    for(int i=0;i<cant_detalles;i++){
    obj.leer_detalle(i);
    if(obj.get_id_venta()==id_venta ){
        return obj.get_forma_pago();
            }
        }
    return -1;
    }


void detalle_venta::sobreescribir_detalle(int pos){
  FILE *p;
  p=fopen("detalle_ventas.dat","rb+");
  if(p==NULL){cout<<"error de archivo en sobreescribir detalle"<<endl;}
  fseek(p,sizeof *this * pos, 0);
  fwrite(this , sizeof *this ,1 ,p);
  fclose(p);
  return;
  }


#endif // DETALLE_VENTA_H_INCLUDED
