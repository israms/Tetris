#ifndef _TABLERO_H
#define _TABLERO_H

#include "matriz.h"
#include "pieza.h"

class Tablero{
     private:
	Matriz M;	// Una matriz
	Pieza P;	// Una pieza
	int x,y;	// Columna y fila donde se encuentra la pieza
     public:
	/**
	 @brief Constructor de tablero

	 Crea un tablero vacio.
	*/
	Tablero();

	/**
	 @brief Constructor con parametros
	 @param M una matriz.

	 Crea un tablero con ciertos parametros.
	*/
	Tablero(const Matriz &M);

	/**
	 @brief Constructor de copia
	*/
	Tablero(const Tablero &T);

	/**
	 @brief Operador de asignacion
	*/
	Tablero &operator=(const Tablero &T);

	/**
	 @brief Destructor
	*/
	~Tablero();

	/**
	 @brief Mueve una pieza hacia la izquierda
	*/
	void MoverPiezaIzqda();

	/**
	 @brief Mueve una pieza hacia la derecha
	*/
	void MoverPiezaDch();

	/**
	 @brief Mueve una pieza hacia abajo
	 @param mover Este bool se utiliza para saber si la pieza ha sido depositada
	*/
	void MoverPiezaAbajo(bool &mover);

	/**
	 @brief Mueve una pieza hacia arriba
	*/
	void MoverPiezaArriba();

	/**
	 @brief Comprueba que una pieza puede moverse hacia la izquierda,hacia la derecha,
	 @brief hacia abajo,girar a la derecha o girar a la izquierda.
	 @return Devuelve true si es posible mover la pieza.
	*/
	bool ValidaMovimiento();

	/**
	 @brief Gira una pieza hacia la izquierda
	*/
	void GirarPiezaIzqda();

	/**
	 @brief Gira una pieza hacia la derecha
	*/
	void GirarPiezaDch();

	/**
	 @brief Comprueba si una linea esta completa
	 @param num_lineas numero de lineas que ha borrado
	*/
	void BorraLineas(int &num_lineas);


	/**
	 @brief Comprueba si el tablero esta disponible para jugar
	 @return Devuelve true si el tablero esta disponible para jugar.
	*/
	bool TableroVal();

	/**
	 @brief Inserta una pieza en el tablero
	 @param P la pieza a insertar en el tablero
	*/
	void InsertarPieza(Pieza &P);
	
	/**
	 @brief Pega o fija una pieza en el tablero
	*/
	void PegarPieza();

	/**
	@brief Devuelve la columna en la que se encuentra la pieza situada
	*/
	int PosPiezaX(){
		return x;
	}
	/**
	@brief Devuelve la fila en la que se encuentra la pieza situada
	*/
	int PosPiezaY(){
		return y;
	}

	/**
	@brief Calcula las filas de la matriz de tablero
	*/
	int FilasTablero(){
		return M.FilasMatriz();
	}

	/**
	@brief Calcula las columnas de la matriz de tablero
	*/
	int ColumnasTablero(){
		return M.ColumnasMatriz();
	}

	/**
	@brief Devuelve el elemento (i,j) del tablero
	*/
	int GetTablero(int i,int j){
		return M.GetMatriz(i,j);
	}

	/**
	@brief Devuelve la pieza que tiene asignada el tablero
	*/
	Pieza& GetPieza(){
		return P;
	}

};

#endif
