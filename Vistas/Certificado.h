#ifndef CERTIFICADO_H
#define CERTIFICADO_H

#include <string>

using namespace std;

struct Certificado {
    string idActividad;
    string idUsuario;

};

    bool actividadFinalizada(const string& idActividad);
    void generarCertificado(const string& idUsuario, const string& idActividad);

    // Agregar más funciones según sea necesario


#endif // CERTIFICADO_H
