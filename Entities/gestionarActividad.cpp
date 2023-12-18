#include <iostream>
#include <fstream>
#include <vector>
#include <limits>
#include <algorithm>
using namespace std;
#include "gestionarActividad.h"

vector<Actividad> actividades;
const string archivoActividades = "actividades.txt";

// Funcion obtener ID libre

int obtenerSiguienteID()
{
    if (actividades.empty())
    {
        return 1;
    }

    return actividades.back().id + 1;
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

// Funcion crear actividad

void crearActividad()
{
    Actividad actividad;
    actividad.id = obtenerSiguienteID();

    cout << "Nombre de la actividad: ";
    cin.ignore();
    getline(cin, actividad.nombre);

    cout << "Descripción de la actividad: ";
    getline(cin, actividad.descripcion);

    actividades.push_back(actividad);
    guardarActividades();
    cout << "Actividad creada exitosamente.\n";
}

// Funcion mostrar actividades

void mostrarActividades()
{
    cout << "ID\tNombre\tDescripción\n";
    for (const Actividad &actividad : actividades)
    {
        cout << actividad.id << '\t' << actividad.nombre << '\t' << actividad.descripcion << '\n';
    }
}

// Funcion editar actividad

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

// Funcion eliminar actividad

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
}

// funcion para guardar actividades

void guardarActividades()
{
    ofstream archivo(archivoActividades);
    if (!archivo.is_open())
    {
        cout << "No se pudo abrir el archivo " << archivoActividades << ".\n";
        return;
    }

    for (const Actividad &actividad : actividades)
    {
        archivo << actividad.id << '\n'
                << actividad.nombre << '\n'
                << actividad.descripcion << '\n';
    }
}

// funcion para cargar actividades

void cargarActividades()
{
    ifstream archivo(archivoActividades);
    if (!archivo.is_open())
    {
        cout << "No se pudo abrir el archivo " << archivoActividades << ".\n";
        return;
    }

    Actividad actividad;
    string linea;
    while (getline(archivo, linea))
    {
        actividad.id = stoi(linea);
        getline(archivo, actividad.nombre);
        getline(archivo, actividad.descripcion);
        actividades.push_back(actividad);
    }
}