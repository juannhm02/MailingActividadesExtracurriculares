#include <iostream>
#include <fstream>
#include <vector>
#include <limits>
#include <algorithm>
using namespace std;
#include "gestionarActividad.h"

vector<Actividad> actividades;
const string archivoActividades = "actividades.txt";

// Funciones nuevas
int obtenerSiguienteID() {
    if (actividades.empty()) return 0;
    int maxId = 0;
    for (auto& actividad : actividades) {
        if (actividad.id > maxId) maxId = actividad.id;
    }
    return maxId + 1;
}

void cargarActividades() {
    ifstream file(archivoActividades);
    Actividad actividad;
    while (file >> actividad.id) {
        file.ignore(); // Ignora el salto de línea después del ID
        getline(file, actividad.nombre);
        getline(file, actividad.descripcion);
        actividades.push_back(actividad);
    }
    file.close();
}

void guardarActividades() {
    ofstream file(archivoActividades);
    for (auto& actividad : actividades) {
        file << actividad.id << endl;
        file << actividad.nombre << endl;
        file << actividad.descripcion << endl;
    }
    file.close();
}

// A continuación, modifica tus funciones actuales para usar el ID y para guardar/cargar del archivo

void crearActividad() {
    Actividad actividad;
    actividad.id = obtenerSiguienteID();
    cin.ignore(); // Limpiar el búfer del teclado

    cout << "Nombre de la actividad: ";
    getline(cin, actividad.nombre);

    cout << "Descripción de la actividad: ";
    getline(cin, actividad.descripcion);

    actividades.push_back(actividad);
    guardarActividades();
    cout << "Actividad creada exitosamente con ID " << actividad.id << ".\n";
}

void mostrarActividadesTotales() {
    if (actividades.empty()) {
        cout << "No hay actividades disponibles.\n";
        return;
    }

    cout << "Lista de actividades:\n";
    for (const Actividad &actividad : actividades) {
        cout << "ID: " << actividad.id << "\n";
        cout << "Nombre: " << actividad.nombre << "\n";
        cout << "Descripción: " << actividad.descripcion << "\n";
        cout << "-----------------------\n";
    }
}

void editarActividad() {
    int id;
    cout << "Ingrese el ID de la actividad a editar: ";
    if (!(cin >> id)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "ID inválido.\n";
        return;
    }

    auto it = find_if(actividades.begin(), actividades.end(), [id](const Actividad &actividad) {
        return actividad.id == id;
    });

    if (it == actividades.end()) {
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

void eliminarActividad() {
    int id;
    cout << "Ingrese el ID de la actividad a eliminar: ";
    if (!(cin >> id)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "ID inválido.\n";
        return;
    }

    auto it = find_if(actividades.begin(), actividades.end(), [id](const Actividad &actividad) {
        return actividad.id == id;
    });

    if (it == actividades.end()) {
        cout << "No se encontró la actividad con el ID " << id << ".\n";
        return;
    }

    actividades.erase(it);
    guardarActividades();
    cout << "Actividad eliminada exitosamente.\n";
}