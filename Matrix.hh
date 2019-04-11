#ifndef MAT_HH
#define MAT_HH

#include <iostream>
#include <vector>
#include "Number.hh"
using namespace std;

class Matrix {
private:
  vector <vector <Number> > vnum;
  int n, m;


public:
  //Constructora
  Matrix (int n, int m);


  //Modificadores
  void cambiar_linea (int a, int b);
  //Pre: cierto;
  // Post: intercambia las lineas a y b;

  void dividir_linea (int index, Number k);
  //Pre: k!=0;
  // Post: divide toda la linea index entre k;

  void restar_lineas (int linea_a, int pivote,  int linea_b);
  //Pre: el pivote es 1, los numero anteriores deben ser 0
  //Post: resta linea_b - k*linea_a; Siendo k el numero que haga que el primer
  //elemento de la linea b sea 0

  void sin_den();
  //Pre: cierto
  //Post: multiplicamos cada linea por el denominador mas grande

  //Consultores
  int numero_lineas() const;
  //Pre: cierto
  //Post: retorna el numero de lineas de la matriz

  int numero_columnas() const;
  //Pre: cierto
  //Post: retorna el numero de columnas

  void buscar_pivote (int& i, int& j, int x);
  //Post: i, j devuelven las coordenadas del pivote

  Number consultar_numero (int i, int j);
  //Pre: indices correctas
  //Post: retorna el numero que hay en esos indices

  //Lectura y escritura

  void leer();
  /* Pre:  hay preparados por el canal estandar de entrada un conjunto
  de pares de enteros */
  /* Post: el parametro implicito pasa a tener los atributos leídos*/

  void escribir ();
  /* Pre: cierto */
  /* Post: se han escrito los atributos del parametro implicito por el canal estandar de salida*/
};
#endif
