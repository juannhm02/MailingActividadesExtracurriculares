#include <iostream>
#include <limits>
using namespace std;
#include "gestionarActividad.h"

// Vector para almacenar las actividades
vector<Actividad> actividades;

// Función para crear una nueva actividad
void crearActividad()
{
    Actividad actividad;
    cin.ignore(); // Limpiar el búfer del teclado

    cout << "Nombre de la actividad: ";
    getline(cin, actividad.nombre);

    cout << "Descripción de la actividad: ";
    getline(cin, actividad.descripcion);

    // Puedes agregar más campos aquí según tus necesidades

    actividades.push_back(actividad);
    cout << "Actividad creada exitosamente.\n";
}

// Función para mostrar todas las actividades
void mostrarActividadesTotales()
{
    if (actividades.empty())
    {
        cout << "No hay actividades disponibles.\n";
        return;
    }

    cout << "Lista de actividades:\n";
    for (const Actividad &actividad : actividades)
    {
        cout << "Nombre: " << actividad.nombre << "\n";
        cout << "Descripción: " << actividad.descripcion << "\n";
        // Muestra otros campos aquí si los tienes
        cout << "-----------------------\n";
    }
}

// Función para editar una actividad existente
void editarActividad()
{
    if (actividades.empty())
    {
        cout << "No hay actividades disponibles para editar.\n";
        return;
    }

    int indice;
    cout << "Índice de la actividad a editar: ";
    cin >> indice;

    if (indice >= 0 && indice < actividades.size())
    {
        Actividad &actividad = actividades[indice];
        cin.ignore(); // Limpiar el búfer del teclado

        cout << "Nuevo nombre de la actividad: ";
        getline(cin, actividad.nombre);

        cout << "Nueva descripción de la actividad: ";
        getline(cin, actividad.descripcion);

        // Puedes editar más campos aquí según tus necesidades

        cout << "Actividad editada exitosamente.\n";
    }
    else
    {
        cout << "Índice de actividad no válido.\n";
    }
}

// Función para eliminar una actividad existente
void eliminarActividad()
{
    if (actividades.empty())
    {
        cout << "No hay actividades disponibles para eliminar.\n";
        return;
    }

    int indice;
    cout << "Índice de la actividad a eliminar: ";
    cin >> indice;

    if (indice >= 0 && indice < actividades.size())
    {
        actividades.erase(actividades.begin() + indice);
        cout << "Actividad eliminada exitosamente.\n";
    }
    else
    {
        cout << "Índice de actividad no válido.\n";
    }
}

void gestionarActividades()
{
    cout << "\nMenú de gestión de actividades (Administradores)...\n\n";

    int opcion;

    cout << "1. Crear actividad\n";
    cout << "2. Mostrar todas las actividades\n";
    cout << "3. Editar actividad\n";
    cout << "4. Eliminar actividad\n";
    cout << "5. Salir\n\n";

    while (true)
    {
        cout << "Elige una opción: ";

        if (!(cin >> opcion))
        {
            cin.clear();                                                   // Limpia el estado de error de cin
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Descarta la entrada incorrecta

            cout << "Opción inválida. Por favor, elige una opción válida.\n";
            continue; // Continúa con la siguiente iteración del bucle
        }

        switch (opcion)
        {
        case 1:
            crearActividad();
            break;
        case 2:
            mostrarActividadesTotales();
            break;
        case 3:
            editarActividad();
            break;
        case 4:
            eliminarActividad();
            break;
        case 5:
            cout << "Saliendo del programa...\n";
            break;
        default:
            cout << "Opción inválida. Por favor, elige una opción válida.\n";
        }
    }
}