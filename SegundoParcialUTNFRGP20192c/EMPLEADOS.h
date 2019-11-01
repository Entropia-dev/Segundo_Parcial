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

#endif // EMPLEADOS_H_INCLUDED
