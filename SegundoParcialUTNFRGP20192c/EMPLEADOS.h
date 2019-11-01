#ifndef EMPLEADOS_H_INCLUDED
#define EMPLEADOS_H_INCLUDED

class empleado:public persona {
	 private:
		int codigo_empleado;
		float sueldo;
		bool estado;
	 public:
        ///====================CARGAR/MOSTRAR/GUARDAR==================
		void Cargar_empleado();
		void Mostrar_empleado();
		bool guardar_empleado();
		bool leerDeDisco(int);
		bool sobreescribir_empleado(int);
            ///====================SETS==================
		void set_codigo_empleado(int nuevo_codigo){codigo_empleado = nuevo_codigo;}
		void set_estado(bool nuevo_estado){estado = nuevo_estado;}
		void set_sueldo(float nuevo_sueldo){sueldo = nuevo_sueldo;}
                    ///====================GETS==================
		bool get_estado(){return estado;}
		int get_codigo_empleado(){return codigo_empleado;}
		float get_sueldo(){return sueldo;}

	 };

void empleado::Cargar_empleado(){
	 persona::cargar_persona();
	 cout<<"INGRESE EL CODIGO DE EMPLEADO: "<<endl;
	 cin>>codigo_empleado;
	 cin.ignore();
	 cout<<"INGRESE EL SUELDO DEL EMPLEADO: "<<endl;
	 cin>>sueldo;
	 estado=true;
	 return;
	 }

void empleado::Mostrar_empleado(){
	 persona::mostrar_persona();
	 cout<<"SUELDO :"<<sueldo<<endl;
	 cout<<"ID DE EMPLEADO"<<codigo_empleado<<endl;
	 }

///guardar empleados ->
bool empleado::guardar_empleado(){
FILE*p=fopen("empleados.dat","ab");
if(p==NULL){cout<<"ERROR DE GUARDADO ! ! ! "; exit(1);}
bool grabo=fwrite(this,sizeof *this,1,p);
fclose(p);
return grabo;
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

void alta_empleado(){
system("cls");
cout<<"MENU CARGA DE EMPLEADOS "<<endl;
empleado obj;
obj.Cargar_empleado();
bool resultado=obj.guardar_empleado();
if(resultado==true){cout<<"EMPLEADO GUARDADO CON EXITO !"<<endl;}
system("pause");
}

bool empleado::leerDeDisco(int pos){
FILE*p=fopen("empleados.dat","rb");
fseek(p,sizeof*this*pos,0);
bool leyo=fread(this, sizeof*this,1,p);
fclose(p);
return leyo;
}

///     MOSTRAR TODOS LOS EMPLEADOS

void mostrar_todos_empleados(){
empleado obj;
int pos=0;
while(obj.leerDeDisco(pos++)){
    obj.Mostrar_empleado();
}

}

 bool empleado::sobreescribir_empleado(int pos){
  FILE *p;
  p=fopen("empleados.dat","rb+");
  if(p==NULL){cout<<"error de archivo en sobreescribir empleado"<<endl;}
  fseek(p,sizeof *this * pos, 0);
  fwrite(this , sizeof *this ,1 ,p);
  fclose(p);
  return true;
  }

  void modificar_empleado(){
int id;
empleado obj;
system("cls");
cout<<"INGRESE LA ID DEL EMPLEADO A MODIFICAR"<<endl;
cin>>id;
cout<<"EL EMPLEADO A MODIFICAR ES"<<endl;
obj.leerDeDisco(id-1);
obj.Mostrar_empleado();
cout<<endl;
obj.Cargar_empleado();
obj.set_codigo_empleado(id);
obj.sobreescribir_empleado(id-1);
return;
}

void eliminar_empleado(){
int id;
empleado obj;
system("cls");
cout<<"INGRESE LA ID DEL EMPLEADO A ELIMINAR"<<endl;
cin>>id;
cout<<"EL EMPLEADO A MODIFICAR ES"<<endl;
obj.leerDeDisco(id-1);
obj.set_estado(false);
obj.sobreescribir_empleado(id-1);
return;
}

void listar_empleado_x_dni(){
char auxiliar[9];
int cantidad_registros;
empleado obj;
cout<<"INGRESE EL DNI DEL EMPLEADO QUE DESEA LISTAR"<<endl;
cin>>auxiliar;
cantidad_registros=contar_empleados();
for(int i=0;i<cantidad_registros;i++){
        obj.leerDeDisco(i);
        if(strcmp(obj.get_dni(),auxiliar)==0 && obj.get_estado() == true ){
            obj.Mostrar_empleado();
                system("pause");
                return;
                }
        }
            cout<<"no se encontro al empleado que se desea listar"<<endl;
}

#endif // EMPLEADOS_H_INCLUDED
