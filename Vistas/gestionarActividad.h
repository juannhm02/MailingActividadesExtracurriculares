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
    int inscritos;
    // Agrega otros campos necesarios aquí
};

struct Inscripcion
{
    int id;
    int idActividad;
    string nombre;
    string correo;
    string telefono;
    string fecha;
    string hora;
    string estado;
    string tipo;
    string ubicacion;
    string ponente;
    string esPago;
    float precio;
    int inscritos;
    
};


void guardarActividades();
void cargarActividades();
void crearActividad();
void editarActividad();
void eliminarActividad();
void mostrarActividadesNoIniciadas();
void mostrarActividadesEnCurso();
void mostrarActividadesFinalizadas();
void inscribirUsuario();
void modificarEstadoActividad(int id, string estado);
void desinscribirUsuario();
void mostrarInscripcionesUsuario();
void generarCertificados(const string &nombreUsuario);
void enviarListaDifusion();
void leerListaDifusion(const string& nombreUsuario);
void verMisCertificados(const string &nombreUsuario);
string normalizarString(const string& str);


#endif
