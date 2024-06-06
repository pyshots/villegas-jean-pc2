/*
Github:https://github.com/pyshots/villegas-jean-pc2
*/
#include <iostream>
#include <string>
using namespace std;

struct Alumno {
    string codigo;
    string nombre;
    string genero;
    int edad;
    float notas[3];
    float promedio;
};

void registrarDatos(Alumno alumnos[], int &contador) {
    cout << "Introduzca el código del alumno: ";
    cin >> alumnos[contador].codigo;
    cout << "Introduzca el nombre del alumno: ";
    cin >> alumnos[contador].nombre;
    cout << "Introduzca el género del alumno: ";
    cin >> alumnos[contador].genero;
    cout << "Introduzca la edad del alumno: ";
    cin >> alumnos[contador].edad;
    for (int i = 0; i < 3; i++) {
        cout << "Introduzca la nota del curso " << i + 1 << " del alumno: ";
        cin >> alumnos[contador].notas[i];
    }
    alumnos[contador].promedio = (alumnos[contador].notas[0] + alumnos[contador].notas[1] + alumnos[contador].notas[2]) / 3;
    contador++;
}

void Promedio(Alumno alumnos[], int contador) {
    for (int i = 0; i < contador; i++) {
        cout << "El promedio del alumno " << alumnos[i].nombre << " es " << alumnos[i].promedio << endl;
    }
}

void mostrarDatos(Alumno alumnos[], int contador) {
    for (int i = 0; i < contador; i++) {
        cout << "Código: " << alumnos[i].codigo << endl;
        cout << "Nombre: " << alumnos[i].nombre << endl;
        cout << "Género: " << alumnos[i].genero << endl;
        cout << "Edad: " << alumnos[i].edad << endl;
        for (int j = 0; j < 3; j++) {
            cout << "Nota del curso " << j + 1 << ": " << alumnos[i].notas[j] << endl;
        }
        cout << "Promedio: " << alumnos[i].promedio << endl;
    }
}

void NotasPorAsignatura(Alumno alumnos[], int contador) {
    for (int j = 0; j < 3; j++) {
        cout << "Notas para la Asignatura " << j + 1 << ":" << endl;
        for (int i = 0; i < contador; i++) {
            cout << "Alumno " << alumnos[i].nombre << ": " << alumnos[i].notas[j] << endl;
        }
        cout << endl;
    }
}

void MostrarPrimeroYUltimo(Alumno alumnos[], int contador) {
    if (contador > 0) {
        Alumno *alumnoMayor = &alumnos[0];
        Alumno *alumnoMenor = &alumnos[0];
        for (int i = 1; i < contador; i++) {
            if (alumnos[i].promedio > alumnoMayor->promedio) {
                alumnoMayor = &alumnos[i];
            }
            if (alumnos[i].promedio < alumnoMenor->promedio) {
                alumnoMenor = &alumnos[i];
            }
        }
        cout << "Nombre del alumno con el promedio más alto: " << alumnoMayor->nombre << ", Promedio: " << alumnoMayor->promedio << endl;
        cout << "Nombre del alumno con el promedio más bajo: " << alumnoMenor->nombre << ", Promedio: " << alumnoMenor->promedio << endl;
    } else {
        cout << "No hay alumnos registrados." << endl;
    }
}

int main() {
    Alumno alumnos[100];
    int contador = 0;
    char respuesta;

    do {
        cout << "Menú de opciones:" << endl;
        cout << "1. Registrar datos" << endl;
        cout << "2. Ver lista de alumnos" << endl;
        cout << "3. Ver Notas por Asignatura" << endl;
        cout << "4. Ver el Cálculo del promedio" << endl;
        cout << "5. Mostrar Primero y Ultimo" << endl;
        cout << "Seleccione una opción: ";
        cin >> respuesta;

        switch (respuesta) {
            case '1':
                registrarDatos(alumnos, contador);
                break;
            case '2':
                mostrarDatos(alumnos, contador);
                break;
            case '3':
                NotasPorAsignatura(alumnos, contador);
                break;
            case '4':
                Promedio(alumnos, contador);
                break;
            case '5':
                MostrarPrimeroYUltimo(alumnos, contador);
                break;
            default:
                cout << "Opción no válida." << endl;
        }

        cout << "¿Desea realizar otra operación? (s/n): ";
        cin >> respuesta;
    } while (respuesta == 's');
    system("pause");
    return 0;
}
