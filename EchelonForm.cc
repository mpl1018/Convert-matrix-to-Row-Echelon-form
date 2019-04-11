#include <iostream>
#include <vector>
#include <algorithm>
#include "Number.hh"
#include "Matrix.hh"
#include <string>
using namespace std;


void echelonform (Matrix& mat, int n){
  if (n == mat.numero_lineas()) return;

  else {
    //Buscamos un elemento distinto de 0
    int i,j;
    mat.buscar_pivote(i,j,n);
    //cout << "EL PIVOTE ES LINEA: " << i << " COLUMNA: " << j << endl;
    if (i==-1) return;
    mat.cambiar_linea(n,i);

    Number k = mat.consultar_numero(n,j);
    mat.dividir_linea(n,k);

    //mat.escribir();

    for (int x=n+1; x<mat.numero_lineas(); ++x){
      mat.restar_lineas(n,j,x);
      //cout << "restar la linea " << x << " menos la linea " << n <<endl;
    }

    //mat.escribir();

    ++n;
    echelonform (mat, n);
  }
}


int main (){
  cout << "Introduce tamaño de la matriz" << endl;
  int n,m;
  cin >> n >> m;
  Matrix mat (n,m);

  cout << "Introduce los valores de la matriz" << endl;
  mat.leer();

  echelonform (mat, 0);

  cout << "La matriz en ech. form es: " << endl;
  mat.escribir();

  string respuesta;
  cout << "¿Quieres la matriz sin denominadores? [si/no]" << endl;
  cin >> respuesta;
  if (respuesta == "si")
  mat.sin_den();

  cout << "Matriz sin denominadores: " << endl;
  mat.escribir();

}
