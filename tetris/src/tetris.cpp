#include<iostream>
#include<cstdlib>
#include<sstream>
#include<fstream>
#include<ctime>
#include<string>
#include "matriz.h"
#include "pieza.h"
#include "tablero.h"
#include "graficos.h"
#include "imagen.h"
#include "visualizador.h"
#include "vistexto.h"
#include "vistab.h"
#include "viscola.h"

using namespace std;

void Inicia_Generador(int semilla);
int ObtenValor(int numPiezas);
int ActualizaTimeN(int Tbajada,int nivel);
void ActualizaMarcadores(VisualizadorTexto &lines,VisualizadorTexto &pzs,VisualizadorTexto                                  &lvl,int num_lineas,int num_piezas,int nvl);

void QuitaComentarios(istream &is);
void LeeVisualizador(istream &is,int &ancho,int &alto,int &marco,Color &borde,Color &fondo,int &x,
                     int &y,Visualizador &V);

void LeeDatosTxt(istream &is,string &ruta,int &tam,int &estilo,Color &ColorLetra);

int main(int argc, char *argv[]){
	if(argc!=2){  // Si el numero de argumentos no es dos sale del programa
    		cerr<<"Error, numero incorrecto de parametros"<<endl;
    		exit(1);
	}
	string carpeta,archivo,ruta;
	int numimg,numPiezasCola,estilo,tam,TimeN;
	int numPiezas;
	string titulo,directorio1,directorio2,directorio3,directorio4,directorio5;
	graficos::TTecla tecla;
	int semilla,subeNvl,Nvl=0;
	fstream f;
	int posx,posy,ancho,alto,marco,fil,col;
	Color fondo,borde,ColorLetra;
	Visualizador VTab,VCola,VTitulo,VNivel,VLineas,VPiezas,VEstado;
	VisualizadorTexto Tit,Niv,Pzs,Lines,Estado;
	f.open(argv[1]);
	if(!f){
		cerr<<"No se puede abrir el fichero "<<argv[1]<<endl;
		exit(1);
	}
	else{
		QuitaComentarios(f);
		f>>semilla;
		QuitaComentarios(f);
		f>>TimeN;
		QuitaComentarios(f);
		f>>subeNvl;
		QuitaComentarios(f);
		f>>numPiezasCola;
		QuitaComentarios(f);
		f>>numimg;
		Imagen *Vimg=new Imagen[numimg];	// Vector de imagenes
		QuitaComentarios(f);
		f>>carpeta;
		for(int i=0;i<numimg;i++){
			QuitaComentarios(f);
			f>>archivo;
			ruta=carpeta+"/"+archivo;
			Vimg[i]=Imagen(ruta.c_str());
		}
		LeeVisualizador(f,ancho,alto,marco,borde,fondo,posx,posy,VTab);
		LeeVisualizador(f,ancho,alto,marco,borde,fondo,posx,posy,VCola);
		QuitaComentarios(f);
		getline(f,titulo);
		LeeDatosTxt(f,directorio1,tam,estilo,ColorLetra);
		LeeVisualizador(f,ancho,alto,marco,borde,fondo,posx,posy,VTitulo);
		Tit=VisualizadorTexto(VTitulo,directorio1.c_str(),ColorLetra,tam,estilo,titulo);
		titulo="Nivel: 0";
		LeeDatosTxt(f,directorio2,tam,estilo,ColorLetra);
		LeeVisualizador(f,ancho,alto,marco,borde,fondo,posx,posy,VNivel);
		Niv=VisualizadorTexto(VNivel,directorio2.c_str(),ColorLetra,tam,estilo,titulo);
		titulo="Lineas: 0";
		LeeDatosTxt(f,directorio3,tam,estilo,ColorLetra);
		LeeVisualizador(f,ancho,alto,marco,borde,fondo,posx,posy,VLineas);
		Lines=VisualizadorTexto(VLineas,directorio3.c_str(),ColorLetra,tam,estilo,titulo);
		titulo="Piezas: 0";
		LeeDatosTxt(f,directorio4,tam,estilo,ColorLetra);
		LeeVisualizador(f,ancho,alto,marco,borde,fondo,posx,posy,VPiezas);
		Pzs=VisualizadorTexto(VPiezas,directorio4.c_str(),ColorLetra,tam,estilo,titulo);
		titulo="Jugando...";
		LeeDatosTxt(f,directorio5,tam,estilo,ColorLetra);
		LeeVisualizador(f,ancho,alto,marco,borde,fondo,posx,posy,VEstado);
		Estado=VisualizadorTexto(VEstado,directorio5.c_str(),ColorLetra,tam,estilo,titulo);
		QuitaComentarios(f);
		f>>numPiezas;
		if(numPiezas<=0){
			cerr<<"Error al leer el fichero. Datos incorrectos"<<endl;
			exit(1);
		}
		Pieza *Vp=new Pieza[numPiezas];
		for(int i=0;i<numPiezas;i++){
			QuitaComentarios(f);
			f>>fil;
			QuitaComentarios(f);
			f>>col;
			if((fil<=0) || (col<=0)){
					cerr<<"Error al leer el fichero. Datos incorrectos"<<endl;
					exit(1);
			}
			Matriz M=Matriz(fil,col);
			QuitaComentarios(f);
			f>>M;
			Pieza P=Pieza(M);
		        Vp[i]=P;
		}
		QuitaComentarios(f);
		f>>fil;
		QuitaComentarios(f);
		f>>col;
		if((fil<=0) || (col<=0)){
				cerr<<"Error al leer el fichero. Datos incorrectos"<<endl;
				exit(1);
		}
		Matriz M=Matriz(fil,col);
		QuitaComentarios(f);
		f>>M;
		Tablero T=Tablero(M);
		//f.close();
		Cola C;
		Pieza P;
		int aleatorio,lineas=0;
		Inicia_Generador(semilla);
		for(int i=0;i<numPiezasCola;i++){
			aleatorio=ObtenValor(numPiezas);
			P=Vp[aleatorio];
			C.Poner(P);
		}
		Cola *pc=&C;
		Tablero *tab=&T;
		graficos::CrearVentana(VTab.Ancho()+VCola.Ancho()+VTitulo.Ancho(),VTab.Alto(),"Tetris");
		VisCola VC=VisCola(VCola,pc,Vimg);
		VisTablero VT=VisTablero(VTab,tab,Vimg);
		VT.Display();
		VC.Display();
		Tit.Display();
		Niv.Display();
		Lines.Display();
		Pzs.Display();
		Estado.Display();
		bool pieza_depositada=false,mover;
		int cont_pieza=0;
		// Comienza la partida
        	while(tab->TableroVal()){
		Pieza Pz=C.GetFirstPieza();
		tab->InsertarPieza(Pz);
		C.Quitar();
		Inicia_Generador(semilla);
		aleatorio=ObtenValor(numPiezas);
		Pz=Vp[aleatorio];
		C.Poner(Pz);
		graficos::DesactivarDibujo();
		VC.Display();
		VT.Display();
		VT.PintaPieza();
		ActualizaMarcadores(Lines,Pzs,Niv,lineas,cont_pieza,Nvl);
		graficos::ActivarDibujo();
		pieza_depositada=false;
		while(!pieza_depositada){
			graficos::CronometroInicio();
			tab->MoverPiezaAbajo(mover);
			if(!mover){
				pieza_depositada=true;
				tab->PegarPieza();
				cont_pieza++;
				tab->BorraLineas(lineas);
				if(lineas>=subeNvl){
					subeNvl=subeNvl+5;
					Nvl++;
					TimeN=ActualizaTimeN(TimeN,Nvl);
				}
			}
			graficos::DesactivarDibujo();
			VT.Display();
			VT.PintaPieza();
			ActualizaMarcadores(Lines,Pzs,Niv,lineas,cont_pieza,Nvl);
			graficos::ActivarDibujo();
			while((graficos::CronometroValor()<TimeN) && !pieza_depositada){
			
		     		tecla=graficos::QueTeclaHayPulsada();
		     		if(tecla==SDLK_DOWN){
			  		tab->MoverPiezaAbajo(mover);
			   		if(!mover){
						pieza_depositada=true;
			        		tab->PegarPieza();
						cont_pieza++;
						tab->BorraLineas(lineas);
			        		if(lineas>=subeNvl){
				  			 subeNvl=subeNvl+5;
				   			 Nvl++;
				   			 TimeN=ActualizaTimeN(TimeN,Nvl);
			        		}
		           		}
		     		}	
		     		else if(tecla==SDLK_LEFT){
			   		tab->MoverPiezaIzqda();
		     		}
		     		else if(tecla==SDLK_RIGHT){
			   	       tab->MoverPiezaDch();
		     		}
		     		else if(tecla==SDLK_q){
			   		tab->GirarPiezaIzqda();
		     		}
		     		else if(tecla==SDLK_w){
			   		tab->GirarPiezaDch();
		     		}
		     		graficos::DesactivarDibujo();
		     		VT.Display();
		     		VT.PintaPieza();
		     		ActualizaMarcadores(Lines,Pzs,Niv,lineas,cont_pieza,Nvl);
		     		graficos::ActivarDibujo();
			}   // while((graficos::CronometroValor()<TimeN) && !pieza_depositada)
	    	     }    // while(!pieza_depositada)
	        }   // while(tab->TableroVal())
		string fin="GAME OVER";
		Estado.AsignaTexto(fin);
		Estado.Display();
		graficos::LiberarFuente(Tit.GetFuente());
		graficos::LiberarFuente(Niv.GetFuente());
		graficos::LiberarFuente(Lines.GetFuente());
		graficos::LiberarFuente(Pzs.GetFuente());
		graficos::LiberarFuente(Estado.GetFuente());
		graficos::Esperar(10000);
		graficos::ObtenerTecla();
        }
	
}

void Inicia_Generador(int semilla){
	if (semilla == 0){
		time_t t=time(0);
        	srandom(t);
	}
	else{
		srandom(semilla);
	}
}

int ObtenValor(int num){
    int aux =random()%num;
    return aux;
}

int ActualizaTimeN(int Tbajada,int nivel){
	return Tbajada/(1+(nivel/4));
}

void ActualizaMarcadores(VisualizadorTexto &lines,VisualizadorTexto &pzs,VisualizadorTexto &lvl,int                             num_lineas,int num_piezas,int nvl){

	string lineas="Lineas: ";
	string piezas="Piezas: ";
	string nivel="Nivel: ";
	string cad;
	stringstream conver;
	char str[100];

	
	conver<<num_lineas;  // Convierte int a char*
	conver>>str;
	conver.clear();  // Limpiar conver para ser reutilizada
	cad=lineas+str;
	lines.AsignaTexto(cad);
	lines.Display();
	conver<<num_piezas;
	conver>>str;
	conver.clear();
	cad=piezas+str;
	pzs.AsignaTexto(cad);
	pzs.Display();
	conver<<nvl;
	conver>>str;
	conver.clear();
	cad=nivel+str;
	lvl.AsignaTexto(cad);
	lvl.Display();
}

void QuitaComentarios(istream &is){
	char c;
	while((is.peek()=='#') || (is.peek()==' ') || (is.peek()=='\n')){
		if(is.peek()=='#'){
			//is.getline(cad,100,'\n');
			is.ignore(1000,'\n');	
		}
		else{
			is.get(c);
		}
        }
}

void LeeVisualizador(istream &is,int &ancho,int &alto,int &marco,Color &borde,Color &fondo,int &x,int &y,Visualizador &V){
		QuitaComentarios(is);
		// Antes de captar el dato comprobar su validez
		is>>y;
		is>>x;
		QuitaComentarios(is);
		is>>ancho;
		is>>alto;
		is>>marco;
		QuitaComentarios(is);
		is>>borde;
		is>>fondo;
		V=Visualizador(ancho,alto,borde,fondo,marco,x,y);
}

void LeeDatosTxt(istream &is,string &ruta,int &tam,int &estilo,Color &ColorLetra){
		QuitaComentarios(is);
		is>>ruta;
		QuitaComentarios(is);
		is>>tam;
		QuitaComentarios(is);
		is>>estilo;
		QuitaComentarios(is);
		is>>ColorLetra;

}
