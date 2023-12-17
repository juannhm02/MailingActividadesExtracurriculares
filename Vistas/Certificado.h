#ifndef CERTIFICADO_H
#define CERTIFICADO_H

#include <string>

using namespace std;

class Certificado {
    string idActividad;
    string idUsuario;

public:
    Certificado(const string& idAct, const string& idUsr);
    void generarCertificado();
    void enviarCertificado();
    // Agregar más funciones según sea necesario
};

#endif // CERTIFICADO_H
