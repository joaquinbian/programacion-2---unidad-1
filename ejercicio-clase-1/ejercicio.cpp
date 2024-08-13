#include <iostream>

using namespace std;


/*
LAS AUTORIDADES DE LA CARRERA ESTÁN REALIZANDO UN ANÁLISIS DE LOS CURSOS VIRTUALES DE LAS DISTINTAS
MATERIAS. POR CADA UNA DE LAS 20 MATERIAS DE LA CARRERA TIENE LA SIGUIENTE INFORMACIÓN
• NÚMERO DE MATERIA (ENTRE 1 Y 20), NOMBRE, CANTIDAD DE ALUMNOS INSCRIPTOS, CANTIDAD DE PROFESORES
ADEMÁS POR CADA INGRESO DE LOS ESTUDIANTES AL AULA VIRTUAL SE REGISTRA LO SIGUIENTE:
• LEGAJO, FECHA DE ACCESO (DÍA Y MES), NÚMERO DE LA MATERIA A LA QUE INGRESO, CANTIDAD DE HORAS (NÚMERO REAL)
EL FIN DE LOS DATOS SE INDICA CON UN NÚMERO DE LEGAJO IGUAL A 0.
SE QUIERE RESPONDER LAS SIGUIENTES PREGUNTAS:
a) LAS MATERIAS QUE NO TUVIERON ACCESO DE ALUMNOS NUNCA
b) LA MATERIA QUE MÁS CANTIDAD DE HORAS REGISTRO DE ACCESO DE ALUMNOS
c) POR CADA MATERIA Y DÍA DE MARZO, LA CANTIDAD DE ACCESOS DE ALUMNOS A LAS AULAS VIRTUALES.
• HACER UN PROGRAMA EN EL MARCO DE UN PROYECTO DE CODEBLOCK CON UN MENÚ CON OPCIONES PARA CARGAR LOS DATOS,
MOSTRAR CADA PUNTO Y SALIR DEL PROGRAMA.

AGREGAR LAS SIGUIENTES PREGUNTAS AL EJERCICIO:
d) LA CANTIDAD DE MATERIAS CON ACCESOS
e) POR CADA MATERIA LA CANTIDAD DE ALUMNOS POR PROFESOR
f) POR CADA MATERIA Y DÍA DE MARZO, LA CANTIDAD DE HORAS DE ACCESOS DE ALUMNOS
A LAS AULAS VIRTUALES.

*/

//Struct de una materia
struct Materia {
    int numero;
    string nombre;
    int cantAlumnos;
    int cantProfesores;
};

//Struct de un Acceso
struct Acceso {
    int legajo;
    int dia;
    int mes;
    int numeroMateria;
    float horas;
};


void cargarDatos(vector<Materia>[]);
void cargarMaterias(string materias[5], int cantAlumnos[5], int cantProfesores[5]);
int cargarLegajo();
int cargarDia();
int cargarMes();
int cargarNumeroMateria();
int cargarCantidadHoras();

//punto A
void calcularAccesosDeAlumnos(string materias[5], int accesosAlumnos[5]);

//punto B
void calcularMateriaConMasHorasIngresos(string materias[5], int cantidadHorasIngresos[5]);

int main() {

    string materias[5];
    int cantAlumnos[5], cantProfesores[5], cantAccesos[5], cantidadHorasIngresos[5], cantAccesosMarzo[5][31], legajo, dia, mes, numMateria, cantHoras;
    
    cargarMaterias(materias, cantAlumnos, cantProfesores);
    
    for(int i = 0; i < 5; i++){
        cout << materias[i] << endl;   
    }
    
    legajo = cargarLegajo();
    
    while(legajo != 0){
        dia = cargarDia();
        mes = cargarMes();
        numMateria = cargarNumeroMateria();
        cout << "El usuario con legajo " << legajo << " entro a " << materias[numMateria - 1];
        cantHoras = cargarCantidadHoras();
        
        cantAccesos[numMateria - 1]++;
        cantidadHorasIngresos[numMateria - 1] += cantHoras;
        
        if(mes == 3){
            cantAccesosMarzo[numMateria - 1][dia]++;
        }
        
        
        legajo = cargarLegajo();
    }
    
    
    //punto A
    calcularAccesosDeAlumnos(materias, cantAccesos);
    
    
  
    
    
    
    
    return 0;
}

void cargarMaterias(string materias[5], int cantAlumnos[5], int cantProfesores[5]){
    string materia;
    int alumnos, profesores;
    
    for(int i = 0; i < 5; i++){
        cout << "Ingese el nombre de la materia: ";
        cin >> materia;
        cout << "Ingese la cantidad de alumnos de la materia: ";
        cin >> alumnos;
        cout << "Ingese la cantidad de profesores de la materia: ";
        cin >> profesores;
        materias[i] = materia;
        cantAlumnos[i] = alumnos;
        cantProfesores[i] = profesores;
    }
}



int cargarLegajo(){
    int legajo;
    do{
        cout << "Ingrese el legajo del alumno: ";
        cin >> legajo;
        
    }while(legajo < 0);
    
    return legajo;
    
}

int cargarDia(){
    int dia;
    
    do{
        cout << "Ingrese el dia (1-31) del mes del ingreso ";
        cin >> dia;
    }while(dia < 1 || dia > 31);
    return dia;
}

int cargarMes(){
    int mes;
    
    do{
        cout << "Ingrese el mes (1-12) del ingreso ";
        cin >> mes;
    }while(mes < 1 || mes > 12);
    return mes;
}

int cargarNumeroMateria(){
    int numMateria;
    do{
        cout << "Ingrese el numero de materia que ingreso :";
        cin >> numMateria;
    }while(numMateria < 1 || numMateria > 5);
    
    return numMateria;
}

int cargarCantidadHoras(){
    int cantHoras;
    
    do{
        cout << "Ingrese la cantidad de horas que curso el alumno: ";
        cin >> cantHoras;
    }while(cantHoras < 1);
    
    return cantHoras;
}

void calcularAccesosDeAlumnos(string materias[5], int accesosAlumnos[5]){
    
    for(int i = 0; i < 5; i++){
        if(accesosAlumnos[i] == 0){
            cout << "No se registraron ingresos en " << materias[i] << endl;
        }
    }

}

void calcularMateriaConMasHorasIngresos(string materias[5], int cantidadHorasIngresos[5]){

    int indiceMasHoras, mayor = -1;
    
    for(int i = 0; i < 5; i++){
        if(cantidadHorasIngresos[i] > mayor){
            mayor = cantidadHorasIngresos[i];
            indiceMasHoras = i;
        }
    }
    
    if(mayor == -1){
        //no hubo ingresos
    } else {
        //hubo ingresos    
    }
    
}
