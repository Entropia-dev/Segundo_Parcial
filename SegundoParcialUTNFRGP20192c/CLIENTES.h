#ifndef CLIENTES_H_INCLUDED
#define CLIENTES_H_INCLUDED

	 class cliente {
        private:

        int codigo_cliente;
        public:
            ///============================SETS=================================
            void set_codigo_cliente(int nuevo_codigo){codigo_cliente=nuevo_codigo;}
            ///=============================GETS======================================
            int get_codigo_cliente(){return codigo_cliente;}
            ///====================CARGAR/MOSTRAR/GUARDAR==================
            bool guardar_cliente();
            void mostrar_cliente();
            void cargar_cliente();
	 };



#endif // CLIENTES_H_INCLUDED
