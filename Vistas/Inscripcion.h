#ifndef INSCRIPCION_H
#define INSCRIPCION_H

#include <string>

using namespace std;

class Inscripcion {
    string idActividad;
    string idUsuario;
    bool pagoRealizado;

public:
    Inscripcion(const string& idAct, const string& idUsr, bool pago);
    void confirmarPago();
    // Agregar más funciones según sea necesario
};

#endif // INSCRIPCION_H
