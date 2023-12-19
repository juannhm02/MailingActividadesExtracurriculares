#include <iostream>
#include <fstream>
#include <string>
#include "Certificado.h"

using namespace std;

// Lógica para generar el certificado

#include <sstream>

bool actividadFinalizada(const string& idActividad) {
    ifstream file("Inscripciones.txt");
    string line;
    while (getline(file, line)) {
        if (line.find("ID Actividad: ") != string::npos) {
            string actividad = line.substr(line.find("ID Actividad: ") + 14);
            getline(file, line); // Nombre
            getline(file, line); // Correo
            getline(file, line); // Teléfono
            getline(file, line); // Fecha
            getline(file, line); // Hora
            getline(file, line); // Estado
            string estado = line.substr(line.find("Estado: ") + 8);
            if (actividad == idActividad && estado == "Finalizada") {
                return true;
            }
        }
    }
    return false;
}

void generarCertificado(const string& idUsuario, const string& idActividad) {
    if (!actividadFinalizada(idActividad)) {
        cout << "La actividad no ha finalizado" << endl;
        return;
    }
    
    cout << "Generando certificado para " << idUsuario << " por la actividad " << idActividad << endl;
    //crear una carpeta con el id de la actividad y genera un archivo con el id del usuario seguido de -certificado.txt y escribe el certificado
    string nombreArchivo = idUsuario + "-certificado.txt";
    string nombreCarpeta = idActividad;
    string ruta = "Certificados/" + nombreCarpeta + "/" + nombreArchivo;
    ofstream file(ruta);
    file << "Certificado de participación " << endl;
    file << "+---------------------------------+"<< endl;
    file << "El usuario: " << idUsuario << "Ha completado la actividad: "<< idActividad<< " con éxito." << endl;
    file << "+---------------------------------+"<< endl;
    file.close();

    cout << "Certificado generado" << endl;
}



