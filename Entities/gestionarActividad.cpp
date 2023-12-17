#include <iostream>
<<<<<<< HEAD
#include <fstream>
#include <vector>
#include <limits>
#include <algorithm>
using namespace std;
#include "gestionarActividad.h"

vector<Actividad> actividades;
const string archivoActividades = "actividades.txt";

// Funciones nuevas
int obtenerSiguienteID()
{
    if (actividades.empty())
        return 0;
    int maxId = 0;
    for (auto &actividad : actividades)
    {
        if (actividad.id > maxId)
            maxId = actividad.id;
    }
    return maxId + 1;
}

void cargarActividades()
{
    ifstream file(archivoActividades);
    Actividad actividad;
    while (file >> actividad.id)
    {
        file.ignore(); // Ignora el salto de línea después del ID
        getline(file, actividad.nombre);
        getline(file, actividad.descripcion);
        actividades.push_back(actividad);
    }
    file.close();
}

// funcion para que un usuario se apunte en una actividad por ID

void inscribirseActividad()
{
    int id;
    cout << "Ingrese el ID de la actividad a inscribirse: ";
    if (!(cin >> id))
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "ID inválido.\n";
        return;
    }

    auto it = find_if(actividades.begin(), actividades.end(), [id](const Actividad &actividad)
                      { return actividad.id == id; });

    if (it == actividades.end())
    {
        cout << "No se encontró la actividad con el ID " << id << ".\n";
        return;
    }

    Actividad &actividad = *it;
    cout << "Nombre de la actividad: ";
    cin.ignore();
    getline(cin, actividad.nombre);

    cout << "Descripción de la actividad: ";
    getline(cin, actividad.descripcion);

    guardarActividades();
    cout << "Actividad editada exitosamente.\n";
}

// funcion para que un usuario se desapunte de una actividad por ID

void desinscribirseActividad()
{
    int id;
    cout << "Ingrese el ID de la actividad a desinscribirse: ";
    if (!(cin >> id))
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "ID inválido.\n";
        return;
    }

    auto it = find_if(actividades.begin(), actividades.end(), [id](const Actividad &actividad)
                      { return actividad.id == id; });

    if (it == actividades.end())
    {
        cout << "No se encontró la actividad con el ID " << id << ".\n";
        return;
    }

    Actividad &actividad = *it;
    cout << "Nombre de la actividad: ";
    cin.ignore();
    getline(cin, actividad.nombre);

    cout << "Descripción de la actividad: ";
    getline(cin, actividad.descripcion);

    guardarActividades();
    cout << "Actividad editada exitosamente.\n";
}


void guardarActividades()
{
    ofstream file(archivoActividades);
    for (auto &actividad : actividades)
    {
        file << actividad.id << endl;
        file << actividad.nombre << endl;
        file << actividad.descripcion << endl;
    }
    file.close();
}

// A continuación, modifica tus funciones actuales para usar el ID y para guardar/cargar del archivo

void crearActividad()
{
    Actividad actividad;
    actividad.id = obtenerSiguienteID();
=======
#include <limits>
using namespace std;
#include "gestionarActividad.h"

// Vector para almacenar las actividades
vector<Actividad> actividades;

// Función para crear una nueva actividad
void crearActividad()
{
    Actividad actividad;
>>>>>>> main
    cin.ignore(); // Limpiar el búfer del teclado

    cout << "Nombre de la actividad: ";
    getline(cin, actividad.nombre);

    cout << "Descripción de la actividad: ";
    getline(cin, actividad.descripcion);

<<<<<<< HEAD
    actividades.push_back(actividad);
    guardarActividades();
    cout << "Actividad creada exitosamente con ID " << actividad.id << ".\n";
}

=======
    // Puedes agregar más campos aquí según tus necesidades

    actividades.push_back(actividad);
    cout << "Actividad creada exitosamente.\n";
}

// Función para mostrar todas las actividades
>>>>>>> main
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
<<<<<<< HEAD
        cout << "ID: " << actividad.id << "\n";
        cout << "Nombre: " << actividad.nombre << "\n";
        cout << "Descripción: " << actividad.descripcion << "\n";
=======
        cout << "Nombre: " << actividad.nombre << "\n";
        cout << "Descripción: " << actividad.descripcion << "\n";
        // Muestra otros campos aquí si los tienes
>>>>>>> main
        cout << "-----------------------\n";
    }
}

<<<<<<< HEAD
void editarActividad()
{
    int id;
    cout << "Ingrese el ID de la actividad a editar: ";
    if (!(cin >> id))
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "ID inválido.\n";
        return;
    }

    auto it = find_if(actividades.begin(), actividades.end(), [id](const Actividad &actividad)
                      { return actividad.id == id; });

    if (it == actividades.end())
    {
        cout << "No se encontró la actividad con el ID " << id << ".\n";
        return;
    }

    Actividad &actividad = *it;
    cout << "Nombre de la actividad: ";
    cin.ignore();
    getline(cin, actividad.nombre);

    cout << "Descripción de la actividad: ";
    getline(cin, actividad.descripcion);

    guardarActividades();
    cout << "Actividad editada exitosamente.\n";
}

void eliminarActividad()
{
    int id;
    cout << "Ingrese el ID de la actividad a eliminar: ";
    if (!(cin >> id))
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "ID inválido.\n";
        return;
    }

    auto it = find_if(actividades.begin(), actividades.end(), [id](const Actividad &actividad)
                      { return actividad.id == id; });

    if (it == actividades.end())
    {
        cout << "No se encontró la actividad con el ID " << id << ".\n";
        return;
    }

    actividades.erase(it);
    guardarActividades();
    cout << "Actividad eliminada exitosamente.\n";
=======
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
>>>>>>> main
}