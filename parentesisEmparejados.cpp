
/*  PARENTESIS EMPAREJADOS
Imprime todas las combinaciones posibles de parentesis emparejados, la funcion parentesisEmparejados(x) 
recibe un numero entero de la cantidad de parentesis balanceados requeridos.
Elaborado por: Carlos Roberto Cano Noguera
Correo: ccanon1100@alumno.ipn.mx
Lenguaje de programacion: C++
Entorno de operacion: Windows 10
Compilador: c++ (i686-posix-dwarf-rev0, Built by MinGW-W64 project) 8.1.0
*/

#include <iostream>
#include <stdlib.h>

using namespace std;

class nodo{
	public:
	nodo(){
		ant=sig=NULL;
	}
    private:
    char info= '{';
	string info1;
    nodo *ant;
	nodo *sig;
	friend class ldl;
};

class ldl{
    private:
        nodo *inicio;
    public:
        ldl(){
            inicio=NULL;
        }

    void insertainicio(int n){
        for (int i = 0; i < n; i++){
            nodo *temp;
            temp= new nodo;
        }    
    }

    void insertainicio1(int n){
        for (int i = 0; i < n; i++){
            nodo *temp;
            temp= new nodo;
            temp->info1= "{}";
            temp->sig=inicio;
            if(inicio!=NULL){
                inicio->ant=temp;
            }
            inicio=temp;
        }
    }

    void insertaFinal(int n){
        for (int i = 0; i < n; i++){
            nodo *recorre, *temp;
            recorre=inicio;
            while(recorre->sig!=NULL){
                recorre=recorre->sig;
            }
            temp=new nodo;
            temp->ant=recorre;
            temp->info='}';
            recorre->sig=temp;
        }
    }

    void imprime(){
        nodo *recorre=inicio;
        if(inicio==NULL){
            cout<<" Lista vacia. \n"<<endl;
            return;
        }
        while(recorre!=NULL){
            cout<<recorre->info1;
            recorre=recorre->sig;
        }
        cout<< " , ";
    }

    void imprime1(){
        nodo *recorre=inicio;
        if(inicio==NULL){
            return;
        }
        while(recorre!=NULL){
        cout<<recorre->info;
        recorre=recorre->sig;
        }
        cout<< "\n"<<endl;
    }

    void parentesisEmparejados(int n){
        insertainicio(n);
        insertainicio1(n);
        insertaFinal(n);
        cout<< "\n\t*** Imprime numero de parentesis: "<<n<<" ***\n"<<endl;
        imprime();
        imprime1();
    }
};

int main(){
    ldl nodo2;
    int x= 0; 
    cout<<"\n\t*** Parentesis emparejados ***\n"<<endl;
    cout<<" Teclea un numero: ";
    cin>>x;
    nodo2.parentesisEmparejados(x);
    return 0;
}
