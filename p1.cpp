/*
Github:https://github.com/pyshots/villegas-jean-pc2
*/
#include <iostream>
#include <string>
using namespace std;

int main() {
    string enfermedades[10] = {"gripe", "indigestión", "catarro", "faringitis", "resfriado", "alergia", "asma", "bronquitis", "neumonía", "tuberculosis"};
    string sintomas[10] = {"fiebre", "tos", "dolor de cabeza", "dolor de garganta", "estornudos", "mucosidad", "dificultad para respirar", "fatiga", "escalofríos", "dolor de pecho"};
    bool sintomatologias[10][10] = {
        {1, 1, 1, 1, 1, 1, 0, 0, 0, 0}, 
        {0, 1, 0, 1, 0, 0, 0, 0, 0, 0}, 
        {0, 1, 1, 1, 1, 1, 0, 0, 0, 0}, 
        {1, 1, 1, 1, 0, 1, 0, 0, 0, 0}, 
        {1, 1, 1, 1, 1, 0, 0, 0, 0, 0}, 
        {0, 1, 0, 1, 0, 0, 1, 0, 0, 0}, 
        {0, 1, 0, 1, 0, 0, 1, 0, 0, 1}, 
        {0, 1, 0, 1, 0, 0, 1, 1, 0, 0}, 
        {1, 1, 1, 0, 1, 1, 1, 1, 1, 0}, 
        {1, 1, 1, 1, 0, 1, 1, 1, 1, 1}  
    };

    string respuesta;
    bool diagnostico = false;
    int enfermedad = -1;

    cout << "Responda con 'si' o 'no' a las siguientes preguntas:" << endl;

    bool respuestas[10] = {false}; 

    for (int i = 0; i < 10; i++) {
        cout << "¿Tiene " << sintomas[i] << "? ";
        cin >> respuesta;
        if (respuesta == "si") {
            respuestas[i] = true;
        }
    }

    for (int i = 0; i < 10; i++) {
        bool coincide = true;
        for (int j = 0; j < 10; j++) {
            if (sintomatologias[i][j] == 1 && respuestas[j] == false) {
                coincide = false;
                break;
            }
        }
        if (coincide) {
            diagnostico = true;
            enfermedad = i;
            break;
        }
    }

    if (diagnostico) {
        cout << "Usted tiene " << enfermedades[enfermedad] << "." << endl;
    } else {
        cout << "No se puede emitir un diagnóstico fiable." << endl;
    }

    return 0;
}