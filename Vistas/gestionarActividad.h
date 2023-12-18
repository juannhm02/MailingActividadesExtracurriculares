#ifndef GESTIONARACTIVIDAD_H
#define GESTIONARACTIVIDAD_H

#include <string>
#include <vector>
using namespace std;


// Estructura para representar una actividad
struct Actividad {
    int id;
    string nombre;
    string descripcion;
    string tipo;
    string estado;
    int aforo;
    string fecha;
    string hora;
    string ubicacion;
    string ponente;
    string esPago;
    float precio;
    // Agrega otros campos necesarios aquí
};

void guardarActividades();
void cargarActividades();
void crearActividad();
void mostrarActividades();
void editarActividad();
void eliminarActividad();
void inscribirseActividad();
void desinscribirseActividad();


#endif
