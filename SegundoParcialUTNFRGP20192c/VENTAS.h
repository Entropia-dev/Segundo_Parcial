#ifndef VENTAS_H_INCLUDED
#define VENTAS_H_INCLUDED

///si tenes un cin y luego del cin un cin.getline entre medio va cin.ignore
///o algo que libere el buffer y si tenes dos ignores juntos entre medio no va nada

///1 EFECTIVO 2 TARJETA CREDITO 3 TARJETA DEBITO 4 CUENTA CORRIENTE         5 MERCADO PAGO 6 CHEQUES
///----------||--------------------------------||SE REALIZA EL PAGO DESPUES ||------------||---------||

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
        void sobreescribir_venta(int );

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
  fseek(p, sizeof *this*pos,0);
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
/// fecha id de venta id de importe forma de pago id de estado id de cliente.
cout<<"MENU CARGAR VENTAS"<<endl;
cout<<"INGRESE LA ID DEL CLIENTE"<<endl;
cin>>nueva_id;
venta_final.set_id_cliente(nueva_id);
if(buscar_id_cliente(nueva_id)==false){cout<<"INGRESE UNA ID DE CLIENTE VALIDA"<<endl;
                                    cin>>nueva_id;          ///esto tiene que ser un while.
                                        venta_final.set_id_cliente(nueva_id);}
for(int i=0;i<cant_art;i++){                ///al inicio de la carga del detalle de venta preguntar si es distinto de null
detalles.set_id_venta(contar_ventas()+1);       ///y chequear si hay detalles del producto con la id de venta que se esta cargando en el momento
detalles.cargar_detalle_venta(contar_ventas()+1);                 ///si hay detalles previamente cargados con la id de venta correspondiente se debe
detalles.set_estado(true);                  ///omitir la solicitud del metodo de pago y la id de cliente de ser requerido
detalles.guardar_detalle_venta();           /// los datos se deberan re cargar con lo obtenido desde el registro previamente cargado.
cout<<"DESEA CARGAR OTRO ARTICULO"<<endl;   ///el detalle ya existe en disco a este punto
cin>>opc;
if(opc == 'S'){cant_art++;}
    }
venta_final.set_id_venta(contar_ventas()+1);
venta_final.set_importe(obtener_importe(contar_ventas()+1));
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
/*cout<<endl;
cout<<"DETALLES: "<<cantidad_detalles<<endl;
cout<<"VENTAS: "<<cantidad_ventas<<endl;
cout<<endl;

cout<<"CANTITDAD DE VENTAS"<<contar_ventas()<<endl;
*/
for(int i=0;i<cantidad_ventas;i++){

  //   cout<<endl;   cout<<"VUELTA DE VENTA NUMERO "<<i<<endl;

    ///MOSTRAR VENTAS GENERALES
        cout<<"INFORMACION GENERAL"<<endl;
        cout<<endl;
      venta_final.leer_venta(i);                ///LEE SOLO LA VENTA 1      ACA TENDRIA QUE CHEQUEAR EL ESTADO
      if(venta_final.get_id_venta()==i+1){          ///LEE LA ID DE VENTA 0+1
     if(venta_final.get_estado()==true) {

            venta_final.mostrar_venta();

            cout<<"================"<<endl;
        cout<<"PRODUCTOS E INFORMACION ADICIONAL"<<endl;
        cout<<endl;

        for(int t=0;t<cantidad_detalles;t++){

       //     cout<<endl;
      //          cout<<"VUELTA DE DETALLE"<<t<<endl;
        detalle.leer_detalle(t);
        if(detalle.get_id_venta()==i+1){
                ///lee los detalles correspondientes a una vuelta del primer for   ACA TENDRIA QUE CHEQUEAR EL ESTADO
                detalle.mostrar_detalle_venta();
                cout<<"============"<<endl;
            }


        }


                }
            }
                }
    cout<<"fin del listado"<<endl;
    system("pause");

}


void listar_venta_x_cliente(){
int id_cli;
cout<<"INGRESE LA ID DEL CLIENTE QUE DESEA LISTAR"<<endl;
cin>>id_cli;
int cantidad_ventas;
venta obj;
cantidad_ventas=contar_ventas();
for(int i=0;i<cantidad_ventas;i++){
obj.leer_venta(i);
    if(obj.get_id_cliente()==id_cli){
       if(obj.get_estado()==true){ obj.mostrar_venta();}
        }
    }
}



void listar_venta_x_anio(){
    int anio;
cout<<"INGRESE EL AÑO QUE DESEA LISTAR"<<endl;
cin>>anio;
int cantidad_ventas;
venta obj;
cantidad_ventas=contar_ventas();
for(int i=0;i<cantidad_ventas;i++){
obj.leer_venta(i);
    if(obj.getFecha().getAnio()==anio){
       cout<<"===================="<<endl;
        obj.mostrar_venta();
        }
    }
}


void listar_ventas_x_id(){
int id;
cout<<"INGRESE LA ID DE VENTA QUE SE DESEA LISTAR"<<endl;
cin>>id;
int cantidad_ventas;
venta obj;
cantidad_ventas=contar_ventas();
for(int i=0;i<cantidad_ventas;i++){
obj.leer_venta(i);
    if(obj.get_id_venta()==id){
        obj.mostrar_venta();
        }
    }
}

void listar_venta_x_mes(){
int mes;
cout<<"INGRESE EL MES QUE DESEA LISTAR"<<endl;
cin>>mes;
int cantidad_ventas;
venta obj;
cantidad_ventas=contar_ventas();
for(int i=0;i<cantidad_ventas;i++){
obj.leer_venta(i);
    if(obj.getFecha().getMes()==mes){
        obj.mostrar_venta();}
    }
}

void modificar_venta(){
int nuevo_cli;
int id_venta;
venta venta_final;
cout<<"INGRESE LA ID DE VENTA QUE DESEA MODIFICAR EL CLIETNE"<<endl;
cin>>id_venta;                                      ///crear funcion booleana que busque si la id de venta existe
cout<<"INGRESE LA NUEVA ID DEL CLIENTE"<<endl;
cin>>nuevo_cli;                                     ///crear funcion booleana que busque si la id de cliente existe
venta_final.leer_venta(id_venta-1);
venta_final.set_id_cliente(nuevo_cli);
venta_final.sobreescribir_venta(id_venta-1);
}

void eliminar_venta(){
venta obj;
detalle_venta detalle;
int cantidad_ventas=contar_ventas();
int cantidad_detalles=contar_detalles_venta();
int id_venta;
cout<<"INGRESE LA ID DE LA VENTA QUE DESEA ELIMINAR"<<endl;
cin>>id_venta;                           ///chequear que la id de venta exista
for(int i=0;i<cantidad_ventas;i++){
    obj.leer_venta(i);
    if(obj.get_id_venta() == id_venta){
        obj.set_estado(false);
        obj.sobreescribir_venta(id_venta-1);
        }
    }
    for(int t=0;t<cantidad_detalles;t++){
        detalle.leer_detalle(t);
        if(detalle.get_id_venta()==id_venta){
            detalle.set_estado(false);
            detalle.sobreescribir_detalle(detalle.get_id_detalle()-1);
                            }
                        }
                        cout<<"VENTA ELIMINADA CON EXITO"<<endl;

        }


void restaurar_venta(){
venta obj;
detalle_venta detalle;
int cantidad_ventas=contar_ventas();
int cantidad_detalles=contar_detalles_venta();
int id_venta;
cout<<"INGRESE LA ID DE LA VENTA QUE DESEA RESTAURAR"<<endl;
cin>>id_venta;                           ///chequear que la id de venta exista
for(int i=0;i<cantidad_ventas;i++){
    obj.leer_venta(i);
    if(obj.get_id_venta() == id_venta){
        obj.set_estado(true);
        obj.sobreescribir_venta(id_venta-1);
        }
    }
    for(int t=0;t<cantidad_detalles;t++){
        detalle.leer_detalle(t);
        if(detalle.get_id_venta()==id_venta){
            detalle.set_estado(true);
            detalle.sobreescribir_detalle(detalle.get_id_detalle()-1);
                            }
                        }
                        cout<<"VENTA RESTAURADA CON EXITO"<<endl;

        }



void venta::sobreescribir_venta(int pos){
  FILE *p;
  p=fopen("ventas.dat","rb+");
  if(p==NULL){cout<<"error de archivo en sobreescribir venta"<<endl;}
  fseek(p,sizeof *this * pos, 0);
  fwrite(this , sizeof *this ,1 ,p);
  fclose(p);
  return;
  }


#endif // VENTAS_H_INCLUDED
