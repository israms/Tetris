#include "imagen.h"

// Constructor por defecto
Imagen::Imagen(){
}

// Constructor por parametros
Imagen::Imagen(const char *fich){
    img=graficos::LeerImagen(fich);
}

// Constructor de copia
Imagen::Imagen(const Imagen &orig){
    img=graficos::ObtenerCopiaImagen(orig.img);
}

// Operador de asignacion
Imagen& Imagen::operator=(const Imagen &otra){
	img=graficos::ObtenerCopiaImagen(otra.img);
	return *this;
}

// Destructor
Imagen::~Imagen(){
    graficos::LiberarImagen(img);
}

// Lee imagen de fichero
void Imagen::LeerImagenFich(const char *fich){
	img=graficos::LeerImagen(fich);
}
// Calcula el ancho de una imagen
int Imagen::AnchoImagen(){
    return graficos::AnchoImagen(img);
}

// Calcula el alto de una imagen
int Imagen::AltoImagen(){
    return graficos::AltoImagen(img);
}

// Dibuja en la ventana uan imagen
void Imagen::DibujaVentana(int x, int y){
    graficos::DibujarImagen(img,x,y,0);
}
