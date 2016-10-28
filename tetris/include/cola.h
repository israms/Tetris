#ifndef _COLA_H
#define _COLA_H

#include "pieza.h"

class Cola{
     private:
	struct Nodo{
	    Pieza P;
	    Nodo *sig;
	};
	Nodo *inicio;
	Nodo *final;
	int nelems;
     public:
	/**
         @brief Constructor por defecto
       */
	Cola();

       /**
       @brief Constructor de copia
      */
       Cola(const Cola &C);

	/**
	 @brief Operador de asignacion
	*/
	 Cola &operator=(const Cola &C);

	/**
	 @brief Destructor
	*/
	 ~Cola();

	/**
	 @brief Introduce una pieza en la cola
	 @param P la pieza que se inserta en la cola

	 Introduce al final de la cola una pieza nueva.
	*/
	 void Poner(Pieza &P);

	/**
	 @brief Elimina una pieza en la cola

	 Quita la primera pieza de la cola.
	*/
	 void Quitar();

	/**
	 @brief Indica si la cola esta vacia o no
	 @return Devuelve 0 si la cola esta vacia, 1 en caso contrario.
	*/
	 int ColaVacia();

	/**
	 @brief Indica el numero de elementos de la cola
	 @return Devuelve el numero de elementos de la cola.
	*/
	 int NumElementos(){
		return nelems;
	 }
	/**
	 @brief Devuelve la primera pieza que hay en 
	 @return devuelve una pieza
	*/
	 Pieza GetFirstPieza(){
		return inicio->P;
	}
	/**
	 @brief Recorre la cola
	 @param nodo un nodo de la cola
	 @return devuelve la pieza que se encuentra en nodo
	*/
	Pieza RecorreCola(int nodo);

};

#endif
