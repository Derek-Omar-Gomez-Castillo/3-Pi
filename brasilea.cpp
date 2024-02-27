#include <iostream>  // Cargo librerías (colecciones de funciones ya hechas que hacen cositas): "iostream" me permite sacar texto
#include <cmath>     // y números por el terminal, para que puedas ver el valor de pi, y "cmath" es una colección de funciones

using namespace std;  // A efectos práticos, esto es para no tener que poner "std" todo el rato.

int main(){           // ¡Comenzamos!
    double N = 12345;         // NÚMERO DE TÉRMINOS A SUMAR. ¡CAMBIAD ESTO!
    double S=0;  // Defino la suma total de los términos y la inicializo a 0.
    for (int i=0; i<N; i++) {  // Bucle, recorre todo los naturales hasta N.
        S=S+ 1/pow(i+1,2);     // En cada vuelta se añade a S el siguiente término.
    }
    
    double pi=sqrt(6*S);       // Se calcula pi.
    
    
    cout.precision(15); // Estos son el número de digitos que quiero que se expulsen por pantalla. Puedes aumentarlo si quieres.
    
    // Sacamos los resultados por pantalla para disfrute del usuario:
    
    cout<<endl<<"  ╔════════════════════════════════════════════════════════════════════════════════════════╗";
    cout<<endl<<"  ║                            "<<"Pi = "<<pi;
    cout<<endl<<"  ║";
    cout<<endl<<"  ║                "<<"El valor real de pi se encuentra algo más arriba";
    cout<<endl<<"  ╚════════════════════════════════════════════════════════════════════════════════════════╝"<<endl<<endl;
    
    
    return 0;
}