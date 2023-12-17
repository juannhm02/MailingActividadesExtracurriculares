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

string Inscripcion::getIdActividad() {
    return idActividad;
}

string Inscripcion::getIdUsuario() {
    return idUsuario;
}

bool Inscripcion::getPagoRealizado() {
    return pagoRealizado;
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