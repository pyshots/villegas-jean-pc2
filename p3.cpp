/*
Github:https://github.com/pyshots/villegas-jean-pc2
*/
#include <iostream>
#include <string>
using namespace std;

struct Estudiante{
    string codigo;
    string nombre;
    float notas[3];
    float promedio;
};

void ingresarDatos(Estudiante estudiantes[], int &contador){
    cout << "Introduzca el codigo del estudiante: ";
    cin >> estudiantes[contador].codigo;
    cout << "Introduzca el nombre del estudiante: ";
    cin >> estudiantes[contador].nombre;
    for(int i = 0; i < 3; i++){
        cout << "Introduzca la nota " << i+1 << " del estudiante: ";
        cin >> estudiantes[contador].notas[i];
    }
    contador++;
}

void mostrarPromedioYDesaprobados(Estudiante estudiantes[], int contador){
    int desaprobados = 0;
    for(int i = 0; i < contador; i++){
        estudiantes[i].promedio = (estudiantes[i].notas[0] + estudiantes[i].notas[1] + estudiantes[i].notas[2]) / 3;
        if(estudiantes[i].promedio < 11){
            desaprobados++;
        }
        cout << "El promedio del estudiante " << estudiantes[i].nombre << " es " << estudiantes[i].promedio << endl;
    }
    cout << "La cantidad de estudiantes desaprobados es " << desaprobados << "." << endl;
}

void ordenarPorPromedio(Estudiante estudiantes[], int contador){
    for(int i = 0; i < contador-1; i++){
        for(int j = 0; j < contador-i-1; j++){
            if(estudiantes[j].promedio > estudiantes[j+1].promedio){
                Estudiante aux = estudiantes[j];
                estudiantes[j] = estudiantes[j+1];
                estudiantes[j+1] = aux;
            }
        }
    }
}

void mostrarDatosOrdenados(Estudiante estudiantes[], int contador){
    for(int i = 0; i < contador; i++){
        cout << "Codigo: " << estudiantes[i].codigo << endl;
        cout << "Nombre: " << estudiantes[i].nombre << endl;
        for(int j = 0; j < 3; j++){
            cout << "Nota " << j+1 << ": " << estudiantes[i].notas[j] << endl;
        }
        cout << "Promedio: " << estudiantes[i].promedio << endl;
    }
}

int main(){
    Estudiante estudiantes[100];
    int contador = 0;
    char respuesta;

    do{
        ingresarDatos(estudiantes, contador);
        cout << "¿Desea ingresar otro estudiante? (s/n): ";
        cin >> respuesta;
    }while(respuesta == 's');

    mostrarPromedioYDesaprobados(estudiantes, contador);
    ordenarPorPromedio(estudiantes, contador);
    mostrarDatosOrdenados(estudiantes, contador);

    system("pause");
    return 0;
}