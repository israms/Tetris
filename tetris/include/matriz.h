#ifndef _MATRIZ_H
#define _MATRIZ_H

#include<iostream>

using namespace std;

class Matriz{
  private:
     int nf; // Numero de filas de la matriz
     int nc; // Numero de columnas de la matriz
     int **m; // Puntero a punteros
  public:
     /**
       @brief Constructor por defecto
     */
     Matriz(); 
     
    /**
      @brief Constructor con parámetros
    */
     Matriz(int nf,int nc);

    /**
      @brief Constructor de copia
   */
    Matriz(const Matriz& M);

    /**
      @brief Operador de asignaci�n
    */
    Matriz& operator=(const Matriz &M);

    /**
      @brief Destructor
    */ 
     ~Matriz();

    /**
      @brief Indica el numero de filas de la matriz
    */
     int FilasMatriz(){   // Funcion inline
        return nf;
     }

     /**
      @brief Indica el numero de columnas de la matriz
    */
     int ColumnasMatriz(){   // Funcion inline
       return nc;
     }

     /**
      @brief Inserta un elemento en la matriz
      @param i posicion de la fila en la matriz
      @param j posicion de la columna en la mariz
      @param v elemento a insertar en la matriz
    */
     void SetMatriz(int i, int j, int v){  // Funcion inline
        m[i][j]=v;
     }

     /**
      @brief Devuelve un elemento de la matriz
      @param i posicion de la fila en la matriz
      @param j posicion de la columna en la mariz
      @return devuelve el elemento que esta en la posicion m(i,j)
     */
     int GetMatriz (int i, int j){   // Funcion inline
         return m[i][j];
     }
     /**
      @brief Operador de entrada
      */
   	friend istream & operator >> (istream &is,Matriz &M);
};

#endif
