#ifndef VENTAS_H_INCLUDED
#define VENTAS_H_INCLUDED

///si tenes un cin y luego del cin un cin.getline entre medio va cin.ignore
///o algo que libere el buffer y si tenes dos ignores juntos entre medio no va nada

#include "PERSONAS.h"
#include "detalle_venta.h"
#include "clientes.h"

float obtener_importe();
void alta_venta();
int contar_ventas();


///FALTA  UN CONSTRUCTOR DE DETALLE VENTA PARA CUANDO NO SE SOLICITA UN DNI

 class venta{
        private:
       Fecha fecha_venta;   /// se genera automaticamente con el constructor de fecha
        int id_venta;       ///se genera automaticamente en base a el archivo fecha
        float importe;      ///se obtiene desde el detalle de la venta
        int forma_pago;     ///se ingresa una sola vez
        bool estado;        ///se setea por defecto en true
        int id_cliente;     ///se ingresa una sola vez
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
        void leer_venta(int);
    };

    void venta::guardar_venta(){
    FILE *p;
    p=fopen("ventas.dat","ab");
    if(p==NULL){cout<<"ERROR VENTA EN GUARDAR VENTA"<<endl;
                    exit(1);}
  fwrite(this, sizeof *this,1,p);
    fclose(p);
    return ;
  }







    void venta::leer_venta(int pos){
  FILE *p;
  p=fopen("ventas.dat","rb");
  if(p==NULL)exit(1);
  fseek(p, sizeof *this*pos,0);//SEEK_SET
  fread(this, sizeof *this, 1, p);
  fclose(p);
  return;
  }



    void venta::cargar_venta(){ /// creo que esto no se usa
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

    cout<<"ID DE VENTA: "<<id_venta<<endl;
    cout<<"ID DE CLIENTE: "<<id_cliente<<endl;
    cout<<"IMPORTE DE LA VENTA: "<<importe<<endl;
    cout<<"FECHA DE VENTA: "<<endl;
    cout<<fecha_venta; ///consultar como funciona esto
}

float obtener_importe(int id_venta){
    FILE *p;
    int importe_final=0;
    p=fopen("detalle_ventas.dat","rb");
    if(p==NULL){cout<<"ERROR DE ARCHIVO EN OBTENER IMPORTE"<<endl;}
    detalle_venta obj;
    while(fread(&obj,sizeof(detalle_venta),1,p)){
        if(id_venta == obj.get_id_venta() && obj.get_estado() == true ){
         importe_final+=obj.get_precio_x_metro() * obj.get_metros_vendidos() ;
        }
    }
        return importe_final;
}

int contar_ventas(){

FILE *p;
long int cant_bytes;
int cant_regs;

p=fopen("ventas.dat","ab");
if(p==NULL){cout<<"ERROR DE ARCHIVO EN CONTAR VENTAS"<<endl;
                    exit(1);}
    fseek(p,0,SEEK_END);
    cant_bytes=ftell(p);
    cant_regs=cant_bytes/sizeof(venta);
    fclose(p);
    return cant_regs;
}

void alta_venta(){
venta venta_final;
detalle_venta detalles;
char opc;                   ///importe de la venta
int cant_art=1;
int nueva_id;

cout<<"MENU CARGAR VENTAS"<<endl;
cout<<"INGRESE LA ID DEL CLIENTE"<<endl;
cin>>nueva_id;
venta_final.set_id_cliente(nueva_id);
if(buscar_id_cliente(nueva_id)==false){cout<<"INGRESE UNA ID DE CLIENTE VALIDA"<<endl;
                                    cin>>nueva_id;
                                        venta_final.set_id_cliente(nueva_id);}
for(int i=0;i<cant_art;i++){
detalles.cargar_detalle_venta();
detalles.set_id_venta(contar_ventas()+1);
detalles.set_estado(true);
detalles.guardar_detalle_venta();
cout<<"DESEA CARGAR OTRO ARTICULO"<<endl;
cin>>opc;
if(opc == 'S'){cant_art++;}
    }
venta_final.set_id_venta(contar_ventas()+1);
venta_final.set_importe(obtener_importe(contar_ventas()+1));     ///obtener importe devuelve cero.
venta_final.set_estado(true);
venta_final.guardar_venta();
cout<<"CARGA DE LA VENTA FINALIZADA CON EXITO"<<endl;
system("pause");
}

void listar_ventas(){
FILE *p;
FILE *d;
p=fopen("ventas.dat","rb");
if(p==NULL){cout<<"ERROR DE ARCHIVO EN LISTAR VENTAS"<<endl;
                    exit(1);}
d=fopen("detalle_ventas.dat","rb");
if(d==NULL){cout<<"ERROR DE ARCHIVO EN LISTAR VENTAS 1"<<endl;
                    exit(1);}
int cantidad_ventas;
int cantidad_detalles;

venta venta_final;
detalle_venta detalle;

cantidad_ventas=contar_ventas();
cantidad_detalles=contar_detalles_venta();
cout<<endl;
cout<<"DETALLES: "<<cantidad_detalles<<endl;
cout<<"VENTAS: "<<cantidad_ventas<<endl;
cout<<endl;
cout<<"CANTITDAD DE VENTAS"<<contar_ventas()<<endl;

for(int i=0;i<cantidad_ventas;i++){

     cout<<endl;   cout<<"VUELTA DE VENTA NUMERO "<<i<<endl;

    ///MOSTRAR VENTAS GENERALES
      cout<<"==========="<<endl;
      venta_final.leer_venta(i);                ///LEE SOLO LA VENTA 1
      if(venta_final.get_id_venta()==i+1){          ///LEE LA ID DE VENTA 0+1
      venta_final.mostrar_venta();
                                }
    /// MOSTRAR DETALLES DE LA VENTA

        for(int t=0;t<cantidad_detalles;t++){
            cout<<endl;
                cout<<"VUELTA DE DETALLE"<<t<<endl;
        detalle.leer_detalle(t);
        if(detalle.get_id_venta()==i+1){
                detalle.mostrar_detalle_venta();

            }


        }

        cout<<"========="<<endl;

            }
    cout<<"fin del listado"<<endl;
    system("pause");
}
#endif // VENTAS_H_INCLUDED
