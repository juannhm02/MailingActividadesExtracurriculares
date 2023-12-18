#include <iostream>
#include <limits>
#include "gestionarActividad.h"
#include "Inscripcion.h"
#include "ListaDifusion.h"
#include "Certificado.h"
#include "Usuario.h"
#include "menu.h"

using namespace std;

void mostrarMenuVisitante()
{
    cout << "\nBienvenido al sistema de gestión de actividades extracurriculares 'Visitante'\n\n";
    cout << "1. Ver actividades\n";
    cout << "2. Iniciar sesión\n";
    cout << "3. Iniciar sesión (Admin)\n";
    cout << "4. Registrarse\n";
    cout << "5. Salir\n\n";
    cout << "Seleccione una opción: ";
}

void mostrarMenuRegistrado()
{
    cout << "\nBienvenido al sistema de gestión de actividades extracurriculares 'Registrado'\n\n";
    cout << "1. Ver actividades\n";
    cout << "2. Inscribirse en actividad\n";
    cout << "3. Cancelar inscripción\n";
    cout << "4. Log out\n";
    cout << "5. Salir\n\n";
    cout << "Seleccione una opción: ";
}

void mostrarMenuAdmin()
{
    cout << "\nBienvenido al sistema de gestión de actividades extracurriculares 'Administrador'\n\n";
    cout << "1. Registrar actividad\n";
    cout << "2. Eliminar actividad\n";
    cout << "3. Modificar actividad\n";
    cout << "4. Modificar roles\n";
    cout << "5. Enviar lista de difusión\n";
    cout << "6. Generar certificado\n";
    cout << "7. Log out\n";
    cout << "8. Salir\n\n";
    cout << "Seleccione una opción: ";
}

void mostrarInscripciones()
{
    cout << "\nBienvenido al sistema de gestión de actividades extracurriculares 'Inscripciones'\n\n";
    cout << "1. Ver inscripciones\n";
    cout << "2. Confirmar pago\n";
    cout << "3. Log out\n";
    cout << "4. Salir\n\n";
    cout << "Seleccione una opción: ";
}
