#ifndef _VISUALIZADOR_TABLERO_H
#define _VISUALIZADOR_TABLERO_H

#include "visualizador.h"
#include "imagen.h"
#include "tablero.h"
#include "graficos.h"

class VisTablero{
   private:
	Visualizador V;
	Tablero *tab;
	Imagen *imgArray;
   public:
	/**
	 @brief Constructor
	*/
	 VisTablero();

	/**
	 @brief Constructor por parametros
	*/
	 VisTablero(Visualizador &Vis,Tablero *T,Imagen *img);

	/**
	 @brief Constructor de copia
	*/
	 VisTablero(const VisTablero &VT);

	/**
	 @brief Operador de igualdad
	*/
	 VisTablero& operator=(const VisTablero &otro);

	/**
	 @brief Destructor
	*/
	 ~VisTablero();

	/**
	 @brief Muestra el visualizador
	*/
	 void Display();

	void PintaPieza();


};

#endif
