#ifndef _COLOR_H
#define _COLOR_H

#include<iostream>

using namespace std;

class Color{
     private:
	int r,g,b;
     public:
	/**
	 @brief Constructor
	*/
	Color();

	/**
	 @brief Constructor con parametros
	 @param red Tonalidad de rojo
	 @param green Tonalidad de verde
	 @param blue Tonalidad de azul
	*/
	 Color(int red,int green,int blue);

	/**
	 @brief Destructor
	*/
	 ~Color();
	/**
	@brief Devuelve la componente roja del color
	*/
	int GetR(){
		return r;
	}
	/**
	@brief Devuelve la componente verde del color
	*/
	int GetG(){
		return g;
	}
	/**
	@brief Devuelve la componente azul del color
	*/
	int GetB(){
		return b;
	}
	/**
	 @brief Operador de entrada
	*/
	friend istream & operator >> (istream &is,Color &C);

};

#endif
