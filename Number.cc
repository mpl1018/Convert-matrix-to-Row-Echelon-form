#include "Number.hh"




Number::Number(){
  num = 0;
  den = 1;
}

Number::Number(int num, int den){
  this->num = num;
  this->den = den;
}

Number::~Number(){}

int Number::mcd(int num1, int num2) {
    int mcd = 0;
    int a = std::max(num1, num2);
    int b = std::min(num1, num2);
    do {
        mcd = b;
        b = a%b;
        a = mcd;
    } while(b!=0);
    return mcd;
}

int Number::mcm(int num1, int num2) {
    int mcm = 0;
    int a = std::max(num1, num2);
    int b = std::min(num1, num2);
    mcm = (a/mcd(a,b))*b;
    return mcm;
}

void Number::simplificar(){
  if (num == 0) {
    den = 1;
  }

  else if (num == den) {
    num = 1;
    den = 1;
  }

  else {
    int x = mcd(num, den);
    if (x!=1){
      num/=x;
      den/=x;
    }
  }

}

void Number::dividir(Number divisor){
  this->num *= divisor.denominador();
  this->den *= divisor.numerador();
  simplificar();
}

void Number::multiplicar(Number k){
  this->num *= k.numerador();
  this->den *= k.denominador();
  simplificar();
}

void Number::restar (Number k){
  int x = mcm(den, k.denominador());
  num = ((x/den)*num) - ((x/k.denominador())*k.numerador());
  den = x;
  simplificar();
}

int Number::numerador(){
  return num;
}

int Number::denominador(){
  return den;
}

void Number::leer(){
  cin >> num;
  cin >> den;
}

void Number::escribir() const{
  if (den==1) cout << num << "    ";
  else{
    cout << num << "/" << den << " ";
    if (den>0 or num>0) cout << "  ";
  }
}
