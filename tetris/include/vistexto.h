#ifndef _VISUALIZADOR_TEXTO_H
#define _VISUALIZADOR_TEXTO_H

#include "visualizador.h"
#include "graficos.h"
#include "color.h"
#include<string>

class VisualizadorTexto{
     private:
	Visualizador V;	// Un visualizador
	graficos::GRF_Fuente fuente;    // Tipo de letra
	Color colorLetra;	// Color de la letra
	string texto;	// Texto
     public:
	/**
	 @brief Constructor por defecto
	*/
	VisualizadorTexto();

	/**
	 @brief Constructor por parametros
	*/
	 VisualizadorTexto(Visualizador &Vis,const char *fich,Color &colorL, int &tamano,graficos::TEstiloFuente &estilo,string &txt);

	/**
	 @brief Destructor
	*/
	 ~VisualizadorTexto();

	/**
	 @brief Muestra en pantalla el visualizador de texto
	*/
	 void Display();

	 void EscribeTexto();

	 void TamanoTexto();

	 void AltoFuente();

	 void AsignaTexto(string &cad);

	 graficos::GRF_Fuente GetFuente(){
		return fuente;
	 }
};

#endif
