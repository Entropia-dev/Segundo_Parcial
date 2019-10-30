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
		bool Guardar_empleado();
		bool leerDeDisco();
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
bool empleado::Guardar_empleado(){
    empleado obj;
FILE*p=fopen("empleados.dat","ab");
if(p==NULL){cout<<"ERROR DE GUARDADO ! ! ! "; exit(1);}
bool grabo=fwrite(this,sizeof *this,1,p);
fclose(p);
return grabo;
}

///  BUSCAR EMPLEADO X DNI   ///

void buscarXdni(char *dni){
    empleado obj;
    FILE*p=fopen("empleados.dat","rb");
    if(p==NULL){cout<<"DNI NO ENCONTRADO ! ! ! "; exit(1);}
while(fread(&obj,sizeof(empleado),1,p)){
    if(strcmp(dni,obj.get_dni())==0){
        obj.Mostrar_empleado();
    }
}
fclose(p);
system("pause");
return;
}

///   LISTAR EMPLEADO    ///

void listar_empleado_x_dni(){
char comparador [9];
cout<<"INGRESE UN NUMERO DE DNI: ";
cin>>comparador;
buscarXdni(comparador);
}

#endif // EMPLEADOS_H_INCLUDED
