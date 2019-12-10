#ifndef VENTAS_H_INCLUDED
#define VENTAS_H_INCLUDED

#include "pagos.h"

bool buscar_detalle_x_id_venta(int id_venta);
char buscar_dni_venta(int id_venta);
int contar_detalles_venta();
void listar_ventas();
void listar_ventas_x_id();
void listar_venta_x_cliente();
void listar_venta_x_anio();
void listar_venta_x_mes();
bool buscar_id_venta(int);
void alta_venta();
int obtener_forma_pago(int);
float obtener_importe_venta(int);



class detalle_venta
{
private:
    float importe_producto; /// se obtiene el  importe del producto listado en el detalle y para la venta se obitnene el detalle final.
    int id_producto;        ///se ingresa una sola vez
    int id_venta;           /// se obtiene de la venta
    bool estado;        /// se setea en verdadero
    float metros_vendidos;          ///se ingresa una vez sola
    float precio_x_metro;           /// se obtiene mediante la id de prodcuto
public:
    ///==================SETS=====================================
    void set_id_producto(int nueva_id)
    {
        id_producto = nueva_id;
    }
    void set_precio_x_metro(float nuevo_precio)
    {
        precio_x_metro = nuevo_precio;
    }
    void set_id_venta(int nueva_id)
    {
        id_venta = nueva_id;
    }
    void set_metros_vendidos(float cant_vendida)
    {
        metros_vendidos = cant_vendida;
    }
    ///====================GETS====================================
    int get_id_producto()
    {
        return id_producto;
    }
    float get_precio_x_metro()
    {
        return precio_x_metro;
    }
    float get_metros_vendidos()
    {
        return metros_vendidos;
    }
    int get_id_venta()
    {
        return id_venta;
    }
    bool get_estado()
    {
        return estado;
    }
    float get_importe_producto()
    {
        return importe_producto;
    }
    ///====================CARGAR/MOSTRAR/GUARDAR==================
    bool cargar_detalle_venta();
    void mostrar_detalle_venta();
    bool guardar_detalle_venta();
    void leer_detalle(int);
    void sobreescribir_detalle(int);

};


int contar_ventas()
{

    FILE *p;
    long int cant_bytes;
    int cant_regs;

    p=fopen("ventas.dat","rb");
    if(p==NULL)
    {
        cout<<"ERROR DE ARCHIVO EN CONTAR VENTAS"<<endl;
        exit(1);
    }
    fseek(p,0,SEEK_END);
    cant_bytes=ftell(p);
    cant_regs=cant_bytes/sizeof(venta);
    fclose(p);
    return cant_regs;
}

bool detalle_venta::cargar_detalle_venta()
{

    cout<<"INGRESE LA ID DE PRODUCTO"<<endl;
    cin>>id_producto;
    if(buscar_id_producto(id_producto)==false)
    {
        cout<<"NO SE ENCONTRO EL PRODUCTO BUSCADO , INTENTELO NUEVAMENTE"<<endl; return false;
    }
    cout<<"INGRESE LOS METROS VENDIDOS"<<endl;
    cin>>metros_vendidos;
    if(metros_vendidos < 0){cout<<"NO SE PUEDE VENDER UNA CANTIDAD DE METROS NEGATIVA , INTENTE NUEVAMENTE"<<endl;
                                    system("pause"); return false;}
    precio_x_metro=buscar_precio_producto(id_producto);
    id_venta=contar_ventas()+1;
    estado=true;
    return true;
}

void detalle_venta::mostrar_detalle_venta()
{
    //cout<<"ID DE VENTA: "<<id_venta<<endl;
    cout<<"ID DEL PRODUCTO: "<<id_producto<<endl;
    cout<<"PRECIO POR METRO: "<<precio_x_metro<<endl;
    cout<<"METROS VENDIDOS: "<<metros_vendidos<<endl;
}

bool detalle_venta::guardar_detalle_venta()
{
    bool grabo;
    FILE *p;
    p=fopen("detalle_ventas.dat","ab");
    if(p==NULL)
    {
        cout<<"ERROR DE ARCHIVO EN DETALLE_VENTA::GUARDAR_DETALLE"<<endl;
        exit(1);
    }
    grabo=fwrite(this,sizeof *this, 1,p);
    fclose(p);
    return grabo;
}

int contar_detalles_venta()
{
    FILE *p;
    int cant_registros;
    long int bytes_arch;
    p=fopen("detalle_ventas.dat","rb");
    if(p==NULL)
    {
        cout<<"ERROR DE ARCHIVO EN CONTAR_DETALLES_VENTA"<<endl;
        exit(1);
    }
    fseek(p,0,SEEK_END);
    bytes_arch=ftell(p);
    cant_registros=bytes_arch/sizeof(detalle_venta);
    fclose(p);
    return cant_registros;
}

void detalle_venta::leer_detalle(int pos)
{
    FILE *p;
    p=fopen("detalle_ventas.dat","rb");
    if(p==NULL)
        exit(1);
    fseek(p, sizeof *this*pos,0);
    fread(this, sizeof *this, 1, p);
    fclose(p);
    return;
}


bool buscar_detalle_x_id_venta(int id_venta)
{
    detalle_venta obj;
    FILE *p;
    p=fopen("detalle_ventas.dat","rb");
    if(p==NULL)
    {
        cout<<"ERROR DE ARCHIVO EN BUSCAR DETALLE X ID VENTA"<<endl;
    }
    int cant_detalles;
    cant_detalles=contar_detalles_venta();
    for(int i=0; i<cant_detalles; i++)
    {
        obj.leer_detalle(i);
        if(obj.get_id_venta()==id_venta)
        {
            return true;
        }
    }
    return false;
}


void detalle_venta::sobreescribir_detalle(int pos)
{
    FILE *p;
    p=fopen("detalle_ventas.dat","rb+");
    if(p==NULL)
    {
        cout<<"error de archivo en sobreescribir detalle"<<endl;
    }
    fseek(p,sizeof *this * pos, 0);
    fwrite(this, sizeof *this,1,p);
    fclose(p);
    return;
}
///si tenes un cin y luego del cin un cin.getline entre medio va cin.ignore
///o algo que libere el buffer y si tenes dos ignores juntos entre medio no va nada

///1 EFECTIVO 2 TARJETA CREDITO 3 TARJETA DEBITO 4 CUENTA CORRIENTE         5 MERCADO PAGO 6 CHEQUES
///----------||--------------------------------||SE REALIZA EL PAGO DESPUES ||------------||---------||

float obtener_importe();
void alta_venta();
int contar_ventas();


void venta::guardar_venta()
{
    FILE *p;
    p=fopen("ventas.dat","ab");
    if(p==NULL)
    {
        cout<<"ERROR VENTA EN GUARDAR VENTA"<<endl;
        exit(1);
    }
    fwrite(this, sizeof *this,1,p);
    fclose(p);
    return ;
}







void venta::leer_venta(int pos)
{
    FILE *p;
    p=fopen("ventas.dat","rb");
    if(p==NULL)
        exit(1);
    fseek(p, sizeof *this*pos,0);
    fread(this, sizeof *this, 1, p);
    fclose(p);
    return;
}

void venta::mostrar_venta()
{

    cout<<"ID DE VENTA: "<<id_venta<<endl;
    cout<<"ID DE CLIENTE: "<<id_cliente<<endl;
    cout<<"IMPORTE DE LA VENTA: "<<importe<<endl;
    cout<<"FECHA DE VENTA: "<<endl;
    fecha_venta.MostrarFecha();
}

float obtener_importe(int id_venta)
{
    FILE *p;
    int importe_final=0;
    p=fopen("detalle_ventas.dat","rb");
    if(p==NULL)
    {
        cout<<"ERROR DE ARCHIVO EN OBTENER IMPORTE"<<endl;
    }
    detalle_venta obj;
    while(fread(&obj,sizeof(detalle_venta),1,p))
    {
        if(id_venta == obj.get_id_venta() && obj.get_estado() == true )
        {
            importe_final+=obj.get_precio_x_metro() * obj.get_metros_vendidos() ;
        }
    }
    return importe_final;
}



void alta_venta()
{
    pago pago_total;
    venta venta_final;
    detalle_venta detalles;
    int nueva_id;
    productos obj;
    cout<<"MENU CARGAR VENTAS"<<endl;
    cout<<"INGRESE LA ID DEL CLIENTE"<<endl;
    cin>>nueva_id;
    venta_final.set_id_cliente(nueva_id);

    if(buscar_id_cliente(nueva_id)==false)
    {
        cout<<"NO SE ENCONTRO LA ID DEL CLIENTE, INTENTELO NUEVAMENTE"<<endl;
        system("pause");
        return;
    }

    if(buscar_estado_cliente(nueva_id)==false){cout<<"EL CLIENTE SE ENCUENTRA DADO DE BAJA , INTENTELO NUEVAMENTE"<<endl;
          system("pause");  return;}

    cout<<"INGRESE LA FORMA DE PAGO (UN NUMERO ENTERO ENTRE 1 Y 6): ";
    int fp;
    cin>>fp;
    if(fp<1 || fp > 6){cout<<"FORMA DE PAGO NO VALIDA , INTENTE NUEVAMENTE "<<endl;
                            system("pause"); return;}

    venta_final.set_forma_pago(fp);
    venta_final.set_importe(0);
    venta_final.set_id_venta(contar_ventas()+1);
///detalles de la venta;
    char continuar='s';
    while(continuar=='s')
    {
         if(detalles.cargar_detalle_venta()==false){cout<<"NO SE PUDO DAR DE ALTA LA VENTA INTENTE NUEVAMENTE"<<endl;
                                                            system("pause");}
      obj.leer_producto(detalles.get_id_producto()-1);
        if(detalles.get_metros_vendidos()  > obj.get_stock()){cout<<"NO DISPONEMOS DEL STOCK NECESARIO PARA REALIZAR LA VENTA"<<endl;   system("pause");    return;}
        detalles.guardar_detalle_venta();
        cout<<"DESEA INGRESAR OTRO PRODUCTO (s: SI; n: NO) :";
        cin>>continuar;
            obj.decrementar_stock(detalles.get_id_producto(),detalles.get_metros_vendidos());
                ///mostrar costo de venta e informacion parcial ?
          }

    venta_final.set_importe(obtener_importe(contar_ventas()+1));
    venta_final.set_estado(true);

    venta_final.guardar_venta();
    cout<<endl;
    cout<<"===================================RESUMEN DE VENTA================================"<<endl;
        venta_final.mostrar_venta();
        /// por aca se tendria que mostrar la venta con el importe final a pagar y demas informacion
        /// en caso de ser un pago realizado por cualquier medio que no sea cuenta corriente se tendria que generar
        /// un registro en el archivo de pagos con la informacion obtenida de  la venta
    cout<<"==================================================================================="<<endl;
     if(fp!=4){pago_total.generar_pago_total(venta_final.get_id_venta(),venta_final.get_id_cliente(),venta_final.get_forma_pago());}
    cout<<"CARGA DE LA VENTA FINALIZADA CON EXITO"<<endl;
    system("pause");
}

void listar_ventas()
{


    int cantidad_ventas;
    int cantidad_detalles;

    venta venta_final;
    detalle_venta detalle;

    cantidad_ventas=contar_ventas();
    if(cantidad_ventas == 0){cout<<"NO SE ENCONTRARON VENTAS REGISTRADAS "<<endl;
        system("pause"); return;}
    cantidad_detalles=contar_detalles_venta();
    for(int i=0; i<cantidad_ventas; i++)
    {

        cout<<endl;
        venta_final.leer_venta(i);
        if(venta_final.get_id_venta()==i+1)
        {
            if(venta_final.get_estado()==true)
            {
                cout<<"RESUMEN DE LA VENTA"<<endl;
                venta_final.mostrar_venta();

                cout<<"================"<<endl;
                cout<<"PRODUCTOS VENDIDOS"<<endl;
                cout<<endl;

                for(int t=0; t<cantidad_detalles; t++)
                {
                    detalle.leer_detalle(t);
                    if(detalle.get_id_venta()-1==i)
                    {

                        detalle.mostrar_detalle_venta();
                        cout<<"============"<<endl;
                    }   ///CIERRE DEL FOR DEL DETALLE DE VENTAS
                }   ///CIERRE DEL IF DE DETALLE DE VENTAS

            }


        }
    }

    cout<<"fin del listado"<<endl;
    system("pause");

}


void listar_venta_x_cliente()
{
    int id_cli;
    cout<<"INGRESE LA ID DEL CLIENTE QUE DESEA LISTAR"<<endl;
    cin>>id_cli;
    int cantidad_ventas;
    venta obj;
    cantidad_ventas=contar_ventas();
    for(int i=0; i<cantidad_ventas; i++)
    {
        obj.leer_venta(i);
        if(obj.get_id_cliente()==id_cli)
        {
            if(obj.get_estado()==true)
            {
                obj.mostrar_venta();
            }
            cout<<"==================="<<endl;
        }
    }
    cout<<"FIN DEL LISTADO"<<endl;
    system("pause");
}


void listar_venta_x_anio()
{
    int anio;
    cout<<"INGRESE EL AÑO QUE DESEA LISTAR"<<endl;
    cin>>anio;
    cout<<"=================="<<endl;
    int cantidad_ventas;
    venta obj;
    cantidad_ventas=contar_ventas();
    for(int i=0; i<cantidad_ventas; i++)
    {
        obj.leer_venta(i);
        if(obj.getFecha().getAnio()==anio)
        {

            obj.mostrar_venta();
            cout<<"===================="<<endl;
        }
    }
    cout<<"FIN DEL LISTADO"<<endl;
    system("pause");
}


void listar_ventas_x_id()
{
    int id;
    cout<<"INGRESE LA ID DE VENTA QUE SE DESEA LISTAR"<<endl;
    cin>>id;
    int cantidad_ventas;
    venta obj;
    cantidad_ventas=contar_ventas();
    for(int i=0; i<cantidad_ventas; i++)
    {
        obj.leer_venta(i);
        if(obj.get_id_venta()==id)
        {
            obj.mostrar_venta();
        }
    }
    system("pause");
}

void listar_venta_x_mes()
{
    int mes;
    cout<<"INGRESE EL MES QUE DESEA LISTAR"<<endl;
    cin>>mes;
    int cantidad_ventas;
    venta obj;
    cantidad_ventas=contar_ventas();
    cout<<"=========="<<endl;
    for(int i=0; i<cantidad_ventas; i++)
    {
        obj.leer_venta(i);
        if(obj.getFecha().getMes()==mes && obj.get_estado() == true)
        {
            obj.mostrar_venta();
            cout<<"=========="<<endl;
        }

    }
    system("pause");
}

void modificar_venta()
{
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

void eliminar_venta()
{
    venta obj;
    int cantidad_ventas=contar_ventas();
    int id_venta;

    cout<<"INGRESE LA ID DE LA VENTA QUE DESEA ELIMINAR"<<endl;
    cin>>id_venta;
    if(buscar_id_venta(id_venta)==false)
    {
        cout<<"NO SE ENCONTRO LA ID DE VENTA , INTENTE NUEVAMENTE"<<endl;
        system("pause");
        return;
    }
    for(int i=0; i<cantidad_ventas; i++)
    {
        obj.leer_venta(i);
        if(obj.get_id_venta() == id_venta)
        {
            obj.set_estado(false);
            obj.sobreescribir_venta(id_venta-1);
        }
    }

    cout<<"VENTA ELIMINADA CON EXITO"<<endl;
    system("pause");

}


void restaurar_venta()
{
    /*
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
    */
}



void venta::sobreescribir_venta(int pos)
{
    FILE *p;
    p=fopen("ventas.dat","rb+");
    if(p==NULL)
    {
        cout<<"error de archivo en sobreescribir venta"<<endl;
    }
    fseek(p,sizeof *this * pos, 0);
    fwrite(this, sizeof *this,1,p);
    fclose(p);
    return;
}



int obtener_forma_pago(int id_venta){
venta obj;
int cantidad_ventas = contar_ventas();
for(int i=0;i<cantidad_ventas;i++){
    obj.leer_venta(i);
    if(obj.get_id_venta()==id_venta){return obj.get_forma_pago();}
    }
    return -1;
}





#endif // VENTAS_H_INCLUDED
