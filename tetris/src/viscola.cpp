#include "viscola.h"

VisCola::VisCola(){
}

VisCola::VisCola(Visualizador &Vis,Cola *pc,Imagen *img){
	V=Vis;
	cl=pc;
	imgArray=img;
}

VisCola::VisCola(const VisCola &otra){
	V=otra.V;
	cl=otra.cl;
	imgArray=otra.imgArray;
}

VisCola& VisCola::operator=(const VisCola &otra){
	V=otra.V;
	cl=otra.cl;
	imgArray=otra.imgArray;
	return *this;
}

VisCola::~VisCola(){
}

void VisCola::Display(){
	int nfil,ncol,nelem,num,k=1,dist=20,cont=1;
	nelem=cl->NumElementos();
	Pieza P;
	int ancho_img;
	int alto_img;
	int marco=V.GetMarco();
	int ancho=V.Ancho();
	int pos=V.GetPosX();
	V.Inicializar();
	for(int nodo=0;nodo<nelem;nodo++){
	   P=cl->RecorreCola(nodo);
	   nfil=P.FilasPieza();
	   ncol=P.ColumnasPieza();
	   for(int i=0;i<nfil;i++){
	      for(int j=0;j<ncol;j++){
		num=P.GetPieza(i,j);
		if(num!=0){
		     ancho_img=imgArray[num-1].AnchoImagen();
		     alto_img=imgArray[num-1].AltoImagen();
		     imgArray[num-1].DibujaVentana((j*ancho_img)+pos+(ancho/2)-(ncol*ancho_img)/2,(i*alto_img)+marco+(k*dist));
	        }
	      }
	   }
	   k=k+3;
        }
}
