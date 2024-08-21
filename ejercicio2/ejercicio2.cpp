#include <iostream>

using namespace std;

/*

Hacer una función llamada quitarRepetidos que reciba dos vectores de enteros de 10 elementos llamados vectorSinProcesar y vectorSinRepetidos. 
La función debe procesar el vectorSinProcesar de manera que en el vectorSinRepetidos queden todos los elementos distintos del vectorSinProcesar.
La función debe devolver la cantidad de elementos asignados a vectorSinRepetidos.

Ejemplo:
vectorUno[10] = { 1, 2, 1, 2, 5, 5, 4, 4, 3, 3 }
vectorDos[10];
int elementos = quitarRepetidos(vectorUno, vectorDos);

En elementos debe quedar el valor 5 ya que son 5 los elementos sin repetirse del vector. Además el vectorDos debe contener los valores 1, 2, 5, 4 y 3.


 */

int quitarRepetidos(int vec1[10], int vec2[10]);

int main(){

    int vectorUno[10] = { 1, 2, 1, 2, 5, 5, 4, 4, 3, 3 };
    int vectorDos[10];
    int elementos = quitarRepetidos(vectorUno, vectorDos);

    cout << elementos << endl;
    return 0;
}

int quitarRepetidos(int vec1[10], int vec2[10]){
    int counter = 0;
    for (int i = 0; i < 10; i++){
        bool isNumber = false;
        for (int k = 0; k < 10; k++){
            if(vec1[i] == vec2[k]){
                isNumber = true;
                break;
            } 
        }
        
        if(!isNumber){
            counter++;
            vec2[counter-1]=vec1[i];
        }
        
    }


    return counter;
}