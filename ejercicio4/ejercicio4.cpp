#include <iostream>



/*
Una fundación que se dedica a fomentar la adopción de mascotas dispone de los registros de adopciones del año 2024. Por cada adopción que se haya efectuado se registró:
Mes de la adopción (entero entre 1 y 12)
Tipo de animal adoptado (entero entre 10 y 15)
Edad del adoptante responsable
Tipo de vivienda del adoptante responsable (entero entre 1 y 5)

La información no se encuentra agrupada ni ordenada bajo ningún criterio. Para indicar el fin de la carga de datos se ingresa un mes de adopción igual a cero.

Se pide calcular e informar
El tipo de animal más adoptado en general.
El promedio de edad de los adoptantes de cada tipo de animal.
Por cada tipo de animal y tipo de vivienda la cantidad total de adopciones registradas.

Aclaración:
Los tipos de animales son:
10 - Perro, 11 - Gato, 12 - Conejo, 13 - Hurón, 14 - Caballo, 15 - Oveja

Los tipos de vivienda son:
1 - Casa, 2 - Departamento, 3 - Casa Quinta, 4 - Finca, 5 - Duplex


 */

using namespace std;


int pedirMes();
int pedirEdad();
int pedirNumeroAnimalAdoptado(string *animales, int size);
int pedirTipoDeViviendaAdoptante();
int pedirTipoDeVivienda();


//funciones para las respuestas
int obtenerTipoMasAdoptado(int *v, int size);
void mostrarPromedioDeEdadDeAdoptantes(int *contadorTipos, int *sumatoriaTipos, string *animales, int size);

int main(){

    int mes, contadorTiposAdoptados[6], sumatoriaEdadAdoptadosPorTipo[6], adopcionesPorTipoYVivienda[6][5], tipoAnimal, edadAdoptante, tipoViviendaAdoptante;
    string animales[6] = {"10 - Perro", "11 - Gato", "12 - Conejo", "13 - Hurón", "14 - Caballo", "15 - Oveja"};

    mes = pedirMes();

    while(mes != 0){
        tipoAnimal = pedirNumeroAnimalAdoptado(animales, 6);
        edadAdoptante = pedirEdad();
        tipoViviendaAdoptante = pedirTipoDeViviendaAdoptante();
        
        //comenzamos a calcular
        
        //punto A
        contadorTiposAdoptados[tipoAnimal - 10]++;

        //punto B
        sumatoriaEdadAdoptadosPorTipo[tipoAnimal - 10] += edadAdoptante;

        //punto C
        adopcionesPorTipoYVivienda[tipoAnimal - 10][tipoViviendaAdoptante - 1]++;


        mes = pedirMes();
    }
    

    //mostramos las respuestas
    int resA = obtenerTipoMasAdoptado(contadorTiposAdoptados, 6);
    cout << "El tipo de animal mas adoptado fue el " << resA << endl;

    mostrarPromedioDeEdadDeAdoptantes(contadorTiposAdoptados, sumatoriaEdadAdoptadosPorTipo, animales, 6);



    return 0;
}


int pedirMes(){
    int mes;
    do{
        cout << "Ingrese el mes de adopcion de la mascota (1-12): ";
        cin >> mes;

    }while(mes < 0 || mes > 12);


    return mes;
}
int pedirEdad(){
    int edad;
    do{
        cout << "Ingrese la edad del adoptante: ";
        cin >> edad;

    }while(edad < 0);


    return edad;
}


int pedirNumeroAnimalAdoptado(string *animales, int size){
    int num;
    cout << "Ingrese el tipo (en numero) del animal adoptado donde " << endl;
    for(int i = 0; i < size; i++){
        cout << animales[i] << endl;
    }

    do {
        cout << "Numero del animal: ";
        cin >> num;
    }while(num < 10 || num > 15);

    return num;
}



int pedirTipoDeViviendaAdoptante(){
    int num;
    string viviendas[5] = {"1 - Casa", "2 - Departamento", "3 - Casa Quinta", "4 - Finca", "5 - Duplex"};
    cout << "Ingrese el tipo (en numero) de vivienda donde vive el adoptante, donde " << endl;
    for(int i = 0; i < 5; i++){
        cout << viviendas[i] << endl;
    }

    do {
        cout << "Numero de vivienda: ";
        cin >> num;
    }while(num < 1 || num > 5);

    return num;
}



//funciones que calculan/muestran las respuestas

int obtenerTipoMasAdoptado(int *v, int size){
    int max = -1;
    int tipo;

    for(int i = 0; i < size; i++){
        if(v[i] > max){
            tipo = i + 10;
            max = v[i];
        }
    }

    return tipo;
}

void mostrarPromedioDeEdadDeAdoptantes(int *contadorTipos, int *sumatoriaTipos, string *animales, int size){
    int promedio;
    for(int i = 0; i < size; i++){
        if(sumatoriaTipos[i] > 0 && contadorTipos[i] > 0){
            promedio = sumatoriaTipos[i] / contadorTipos[i];
        } else {
            promedio = 0;
        }
        cout << "El promedio de edad del " << animales[i] << " es " << promedio << endl;
    }
}