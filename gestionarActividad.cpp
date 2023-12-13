#include <iostream>
#include "gestionarActividad.h"

// Vector para almacenar las actividades
std::vector<Actividad> actividades;

// Función para crear una nueva actividad
void crearActividad()
{
    Actividad actividad;
    std::cin.ignore(); // Limpiar el búfer del teclado

    std::cout << "Nombre de la actividad: ";
    std::getline(std::cin, actividad.nombre);

    std::cout << "Descripción de la actividad: ";
    std::getline(std::cin, actividad.descripcion);

    // Puedes agregar más campos aquí según tus necesidades

    actividades.push_back(actividad);
    std::cout << "Actividad creada exitosamente.\n";
}

// Función para mostrar todas las actividades
void mostrarActividadesTotales()
{
    if (actividades.empty())
    {
        std::cout << "No hay actividades disponibles.\n";
        return;
    }

    std::cout << "Lista de actividades:\n";
    for (const Actividad &actividad : actividades)
    {
        std::cout << "Nombre: " << actividad.nombre << "\n";
        std::cout << "Descripción: " << actividad.descripcion << "\n";
        // Muestra otros campos aquí si los tienes
        std::cout << "-----------------------\n";
    }
}

// Función para editar una actividad existente
void editarActividad()
{
    if (actividades.empty())
    {
        std::cout << "No hay actividades disponibles para editar.\n";
        return;
    }

    int indice;
    std::cout << "Índice de la actividad a editar: ";
    std::cin >> indice;

    if (indice >= 0 && indice < actividades.size())
    {
        Actividad &actividad = actividades[indice];
        std::cin.ignore(); // Limpiar el búfer del teclado

        std::cout << "Nuevo nombre de la actividad: ";
        std::getline(std::cin, actividad.nombre);

        std::cout << "Nueva descripción de la actividad: ";
        std::getline(std::cin, actividad.descripcion);

        // Puedes editar más campos aquí según tus necesidades

        std::cout << "Actividad editada exitosamente.\n";
    }
    else
    {
        std::cout << "Índice de actividad no válido.\n";
    }
}

// Función para eliminar una actividad existente
void eliminarActividad()
{
    if (actividades.empty())
    {
        std::cout << "No hay actividades disponibles para eliminar.\n";
        return;
    }

    int indice;
    std::cout << "Índice de la actividad a eliminar: ";
    std::cin >> indice;

    if (indice >= 0 && indice < actividades.size())
    {
        actividades.erase(actividades.begin() + indice);
        std::cout << "Actividad eliminada exitosamente.\n";
    }
    else
    {
        std::cout << "Índice de actividad no válido.\n";
    }
}

void gestionarActividades()
{

    int opcion;

    std::cout << "Gestión de actividades (Administradores)...\n\n";

    std::cout << "1. Mostrar actividades\n";
    std::cout << "2. Crear actividad\n";
    std::cout << "3. Editar actividad\n";
    std::cout << "4. Eliminar actividad\n";
    std::cout << "5. Volver hacia atrás\n";

    while (true)
    {

        std::cout << "Elige una opción: ";
        std::cin >> opcion;

        switch (opcion)
        {
        case 1:
            mostrarActividadesTotales();
            break;
        case 2:
            crearActividad();
            break;
        case 3:
            editarActividad();
            break;
        case 4:
            eliminarActividad();
            break;
        case 5:
            std::cout << "Volviendo atrás...\n";
            break; // Termina la función si se selecciona la opción 5 (Volver al menú)
        default:
            std::cout << "Opción inválida. Por favor, elige una opción válida.\n";
        }
    }
    // Lógica para la gestión de actividades
}