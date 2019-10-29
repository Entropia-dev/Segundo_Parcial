#ifndef CLIENTES_H_INCLUDED
#define CLIENTES_H_INCLUDED

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
	 };

void cliente::cargar_cliente(){
persona::cargar_persona();
cout<<"INGRESE EL CODIGO DE CLIENTE"<<endl;
cin>>codigo_cliente;
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

#endif // CLIENTES_H_INCLUDED
