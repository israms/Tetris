#include "vistexto.h"

VisualizadorTexto::VisualizadorTexto(){
}

VisualizadorTexto::VisualizadorTexto(Visualizador &Vis,const char *fich,Color &colorL, int &tamano,graficos::TEstiloFuente &estilo,string &txt){
   V=Vis;
   fuente=graficos::CargarFuente(fich,tamano,estilo);
   colorLetra=colorL;
   texto=txt;
}

VisualizadorTexto::~VisualizadorTexto(){
    //graficos::LiberarFuente(fuente);
}

void VisualizadorTexto::Display(){
	int x=V.GetPosX();
	int y=V.GetPosY();
	int ancho=V.Ancho();
	int alto=V.Alto();
	int marco=V.GetMarco();
	V.Inicializar();
	graficos::EscribirTexto(x+marco,y+(alto/3),texto.c_str(),fuente,colorLetra.GetR(),colorLetra.GetG(),colorLetra.GetB());
}

void VisualizadorTexto::AsignaTexto(string &cad){
	texto=cad;
}

