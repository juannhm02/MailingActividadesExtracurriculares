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
    
    string getIdActividad();
    string getIdUsuario();
    bool getPagoRealizado();

    void setIdActividad(const string& idAct);
    void setIdUsuario(const string& idUsr);
    void setPagoRealizado(bool pago);

    //Hacer una funcion para inscribirse a una actividad en el fichero de inscripciones
    void inscribirseActividad(const string& idAct, const string& idUsr, bool pago);

    //Hacer una funcion para desinscribirse de una actividad en el fichero de inscripciones
    void desinscribirseActividad(const string& idAct, const string& idUsr, bool pago);

    // Agregar más funciones según sea necesario
};

#endif // INSCRIPCION_H
