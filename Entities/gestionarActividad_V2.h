#ifndef GESTIONARACTIVIDAD_H
#define GESTIONARACTIVIDAD_H

#include <string>
#include <vector>

// Estructura para representar una actividad
struct Actividad {
    std::string nombre;
    std::string descripcion;
    std::string fecha;
    std::string hora;
    std::string ubicacion;
    std::string ponente;
    bool esPago;
    // Agrega otros campos necesarios aquí
};

void crearActividad(std::vector<Actividad>& actividades);
void mostrarActividadesTotales(const std::vector<Actividad>& actividades);
void editarActividad(std::vector<Actividad>& actividades);
void eliminarActividad(std::vector<Actividad>& actividades);

#endif // GESTIONARACTIVIDAD_H
