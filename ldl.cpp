#include <iostream>
#include <stdlib.h>

using namespace std;

class nodo{
	public:

	nodo(){
		ant=sig=NULL;
	}
    private:
	int info;
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

nodo *temp;
temp= new nodo;
temp->info=n;
temp->sig=inicio;

if(inicio!=NULL){
    inicio->ant=temp;
}
inicio=temp;
cout<<"\n Elemento agregado al inicio."<<endl;

}

void insertaFinal(int n){

    nodo *recorre, *temp;

    if(inicio==NULL){
        cout<<"\n La lista estaba vacia! "<<endl;
        insertainicio(n);
        return;
    }

    recorre=inicio;
    while(recorre->sig!=NULL){
        recorre=recorre->sig;
    }
    temp=new nodo;
    temp->ant=recorre;
    temp->info=n;
    recorre->sig=temp;
    cout<<"\n Elemento agregado al final."<<endl;
}

void borraInicio(){

    if(inicio==NULL){
      cout<<"\n Lista vacia. "<<endl;
      return;
    }

    if(inicio->sig!=NULL){
    inicio=inicio->sig;
    inicio->ant=NULL;
    cout<<"\n Se borro un elemento"<<endl;
    }
    else{
      inicio=NULL;
      cout<<"\n Se borro el ultimo elemento"<<endl;
    }
}

void borraFinal(){
    nodo *recorre=inicio;
    if(inicio==NULL){
        cout<<"\n Lista vacia. "<<endl;
        return;
    }


    while(recorre->sig!=NULL){
        recorre=recorre->sig;
    }

    if(recorre->ant!=NULL){

    recorre=recorre->ant;
    recorre->sig=NULL;
    cout<<"\n Se borro un elemento "<<endl;
    }
    
    else{
    
      inicio=NULL;
      delete recorre;
    
      if (inicio==NULL){
        cout<<"\n Se borro el ultimo elemento"<<endl;
      }

    }
}

void imprime(){


    nodo *recorre=inicio;
    if(inicio==NULL){
        cout<<"\n Lista vacia. "<<endl;
        return;
    }
    cout<<"\n NULL <-> ";
    while(recorre!=NULL){
       cout<<recorre->info<<" <-> ";
       recorre=recorre->sig;
    }
    cout<<"NULL"<<endl;
}

void imprimeReves(){
    nodo *recorre=inicio;
    if(inicio==NULL){
        cout<<"\n Lista vacia. "<<endl;
        return;
    }
    while(recorre->sig!=NULL){
        recorre=recorre->sig;
    }
    cout<<"\n NULL <-> ";
    while(recorre!=NULL){
        cout<<recorre->info<<" <-> ";
        recorre=recorre->ant;
    }
    cout<<"NULL"<<endl;
}

void contador(){

    nodo *p=inicio;
    int cnt=0;
    if(p==NULL){
        cout<<"\n Lista vacia. "<<endl;
        return;
    }
    cout<<"\n Inicio actual vale: "<<p->info<<endl;
    while(p!=NULL){
        p=p->sig;
    cnt++;
    }
    cout<<"\n Numero de elementos: "<<cnt<<endl;

}

void menu(){
    int x;
    char opcion=' ';
    cout<<"\n\t MENU: \n"<<endl;
    cout<<" (A) Inserta al inicio. \n"<<endl;
    cout<<" (B) Inserta al final. \n"<<endl;
    cout<<" (C) Borra inicio. \n"<<endl;
    cout<<" (D) Borra final. \n"<<endl;
    cout<<" (E) Imprime lista. \n"<<endl;
    cout<<" (F) Imprime lista invertida. \n"<<endl;
    cout<<" (G) Contador. \n"<<endl;

    cout<<"\n Elige una opcion: ";
    cin>>opcion;

    switch(opcion){

       case 'a': case 'A':
       system("cls");
       cout<<"\n\n\t*** Inserta inicio ***\n"<<endl;
       cout<<" Teclea dato: ";
       cin>>x;
       insertainicio(x);
       menu();
       break;

       case 'b': case 'B':
       system("cls");
       cout<<"\n\n\t*** Inserta Final ***\n"<<endl;
       cout<<" Teclea dato: ";
       cin>>x;
       insertaFinal(x);
       menu();
       break;

       case 'c': case 'C':
       system("cls");
       cout<<"\n\n\t*** Borra inicio ***\n"<<endl;
       borraInicio();
       menu();
       break;

       case 'd': case 'D':
       system("cls");
       cout<<"\n\n\t*** Borra final ***\n"<<endl;
       borraFinal();
       menu();
       break;

       case 'e': case 'E':
       system("cls");
       cout<<"\n\n\t*** Lista ***\n"<<endl;
       imprime();
       menu();
       break;

       case 'f': case 'F':
       system("cls");
       cout<<"\n\n\t*** Lista invertida***\n"<<endl;
       imprimeReves();
       menu();
       break;

       case 'g': case 'G':
       system("cls");
       cout<<"\n\n\t*** Numero de elementos ***\n"<<endl;
       contador();
       menu();
       break;

       default:
       cout<< "\n\n\t ++ END ++ \n\n" ;
    }
}

};

int main(){

    ldl nodo2;
    cout<<"\n\n\t*** Lista doblemente ligada ***\n"<<endl;
    nodo2.menu();
    return 0;
}
