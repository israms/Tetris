#include "cola.h"

#include<iostream>

using namespace std;

// Constructor por defecto
Cola::Cola(){
    inicio=0;
    final=0;
    nelems=0;
}

// Destructor
Cola::~Cola(){
    if(nelems!=0){
       Nodo *aux=inicio;

       while(aux!=0){ 
         inicio=inicio->sig;
	 delete aux;
	 aux=inicio;
       }
       final=0;
    }
}

// Inserta pieza al finalde la cola
void Cola::Poner(Pieza &P){
    Nodo *aux=new Nodo;

    if(nelems==0){
	inicio=aux;
	final=aux;
	inicio->P=P;
     }
     else{
	final->sig=aux;
	final=aux;
	final->P=P;
     }
     nelems++;
     final->sig=0;
     aux=0;
}

// Saca la primera pieza de la cola
void Cola::Quitar(){
    if(nelems!=0){
	Nodo *aux=inicio;

	inicio=inicio->sig;
	delete aux;
	aux=0;
	nelems--;
     }
}

// Recorre la cola
Pieza Cola::RecorreCola(int nodo){
	Nodo *aux=inicio;
	int cont=0;
	while(cont<nodo){
		aux=aux->sig;
		cont++;
	}
	return aux->P;
}
