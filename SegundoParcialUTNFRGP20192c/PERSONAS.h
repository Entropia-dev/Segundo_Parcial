#ifndef PERSONAS_H_INCLUDED
#define PERSONAS_H_INCLUDED



void persona::cargar_persona()
{
    cin.ignore();
    cout<<"NOMBRE: "<<endl;
    cin.getline(nombre,50);
    cout<<"APELLIDO: "<<endl;
    cin.getline(apellido,50);
    cout<<"INGRESE EL EMAIL :"<<endl;
    cin>>e_mail;
    cin.ignore();
    cout<<"DIRECCION: "<<endl;
    cin.getline(direccion,50);
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
