# Convertir matriz a forma escalonada

_Este programa te permite transformar una matriz a su respectiva forma escalonada_

## Puesta en marcha 🚀

_Para volver a **compilar** de nuevo el proyecto puedes escribir la siguiente línea en tu terminal (en linux):_
```
g++ -o EchelonForm.x EchelonForm.cc Matrix.cc Number.cc 
```

_Para **ejecutar** el programa escribe la siguiente línea:_

```
./EchelonForm.x 
```

## Requisitos de entrada 📋
_A la hora de introducir el **tamaño de la matriz** se deberá meter el número de líneas y el número de columnas, **en ese orden.**_ 

_Al introducir los **elementos de la matriz**, se deberá escribir dos enteros para cada número, el numerador y el denominador._

## Juegos de pruebas ⚗️
_Suponemos que queremos transformar la siguiente matriz:_ 
```
                                 5 7 9 6 4                                             1  7/5  9/5  6/5  4/5
      Matriz a transformar   =   7 4 2 7 8        --->  Matriz en forma escalonada =   0   1  53/29  7/29 -12/29
                                 8 9 3 6 2                                             0   0    1   89/214  77/107
```
_Este sería el resultado:_
![Texto alternativo](https://raw.githubusercontent.com/mpl1018/Convert-matrix-to-Row-Echelon-form/master/imagenes/ejemplo_funcionamiento.PNG)
