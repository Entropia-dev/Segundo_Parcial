#ifndef PERSONAS_H_INCLUDED
#define PERSONAS_H_INCLUDED



void persona::cargar_persona()
{
    cin.ignore();
    cout<<"NOMBRE: "<<endl;
    cin.ignore();
    cin.getline(nombre,50);
    cout<<"APELLIDO: "<<endl;
    cin.getline(apellido,50);
    //cin.ignore();
    cout<<"INGRESE EL EMAIL :"<<endl;
    cin.getline(e_mail,50);
    //cin.ignore();
    cout<<"DIRECCION: "<<endl;
    cin.getline(direccion,50);
    cout<<"DNI :"<<endl;
    cin>>dni;
    if(strcmp(dni,get_dni())==0){
       cout<<" DNI EXISTENTE, INTENTE NUEVAMENTE "<<endl;
       return;}
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
