#ifndef PERSONAS_H_INCLUDED
#define PERSONAS_H_INCLUDED



void persona::cargar_persona()
{
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

void persona::mostrar_persona()
{
    cout<<"NOMBRE :"<<nombre<<endl;
    cout<<"APELLIDO :"<<apellido<<endl;
    cout<<"EMAIL :"<<e_mail<<endl;
    cout<<"DNI :"<<dni<<endl;
    cout<<"DIRECCION :"<<direccion<<endl;
    return;
}



#endif // PERSONAS_H_INCLUDED
