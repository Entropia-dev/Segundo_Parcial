#ifndef EMPLEADOS_H_INCLUDED
#define EMPLEADOS_H_INCLUDED

int contar_empleados();

class empleado:public persona {
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
		void set_codigo_empleado(int nuevo_codigo){codigo_empleado = nuevo_codigo;}
		void set_estado(bool nuevo_estado){estado = nuevo_estado;}
		void set_sueldo(float nuevo_sueldo){sueldo = nuevo_sueldo;}
		void set_id(int nueva_id){}
                    ///====================GETS==================
		bool get_estado(){return estado;}
		int get_codigo_empleado(){return codigo_empleado;}
		float get_sueldo(){return sueldo;}

	 };


bool buscar_dni_empleado(char *dni){
FILE *p;
empleado obj;
p=fopen("empleados.dat","rb");
if(p==NULL){cout<<"error de archivo en buscar_dni_empleado"<<endl;
                exit(1);}
int cant_registros;
cant_registros=contar_empleados();
for(int i=0;i<cant_registros;i++){
    obj.leer_empleado(i);
    if(strcasecmp(obj.get_dni(),dni)==0){return true;}
    }
        return false;
}


int contar_empleados(){
FILE *p;
long int bytes_arch;
int cant_registros;

p=fopen("empleados.dat","rb");
if(p==NULL){cout<<"error de archivo en contar empleados"<<endl;
                exit(1);}

    fseek(p,0,SEEK_END);

    bytes_arch=ftell(p);
    cant_registros = bytes_arch / sizeof (empleado);

fclose(p);

return cant_registros;
}


 void listar_todos_empleados(){
 empleado obj;
 system("cls");
 int cant_regs;
 cant_regs=contar_empleados();

 for(int i=0;i<cant_regs;i++){
        obj.leer_empleado(i);
       if(obj.get_estado()==true)
         cout<<"================"<<endl;
            obj.Mostrar_empleado();

    }
         cout<<"================"<<endl;
        cout<<"FIN DEL LISTADO"<<endl;
        system("pause");
        return;
 }



void empleado::Cargar_empleado(){
	 persona::cargar_persona();
	 codigo_empleado=1+contar_empleados();
	 cout<<"INGRESE EL SUELDO DEL EMPLEADO"<<endl;
	 cin>>sueldo;
	 estado=true;
	 return;
	 }

void empleado::Mostrar_empleado(){
	 persona::mostrar_persona();
	 cout<<"SUELDO :"<<sueldo<<endl;
	 cout<<"ID DE EMPLEADO :"<<codigo_empleado<<endl;
	 }

///guardar empleados ->

bool empleado::guardar_empleado(){
FILE*p=fopen("empleados.dat","ab");
if(p==NULL){cout<<"ERROR DE GUARDADO ! ! ! "; exit(1);}
bool grabo=fwrite(this,sizeof *this,1,p);
fclose(p);
return grabo;
}


void alta_empleado(){
system("cls");
cout<<"MENU CARGA DE EMPLEADOS :"<<endl;
empleado obj;
bool resultado;
obj.Cargar_empleado();
resultado=obj.guardar_empleado();
if(resultado==true){cout<<"EMPLEADO CARGADO CON EXITO"<<endl;}
system("pause");
}

void empleado::leer_empleado(int pos){
  FILE *p;
  p=fopen("empleados.dat","rb");
  if(p==NULL)exit(1);
  fseek(p, sizeof *this*pos,0);//SEEK_SET
  fread(this, sizeof *this, 1, p);
  fclose(p);
  return;
  }

  void empleado::sobreescribir_empleado(int pos){
  FILE *p;
  p=fopen("empleados.dat","rb+");
  if(p==NULL){cout<<"error de archivo en sobreescribir empleado"<<endl;}
  fseek(p,sizeof *this * pos, 0);
  fwrite(this , sizeof *this ,1 ,p);
  fclose(p);
  return;
  }

  int buscar_pos_dni(char *dni){
  empleado obj;
    int cant_registros;
  FILE *p;
  p=fopen("empleados.dat","rb");
  if(p==NULL){cout<<"error de archivo en buscar_pos_dni"<<endl;
                    exit(1);}

    cant_registros=contar_empleados();

  for(int i=0;i<cant_registros;i++){
    obj.leer_empleado(i);
    if(strcmp(dni, obj.get_dni())==0){
            fclose(p);
        return i;
    }
        }
    fclose(p);
        return -1;
  }

void modificar_empleado(){
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

/*void eliminar_empleado(){
empleado obj;
char dni[9];
int cantidad_empleados = contar_empleados();
system("cls");
cout<<"INGRESE EL DNI DEL EMPLEADO A ELIMINAR"<<endl;
cin>>dni;
for(int i=0;i<cantidad_empleados;i++){
    obj.leer_empleado(i);
//    if(strcmp(obj.get_dni(),dni)=0){
        obj.set_estado(false);
        obj.sobreescribir_empleado(buscar_pos_dni(dni));
        }
    }
}
*/
void listar_empleado_x_dni(){
char auxiliar[9];
int cantidad_registros;
empleado obj;
cout<<"INGRESE EL DNI DEL EMPLEADO QUE DESEA LISTAR"<<endl;
cin>>auxiliar;
cantidad_registros=contar_empleados();
for(int i=0;i<cantidad_registros;i++){
        obj.leer_empleado(i);
        if(strcmp(obj.get_dni(),auxiliar)==0 && obj.get_estado() == true ){
            obj.Mostrar_empleado();
                system("pause");
                return;
                }
        }
            cout<<"no se encontro al empleado que se desea listar"<<endl;
}


#endif // EMPLEADOS_H_INCLUDED
