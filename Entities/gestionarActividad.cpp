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

    int tipo = 0;
    do
    {
        cout << "Tipo de actividad: \n";
        cout << "1. Congreso ordinario\n";
        cout << "2. Congreso extraordinario\n";
        cout << "3. Ponencia\n";
        cout << "4. Taller\n";
        cout << "5. Seminario\n";
        cout << "Ingrese el número correspondiente al estado: ";
        cin >> tipo;

    } while (tipo < 1 || tipo > 5);

    switch (tipo)
    {
    case 1:
        actividad.tipo = "Congreso ordinario";
        break;
    case 2:
        actividad.tipo = "Congreso extraordinario";
        break;
    case 3:
        actividad.tipo = "Ponencia";
        break;
    case 4:
        actividad.tipo = "Taller";
        break;
    case 5:
        actividad.tipo = "Seminario";
        break;
    }

    int estado = 0;
    do
    {
        cout << "Estado de actividad: \n";
        cout << "1. No iniciado\n";
        cout << "2. En curso\n";
        cout << "3. Finalizado\n";
        cout << "Ingrese el número correspondiente al estado: ";
        cin >> estado;

    } while (estado < 1 || estado > 3);

    switch (estado)
    {
    case 1:
        actividad.estado = "No iniciado";
        break;
    case 2:
        actividad.estado = "En curso";
        break;
    case 3:
        actividad.estado = "Finalizado";
        break;
    }

    cout << "Aforo de la actividad: ";
    cin >> actividad.aforo;

    cout << "Fecha actividad (dd/mm/yy): ";
    cin.ignore();
    getline(cin, actividad.fecha);

    cout << "Hora actividad (hh:mm): ";
    getline(cin, actividad.hora);

    cout << "Ubicacion actividad: ";
    getline(cin, actividad.ubicacion);

    cout << "Autor: ";
    getline(cin, actividad.ponente);

    int esPago = 0;

    do
    {
        cout << "¿Es de pago?: \n";
        cout << "1. Sí\n";
        cout << "2. No\n";
        cout << "Ingrese el número correspondiente al estado: ";
        cin >> esPago;

    } while (esPago < 1 || esPago > 2);

    switch (esPago)
    {
    case 1:
        actividad.esPago = "Sí";

        cout << "Precio: ";
        cin >> actividad.precio;

        break;
    case 2:
        actividad.esPago = "No";
        actividad.precio = 0;
        break;
    }

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

// Funcion editar actividad con menu para elegir qué editar

void editarActividad()
{
    int id;
    int esPago = 0;
    int tipo = 0;
    int estado = 0;
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
    int opcion = 0;
    do
    {
        cout << "¿Qué desea editar?\n";
        cout << "1. Nombre\n";
        cout << "2. Descripción\n";
        cout << "3. Tipo\n";
        cout << "4. Estado\n";
        cout << "5. Aforo\n";
        cout << "6. Fecha\n";
        cout << "7. Hora\n";
        cout << "8. Ubicación\n";
        cout << "9. Ponente\n";
        cout << "10. Es de pago\n";
        cout << "11. Precio\n";
        cout << "12. Salir\n";
        cout << "Ingrese el número correspondiente a la opción: ";
        cin >> opcion;

        switch (opcion)
        {
        case 1:
            cout << "Nombre de la actividad: ";
            cin.ignore();
            getline(cin, actividad.nombre);
            break;
        case 2:
            cout << "Descripción de la actividad: ";
            cin.ignore();
            getline(cin, actividad.descripcion);
            break;
        case 3:

            do
            {
                cout << "Tipo de actividad: \n";
                cout << "1. Congreso ordinario\n";
                cout << "2. Congreso extraordinario\n";
                cout << "3. Ponencia\n";
                cout << "4. Taller\n";
                cout << "5. Seminario\n";
                cout << "Ingrese el número correspondiente al estado: ";
                cin >> tipo;

            } while (tipo < 1 || tipo > 5);

            switch (tipo)
            {
            case 1:
                actividad.tipo = "Congreso ordinario";
                break;
            case 2:
                actividad.tipo = "Congreso extraordinario";
                break;
            case 3:
                actividad.tipo = "Ponencia";
                break;
            case 4:
                actividad.tipo = "Taller";
                break;
            case 5:
                actividad.tipo = "Seminario";
                break;
            }
            break;
        case 4:
            do
            {
                cout << "Estado de actividad: \n";
                cout << "1. No iniciado\n";
                cout << "2. En curso\n";
                cout << "3. Finalizado\n";
                cout << "Ingrese el número correspondiente al estado: ";
                cin >> estado;

            } while (estado < 1 || estado > 3);

            switch (estado)
            {
            case 1:
                actividad.estado = "No iniciado";
                break;
            case 2:
                actividad.estado = "En curso";
                break;
            case 3:
                actividad.estado = "Finalizado";
                break;
            }
            break;
        case 5:
            cout << "Aforo de la actividad: ";
            cin >> actividad.aforo;
            break;
        case 6:
            cout << "Fecha actividad (dd/mm/yy): ";
            cin.ignore();
            getline(cin, actividad.fecha);
            break;
        case 7:
            cout << "Hora actividad (hh:mm): ";
            getline(cin, actividad.hora);
            break;
        case 8:
            cout << "Ubicacion actividad: ";
            getline(cin, actividad.ubicacion);
            break;
        case 9:
            cout << "Autor: ";
            getline(cin, actividad.ponente);
            break;
        case 10:
            
            do
            {
                cout << "¿Es de pago?: \n";
                cout << "1. Sí\n";
                cout << "2. No\n";
                cout << "Ingrese el número correspondiente al estado: ";
                cin >> esPago;

            } while (esPago < 1 || esPago > 2);
            switch (esPago)
            {
            case 1:
                actividad.esPago = "Sí";

                cout << "Precio: ";
                cin >> actividad.precio;

                break;
            case 2:
                actividad.esPago = "No";
                actividad.precio = 0;
                break;
            }
            break;
        case 11:
            cout << "Precio: ";
            cin >> actividad.precio;
            break;
        }
    } while (opcion != 12);

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
        archivo << "ID: " << actividad.id << '\n'
                << "Nombre: " << actividad.nombre << '\n'
                << "Descripción: " << actividad.descripcion << '\n'
                << "Tipo: " << actividad.tipo << '\n'
                << "Estado: " << actividad.estado << '\n'
                << "Aforo: " << actividad.aforo << '\n'
                << "Fecha: " << actividad.fecha << '\n'
                << "Hora: " << actividad.hora << '\n'
                << "Ubicación: " << actividad.ubicacion << '\n'
                << "Ponente: " << actividad.ponente << '\n'
                << "Es de pago: " << actividad.esPago << '\n'
                << "Precio: " << actividad.precio << "€" << '\n';
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

    string linea;
    Actividad actividad;
    while (getline(archivo, linea))
    {
        if (linea.find("ID: ") == 0)
        {
            actividad.id = stoi(linea.substr(4));
        }
        else if (linea.find("Nombre: ") == 0)
        {
            actividad.nombre = linea.substr(8);
        }
        else if (linea.find("Descripción: ") == 0)
        {
            actividad.descripcion = linea.substr(13);
        }
        else if (linea.find("Tipo: ") == 0)
        {
            actividad.tipo = linea.substr(6);
        }
        else if (linea.find("Estado: ") == 0)
        {
            actividad.estado = linea.substr(8);
        }
        else if (linea.find("Aforo: ") == 0)
        {
            actividad.aforo = stoi(linea.substr(7));
        }
        else if (linea.find("Fecha: ") == 0)
        {
            actividad.fecha = linea.substr(7);
        }
        else if (linea.find("Hora: ") == 0)
        {
            actividad.hora = linea.substr(6);
        }
        else if (linea.find("Ubicación: ") == 0)
        {
            actividad.ubicacion = linea.substr(11);
        }
        else if (linea.find("Ponente: ") == 0)
        {
            actividad.ponente = linea.substr(9);
        }
        else if (linea.find("Es de pago: ") == 0)
        {
            actividad.esPago = linea.substr(12);
        }
        else if (linea.find("Precio: ") == 0)
        {
            actividad.precio = stof(linea.substr(8));
            actividades.push_back(actividad);
        }
    }
}