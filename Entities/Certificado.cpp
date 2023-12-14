#include "Certificado.h"
#include <iostream>

Certificado::Certificado(const std::string& idAct, const std::string& idUsr)
: idActividad(idAct), idUsuario(idUsr) {}

void Certificado::generarCertificado() {
    // Lógica para generar el certificado
}

void Certificado::enviarCertificado() {
    std::cout << "Enviando certificado a " << idUsuario << " por la actividad " << idActividad << std::endl;
}
