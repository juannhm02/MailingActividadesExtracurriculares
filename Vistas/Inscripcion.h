#ifndef INSCRIPCION_H
#define INSCRIPCION_H

#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <limits>

#include "Usuario.h"
#include "gestionarActividad.h"


using namespace std;

struct Inscripcion {
    Actividad actividad; // Actividad a la que se inscribe el usuario
    Usuario usuario; // Usuario que se inscribe a la actividad
    bool pagoRealizado; // Indica si el usuario ha realizado el pago

};

// Verifica el aforo de una actividad
bool verificarAforo(const string& archivoInscripciones, int actividadId, int aforoMaximo);

// Solicita el pago de una actividad
bool solicitarPago();

// Inscribir a un usuario a una actividad
void inscribirEnActividad(const string& archivoInscripciones, const Inscripcion& inscripcion);

//Desinscribir a un usuario de una actividad
void desinscribirEnActividad(const string& archivoInscripciones, const Usuario& usuario, int actividadId);

// Mostrar las inscripciones de un usuario
void mostrarInscripcionesUsuario(const string& archivoInscripciones, const string& nombreUsuario);

// Agregar más funciones según sea necesario


#endif // INSCRIPCION_H
