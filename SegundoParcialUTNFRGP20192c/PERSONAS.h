#ifndef PERSONAS_H_INCLUDED
#define PERSONAS_H_INCLUDED

class persona{
protected:
char nombre[50];
char apellido[50];
char dni[9];
char e_mail[50];
char direccion[50];
public:
                ///====================SETS==================
void set_nombre(char *nuevo_nombre){strcpy(nombre , nuevo_nombre);}
void set_direccion(char *nueva_direccion){strcpy(direccion, nueva_direccion);}
void set_apellido(char *nuevo_apellido){strcpy(apellido, nuevo_apellido);}
void set_dni(char *nuevo_dni){strcpy(dni, nuevo_dni);}
void set_email(char *nuevo_email){strcpy(e_mail, nuevo_email);}
            ///============GETS========================
char *get_email(){return e_mail;}
char *get_direccion(){return direccion;}
char *get_nombre(){return nombre;}
char *get_apellido(){return apellido;}
char *get_dni(){return dni;}
        ///======================CARGAR/MOSTRAR====================
void cargar_persona();
void mostrar_persona();
};

void persona::cargar_persona(){
cout<<"NOMBRE :"<<endl;
cin>>nombre;
cout<<"APELLIDO :"<<endl;
cin>>apellido;
cout<<"INGRESE EL EMAIL :"<<endl;
cin>>e_mail;
cout<<"DIRECCION: "<<endl;
cin>>direccion;
cout<<"DNI :"<<endl;
cin>>dni;
return;
}

void persona::mostrar_persona(){
cout<<"NOMBRE :"<<nombre<<endl;
cout<<"APELLIDO :"<<apellido<<endl;
cout<<"EMAIL :"<<e_mail<<endl;
cout<<"DIN :"<<dni<<endl;
cout<<"DIRECCION :"<<direccion<<endl;
return;
}

#endif // PERSONAS_H_INCLUDED
