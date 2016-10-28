#include "matriz.h"
#include<iostream>

using namespace std;

// Constructor por defecto
Matriz::Matriz(){	// Inicializa a cero la matriz
   nf=0;
   nc=0;
   m=0;
}

// Constructor por parametros
Matriz::Matriz(int nf,int nc){
   this->nf=nf;
   this->nc=nc;
   m=new int *[nf];
   for(int i=0;i<nf;i++){
      m[i]=new int [nc];
   }
}

// Constructor de copia
Matriz::Matriz(const Matriz& M){
   nf=M.nf;
   nc=M.nc;
   m=new int *[nf];
   for(int i=0;i<nf;i++){
      m[i]=new int [nc];
      for(int j=0;j<nc;j++){
         m[i][j]=M.m[i][j];
      }
   }
}

// Operador de asignacion
Matriz& Matriz::operator=(const Matriz &M){
   if(this!=&M){
     for(int i=0;i<nf;i++){
         delete [] m[i];
     }
     delete [] m;
     nf=M.nf;
     nc=M.nc,
     m=new int *[nf];
     for(int i=0;i<nf;i++){
        m[i]=new int [nc];
     }
     for(int i=0;i<nf;i++){
        for(int j=0;j<nc;j++){
            m[i][j]=M.m[i][j];
        }
     }
  }
  return *this;
}

// Destrcutor
Matriz::~Matriz(){
   if(m!=0){
      for(int i=0;i<nf;i++){
           delete [] m[i];
      }
   }
   delete [] m;
}

// Operador de entrada
istream & operator >> (istream &is,Matriz &M){
	int fil=M.FilasMatriz();
	int col=M.ColumnasMatriz();
	int valor;

	for(int i=0;i<fil;i++){
		for(int j=0;j<col;j++){
			is>>valor;
			M.SetMatriz(i,j,valor);
		}
	}
	return is;
}
