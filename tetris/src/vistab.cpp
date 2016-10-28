#include "vistab.h"

VisTablero::VisTablero(){
}

VisTablero::VisTablero(Visualizador &Vis,Tablero *T,Imagen *img){
	V=Vis;
	tab=T;
	imgArray=img;
}

VisTablero::VisTablero(const VisTablero &VT){
	V=VT.V;
	tab=VT.tab;
	imgArray=VT.imgArray;
}

VisTablero& VisTablero::operator=(const VisTablero &VT){
	V=VT.V;
	tab=VT.tab;
	imgArray=VT.imgArray;
	return *this;
}

VisTablero::~VisTablero(){
}

void VisTablero::Display(){
	int fil=tab->FilasTablero();
	int col=tab->ColumnasTablero();
	int num;
	int marco=V.GetMarco();
	int ancho_img;
	int alto_img;

	V.Inicializar();
	for(int i=0;i<fil;i++){
		
	   for(int j=0;j<col;j++){
		num=tab->GetTablero(i,j);
		if(num!=0){
		     ancho_img=imgArray[num-1].AnchoImagen();
		     alto_img=imgArray[num-1].AltoImagen();
		     imgArray[num-1].DibujaVentana((j*ancho_img)+marco,(i*alto_img)+marco);
	}
   }
 }
}

void VisTablero::PintaPieza(){
	Pieza P=tab->GetPieza();
	int fil=P.FilasPieza();
	int col=P.ColumnasPieza();
	int elem;
	int marco=V.GetMarco();
	int x=tab->PosPiezaX();
	int y=tab->PosPiezaY();
	int ancho_img;
	int alto_img;
	
	for(int i=0;i<fil;i++){
	   for(int j=0;j<col;j++){
		elem=P.GetPieza(i,j);
		if(elem!=0){
		     ancho_img=imgArray[elem-1].AnchoImagen();
		     alto_img=imgArray[elem-1].AltoImagen();
		     imgArray[elem-1].DibujaVentana(x*ancho_img+(j*ancho_img)+marco,y*alto_img+(i*alto_img)+marco);
		}
	   }
	}
}
