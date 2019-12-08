#ifndef EMPLEADOS_H_INCLUDED
#define EMPLEADOS_H_INCLUDED

int contar_empleados();
int contar_baja_empleados();




bool buscar_dni_empleado(char *dni)
{
    FILE *p;
    empleado obj;
    p=fopen("empleados.dat","rb");
    if(p==NULL)
    {
        cout<<"error de archivo en buscar_dni_empleado"<<endl;
        exit(1);
    }
    int cant_registros;
    cant_registros=contar_empleados();
    for(int i=0; i<cant_registros; i++)
    {
        obj.leer_empleado(i);
        if(strcasecmp(obj.get_dni(),dni)==0)
        {
            return true;
        }
    }
    return false;
}


int contar_empleados()
{
    FILE *p;
    long int bytes_arch;
    int cant_registros;

    p=fopen("empleados.dat","rb");
    if(p==NULL)
    {
        cout<<"error de archivo en contar empleados"<<endl;
        exit(1);
    }

    fseek(p,0,SEEK_END);

    bytes_arch=ftell(p);
    cant_registros = bytes_arch / sizeof (empleado);

    fclose(p);

    return cant_registros;
}

int contar_baja_empleados(){
empleado obj;
int cant_empleados=contar_empleados();
int empleados_eliminados=0;
for(int i=0;i<cant_empleados;i++){
obj.leer_empleado(i);
if(obj.get_estado()==false){empleados_eliminados++;}
}
return empleados_eliminados;
}


void listar_todos_empleados()
{
    empleado obj;
    system("cls");
    int cant_regs;
    cant_regs=contar_empleados();

    for(int i=0; i<cant_regs; i++)
    {
        obj.leer_empleado(i);
        if(obj.get_estado() == true)
        {

            obj.Mostrar_empleado();
            cout<<"================"<<endl;
        }
    }
    cout<<"================"<<endl;
    cout<<"FIN DEL LISTADO"<<endl;
    system("pause");
}



void empleado::Cargar_empleado()
{
    persona::cargar_persona();
    codigo_empleado=1+contar_empleados();
    cout<<"INGRESE EL SUELDO DEL EMPLEADO"<<endl;
    cin>>sueldo;
    estado=true;
    return;
}

void empleado::Mostrar_empleado()
{
    persona::mostrar_persona();
    cout<<"SUELDO :"<<sueldo<<endl;
    cout<<"ID DE EMPLEADO :"<<codigo_empleado<<endl;
}

///guardar empleados ->

bool empleado::guardar_empleado()
{
    FILE*p=fopen("empleados.dat","ab");
    if(p==NULL)
    {
        cout<<"ERROR DE GUARDADO ! ! ! ";
        exit(1);
    }
    bool grabo=fwrite(this,sizeof *this,1,p);
    fclose(p);
    return grabo;
}


void alta_empleado()
{
    system("cls");
    cout<<"MENU CARGA DE EMPLEADOS :"<<endl;
    empleado obj;
    bool resultado;
    obj.Cargar_empleado();
    resultado=obj.guardar_empleado();
    if(resultado==true)
    {
        cout<<"EMPLEADO CARGADO CON EXITO"<<endl;
    }
    system("pause");
}

void empleado::leer_empleado(int pos)
{
    FILE *p;
    p=fopen("empleados.dat","rb");
    if(p==NULL)
        exit(1);
    fseek(p, sizeof *this*pos,0);//SEEK_SET
    fread(this, sizeof *this, 1, p);
    fclose(p);
    return;
}

void empleado::sobreescribir_empleado(int pos)
{
    FILE *p;
    p=fopen("empleados.dat","rb+");
    if(p==NULL)
    {
        cout<<"error de archivo en sobreescribir empleado"<<endl;
    }
    fseek(p,sizeof *this * pos, 0);
    fwrite(this, sizeof *this,1,p);
    fclose(p);
    return;
}

int buscar_pos_dni(char *dni)
{
    empleado obj;
    int cant_registros;
    FILE *p;
    p=fopen("empleados.dat","rb");
    if(p==NULL)
    {
        cout<<"error de archivo en buscar_pos_dni"<<endl;
        exit(1);
    }

    cant_registros=contar_empleados();

    for(int i=0; i<cant_registros; i++)
    {
        obj.leer_empleado(i);
        if(strcmp(dni, obj.get_dni())==0)
        {
            fclose(p);
            return i;
        }
    }
    fclose(p);
    return -1;
}

void modificar_empleado()
{
    int id;
    empleado obj;
    system("cls");
    cout<<"INGRESE LA ID DEL EMPLEADO A MODIFICAR"<<endl;
    cin>>id;
    cout<<"EL EMPLEADO A MODIFICAR ES"<<endl;
    obj.leer_empleado(id-1);
    obj.Mostrar_empleado();
    cout<<endl;
    obj.Cargar_empleado();
    obj.set_codigo_empleado(id);
    obj.sobreescribir_empleado(id-1);
    return;
}

void eliminar_empleado()
{
    char auxiliar[9];
    int cantidad_registros;
    empleado obj;
        cantidad_registros=contar_empleados();
        if(cantidad_registros==0){cout<<"NO SE ENCONTRARON EMPLEADOS CARGADOS"<<endl;
                                    system("pause"); return;}
    cout<<"INGRESE EL DNI DEL EMPLEADO QUE DESEA ELIMINAR"<<endl;
    cin>>auxiliar;

    for(int i=0; i<cantidad_registros; i++)
    {
        obj.leer_empleado(i);
        if(strcmp(obj.get_dni(),auxiliar)==0 && obj.get_estado() == true )
        {
            obj.set_estado(false);
            obj.sobreescribir_empleado(i);
            cout<<"EMPLEADO ELIMINADO CON EXITO"<<endl;
            system("pause");
            return;
        }
    }
    cout<<"no se encontro al empleado que se desea ELIMINAR"<<endl;
    system("pause");
}


void listar_empleado_x_dni()
{
    char auxiliar[9];
    int cantidad_registros;
    empleado obj;
    cout<<"INGRESE EL DNI DEL EMPLEADO QUE DESEA LISTAR"<<endl;
    cin>>auxiliar;
    cantidad_registros=contar_empleados();
    for(int i=0; i<cantidad_registros; i++)
    {
        obj.leer_empleado(i);
        if(strcmp(obj.get_dni(),auxiliar)==0 && obj.get_estado() == true )
        {
            obj.Mostrar_empleado();
            system("pause");
            return;
        }
    }
    cout<<"no se encontro al empleado que se desea listar"<<endl;
    system("pause");
}



void restaurar_empleado()
{
    int id;
    int cant=contar_empleados();
    empleado obj;
    system("cls");
        if(cant==0){cout<<"NO SE ENCONTRARON EMPLEADOS CARGADOS"<<endl;
        system("pause");    return;}
    if(contar_baja_empleados()==0){cout<<"NO SE ENCONTRARON EMPLEADOS DADOS DE BAJA"<<endl;
        system("pause");    return;}
    cout<<"ESTOS SON LOS EMPLEADOS DADOS DE BAJA: "<<endl;
    for(int i=0; i<cant; i++)
    {
        obj.leer_empleado(i);
        if(obj.get_estado()==false)
        {

            obj.Mostrar_empleado();
            cout<<"=============="<<endl;
        }

    }
    cout<<"INGRESE LA ID DEL EMPLEADO A RESTAURAR: "<<endl;
    cin>>id;

    for(int i=0; i<cant; i++)
    {
        obj.leer_empleado(i);
        if(obj.get_codigo_empleado()==id)
        {
            obj.set_estado(true);
            obj.sobreescribir_empleado(i);
            cout<<"EMPLEADO RESTAURADO CON EXITO"<<endl;
            system("pause");
            return;
        }
    }
    cout<<"ID DEL EMPLEADO NO ENCONTRADO , INTENTELO NUEVAMENTE"<<endl;
    system("pause");
}


#endif // EMPLEADOS_H_INCLUDED
