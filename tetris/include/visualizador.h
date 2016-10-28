#ifndef _VISUALIZADOR_H
#define _VISUALIZADOR_H

#include "color.h"
#include "graficos.h"

class Visualizador{
    private:
	int ancho;	// Numero de columnas (en pixeles) de la region, incluyendo el marco
	int alto;	// Numero de filas (en pixeles) de la region, incluyendo el marco
	Color borde;	// Color del borde
	Color fondo;	// Color del fondo
	int marco;	// Numero de pixeles que determinan el grosor del borde
	int x;	// Columna de la ventana donde se situa la esquina superior izquierda de la region
	int y;	// Fila de la ventana donde se situa la esquina superior izquierda de la region
    public:
	/**
	 @brief Constructor por defecto
	*/
	 Visualizador();

	/**
	 @brief Constructor con parametros
	 @param anch Numero de columnas (en pixeles) de la region, incluyendo el marco
	 @param alt Numero de filas (en pixeles) de la region, incluyendo el marco
	 @param bor Color del borde
	 @param fon Color del fondo
	 @param mar Numero de pixeles que determinan el grosor del borde
	 @param posX Columna de la ventana donde se situa la esquina superior izquierda de la region
	 @param posY Fila de la ventana donde se situa la esquina superior izquierda de la region
	*/
	 Visualizador(int &anch,int &alt,Color &bor,Color &fon,int &mar,int &posX,int &posY);

	/**
	 @brief Destructor
	*/
	 ~Visualizador();

	/**
	 @brief Operador de igualdad
	*/
	 Visualizador &operator=(const Visualizador &V);

	/**
	 @brief Inicia el juego
	*/
	 void Inicializar();

	 int GetPosX(){
		return x;
	 }

	 int GetPosY(){
		return y;
	 }


	 int Ancho(){
		return ancho;
	 }


	 int Alto(){
		return alto;
	 }

	int GetMarco(){
		return marco;
	}

	Color GetColorBorde(){
		return borde;
	}

	Color GetColorFondo(){
		return fondo;
	}
};

#endif
