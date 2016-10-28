#ifndef _VISUALIZADOR_COLA_H
#define _VISUALIZADOR_COLA_H

#include "visualizador.h"
#include "imagen.h"
#include "cola.h"
#include "graficos.h"
#include "pieza.h"

class VisCola{
    private:
	Visualizador V;
	Cola *cl;
	Imagen *imgArray;
    public:
	/**
	 @brief Constructor por defecto
	*/
	 VisCola();

	/**
	 @brief Constructor con parametros
	*/
	 VisCola(Visualizador &Vis,Cola *pc,Imagen *img);

	/**
	 @brief Constructor de copia
	*/
	 VisCola(const VisCola &otra);

	/**
	 @brief Operador de asignacion
	*/
	 VisCola& operator=(const VisCola &otra);

	/**
	 @brief Destructor
	*/
	 ~VisCola();

	/**
	 @brief Muestra la cola en pantalla
	*/
	 void Display();
};

#endif
