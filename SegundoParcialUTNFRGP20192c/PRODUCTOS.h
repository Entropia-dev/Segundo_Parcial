#ifndef PRODUCTOS_H_INCLUDED
#define PRODUCTOS_H_INCLUDED

 class productos {
        private:
    int id_producto;
	 float precio_x_metro;
	 char modelo[9];
	 bool estado;
        public:
            ///========================GETS====================================================
            int get_id_producto(){return id_producto;}
            bool get_estado(){return estado;}
            char *get_modelo(){return modelo;}
            float get_precio_x_metro(){return precio_x_metro;}
            ///=======================SETS====================================================
            void set_estado(bool nuevo_estado){estado= nuevo_estado;}
            void set_modelo(char *nuevo_modelo){strcpy(modelo, nuevo_modelo);}
             void set_precio_x_metro(float nuevo_precio){precio_x_metro = nuevo_precio;}
            void set_id_producto(int nueva_id){id_producto= nueva_id;}
            ///====================CARGAR/MOSTRAR/GUARDAR==================
            void cargar_producto();
            void mostrar_producto();
            bool guardar_producto();
	 };

    void productos::cargar_producto(){
    cout<<"INGRESE LA ID DEL PRODUCTO"<<endl;
    cin>>id_producto;
    cout<<"INGRESE EL MODELO DEL PRODUCTO"<<endl;
    cin>>modelo;
    cout<<"INGRESE EL PRECIO POR METRO"<<endl;
    cin>>precio_x_metro;
    estado=true;
    }

    void productos::mostrar_producto(){
    cout<<"MODELO DEL PRODUCTO :"<<modelo<<endl;
    cout<<"ID DEL PRODUCTO :"<<id_producto<<endl;
    cout<<"PRECIO POR METRO :"<<precio_x_metro<<endl;
    }

    bool productos::guardar_producto(){
    bool grabo;
    FILE *p;
    p=fopen("productos.dat","ab");
    if(p==NULL){cout<<"ERROR DE ARCHIVO EN PRODUCTOS::CARGARPRODUCTO"<<endl;
                    exit(1);}
    grabo=fwrite(this, sizeof *this,1,p);
    fclose(p);
    return grabo;
    }

#endif // PRODUCTOS_H_INCLUDED
