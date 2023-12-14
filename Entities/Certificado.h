#ifndef CERTIFICADO_H
#define CERTIFICADO_H

#include <string>

class Certificado {
    std::string idActividad;
    std::string idUsuario;

public:
    Certificado(const std::string& idAct, const std::string& idUsr);
    void generarCertificado();
    void enviarCertificado();
    // Agregar más funciones según sea necesario
};

#endif // CERTIFICADO_H
