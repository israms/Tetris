#include "visualizador.h"

Visualizador::Visualizador(){
}

Visualizador::Visualizador(int &anch,int &alt,Color &bor,Color &fon,int &mar,int &posX,int &posY){
	ancho=anch;
	alto=alt;
	borde=bor;
	fondo=fon;
	marco=mar;
	x=posX;
	y=posY;
}

Visualizador::~Visualizador(){
}

Visualizador& Visualizador::operator=(const Visualizador &V){
	ancho=V.ancho;
	alto=V.alto;
	borde=V.borde;
	fondo=V.fondo;
	marco=V.marco;
	x=V.x;
	y=V.y;

	return *this;
}

void Visualizador::Inicializar(){
   graficos::RectanguloR(x,y,x+ancho-1,y+alto-1,borde.GetR(),borde.GetG(),borde.GetB());
   graficos::RectanguloR(x+marco,y+marco,x+ancho-marco-1,y+alto-marco-1,fondo.GetR(),fondo.GetG(),fondo.GetB());
}
