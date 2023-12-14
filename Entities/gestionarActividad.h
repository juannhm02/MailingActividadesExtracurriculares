#ifndef GESTIONARACTIVIDAD_H
#define GESTIONARACTIVIDAD_H

#include <string>
#include <vector>

// Estructura para representar una actividad
struct Actividad {
    std::string nombre;
    std::string descripcion;
    // Agrega otros campos necesarios aquí
};



void crearActividad(std::vector<Actividad>& actividades);
void mostrarActividadesTotales(const std::vector<Actividad>& actividades);
void editarActividad(std::vector<Actividad>& actividades);
void eliminarActividad(std::vector<Actividad>& actividades);
void gestionarActividades();

#endif
