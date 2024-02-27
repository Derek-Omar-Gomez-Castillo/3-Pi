#include <iostream>  // Cargo librerías (colecciones de funciones ya hechas que hacen cositas): "iostream" me permite sacar texto
#include <cmath>     // y números por el terminal, para que puedas ver el valor de pi, y "cmath" es una colección de funciones

using namespace std;  // A efectos práticos, esto es para no tener que poner "std" todo el rato.

int main(){           // ¡Comenzamos!
    double numero_de_dardos = 12345;         // NÚMERO DE PUNTOS ALEATORIOS A LANZAR. ¡CAMBIAD ESTO!
    cout << "Cantidd de dardos a lanzar" << numero_de_dardos;
    double r=1;       // RADIO DEL CÍRCULO: Puedes cambiar este número si lo deseas; el tamaño de la circunferencia no afecta a pi.
 
    srand((unsigned)time(0));  // Para que el ordenador nos genere los números aleatorios, hay que darle una semilla. Normalmente
                               // suele cogerse el tiempo del reloj del ordenador en ese momento.
    
    double x;                  // Defino las coordenadas de cada punto aleatorio. No queremos almacenarlas; reescribiremos estas variable.
    double y;
    
    double c=0;                // Defino el número de puntos dentro del círculo (de la porción). Partimos de 0.
    
    //int m=1e7;
    
    int cota=10;               // COTA. NÚMERO DE REPETICIONES DEL MÉTODO. Puedes cambiar este número si lo deseas.
    
    double pi_ar[cota];        // Defino el array que voy a llenar de los distintos pi's que obtenga.
    
    
    for (int j=0; j<cota; j++) {               // Primer BUCLE. Repetirá Montecarlo "cota" veces.
        
        for (int i=0; i<numero_de_dardos; i++) {                // Segundo BUCLE. En cada vuelta, lanza un dardo.
            
            x=(double)rand()/(double)RAND_MAX;   // Generamos dos números aleatorios desde 0 a 1. Nótese que en los siguientes
            y=(double)rand()/(double)RAND_MAX;   // lanzamientos estos números serán reescritos.
            
            x=x*r;                               // Dilato estos números hasta el radio. Ahora van de 0 a "r". Estas son las coordenadas
            y=y*r;                               // en las que ha caido un dardo.
            
            if (x*x+y*y<r*r) {                   // Compruebo si el dardo está o no dentro del circulo. Si es así, c aumentará en uno.
                c++;
            }
        }                                        // FIN Segundo BUCLE
        
        pi_ar[j]=4*c/numero_de_dardos;                        // Calculo el pi generado en esta tanda y lo almaceno.
        c=0;                                   // Inicializo a cero para la siguiente tanda de disparos.
        
    }                                          // FIN Primer BUCLE
    
    double pi=0;             // Defino pi y el error de pi. Los inicializo a cero por el método para obtener la media y la SD.
    double err=0;
    
    for (int j=0; j<cota; j++) {
        pi = pi_ar[j]/cota + pi;                 // Hago la media de todos los pi's calculados
    }
    
    for (int j=0; j<cota; j++) {
        err = err + pow(pi-pi_ar[j],2)/cota;     // Calculo la desviación estándar de los pi's calculados. Consulta su definición
    }                                            // para más info, pero es sumar estos términos y...
    
    err = sqrt(err);                             // ... hacer la raiz cuadrada de lo que te salga.
    
    
    cout.precision(15); // Estos son el número de digitos que quiero que se expulsen por pantalla. Puedes aumentarlo si quieres.
    
    // Sacamos los resultados por pantalla para disfrute del usuario:
    
    cout<<endl<<"  ╔════════════════════════════════════════════════════════════════════════════════════════╗";
    cout<<endl<<"  ║                       "<<"Pi = "<<pi<<"  +/-  "<<err;
    cout<<endl<<"  ║";
    cout<<endl<<"  ║                "<<"o, dicho de otra manera, el valor de pi se encuentra entre";
    cout<<endl<<"  ║                       "<<pi+err<<"   y   "<<pi-err;
    cout<<endl<<"  ╚════════════════════════════════════════════════════════════════════════════════════════╝"<<endl<<endl;

    
    return 0;
}


