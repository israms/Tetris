#ifndef _IMAGEN_H
#define _IMAGEN_H

#include "graficos.h"

class Imagen{
     private:
	graficos::GRF_Imagen img;
     public:
	/**
	 @brief Constructor por defecto
	*/
	 Imagen();

	/**
	 @brief Constructor con parametros
	 @param ancho El ancho de la imagen
	 @param alto El alto de la imagen
	*/
	 Imagen(const char *fich);

	/**
	 @brief Constructor de copia
	*/
	 Imagen(const Imagen &imagen);

	/**
	 @brief Operador de asignacion
	*/
	 Imagen &operator=(const Imagen &otra);
	/**
	 @brief Destructor
	*/
	 ~Imagen();

	/**
  	@brief Cargar desde un fichero en disco una imagen BMP
  	@param fich nombre del archivo con la imagen
  	@return Un puntero a la imagen cargada, 0 si no es posible cargarla. 
  	         Si ocurre un error, se describe el problema en la salida estándar de error
  	@post Si se realiza la lectura con éxito, la imagen deberá finalmente ser liberada con
  	      LiberarImagen
  	@see LiberarImagen, DimensionesImagenFichero
  	*/
	void LeerImagenFich(const char *fich);

	/**
	 @brief Calcula el ancho de una imagen
	 @return Devuelve el ancho de la imagen en pixel.
	*/
	 int AnchoImagen();

	/**
	 @brief Calcula el ancho de una imagen
	 @return Devuelve el ancho de la imagen en pixel.
	*/
	 int AltoImagen();

	/**
	 @brief Dibuja en la ventana gráfica, a partir de las coordenadas (@a x, @a y),
	 @brief la imagen almacenada en @a img
	 @param img puntero a la imagen que dibujar
	 @param x coordenada horizontal (columna) a partir de la cual pintar la imagen @a img
	 @param y coordenada vertical (fila) a partir de la cual pintar la imagen  @a img
	 @param imgdest indica la imagen donde pintar. Si vale cero, se asume la ventana.
	 @pre imgdest debe indicar un destino válido, ya sea que la ventana se haya creado si vale 0, o que apunte a una imagen creada.
	 @pre La imagen debe caber completa en el área delimitada por el destino
        */
	 void DibujaVentana(int x, int y);


};

#endif
