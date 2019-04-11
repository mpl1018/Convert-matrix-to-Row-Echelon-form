#include "Matrix.hh"
#include <algorithm>

Matrix::Matrix(int n, int m) {
  this->n = n;
  this->m = m;
  vnum = vector <vector <Number> > (n, vector <Number> (m));
}

void Matrix:: cambiar_linea (int linea_a, int linea_b){
  if (linea_a!=linea_b)
  for (int i=0; i<m; ++i){
    swap (vnum[linea_a][i], vnum[linea_b][i]);
  }
}

void Matrix:: dividir_linea (int index, Number k){
  for (int i=0; i<m; ++i){
    vnum[index][i].dividir(k);
  }
}

void Matrix:: restar_lineas (int linea_a, int pivote, int linea_b){
  Number factor = vnum[linea_b][pivote];
  for (int i=pivote; i<m; ++i){
    Number restador = vnum[linea_a][i];
    restador.multiplicar(factor);
    vnum[linea_b][i].restar(restador);
  }
}

void Matrix:: sin_den(){
  for (int i=0; i<n; ++i){
    int den_max = 0;
    for (int j=0; j<m; ++j){
      if (abs(vnum[i][j].denominador()) > abs(den_max)) den_max = vnum[i][j].denominador();
    }
    Number x(den_max,1);
    for (int j=0; j<m; ++j){
      if (vnum[i][j].numerador()!=0) vnum[i][j].multiplicar(x);
    }
  }
}

int Matrix::numero_lineas() const{
  return n;
}

int Matrix::numero_columnas() const{
  return m;
}

void Matrix::buscar_pivote(int& i, int& j, int x){
  bool found = false;
  j=0;
  while (j<m and !found){
    i=x;
    while (i<n and !found){
      if (vnum[i][j].numerador()!=0) found = true;
      else ++i;
    }
    if (!found) ++j;
  }
  if (!found) i= -1;
}

Number Matrix::consultar_numero(int i, int j){
  return vnum[i][j];
}

void Matrix::leer(){
  for (int i = 0; i<n; ++i){
    for (int j = 0; j<m; ++j){
      vnum[i][j].leer();
    }
  }
}

void Matrix::escribir() {
  for (int i=0; i<n; ++i){
    for (int j=0; j<m; ++j){
      vnum[i][j].escribir();
    }
    cout << endl;
  }
}
