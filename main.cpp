/******************************************************************************
 // FileName:        main.cpp
 // Program version: Dev-C++ 5.11
 // Company:         TECNM - ITCH
 // Description:     LABORATORIO 3
 // Authors:         LUIS MACIAS
 // Updated:         03/10/2022
 
******************************************************************************/

#include <iostream>
#include <stdlib.h>
using namespace std;

/*clase*/
class Adc{
	private:
		//atributos 
		static int Rs;    //resolucion de 8,10 o 12 bits
	    static float Frecuencia;  //frecuencia de muestreo
	    float  voltaje;           //voltaje de 0 a 3.3v
        double  Rs2;      //conversion a bits
        string canal;             //canales
             
	public:
	    //metodos 
		Adc(){
			canal = "";
		}
		
		void muestraDatos();
		void canales();
        void lectura();
		static void captura();
    
		
};

void Adc::lectura(){
	
  /*ciclo para leer los voltajes y validar que sean del rango correcto*/
  do{
    cout<<"INTRODUZCA UN VOLTAJE DE 0-3.3 VOLTS DEL CANAL " <<canal<<endl;
    cin>>voltaje;
    if(voltaje<0 || voltaje>3.3){
      cout<<"Voltaje erroneo"<<endl;
    }
    
  }while (voltaje<0 || voltaje>3.3);  /*validacion*/
  
  /*calculo para la resolucion de 8 bits*/
  if(Rs == 8){
    Rs2 = (voltaje*255)/3.3;
  }
    /*calculo para la resolucion de 10 bits*/
  if(Rs == 10){
  	Rs2 = (voltaje*1023)/3.3;
  }
    /*calculo para la resolucion de 12 bits*/
   if(Rs == 12){
  	Rs2 = (voltaje*4095)/3.3;
  }
}

/*muestra de datos*/
void Adc::muestraDatos(){
	cout<<"CANAL: "<<canal<<"  DATO CONVERTIDO: "<<Rs2<<endl;
	
}

/*captura de datos*/
void Adc::captura(){
	
	
	
  do{
	  cout<<"INTRODUZCA UNA RESOLUCION DE 8,10 o 12 BITS: ";
	  cin>> Rs;
	  
    if(Rs != 8 && Rs != 10 && Rs !=12)
    {
      cout<< "Datos No validos"<<endl;
    }
  }while(Rs!= 8 && Rs!= 10 && Rs!=12);
  
	cout<<"INTRODUZCA LA FRECUENCIA: ";
	cin>> Frecuencia;
    cout<< "\n";
}


void Adc::canales(){
  cout<< "INTRODUZCA QUE CANALES SE VAN A LEER  AN1---AN32:"<<endl;
  cin>> canal;
}
/*prototipo de funcion portada*/
void portada(void);
/*inicializacion de variables estaticas*/
int Adc:: Rs=0;  
float Adc:: Frecuencia=0;

 /** main **///
int main() {
	
  portada();

  int i, can;
  
  Adc::captura();
  cout<< "INTRODUZCA LA CANTIDADAD DE CANALES DESEADOS: ";
  cin>> can;
  
  /*arreglo de objetos*/
  Adc lectura[can];
    
    
for(int i=0; i<can; i++){
		lectura[i].canales();
	}
	
	for(int i=0; i<can; i++){
		lectura[i].lectura();
	}
	for (int i=0;i<can;i++){
	    lectura[i].muestraDatos();
	
}
	
return 0;
}


void portada(){

cout<<"*********LABORATORIO 3*********"<<endl;
cout<<"FileName:        main.cpp"<<endl;
cout<<"Program version: Dev-C++ 5.11"<<endl;
cout<<"Company:         TECNM - ITCH"<<endl;
cout<<" Authors:         LUIS MACIAS"<<endl;
cout<<"Updated:         03/10/2022"<<endl;
cout<<"*******************************"<<endl;
}
