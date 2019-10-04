#include <iostream>

using namespace std;

/**probando git

	el trabajo terminado es la nota del segundo parcial
	
	paso 1 definir grupo y tema	

	paso 2 presentacion del informe (puede estar desaprobado)
	hay dos tipos 1 para un sistema de gestion y otro para un juego en el campus
	
	para la entrega del prototipo se necesita el informe aprobado
	cuando traemos el prototipo tenemos que traer el informe.
		
	si llega el 22 de noviemre y no tenes el prototipo aprobado ,

	o el programa terminado no se consigue y se terminaron estan las mesas de final

	en las mesas de final se puede venir con el prototipo o con el programa terminado 

	se viene a las 8 am y despues de que los compañeros rindan se ve lo que trajiste para corregir.
	
	recuperatorios del primero va a haber uno en noviempre y uno en febrero.

	en el final lo que van a tomar es el programa terminado del segundo parcial con alguna mejora en el medio.4

	que se solicita en la revision del programa.

	el final y la presentacion del programa terminado es individual
	
	se le hacen preguntas al grupo con respecto a el trabajo final terminado, una vez que esta completo.
		
	
		
	===========================================================
	


		

    base pdf:intro_a_POO

 notas/tareas:
 preguntar por que los gets usan en caso de ser char la variable en modo de puntero por ejemplo
 de: intro a poo pagina 10

  char * Articulo::getDescripcion(){
 return descripcion;
 }

    preguntar si una clase es un TDA (tipo de dato abstracto)



 (se usa el tipo de dato despues la funcion y con los dos puntos
    se especifica a que metodo de la clase se desea llamar )

    los gets suelen ser return de la variable de la clase
    (propiedad que se desea leer.)

    en caso de querer setear un string de caracteres
    se tiene que usar la funcion strcpy desde una varuable
    que se envia a el metodo mediante puntero de char.

    los metodos son las funciones que posee cada objeto. ()
    las propiedades son las variables que posee cada objeto.

    (generalmente son de tipo private
        o protected segun el caso por cuestiones de encapsulamiento.)


      //////////////////////////////////  ejemplo de clase: /////////////////////////////////////////////////

        class Articulo{
        private:
        char codArticulo[5];
        char descripcion[30];
        float pu;
        int stock;
        public:
        void Cargar(void);
        void Mostrar(void);
        };

                void Articulo::Cargar(){
        cout<<”INGRESE EL CODIGO: “;
        cin>>codArt;
        cout<<”INGRESE LA DESCRIPCION: ”;
        cin>>descripcion;
        cout<<”INGRESE EL PRECIO UNITARIO: “;
        cin>>pu;
        cout<<”INGRESE EL STOCK”;
        cin>>stock;
        }
        void Articulo::Mostrar(){
        cout<<” CODIGO: “;
        cout<<codArt<<endl;
        cout<<” DESCRIPCION: ”;
        cout<<descripcion<<endl;
        cout<<” PRECIO UNITARIO: “;
        cout<<pu<<endl;
        cout<<” STOCK”;
        cout<<stock<<endl;
        }

           //////////////////////////////////  Sets y Gets  /////////////////////////////////////////////////

            char * Articulo::getCodArt(){
            return codArticulo; }


            char * Articulo::getDescripcion(){
            return descripcion; }

            float Articulo::getPu(){
            return pu;  }

            int Articulo::getStock(){return stock; }


            void Articulo::setCodArt(char *cod){
            strcpy(codArticulo, cod); }

            void Articulo::setDescripcion(char *desc){
            strcpy(descripcion, desc); }

            void Articulo::setPu(float p){
            pu=p;   }

            void Articulo::setStock(int s){
            stock=s; }


        ===========================================================





**/


int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
