#ifndef CLASES_H_INCLUDED
#define CLASES_H_INCLUDED


class persona{
protected:
char nombre[50];
char apellido[50];
char dni[9];
char e_mail[50];
char direccion[50];
public:
void set_nombre(char *nuevo_nombre){strcpy(nombre , nuevo_nombre);}
char *get_nombre(){return nombre;}
void set_apellido(char *nuevo_apellido){strcpy(apellido, nuevo_apellido);}
char *get_apellido(){return apellido;}
void set_dni(char *nuevo_dni){strcpy(dni, nuevo_dni);}
char *get_dni(){return dni;}
void set_email(char *nuevo_email){strcpy(e_mail, nuevo_email);}
char *get_email(){return e_mail;}
void set_direccion(char *nueva_direccion){strcpy(direccion, nueva_direccion);}
char *get_direccion(){return direccion;}
};

class empleado:public persona {
	 private:
		int codigo_empleado;
		float sueldo;
		bool estado;
	 public:
		void Cargar_empleado();
		void Mostrar_empleado();
		void set_codigo_empleado(int nuevo_codigo){codigo_empleado = nuevo_codigo;}
		void set_estado(bool nuevo_estado){estado = nuevo_estado;}
		void set_sueldo(float nuevo_sueldo){sueldo = nuevo_sueldo;}
		bool get_estado(){return estado;}
		int get_codigo_empleado(){return codigo_empleado;}
		float get_sueldo(){return sueldo;}

	 };

	 class cliente : public persona{
        private:

        public:

	 };

#endif // CLASES_H_INCLUDED
