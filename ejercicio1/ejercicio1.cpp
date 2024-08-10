#include <iostream>

using namespace std;

/*
Cargar las notas del primer parcial de los 20 estudiantes de un curso. Luego de cargar todas las notas:

- Pedir un número y mostrar por pantalla la nota registrada. Por ejemplo, se ingresa 10 para mostrar el décimo examen.

- Listar cuántos estudiantes obtuvieron una nota mayor al promedio.

 */

bool preguntarVerNotas(string message);
int obtenerIndiceAlumno();

int main(){

    float notas[20];

    int nota, indiceNota;

    bool verNota;

    string res;

    for(int i = 0; i < 20; i++){
        do{
        cout << "Nota del alumno " << i + 1 << ": ";
        cin >> nota;
        } while(nota <= 0 || nota > 10);
        notas[i] = nota;
    }
    
    verNota = preguntarVerNotas("Deseas ver la nota de un alumno? (S/N) ");
    
    while(verNota){
        
        indiceNota = obtenerIndiceAlumno();

        cout << "La nota del alumno " << indiceNota << " es " << notas[indiceNota - 1] << endl;


        verNota = preguntarVerNotas("Quieres ver la nota de otro alumno?");
    }

    //pase lo que pase, le mostramos el punto 2
    
    

    //datos de los alumnos
    cout << "Hola mundo";

    return 0;
}



bool preguntarVerNotas(string message){
    bool verNota;
    string res;
    do {
        cout << message;
        cin >> res;

        if(res == "S" || res == "s"){
            verNota = true;
        } else {
            verNota = false;
        }

    } while((res != "S" && res != "s") && (res != "N" && res != "n"));

    return verNota;
}

int obtenerIndiceAlumno(){
    int indiceNota;
    do{

        //quiere ver la nota
        //le pide el numero de alumno, le muestra la nota, y le sigyue preguntando si quiere ver mas notas 
        cout << "Ingresa del 1 al 20 el numero del alumno de quien quieres ver la nota >> ";
        cin >> indiceNota;
        }while(indiceNota < 0 && indiceNota > 20);

        return indiceNota;
}