#include "Certificado.h"
#include <iostream>

using namespace std;

Certificado::Certificado(const string& idAct, const string& idUsr)
: idActividad(idAct), idUsuario(idUsr) {}

void Certificado::generarCertificado() {
    // Lógica para generar el certificado
}

void Certificado::enviarCertificado() {
    cout << "Enviando certificado a " << idUsuario << " por la actividad " << idActividad << endl;
}
