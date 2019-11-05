#ifndef CLIENTES_H_INCLUDED
#define CLIENTES_H_INCLUDED

    int contar_clientes();

	 class cliente:public persona {
        private:
        bool estado;
        int codigo_cliente;
        public:
            ///============================SETS=================================
            void set_codigo_cliente(int nuevo_codigo){codigo_cliente=nuevo_codigo;}
            void set_estado_cliente(bool nuevo_estado){estado=nuevo_estado;}
            ///=============================GETS======================================
            int get_codigo_cliente(){return codigo_cliente;}
            bool get_estado_cliente(){return estado;}
            ///====================CARGAR/MOSTRAR/GUARDAR==================
            bool guardar_cliente();
            void mostrar_cliente();
            void cargar_cliente();
            void leer_cliente(int);
            bool sobreescribir_cliente(int);
	 };

void cliente::cargar_cliente(){
persona::cargar_persona();
codigo_cliente=contar_clientes()+1;
estado=true;
return;
}

void cliente::mostrar_cliente(){
persona::mostrar_persona();
cout<<"ID DE CLIENTE: "<<codigo_cliente<<endl;
return;
}

bool cliente::guardar_cliente(){
FILE *p;
bool grabo;
p=fopen("clientes.dat","ab");
if(p==NULL){cout<<"ERROR DE ARCHIVO EN CLIENTE::GUARDAR_CLIENTE"<<endl;
                exit(1);}
grabo=fwrite(this, sizeof *this , 1 , p);
fclose(p);
return grabo;
}

void alta_cliente(){
bool estado;
cliente obj;
system("cls");
cout<<  "MENU DE CARGA DE CLIENTES"<<endl;
obj.cargar_cliente();
estado=obj.guardar_cliente();
if(estado==true){cout<<"EL CLIENTE SE GUARDO CORRECTAMENTE"<<endl;
                    system("pause");
                        return;
                            }

}

int contar_clientes(){
FILE *p;
long int  bytes_arch;
int cantidad_clientes;
p=fopen("clientes.dat","rb");
if(p==NULL){cout<<"ERROR DE ARCHIVO EN CONTAR CLIENTES"<<endl;
                exit(1);}
fseek(p,0,SEEK_END);
bytes_arch=ftell(p);
cantidad_clientes=bytes_arch/sizeof(cliente);
return cantidad_clientes;
}

void cliente::leer_cliente(int pos){
FILE *p;
p=fopen("clientes.dat","rb+");
if(p==NULL){cout<<"ERROR DE ARCHIVO EN LEER CLIENTE"<<endl;
                        exit(1);}
    fseek(p,sizeof *this * pos,0);
    fread(this , sizeof *this , 1 ,p);
    fclose(p);
    return;
}

void listar_todos_clientes(){
cliente obj;
int cantidad_clientes;
cantidad_clientes=contar_clientes();
for(int i=0;i<cantidad_clientes;i++){
    obj.leer_cliente(i);
        if(obj.get_estado_cliente()==true){
    obj.mostrar_cliente();
        }
    }
    cout<<endl;
    cout<<"FIN DEL LISTADO"<<endl;
    system("pause");
}

bool cliente::sobreescribir_cliente(int pos){
  bool estado;
  FILE *p;
  p=fopen("clientes.dat","rb+");
  if(p==NULL){cout<<"error de archivo en sobreescribir cliente"<<endl;}
  fseek(p,sizeof *this * pos, 0);
  estado = fwrite(this , sizeof *this ,1 ,p);
  fclose(p);
  return estado;
}

bool buscar_id_cliente(int id){
cliente obj;
FILE *p;
int cantidad_clientes;
p=fopen("clientes.dat","rb");
if(p==NULL){cout<<"ERROR DE ARCHIVO EN BUSCAR ID CLIENTE"<<endl;
                    exit(1);}
cantidad_clientes=contar_clientes();
for(int i=0;i<cantidad_clientes;i++){
        obj.leer_cliente(i);
        if(obj.get_codigo_cliente()==id){
            fclose(p);
            return true;
            }
        }
        fclose(p);
        return false;
}

void eliminar_cliente(){
int id;
cliente obj;
system("cls");
cout<<"INGRESE LA ID DEL CLIENTE A ELIMINAR"<<endl;
cin>>id;
if(buscar_id_cliente(id)==true){
obj.leer_cliente(id-1);
obj.set_estado_cliente(false);
obj.sobreescribir_cliente(id-1);
cout<<"CLIENTE ELIMINADO CON EXITO"<<endl;
system("pause");
return;
    }else{cout<<"ID DEL CLIENTE NO ENCONTRADO"<<endl;}

}


void listar_cliente_x_id(){
cliente obj;
int id;
cout<<"INGRESE LA ID DEL CLIENTE A LISTAR"<<endl;
cin>>id;
if(buscar_id_cliente(id)==false){cout<<"ID NO ENCONTRADA, INGRESE OTRA ID"<<endl;
                                    cin>>id;}
obj.leer_cliente(id-1);
obj.mostrar_cliente();
system("pause");
return;
}

#endif // CLIENTES_H_INCLUDED
