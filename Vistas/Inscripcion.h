#ifndef INSCRIPCION_H
#define INSCRIPCION_H

#include <string>

using namespace std;

struct Inscripcion {
    string idActividad;
    string idUsuario;
    bool pagoRealizado;

};

    void confirmarPago(const string& idUsuario, const string& idActividad);
    // Agregar más funciones según sea necesario


#endif // INSCRIPCION_H
