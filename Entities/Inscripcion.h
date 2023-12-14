#ifndef INSCRIPCION_H
#define INSCRIPCION_H

#include <string>

class Inscripcion {
    std::string idActividad;
    std::string idUsuario;
    bool pagoRealizado;

public:
    Inscripcion(const std::string& idAct, const std::string& idUsr, bool pago);
    void confirmarPago();
    // Agregar más funciones según sea necesario
};

#endif // INSCRIPCION_H
