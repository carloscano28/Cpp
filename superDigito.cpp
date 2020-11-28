
/*  SUPER DIGITO
Dado un numero se encuentra el super digito de ese numero.
La funcion superDigito() recibe 2 numeros y se calcula el super digito del numero resultante en
la concatenacion de n veces.
Elaborado por: Carlos Roberto Cano Noguera
Correo: ccanon1100@alumno.ipn.mx
Entorno de operacion: WIndows 10
Lenguaje de programacion: C++
Compilador: c++ (i686-posix-dwarf-rev0, Built by MinGW-W64 project) 8.1.0
*/

#include <iostream>
#include <stdlib.h>

using namespace std;

void super_digit(long n, int m){    
    
    int numTotal, x=0, suma=0, y=0,z=0;
    long num2=n, t=0;

    while ( n != 0 ){                       // Cuenta digitos de un numero.
        n= n/10;
        x++;                         
    }
    
    numTotal = x*m;                         // num digitos * num concatenaciones
    int arr[numTotal];               
        
    for(int i=0; i < m; i++){               // Separa un numero en sus cifras individuales
        t=num2;
        while ( t > 0 ){
            arr[z]=t %10;
            t= t/10;
            z++;                         
        } 
    }

    cout<<"\n\t*** Resultado ***\n\n";        // Suma de digitos
    for (y = numTotal-1; y >= 0 ; y--){
        suma+=arr[y];
        
        if (y==0){
            cout<<arr[y];
        }
        else{
            cout<<arr[y]<<"+";
        }
    }
    cout<<": "<<suma<<" \n";
    x=0;
    n=suma;
    while ( n != 0 ){                        // Cuenta digitos de un numero.
        n= n/10;
        x++;                         
    }

    long a=suma, b=suma, u=0;        
    int c=0;

    while (x>1){
        x=0;
        z=0;
        while ( a >=1 ){                    // Cuenta digitos de un numero.
            a= a/10;
            x++;                         
        }
        
        int arr[x];                         //Crea arreglo con tamanio x
        
        while ( b > 0 ){                    // Separa un numero en cifras individuales
            arr[z]=b %10;
            b= b/10;
            z++;                         
        }
        
        u=0;
        for (c = x-1; c >= 0 ; c--){        // Suma de digitos
            u+=arr[c];                    
            if (c==0){
                cout<<arr[c];
            }
            else{
                cout<<arr[c]<<"+";
            }             
        }
        cout<<": "<<u<<"\n";            
        a=u;                            
        b=u;
        x=0;
        while ( a >=1 ){                   // Cuenta digitos de un numero.
            a= a/10;
            x++;                         
        }
        a=u;
        b=u;  
    }
}


int main(){
    long x=0;        
    int y=0;        
    cout<<"\n\t*** Super digito ***\n"<<endl;
    cout<<" Teclea un numero para encontrar el super digito: ";
    cin>>x;
    cout<<" Teclea otro numero para concatenar: ";
    cin>>y;
    super_digit(x,y);   
    cout<<endl;
    return 0;
}