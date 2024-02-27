#include <iostream>  // Cargo librerías (colecciones de funciones ya hechas que hacen cositas): "iostream" me permite sacar texto
#include <cmath>     // y números por el terminal, para que puedas ver el valor de pi, y "cmath" es una colección de funciones
//#include <fstream>   // matemáticas que necesito, como elevar al cuadrado y hacer la raiz cuadrada.

using namespace std;  // A efectos práticos, esto es para no tener que poner "std" todo el rato.

int main(){           // ¡Comenzamos!
    int n = 12345;  // numero de lados del poligono
    double radio=1;  // Este es RADIO DE LA CIRCUNFERENCIA. Puedes cambiarlo; el valor de pi no se ve afectado.

    double A;    // Defino los Perímetros de los polígonos inscritos y circunscritos.
    double B;
    
    A= 4 * sqrt(2) * radio;  // Cargo los perímetros de un CUADRADO inscrito (A) y circunscrito (B). Estos valores pueden ser fácilmente
    B= 8 * radio;          // obtenidos con el teorema de pitagoras, no pi required.
    
    double m=4;     // Este es el número de lados de los polígonos con los que estamos trabajando.
    
    while (m*2<=n) {  // BUCLE. Si el número de lados del polígono a generar supera el número impuesto por usuario, para.
        
        B=2*A*B/(A+B);      // Calculo de los perímetros con el doble de lados. A cada vuelta los valores de A y B se sobreeescriben.
        A=sqrt(A*B);
        
        m=m*2;              // El número de lados se duplica en cada vuelta.
        
    }                 // Fin de BUCLE
    
    double pi=(  A/2/radio + B/2/radio  )/2;         // Calculamos pi como la media de los valores de pi de cada perimetro...
    double err = abs(  A/2/radio - B/2/radio  )/2;   // ... y el error como la resta.
    
    cout.precision(15); // Estos son el número de digitos que quiero que se expulsen por pantalla. Puedes aumentarlo si quieres.
    
    // Sacamos los resultados por pantalla para disfrute del usuario:
    
    cout<<endl<<"  ╔════════════════════════════════════════════════════════════════════════════════════════╗";
    cout<<endl<<"  ║                Con un polígono de "<<m<<" lados, obtenemos:";
    cout<<endl<<"  ║";
    cout<<endl<<"  ║                       "<<"Pi = "<<pi<<"  +/-  "<<err;
    cout<<endl<<"  ║";
    cout<<endl<<"  ║                "<<"o, dicho de otra manera, el valor de pi se encuentra entre";
    cout<<endl<<"  ║                       "<<pi+err<<"   y   "<<pi-err;
    cout<<endl<<"  ╚════════════════════════════════════════════════════════════════════════════════════════╝"<<endl<<endl;
    
    
    return 0;  // Y hemos terminado. Cerramos el chiringuito.
    
}





 