#ifndef GESTIONARACTIVIDAD_H
#define GESTIONARACTIVIDAD_H

#include <string>
#include <vector>
using namespace std;


// Estructura para representar una actividad
struct Actividad {
<<<<<<< HEAD
    int id;
=======
>>>>>>> main
    string nombre;
    string descripcion;
    string fecha;
    string hora;
    string ubicacion;
    string ponente;
    bool esPago;
    // Agrega otros campos necesarios aquí
};


<<<<<<< HEAD
void cargarActividades();
void guardarActividades();
=======
>>>>>>> main
void crearActividad();
void mostrarActividadesTotales();
void editarActividad();
void eliminarActividad();
<<<<<<< HEAD
void inscribirseActividad();
void desinscribirseActividad();
=======
void gestionarActividades();
// void mostrarActividades(const vector<Actividad>& actividades);
// void registrarUsuario();
// void inscribirseActividad();
// void cancelarInscripcion();
// void mostrarActividades();
// void menu();
>>>>>>> main


#endif
