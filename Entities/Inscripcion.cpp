#include "Inscripcion.h"

Inscripcion::Inscripcion(const std::string& idAct, const std::string& idUsr, bool pago)
: idActividad(idAct), idUsuario(idUsr), pagoRealizado(pago) {}

void Inscripcion::confirmarPago() {
    pagoRealizado = true;
    // Lógica para confirmar el pago
}
