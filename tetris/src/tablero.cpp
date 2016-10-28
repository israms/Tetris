#include "tablero.h"
#include<iostream>

using namespace std;

// Constructor por defecto
Tablero::Tablero(){
}

// Constructor por parametros
Tablero::Tablero(const Matriz &M){
	this->M=M;
	this->x=0;
	this->y=0;
}

// Constructor de copia
Tablero::Tablero(const Tablero &T){
	this->M=T.M;
	this->P=T.P;
	this->x=T.x;
	this->y=T.y;
}

// Operador de asignacion
Tablero& Tablero::operator=(const Tablero &T){
	M=T.M;
	P=T.P;
	x=T.x;
	y=T.y;
	return *this;
}

// Destructor
Tablero::~Tablero(){
}

// Mover izquierda
void Tablero::MoverPiezaIzqda(){
	if(x!=0){
	   x=x-1;
	}
	if(!ValidaMovimiento()){
	      MoverPiezaDch();
	}
}

// Mover derecha
void Tablero::MoverPiezaDch(){
	int ncolP=P.ColumnasPieza();
	int ncolM=M.ColumnasMatriz();
	if(ncolM-1-x>=ncolP){
		x=x+1;
	}
	if(!ValidaMovimiento()){
	       MoverPiezaIzqda();
	}
}

// Mover abajo
void Tablero::MoverPiezaAbajo(bool &mover){
	int filM=M.FilasMatriz();
	int filP=P.FilasPieza();
	mover=false;
	
	if(filM-1-y>=filP){
		y=y+1;
		if(ValidaMovimiento()){
			mover=true;
		}
	}
	else{
		y=y+1;
	}
	if(!mover){
	    MoverPiezaArriba();
        }
}

// Mover arriba
void Tablero::MoverPiezaArriba(){
	int filM=M.FilasMatriz();
	int filP=P.FilasPieza();
	if(filM-y+1>=filP){
	   y=y-1;
	}
}

// Valida si un movimiento es posible
bool Tablero::ValidaMovimiento(){
    int fil=P.FilasPieza();
    int col=P.ColumnasPieza();
    int colM=M.ColumnasMatriz();
    int filM=M.FilasMatriz();
    bool mover=true;

    for(int i=0;i<fil && mover;i++){
	for(int j=0;j<col && mover;j++){
		if((P.GetPieza(i,j)!=0) && (M.GetMatriz(y+i,x+j)!=0)){
		    mover=false;
	        }
	}
    }
    return mover;
}

// Gira pieza izquierda
void Tablero::GirarPiezaIzqda(){
    int fil=P.FilasPieza();
    int col=P.ColumnasPieza();
    int colM=M.ColumnasMatriz();
    int filM=M.FilasMatriz();
    if((y+col<=filM) && (x+fil<=colM)){
		P.GirarIzquierda();
    }
    if(!ValidaMovimiento()){
	 GirarPiezaDch();
    }
}

// Gira pieza derecha
void Tablero::GirarPiezaDch(){
    int fil=P.FilasPieza();
    int col=P.ColumnasPieza();
    int colM=M.ColumnasMatriz();
    int filM=M.FilasMatriz();
    if((y+col<=filM) && (x+fil<=colM)){
	    P.GirarDerecha();
    }
    if(!ValidaMovimiento()){
	 GirarPiezaIzqda();
    }
}

// Borra una linea completa
void Tablero::BorraLineas(int &num_lineas){
	int fil=M.FilasMatriz();
	int col=M.ColumnasMatriz();
	bool salir=false;
	bool completa;
	int fila;
	for(fila=0;fila<fil;fila++){
		completa=true;
		salir=false;
		for(int j=0;j<col && !salir;j++){
			if(M.GetMatriz(fila,j)==0){
				completa=false;
				salir=true;
			}
		}
		if(completa){
			num_lineas++;
			for(int i=fila;i>0;i--){
				for(int j=0;j<col;j++){
					M.SetMatriz(i,j,M.GetMatriz(i-1,j));
				}
			}
			for(int j=0;j<col;j++){
				M.SetMatriz(0,j,0);
			}
		}	
	}
}

// Comprueba el estado del acumulador de piezas
bool Tablero::TableroVal(){
	int filP=P.FilasPieza();
	int colP=P.ColumnasPieza();
	int col=M.ColumnasMatriz();
	
	for(int i=0;i<filP;i++){
		for(int j=(col/2)-2;j<(col/2)-2+colP;j++){
			if(M.GetMatriz(i,j)!=0){
				return false;
			}
		}
	}
	return true;
}

// Inserta y le asigna al tablero una pieza
void Tablero::InsertarPieza(Pieza &P){
	int col=M.ColumnasMatriz();
	int fil=M.FilasMatriz();
	this->P=P;
	x=(col/2)-2;
	y=0;
}

// Pega la pieza en el tablero
void Tablero::PegarPieza(){
	int fil=P.FilasPieza();
	int col=P.ColumnasPieza();

	for(int i=0;i<fil;i++){
	    for(int j=0;j<col;j++){
		if(P.GetPieza(i,j)!=0){
		     M.SetMatriz(y+i,x+j,P.GetPieza(i,j));
	        }

	    }
	}
}

