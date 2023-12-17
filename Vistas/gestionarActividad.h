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
    string fecha;
    string hora;
    string ubicacion;
    string ponente;
    bool esPago;
    // Agrega otros campos necesarios aquí
};


void cargarActividades();
void guardarActividades();
void crearActividad();
void mostrarActividadesTotales();
void editarActividad();
void eliminarActividad();


#endif
