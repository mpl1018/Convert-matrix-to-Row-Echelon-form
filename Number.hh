#ifndef NUMBER_HH
#define NUMBER_HH

#include <iostream>
using namespace std;

class Number {
private:
  int num;
  int den;

  int mcd (int a, int b);
  //Pre: cierto;
  // Post: retorna mcd de a y b;
  int mcm (int a, int b);
  //Pre: cierto;
  // Post: retorna mcm de a y b;

public:
  //Constructores
  Number();
  /* Pre: cierto */
  /* Post: el resultado es un numero de num 0 y den 1*/

  Number (int num, int den);
  /* Pre: den != 0 */
  /* Post: el resultado es un numero de numerador "num" y denominador "den"*/

  //Destructora
  ~Number();

  //Modificadores
  void simplificar ();
  /* Pre: cierto */
  /* Post: el resultado es una fraccion simplificada de la inicial (si es posible)*/

  void dividir (Number divisor);
  //Pre: ambos numeros correctos (den!=0);
  // Post: parametro implicito entre "divisor"

  void multiplicar (Number k);
  //Pre: ambos numeros correctos (den!=0);
  // Post: parametro implicito por "k"

  void restar (Number k);
  //Pre: ambos numeros correctos (den!=0);
  // Post: parametro implicito menos "k"

  //Consultores
  int numerador ();
  //Pre: cierto;
  // Post: retorna num;

  int denominador();
  //Pre: cierto;
  // Post: retorna den;

  void leer ();
  /* Pre:  hay preparados por el canal estandar de entrada dos enteros, el segundo de ellos positivo */
  /* Post: el parametro implicito pasa a tener los atributos leídos*/
  void escribir () const;
  /* Pre: cierto */
  /* Post: se han escrito los atributos del parametro implicito por el canal estandar de salida*/
};
#endif
