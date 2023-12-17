#ifndef GESTIONARACTIVIDAD_H
#define GESTIONARACTIVIDAD_H

#include <string>
#include <vector>
using namespace std;


// Estructura para representar una actividad
struct Actividad {
    string nombre;
    string descripcion;
    string fecha;
    string hora;
    string ubicacion;
    string ponente;
    bool esPago;
    // Agrega otros campos necesarios aquí
};


void crearActividad();
void mostrarActividadesTotales();
void editarActividad();
void eliminarActividad();
void gestionarActividades();
// void mostrarActividades(const vector<Actividad>& actividades);
// void registrarUsuario();
// void inscribirseActividad();
// void cancelarInscripcion();
// void mostrarActividades();
// void menu();


#endif
