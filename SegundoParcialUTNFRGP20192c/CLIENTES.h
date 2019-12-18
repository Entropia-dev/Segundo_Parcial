#ifndef CLIENTES_H_INCLUDED
#define CLIENTES_H_INCLUDED

int contar_clientes();
int buscar_pos_id(int);
bool buscar_estado_cliente(int);


void cliente::cargar_cliente()
{
    cin.ignore();
    cout<<endl;
    cout<<"INGRESE EL NOMBRE DEL CLIENTE"<<endl;
    cin.getline(nombre,50);
    //cin.ignore();
    cout<<"INGRESE EL APELLIDO DEL CLIENTE"<<endl;
    cin.getline(apellido,50);
    //cin.ignore();
    cout<<"INGRESE EL EMAIL DEL CLIENTE"<<endl;
    cin.getline(e_mail,50);
    //cin.ignore();
    cout<<"INGRESE LA DIRECCION DEL CLIENTE"<<endl;
    cin.getline(direccion,50);
    //cin.ignore();
    strcpy(dni,"-----");
    codigo_cliente=contar_clientes()+1;
    estado=true;
    return;
}

void cliente::mostrar_cliente()
{
    persona::mostrar_persona();
    cout<<"ID DE CLIENTE: "<<codigo_cliente<<endl;
    return;
}

bool cliente::guardar_cliente()
{
    FILE *p;
    bool grabo;
    p=fopen("clientes.dat","ab");
    if(p==NULL)
    {
        cout<<"ERROR DE ARCHIVO EN CLIENTE::GUARDAR_CLIENTE"<<endl;
        exit(1);
    }
    grabo=fwrite(this, sizeof *this, 1, p);
    fclose(p);
    return grabo;
}

void alta_cliente()
{
    bool estado;
    cliente obj;
    system("cls");
    cout<<  "MENU DE CARGA DE CLIENTES"<<endl;
    obj.cargar_cliente();
    estado=obj.guardar_cliente();
    if(estado==true)
    {
        cout<<"EL CLIENTE SE GUARDO CORRECTAMENTE"<<endl;
        system("pause");
        return;
    }

}

int contar_clientes()
{
    FILE *p;
    long int  bytes_arch;
    int cantidad_clientes;
    p=fopen("clientes.dat","rb");
    if(p==NULL)
    {
        cout<<"ERROR DE ARCHIVO EN CONTAR CLIENTES"<<endl;
        exit(1);
    }
    fseek(p,0,SEEK_END);
    bytes_arch=ftell(p);
    cantidad_clientes=bytes_arch/sizeof(cliente);
    return cantidad_clientes;
}

void cliente::leer_cliente(int pos)
{
    FILE *p;
    p=fopen("clientes.dat","rb+");
    if(p==NULL)
    {
        cout<<"ERROR DE ARCHIVO EN LEER CLIENTE"<<endl;
        exit(1);
    }
    fseek(p,sizeof *this * pos,0);
    fread(this, sizeof *this, 1,p);
    fclose(p);
    return;
}

/// leerDeDisco

bool cliente::leerDeDisco(int pos){
FILE*p=fopen("clientes.dat","rb");
if(p==NULL){
    cout<<" ERROR DE LECTURA ! "<< endl;
    exit(1);
    }
    fseek(p,sizeof*this*pos,0);
    bool leyo = fread(this,sizeof*this,1,p);
    fclose(p);
    return leyo;
    }



void listar_todos_clientes()
{
    cliente obj;
    int cantidad_clientes;
    cantidad_clientes=contar_clientes();
    cout<<"=====LISTADO DE CLIENTES ===="<<endl;
    for(int i=0; i<cantidad_clientes; i++)
    {
        obj.leer_cliente(i);
        if(obj.get_estado_cliente()==true)
        {
            obj.mostrar_cliente();
            cout<<"============"<<endl;
        }
    }
    cout<<endl;
    cout<<"FIN DEL LISTADO"<<endl;
    cout<<endl;
    system("pause");
}

bool cliente::sobreescribir_cliente(int pos)
{
    bool estado;
    FILE *p;
    p=fopen("clientes.dat","rb+");
    if(p==NULL)
    {
        cout<<"error de archivo en sobreescribir cliente"<<endl;
    }
    fseek(p,sizeof *this * pos, 0);
    estado = fwrite(this, sizeof *this,1,p);
    fclose(p);
    return estado;
}

bool buscar_id_cliente(int id)
{
    cliente obj;
    int cantidad_clientes;
    cantidad_clientes=contar_clientes();
    for(int i=0; i<cantidad_clientes; i++)
    {
        obj.leer_cliente(i);
        if(obj.get_codigo_cliente()==id)
        {
            return true;
        }
    }
    return false;
}

void eliminar_cliente()
{
    int id;
    cliente obj;
    int cant_clientes=contar_clientes();
    system("cls");
    if(cant_clientes==0){cout<<"NO SE ENCONTRARON CLIENTES DADOS DE ALTA "<<endl;
                        system("pause"); return;}
    cout<<"INGRESE LA ID DEL CLIENTE A ELIMINAR"<<endl;
    cin>>id;
    if(buscar_id_cliente(id)==true)
    {
        obj.leer_cliente(id-1);
        obj.set_estado_cliente(false);
        obj.sobreescribir_cliente(id-1);
        cout<<"CLIENTE ELIMINADO CON EXITO"<<endl;
        system("pause");
        return;
    }
    else
    {
        cout<<"ID DEL CLIENTE NO ENCONTRADO"<<endl;
    }

}


void listar_cliente_x_id()
{
    cliente obj;
    int id;
    cout<<"INGRESE LA ID DEL CLIENTE A LISTAR"<<endl;
    cin>>id;
    if(buscar_id_cliente(id)==false)
    {
        cout<<"ID NO ENCONTRADA, INTENTELO NUEVAMENTE"<<endl;
        system("pause"); return;
    }
    obj.leer_cliente(id-1);
    obj.mostrar_cliente();
    system("pause");
    return;
}

void modificar_cliente() ///modifica el e mail del cliente
{
    cliente obj;
    int cant_clientes;
    int id_cliente;
    char nuevo_correo[50];
    cout<<"INGRESE LA ID DE CLIENTE QUE DESEA MODIFICAR"<<endl;
    cin>>id_cliente;
    if(buscar_id_cliente(id_cliente)==false)
    {
        cout<<endl;
        cout<<"ID DE CLIENTE NO VALIDA , INTENTELO NUEVAMENTE"<<endl;
        system("pause");
        return;
    }
    if(buscar_estado_cliente(id_cliente)==false){cout<<"EL CLIENTE SE ENCUENTRA DADO DE BAJA , INTENTE NUEVAMENTE"<<endl;
                                                    system("pause"); return;}
    cant_clientes=contar_clientes();
    for(int i=0; i<cant_clientes; i++)
    {
        obj.leer_cliente(i);
        if(obj.get_codigo_cliente()==id_cliente)
        {
            cout<<"INGRESE EL NUEVO CORREO DEL CLIENTE"<<endl;
            cin>>nuevo_correo;
            obj.set_email(nuevo_correo);
            obj.sobreescribir_cliente(id_cliente-1);
            cout<<"CORREO DEL CLIENTE MODIFICADO CON EXITO"<<endl;
            system("pause");
        }
    }
}

void restaurar_cliente()
{
    int id;
    int cant_clientes=contar_clientes();
    cliente obj;
    system("cls");
    if(cant_clientes == 0)
    {
        cout<<"NO SE ENCONTRARON CLIENTES CARGADOS"<<endl;
        system("pause");
        return;
    }


    cout<<"ESTOS SON LOS CLIENTES DADOS DE BAJA: "<<endl;
    for(int i=0; i<cant_clientes; i++)
    {
        obj.leer_cliente(i);
        if(obj.get_estado_cliente()==false)
        {

            obj.mostrar_cliente();
            cout<<"=============="<<endl;
        }

    }
    cout<<"INGRESE LA ID DEL CLIENTE A RESTAURAR: "<<endl;
    cin>>id;
    if(buscar_id_cliente(id)==false){
            cout<<"ID INCORRECTA"<<endl;
            cout<<"INTENTELO NUEVAMENTE INGRESANDO UNA ID DE CLIENTE VALIDA "<<endl;
                                        system("pause"); return;    }
    if(buscar_id_cliente(id)==true)
    {
        obj.leer_cliente(id-1);
        obj.set_estado_cliente(true);
        obj.sobreescribir_cliente(id-1);
        cout<<"CLIENTE RESTAURADO CON EXITO"<<endl;
        system("pause");
        return;
    }
    else
    {
        cout<<"ID DEL CLIENTE NO ENCONTRADO , INTENTELO NUEVAMENTE"<<endl;
        system("pause");
    }

}

int buscar_pos_id(int id_cliente){  ///buca la pocison en el archivo en la cual coincida la id de cliente
cliente obj;
int cant_clientes = contar_clientes();
for(int i=0;i<cant_clientes;i++){
    obj.leer_cliente(i);
    if(obj.get_codigo_cliente() == id_cliente){return i;}
    }
    return -1;
}

bool buscar_estado_cliente(int id_buscada){     ///obtiene el estado del cliente para saber si es apto para ser utilizado como parametro
cliente obj;                                    ///por ejemplo de un pago
obj.leer_cliente(buscar_pos_id(id_buscada));
bool aux;
aux = obj.get_estado_cliente();
return aux;
}

#endif // CLIENTES_H_INCLUDED
