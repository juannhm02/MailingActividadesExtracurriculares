#include <iostream>
#include <string>
#include "gestionarActividad.h"

void mostrarActividades()
{
    std::cout << "Mostrando actividades disponibles...\n";
    // Lógica para mostrar actividades
}

void registrarUsuario()
{
    std::cout << "Registro de nuevo usuario...\n";
    // Lógica para registrar usuario
}

void inscribirseActividad()
{
    std::cout << "Inscripción en actividad...\n";
    // Lógica para inscribirse en una actividad
}

void cancelarInscripcion()
{
    std::cout << "Cancelar inscripción...\n";
    // Lógica para cancelar inscripción
}

void gestionarActividades()
{
    std::cout << "Gestión de actividades (Administradores)...\n";
    // Lógica para la gestión de actividades
}

int main()
{
    int opcion;

    std::cout << "Menú de Actividades Académicas\n";
    std::cout << "1. Mostrar Actividades\n";
    std::cout << "2. Registrar Usuario\n";
    std::cout << "3. Inscribirse en una Actividad\n";
    std::cout << "4. Cancelar Inscripción\n";
    std::cout << "5. Gestionar Actividades (Solo Administradores)\n";
    std::cout << "6. Salir\n";

    while (true)
    {

        std::cout << "Elige una opción: ";
        std::cin >> opcion;

        switch (opcion)
        {
        case 1:
            mostrarActividades();
            break;
        case 2:
            registrarUsuario();
            break;
        case 3:
            inscribirseActividad();
            break;
        case 4:
            cancelarInscripcion();
            break;
        case 5:
            gestionarActividades();
            break;
        case 6:
            std::cout << "Saliendo del programa...\n";
            return 0; // Termina el programa si se selecciona la opción 6 (Salir)
        default:
            std::cout << "Opción inválida. Por favor, elige una opción válida.\n";
        }
    }

    return 0;
}
