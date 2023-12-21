#include <iostream>
#include <limits>
#include "gestionarActividad.h"
#include "Usuario.h"
#include "menu.h"

using namespace std;

void mostrarMenuVisitante()
{
    cout << "\nBienvenido al sistema de gestión de actividades extracurriculares 'Visitante'\n\n";
    cout << "1. Ver actividades no iniciadas\n";
    cout << "2. Ver actividades en curso\n";
    cout << "3. Ver actividades finalizadas\n";
    cout << "4. Iniciar sesión\n";
    cout << "5. Iniciar sesión (Admin)\n";
    cout << "6. Iniciar sesión (Director Académico)\n";
    cout << "7. Registrarse\n";
    cout << "8. Salir\n\n";
    cout << "Seleccione una opción: ";
}

void mostrarMenuRegistrado()
{
    cout << "\nBienvenido al sistema de gestión de actividades extracurriculares 'Registrado'\n\n";
    cout << "1. Ver actividades no iniciadas\n";
    cout << "2. Ver actividades en curso\n";
    cout << "3. Ver actividades finalizadas\n";
    cout << "4. Inscribirse en actividad\n";
    cout << "5. Cancelar inscripción\n";
    cout << "6. Mostrar actividades en las que estoy inscrito\n";
    cout << "7. Mensajes lista de difusión\n";
    cout << "8. Ver mis certificados\n";
    cout << "9. Cerrar sesión\n";
    cout << "10. Salir\n\n";
    cout << "Seleccione una opción: ";
}

void mostrarMenuAdmin()
{
    cout << "\nBienvenido al sistema de gestión de actividades extracurriculares 'Admin'\n\n";
    cout << "1. Ver actividades no iniciadas\n";
    cout << "2. Ver actividades en curso\n";
    cout << "3. Ver actividades finalizadas\n";
    cout << "4. Registrar actividad\n";
    cout << "5. Eliminar actividad\n";
    cout << "6. Modificar actividad\n";
    cout << "7. Modificar roles\n";
    cout << "8. Enviar lista de difusión\n";
    cout << "9. Generar certificado\n";
    cout << "10. Ver usuarios registrados\n";
    cout << "11. Cerrar sesión\n";
    cout << "12. Salir\n\n";
    cout << "Seleccione una opción: ";
}

void mostrarMenuDirectorAcademico()
{
    cout << "\nBienvenido al sistema de gestión de actividades extracurriculares 'Director Académico'\n\n";
    cout << "1. Ver actividades no iniciadas\n";
    cout << "2. Ver actividades en curso\n";
    cout << "3. Ver actividades finalizadas\n";
    cout << "4. Registrar actividad\n";
    cout << "5. Eliminar actividad\n";
    cout << "6. Modificar actividad\n";
    cout << "7. Enviar lista de difusión\n";
    cout << "8. Cerrar sesión\n";
    cout << "9. Salir\n\n";
    cout << "Seleccione una opción: ";
}
