#include "pieza.h"
#include<iostream>

using namespace std;

// Constructor por defecto
Pieza::Pieza(){ } // LLama al constructor por defecto de matriz

// Constructor por parametros
Pieza::Pieza(const Matriz &m){	// Constructor con parametros
   M=m;
}

// Operador de asignacion
Pieza& Pieza::operator=(const Pieza &P){
	this->M=P.M;
	return *this;
}

// Destructor
Pieza::~Pieza(){ } // LLama al destructor de matriz

// Calcula la traspuesta de una matriz
void Pieza::Traspuesta(){
   int fil=M.FilasMatriz();
   int col=M.ColumnasMatriz();
   Matriz aux=Matriz(col,fil);   // Matriz auxiliar 

   for(int i=0;i<fil;i++){    // Calcula traspuesta de M
      for(int j=0;j<col;j++){
          aux.SetMatriz(j,i,M.GetMatriz(i,j));
      }
   }
   M=aux;
}

// Calcula la simetrica por columnas de una matriz
void Pieza::SimColumnas(){
   int fil=M.FilasMatriz();
   int col=M.ColumnasMatriz();
   int valTemp;
   Matriz aux=Matriz(fil,col);

   for(int i=0;i<fil;i++){
      for(int j=0;j<col;j++){
	  valTemp=M.GetMatriz(i,j);
          aux.SetMatriz(i,j,M.GetMatriz(i,col-1-j));
          aux.SetMatriz(i,col-1-j,valTemp);
      }
   }
   M=aux;
}	

// Calcula la simetrica por filas de una matriz
void Pieza::SimFilas(){
   int fil=M.FilasMatriz();
   int col=M.ColumnasMatriz();
   int valTemp;
   Matriz aux=Matriz(fil,col);

   for(int i=0;i<fil;i++){
      for(int j=0;j<col;j++){
	  valTemp=M.GetMatriz(i,j);
          aux.SetMatriz(i,j,M.GetMatriz(fil-1-i,j));
          aux.SetMatriz(fil-1-i,j,valTemp);
      }
   }
   M=aux;
}

// Gira una pieza a la derecha
void Pieza::GirarDerecha(){
   Traspuesta();
   SimColumnas();
}

// Gira una pieza a la izquierda
void Pieza::GirarIzquierda(){
   Traspuesta();
   SimFilas();
}

