#ifndef _PIEZA_H
#define _PIEZA_H

#include "matriz.h"
#include<iostream>

class Pieza{
   private:
	Matriz M;  // Una matriz

	/**
	  @brief Calcula la traspuesta de una matriz
	*/
	void Traspuesta();

	/**
	  @brief Calcula la simetrica por columnas de una matriz
	*/
	void SimColumnas();

	/**
	  @brief Calcula la simetrica por filas de una matriz
	*/
	void SimFilas();
   public:
    	/**
     	@brief Constructor por defecto

     	Crea una pieza vacia.
    	*/
     	Pieza();

    	/**
     	@brief Constructor con parametros
     	@param M una matriz

     	Crea una pieza.
    	*/
     	Pieza(const Matriz &M);

	/**
	 @brief Operador de asignacion
	*/
	Pieza &operator=(const Pieza &P);

    	/** 
    	 @brief Destructor
    	*/
     	~Pieza();
    	/**
     	@brief Gira una pieza hacia la derecha
    
     	Calcula la traspuesta de matriz, luego calcula la simetrica por columnas de esta.
    	*/
     	void GirarDerecha();
     
    	/**
     	@brief Gira una pieza hacia la izquierda
    
     	Calcula la traspuesta de una matriz, luego calcula la simetrica por filas de esta.
    	*/
    	void GirarIzquierda();

	/**
	@brief Calcula el alto de la pieza
	@return devuelve un entero con la altura de la pieza
	*/
	int FilasPieza(){
		return M.FilasMatriz();
	}
	/**
	@brief Calcula el ancho de la pieza
	@return devuelve un entero con la anchura de la pieza
	*/
	int ColumnasPieza(){
		return M.ColumnasMatriz();
	}
	/**
	 @brief Calcula el elemento(i,j) de la pieza
	 @param i fila i de la pieza
	 @param j columna j de la pieza
	 @return Devuelve el elemento(i,j) de la pieza
	*/

	int GetPieza(int i,int j){
		return M.GetMatriz(i,j);
	}
};

#endif
