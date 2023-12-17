#include "Inscripcion.h"
#include <string>

using namespace std;

Inscripcion::Inscripcion(const string& idAct, const string& idUsr, bool pago)
: idActividad(idAct), idUsuario(idUsr), pagoRealizado(pago) {}

void Inscripcion::confirmarPago() {
    pagoRealizado = true;
    // Lógica para confirmar el pago
}
