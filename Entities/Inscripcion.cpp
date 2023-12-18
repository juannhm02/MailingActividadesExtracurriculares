#include "Inscripcion.h"
#include <string>
#include <fstream>

using namespace std;

Inscripcion::Inscripcion(const string& idAct, const string& idUsr, bool pago)
: idActividad(idAct), idUsuario(idUsr), pagoRealizado(pago) {}

void Inscripcion::confirmarPago() {
    pagoRealizado = true;
    // Lógica para confirmar el pago
}

//Getters
string Inscripcion::getIdActividad() {
    return idActividad;
}

string Inscripcion::getIdUsuario() {
    return idUsuario;
}

bool Inscripcion::getPagoRealizado() {
    return pagoRealizado;
}

//Setters
void Inscripcion::setIdActividad(const string& idAct) {
    idActividad = idAct;
}

void Inscripcion::setIdUsuario(const string& idUsr) {
    idUsuario = idUsr;
}

void Inscripcion::setPagoRealizado(bool pago) {
    pagoRealizado = pago;
}

void Inscripcion::inscribirseActividad(const string& idAct, const string& idUsr, bool pago) {
    // Lógica para inscribirse a una actividad
    //crear un objeto de tipo inscripcion
    Inscripcion inscripcion(idAct, idUsr, pago);

    //agregarlo al fichero de inscripciones
    fstream fichero;
    fichero.open("inscripciones.txt", ios::out | ios::app);
    fichero << inscripcion.getIdActividad() << " " << inscripcion.getIdUsuario() << " " << inscripcion.getPagoRealizado() << endl;
    fichero.close();
}

void Inscripcion::desinscribirseActividad(const string& idAct, const string& idUsr, bool pago) {
    // Lógica para desinscribirse de una actividad
    
    fstream fichero;
    fichero.open("inscripciones.txt", ios::in);
    string idActAux, idUsrAux, pagoAux;
    while (fichero >> idActAux >> idUsrAux >> pagoAux) 
    {
        if (idActAux == idAct && idUsrAux == idUsr && pagoAux == pago) 
        {
            fichero.close();
            fichero.open("inscripciones.txt", ios::out);
            fichero << idActAux << " " << idUsrAux << " " << false << endl;
            fichero.close();
        }
    }
    fichero.close();
}


//Funciones del fichero de gestionarActividad.h

// void inscribirseActividad()
// {
//     int id;
//     cout << "Ingrese el ID de la actividad a inscribirse: ";
//     if (!(cin >> id))
//     {
//         cin.clear();
//         cin.ignore(numeric_limits<streamsize>::max(), '\n');
//         cout << "ID inválido.\n";
//         return;
//     }

//     auto it = find_if(actividades.begin(), actividades.end(), [id](const Actividad &actividad)
//                       { return actividad.id == id; });

//     if (it == actividades.end())
//     {
//         cout << "No se encontró la actividad con el ID " << id << ".\n";
//         return;
//     }

//     Actividad &actividad = *it;
//     cout << "Nombre de la actividad: ";
//     cin.ignore();
//     getline(cin, actividad.nombre);

//     cout << "Descripción de la actividad: ";
//     getline(cin, actividad.descripcion);

//     guardarActividades();
//     cout << "Actividad editada exitosamente.\n";
// }

// void desinscribirseActividad()
// {
//     int id;
//     cout << "Ingrese el ID de la actividad a desinscribirse: ";
//     if (!(cin >> id))
//     {
//         cin.clear();
//         cin.ignore(numeric_limits<streamsize>::max(), '\n');
//         cout << "ID inválido.\n";
//         return;
//     }

//     auto it = find_if(actividades.begin(), actividades.end(), [id](const Actividad &actividad)
//                       { return actividad.id == id; });

//     if (it == actividades.end())
//     {
//         cout << "No se encontró la actividad con el ID " << id << ".\n";
//         return;
//     }

//     Actividad &actividad = *it;
//     cout << "Nombre de la actividad: ";
//     cin.ignore();
//     getline(cin, actividad.nombre);

//     cout << "Descripción de la actividad: ";
//     getline(cin, actividad.descripcion);

//     guardarActividades();
//     cout << "Actividad editada exitosamente.\n";
// }
