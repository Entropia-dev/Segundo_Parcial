#ifndef PRODUCTOS_H_INCLUDED
#define PRODUCTOS_H_INCLUDED

///=================  ACTUALIZACION AL 5/11/2019 (2:00 AM) ===============
///
/// -agregue color a la clase producto.
/// -corregi la carga para que acepte espacios y no se rompa.
/// -Realice la opcion 4 de listar todos los productos (emprolijada)
///
///===================================================================



void alta_producto();
int contar_cant_productos();
bool buscar_id_producto(int);
float buscar_precio_producto(int id_producto);

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

void productos::cargar_producto()
{

    id_producto=contar_cant_productos()+1;
    cin.ignore();
    cout<<"INGRESE EL MODELO DEL PRODUCTO"<<endl;
    //cin.ignore();
    cin.getline(modelo,50);
    //cin.ignore();
    cout<<"INGRESE EL COLOR: "<<endl;
    cin.getline(color,50);
    //cin.ignore();
    cout<<"INGRESE EL PRECIO POR METRO: "<<endl;
    cin>>precio_x_metro;
    cout<<"INGRESE EL STOCK DISPONIBLE "<<endl;
    cin>>stock;
    estado=true;

}

void productos::mostrar_producto()
{
    cout<<endl;
    cout<<"********************************************"<<endl;
    cout<<"MODELO DEL PRODUCTO: "<<modelo<<endl;
    cout<<"COLOR: "<<color<<endl;
    cout<<"ID DEL PRODUCTO: "<<id_producto<<endl;
    cout<<"PRECIO POR METRO: "<<precio_x_metro<<endl;
    cout<<"STOCK DISPONIBLE: "<<stock;
    cout<<endl;
}

bool productos::guardar_producto()
{
    bool grabo;
    FILE *p;
    p=fopen("productos.dat","ab");
    if(p==NULL)
    {
        cout<<"ERROR DE ARCHIVO EN PRODUCTOS::CARGARPRODUCTO"<<endl;
        exit(1);
    }
    grabo=fwrite(this, sizeof *this,1,p);
    fclose(p);
    return grabo;
}


bool productos::leer_producto(int pos)
{
    FILE *p;
    p=fopen("productos.dat","rb");
    if(p==NULL)
        exit(1);
    fseek(p, sizeof *this*pos,0);
    bool leyo=fread(this, sizeof *this, 1, p);
    fclose(p);
    return leyo;
}

int contar_cant_productos()
{
    FILE *p;
    long int bytes_arch;
    int cant_registros;
    p=fopen("productos.dat","rb");
    fseek(p,0,SEEK_END);
    bytes_arch=ftell(p);
    cant_registros=bytes_arch/sizeof(productos);
    fclose(p);
    return cant_registros;
}

void alta_producto()
{
    system("cls");
    cout<<"======================="<<endl;
    cout<<"MENU CARGA DE PRODUCTO "<<endl;
    cout<<"========================"<<endl;
    productos obj;
    bool resultado;
    obj.cargar_producto();
    resultado=obj.guardar_producto();
    if(resultado==true)
    {
        cout<<"PRODUCTO CARGADO CON EXITO"<<endl;
    }
    system("pause");
}

bool buscar_id_producto(int id_buscada)
{
    int cantidad_productos;
    productos obj;
    cantidad_productos=contar_cant_productos();
    for(int i=0; i<cantidad_productos; i++)
    {
        obj.leer_producto(i);
        if(obj.get_id_producto() == id_buscada)
        {
            return true;
        }
    }
    return false;
}

float buscar_precio_producto(int id_producto)
{
    FILE *p;
    productos obj;
    p=fopen("productos.dat","rb");
    if(p==NULL)
    {
        cout<<"ERROR DE ARCHIVO EN BUSCAR PRECIO PRODUCTO"<<endl;
        exit(1);
    }
    int cantidad_productos=contar_cant_productos();
    for(int i=0; i<cantidad_productos; i++)
    {
        obj.leer_producto(i);
        if(id_producto == obj.get_id_producto() && obj.get_estado() == true)
        {
            fclose(p);
            return obj.get_precio_x_metro();
        }
    }
    cout<<"NO SE ENCONTRO EL PRODUCTO"<<endl;
    fclose(p);
    return -1;
}

void listar_todos_productos()
{
    productos obj;
    int cant_productos=contar_cant_productos();

    if(cant_productos==0){cout<<"NO SE ENCONTRARON PRODUCTOS QUE LISTAR"<<endl; system("pause"); return;}

    for(int i=0; i<cant_productos; i++)
    {
        obj.leer_producto(i);
        if(obj.get_estado()==true)
        {
            obj.mostrar_producto();

        }
    }
    cout<<"********************************************"<<endl;
    cout<<"FIN DEL LISTADO"<<endl;
    system("pause");
}

void listar_producto_x_id()
{
    productos obj;
    int id_producto;
    int cant_productos;
    cout<<"INGRESE LA ID DEL PRODUCTO QUE DESEA LISTAR"<<endl;
    cin>>id_producto;
    cant_productos=contar_cant_productos();
    for(int i=0; i<cant_productos; i++)
    {
        obj.leer_producto(i);
        if(obj.get_estado()==true && obj.get_id_producto() == id_producto)
        {
            obj.mostrar_producto();
            cout<<endl;
            system("pause");
            return;
        }
    }
    cout<<"NO SE ENCONTRO EL PRODUCTO , INTENTELO NUEVAMENTE"<<endl;
    system("pause");
    return;

}


///          completar !!!
void modificar_precio_producto()
{
    float nuevo_precio;
    int id_producto;
    productos obj;
    cout<<"INGRESE LA ID DE PRODUCTO QUE DESEA MODIFICAR "<<endl;
    cin>>id_producto;                                      ///crear funcion booleana que busque si la id de venta existe
    cout<<"INGRESE EL NUEVO PRECIO "<<endl;
    cin>>nuevo_precio;                                     ///crear funcion booleana que busque si la id de cliente existe
    obj.leer_producto(id_producto-1);
    obj.set_precio_x_metro(nuevo_precio);
    obj.sobreescribir_producto(id_producto-1);
}
///       completar!!!

void eliminar_producto()
{
    productos obj;
    int id_productos;
    int nro_prod=contar_cant_productos();
    if(nro_prod==0){cout<<"NO SE ENCONTRARON PRODUCTOS CARGADOS"<<endl;
        system("pause"); return;}
    cout<<"INGRESE LA ID DEL PRODUCTO QUE DESEA ELIMINAR"<<endl;
    cin>>id_productos;
    FILE *p=fopen("productos.dat","rb+");
    if(p==NULL)
    {
        exit(1);   ///chequear que la id de venta exista
    }
    while(fread(&obj, sizeof(productos),1,p)==true)
    {
        if(obj.get_id_producto()==id_productos)
        {
            obj.set_estado(false);
            obj.sobreescribir_producto(id_productos-1);
            fclose(p);
            cout<<"PRODUCTO ELIMINADO CON EXITO"<<endl;
            system("pause");
            return;

        }
    }
    fclose(p);
    cout<<"ERROR AL ELIMINAR EL PRODUCTO , INTENTELO NUEVAMENTE"<<endl;
    system("pause");
    return;
}



void productos::sobreescribir_producto(int pos)
{
    FILE *p;
    p=fopen("productos.dat","rb+");
    if(p==NULL)
    {
        cout<<"error de archivo en sobreescribir producto"<<endl;
    }
    fseek(p,sizeof *this * pos, 0);
    fwrite(this, sizeof *this,1,p);
    fclose(p);
    return;
}

void productos::decrementar_stock(int id_prod, float mts_vendidos){
this->leer_producto(id_prod-1);
stock=stock-mts_vendidos;
sobreescribir_producto(id_prod-1);
}

#endif // PRODUCTOS_H_INCLUDED
