#include <iostream>

using namespace std;


/*
Una persona desea registrar los gastos realizados durante un mes. Ha definido que los gastos se pueden categorizar en:

ID de Categoría
Nombre de categoría
1
Servicios
2
Alimentación
3
Limpieza
4
Transporte
5
Educación
6
Salud
7
Ocio
8
Impuestos
9
Vestimenta
10
Inversiones


Por cada gasto registrado se ingresa el siguiente registro:
- Día (número entero)
- ID de Categoría de gasto (número entero entre 1 y 10)
- Importe del gasto (número real)

La información no se encuentra agrupada ni ordenada. No se sabe de antemano cuántos registros de gastos habrá. El fin de la carga de información se indica con un día igual a cero.

Calcular e informar:
A) La categoría de gasto que mayor dinero se haya destinado y cuál es dicha categoría.
B) Por cada categoría de gasto, el nombre de la categoría y el total acumulado en concepto de gastos del mes.
C) La cantidad de categorías de gasto que no hayan registrado movimientos.
D) Por cada día, la cantidad de gastos que se hayan registrado. Sólo mostrar aquellos registros de días que hayan registrado gastos.



 */


int pedirDiaDeGasto();
int pedirIdCategoria();
float pedirImporte();

int obtenerMayorGasto(int gastos[10]);

int main(){

    string categorias[10] = {"Servicios", "Alimentacion", "Limpieza", "Transporte", "Educacion", "Salud", "Ocio", "Impuestos", "Vestimenta", "Inversiones"};
    int gastoCategorias[10];
   
    int dia, idCategoria, importe, idCategoriaMayorGastos;

    cout << "******************** CONTROL DE GASTOS ********************" << endl << endl;

    cout << "Ingresa el dia 0 para salir del programa " << endl << endl << endl;

    dia = pedirDiaDeGasto();
    while (dia != 0){
        idCategoria = pedirIdCategoria();
        importe = pedirImporte();

        //empezamos a calcular

        //a
        gastoCategorias[idCategoria - 1] += importe;

        dia = pedirDiaDeGasto();
    }
    
    idCategoriaMayorGastos = obtenerMayorGasto(gastoCategorias);
    
    cout << "La categoria en la que mas se gasto fue " << categorias[idCategoriaMayorGastos] << " con $" << gastoCategorias[idCategoriaMayorGastos] << endl << endl;

    return 0;
}


int pedirDiaDeGasto(){
    int dia;

    do {
        cout << "Ingresa el dia del gasto (numero del 1-30) >> ";
        cin >> dia;

    }while(dia < 0 || dia > 31);

    return dia;
}

int pedirIdCategoria(){
    int id;

    do {
        cout << "Ingresa el Numero de categoria (numero del 1-10) >> ";
        cin >> id;

    }while(id < 1 || id > 10);

    return id;
}

float pedirImporte(){
    float importe;
    do {

        cout << "Ingresa el importe del gasto >> $";
        cin >> importe;

    }while(importe < 0);


    return importe;
}

int obtenerMayorGasto(int gastos[10]){
    int mayor = 0;
    for(int i = 0; i < 10; i++){
        if(gastos[i] > mayor){
            mayor = i;
        }
    }

    return mayor;
}
