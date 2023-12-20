#include <iostream>
#include <fstream>
#include <vector>
#include <limits>
#include <algorithm>
#include <string>
#include <sys/stat.h>
#include <sys/types.h>
using namespace std;
#include "gestionarActividad.h"
#include "Usuario.h"

vector<Actividad> actividades;
const string archivoActividadesNoIniciadas = "actividadesNoIniciadas.txt";
const string archivoActividadesEnCurso = "actividadesEnCurso.txt";
const string archivoActividadesFinalizadas = "actividadesFinalizadas.txt";

// Funcion obtener ID libre

int obtenerSiguienteID()
{
    if (actividades.empty())
    {
        return 1;
    }

    return actividades.back().id + 1;
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

    actividad.estado = "No iniciado";
    cout << "Estado de actividad: " << actividad.estado << '\n';

    cout << "Aforo de la actividad: ";
    cin >> actividad.aforo;

    cout << "Fecha actividad (dd/mm/yy): ";
    cin.ignore();
    getline(cin, actividad.fecha);

    cout << "Hora actividad (hh:mm): ";
    getline(cin, actividad.hora);

    cout << "Ubicacion actividad: ";
    getline(cin, actividad.ubicacion);

    cout << "Ponente: ";
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

    actividad.inscritos = 0;
    cout << "Inscritos: " << actividad.inscritos << '\n';

    actividades.push_back(actividad);
    guardarActividades();
    cout << "Actividad creada exitosamente.\n";
}

// Funcion mostrar actividades no iniciadas

void mostrarActividadesNoIniciadas()
{
    ifstream archivoNoIniciadas(archivoActividadesNoIniciadas);

    if (!archivoNoIniciadas.is_open())
    {
        cout << "No se pudo abrir el archivo " << archivoActividadesNoIniciadas << '\n';
        return;
    }

    string linea;
    while (getline(archivoNoIniciadas, linea))
    {
        cout << linea << '\n';
    }

    archivoNoIniciadas.close();
}

// Funcion mostrar actividades en curso

void mostrarActividadesEnCurso()
{
    ifstream archivoEnCurso(archivoActividadesEnCurso);

    if (!archivoEnCurso.is_open())
    {
        cout << "No se pudo abrir el archivo " << archivoActividadesEnCurso << '\n';
        return;
    }

    string linea;
    while (getline(archivoEnCurso, linea))
    {
        cout << linea << '\n';
    }

    archivoEnCurso.close();
}

// Funcion mostrar actividades finalizadas

void mostrarActividadesFinalizadas()
{
    ifstream archivoFinalizadas(archivoActividadesFinalizadas);

    if (!archivoFinalizadas.is_open())
    {
        cout << "No se pudo abrir el archivo " << archivoActividadesFinalizadas << '\n';
        return;
    }

    string linea;
    while (getline(archivoFinalizadas, linea))
    {
        cout << linea << '\n';
    }

    archivoFinalizadas.close();
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
                cout << "1. En curso\n";
                cout << "2. Finalizado\n";
                cout << "Ingrese el número correspondiente al estado: ";
                cin >> estado;

            } while (estado < 1 || estado > 2);

            switch (estado)
            {
            case 1:
                actividad.estado = "En curso";
                modificarEstadoActividad(actividad.id, actividad.estado);
                break;
            case 2:
                actividad.estado = "Finalizado";
                modificarEstadoActividad(actividad.id, actividad.estado);
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
            cout << "Ponente: ";
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
        case 12:

            cout << "Inscritos: ";
            int seguro = actividad.inscritos;
            cin >> actividad.inscritos;

            if (actividad.inscritos > actividad.aforo)
            {
                cout << "El número de inscritos no puede ser mayor que el aforo.\n";
                actividad.inscritos = seguro;
                return;
            }
            break;
        }
    } while (opcion != 13);

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

// funcion para guardar actividades dependiendo de su estado

void guardarActividades()
{
    ofstream archivoNoIniciadas(archivoActividadesNoIniciadas);
    ofstream archivoEnCurso(archivoActividadesEnCurso);
    ofstream archivoFinalizadas(archivoActividadesFinalizadas);

    for (const Actividad &actividad : actividades)
    {
        if (actividad.estado == "No iniciado")
        {
            archivoNoIniciadas << "ID: " << actividad.id << '\n'
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
                               << "Precio: " << actividad.precio << "€" << '\n'
                               << "Inscritos: " << actividad.inscritos << '\n'
                               << "----------------------------------------\n";
        }
        else if (actividad.estado == "En curso")
        {
            archivoEnCurso << "ID: " << actividad.id << '\n'
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
                           << "Precio: " << actividad.precio << "€" << '\n'
                           << "Inscritos: " << actividad.inscritos << '\n'
                           << "----------------------------------------\n";
        }
        else if (actividad.estado == "Finalizado")
        {
            archivoFinalizadas << "ID: " << actividad.id << '\n'
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
                               << "Precio: " << actividad.precio << "€" << '\n'
                               << "Inscritos: " << actividad.inscritos << '\n'
                               << "----------------------------------------\n";
        }
    }
}

// funcion para cargar actividades sin stoi

void cargarActividades()
{
    ifstream archivoNoIniciadas(archivoActividadesNoIniciadas);
    ifstream archivoEnCurso(archivoActividadesEnCurso);
    ifstream archivoFinalizadas(archivoActividadesFinalizadas);

    if (!archivoNoIniciadas.is_open())
    {
        cout << "No se pudo abrir el archivo " << archivoActividadesNoIniciadas << '\n';
        return;
    }

    if (!archivoEnCurso.is_open())
    {
        cout << "No se pudo abrir el archivo " << archivoActividadesEnCurso << '\n';
        return;
    }

    if (!archivoFinalizadas.is_open())
    {
        cout << "No se pudo abrir el archivo " << archivoActividadesFinalizadas << '\n';
        return;
    }

    string linea;
    while (getline(archivoNoIniciadas, linea))
    {
        Actividad actividad;
        actividad.id = stoi(linea.substr(4));
        getline(archivoNoIniciadas, linea);
        actividad.nombre = linea.substr(8);
        getline(archivoNoIniciadas, linea);
        actividad.descripcion = linea.substr(13);
        getline(archivoNoIniciadas, linea);
        actividad.tipo = linea.substr(6);
        getline(archivoNoIniciadas, linea);
        actividad.estado = linea.substr(8);
        getline(archivoNoIniciadas, linea);
        actividad.aforo = stoi(linea.substr(7));
        getline(archivoNoIniciadas, linea);
        actividad.fecha = linea.substr(7);
        getline(archivoNoIniciadas, linea);
        actividad.hora = linea.substr(6);
        getline(archivoNoIniciadas, linea);
        actividad.ubicacion = linea.substr(12);
        getline(archivoNoIniciadas, linea);
        actividad.ponente = linea.substr(10);
        getline(archivoNoIniciadas, linea);
        actividad.esPago = linea.substr(12);
        getline(archivoNoIniciadas, linea);
        actividad.precio = stof(linea.substr(8));
        getline(archivoNoIniciadas, linea);
        actividad.inscritos = stoi(linea.substr(11));
        getline(archivoNoIniciadas, linea);
        actividades.push_back(actividad);
    }

    while (getline(archivoEnCurso, linea))
    {
        Actividad actividad;
        actividad.id = stoi(linea.substr(4));
        getline(archivoEnCurso, linea);
        actividad.nombre = linea.substr(8);
        getline(archivoEnCurso, linea);
        actividad.descripcion = linea.substr(13);
        getline(archivoEnCurso, linea);
        actividad.tipo = linea.substr(6);
        getline(archivoEnCurso, linea);
        actividad.estado = linea.substr(8);
        getline(archivoEnCurso, linea);
        actividad.aforo = stoi(linea.substr(7));
        getline(archivoEnCurso, linea);
        actividad.fecha = linea.substr(7);
        getline(archivoEnCurso, linea);
        actividad.hora = linea.substr(6);
        getline(archivoEnCurso, linea);
        actividad.ubicacion = linea.substr(12);
        getline(archivoEnCurso, linea);
        actividad.ponente = linea.substr(10);
        getline(archivoEnCurso, linea);
        actividad.esPago = linea.substr(12);
        getline(archivoEnCurso, linea);
        actividad.precio = stof(linea.substr(8));
        getline(archivoEnCurso, linea);
        actividad.inscritos = stoi(linea.substr(11));
        getline(archivoEnCurso, linea);
        actividades.push_back(actividad);
    }

    while (getline(archivoFinalizadas, linea))
    {
        Actividad actividad;
        actividad.id = stoi(linea.substr(4));
        getline(archivoFinalizadas, linea);
        actividad.nombre = linea.substr(8);
        getline(archivoFinalizadas, linea);
        actividad.descripcion = linea.substr(13);
        getline(archivoFinalizadas, linea);
        actividad.tipo = linea.substr(6);
        getline(archivoFinalizadas, linea);
        actividad.estado = linea.substr(8);
        getline(archivoFinalizadas, linea);
        actividad.aforo = stoi(linea.substr(7));
        getline(archivoFinalizadas, linea);
        actividad.fecha = linea.substr(7);
        getline(archivoFinalizadas, linea);
        actividad.hora = linea.substr(6);
        getline(archivoFinalizadas, linea);
        actividad.ubicacion = linea.substr(12);
        getline(archivoFinalizadas, linea);
        actividad.ponente = linea.substr(10);
        getline(archivoFinalizadas, linea);
        actividad.esPago = linea.substr(12);
        getline(archivoFinalizadas, linea);
        actividad.precio = stof(linea.substr(8));
        getline(archivoFinalizadas, linea);
        actividad.inscritos = stoi(linea.substr(11));
        getline(archivoFinalizadas, linea);
        actividades.push_back(actividad);
    }

    archivoNoIniciadas.close();
    archivoEnCurso.close();
    archivoFinalizadas.close();
}

// Funcion que cree un fichero donde se incriba un usuario en una actividad solo no iniciada

void inscribirUsuario()
{
    int id;
    cout << "Ingrese el ID de la actividad no iniciada a la que desea inscribirse: ";
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
        cout << "No se encontró la actividad no iniciada con el ID " << id << ".\n";
        return;
    }

    if (it->estado != "No iniciado")
    {
        cout << "No se puede inscribir a una actividad que no esté no iniciada.\n";
        return;
    }

    ifstream archivoInscripciones("inscripciones.txt");

    if (!archivoInscripciones.is_open())
    {
        cout << "No se pudo abrir el archivo inscripciones.txt\n";
        return;
    }

    string linea;
    vector<Inscripcion> inscripciones;

    while (getline(archivoInscripciones, linea))
    {
        Inscripcion inscripcion;
        inscripcion.id = stoi(linea.substr(4));
        getline(archivoInscripciones, linea);
        inscripcion.idActividad = stoi(linea.substr(13));
        getline(archivoInscripciones, linea);
        inscripcion.nombre = linea.substr(8);
        getline(archivoInscripciones, linea);
        inscripcion.correo = linea.substr(8);
        getline(archivoInscripciones, linea);
        inscripcion.telefono = linea.substr(11);
        getline(archivoInscripciones, linea);
        inscripcion.fecha = linea.substr(7);
        getline(archivoInscripciones, linea);
        inscripcion.hora = linea.substr(6);
        getline(archivoInscripciones, linea);
        inscripcion.estado = linea.substr(8);
        getline(archivoInscripciones, linea);
        inscripcion.tipo = linea.substr(6);
        getline(archivoInscripciones, linea);
        inscripcion.ubicacion = linea.substr(12);
        getline(archivoInscripciones, linea);
        inscripcion.ponente = linea.substr(10);
        getline(archivoInscripciones, linea);
        inscripcion.esPago = linea.substr(12);
        getline(archivoInscripciones, linea);
        inscripcion.precio = stof(linea.substr(8));
        getline(archivoInscripciones, linea);
        inscripcion.inscritos = stoi(linea.substr(11));
        getline(archivoInscripciones, linea);
        inscripciones.push_back(inscripcion);
    }

    archivoInscripciones.close();

    for (const Inscripcion &inscripcion : inscripciones)
    {
        if (inscripcion.idActividad == id)
        {
            cout << "Ya estás inscrito en esta actividad.\n";
            return;
        }
    }

    Actividad &actividad = *it;

    Inscripcion inscripcion;

    if (inscripcion.inscritos == actividad.aforo)
    {
        cout << "No se puede inscribir a esta actividad porque ya está llena.\n";
        return;
    }

    inscripcion.id = obtenerSiguienteID();

    cout << "Nombre: ";
    cin.ignore();
    getline(cin, inscripcion.nombre);

    cout << "Correo: ";
    getline(cin, inscripcion.correo);

    cout << "Teléfono: ";
    getline(cin, inscripcion.telefono);

    if (actividad.esPago == "Sí")
    {
        cout << "Precio: " << actividad.precio << "€" << '\n';
        cout << "¿Desea pagar ahora? (S/N): ";
        char opcion;
        cin >> opcion;

        if (opcion == 'S' || opcion == 's')
        {
            cout << "Pago realizado exitosamente.\n";
        }
        else
        {
            cout << "No se puede inscribir a esta actividad porque no se ha realizado el pago.\n";
            return;
        }
    }

    inscripcion.idActividad = actividad.id;
    inscripcion.fecha = actividad.fecha;
    inscripcion.hora = actividad.hora;
    inscripcion.estado = actividad.estado;
    inscripcion.tipo = actividad.tipo;
    inscripcion.ubicacion = actividad.ubicacion;
    inscripcion.ponente = actividad.ponente;
    inscripcion.esPago = actividad.esPago;
    inscripcion.precio = actividad.precio;
    actividad.inscritos++;
    inscripcion.inscritos = actividad.inscritos;

    ofstream archivoInscripcion("inscripciones.txt", ios::app);

    if (!archivoInscripcion.is_open())
    {
        cout << "No se pudo abrir el archivo inscripciones.txt\n";
        return;
    }

    archivoInscripcion << "ID: " << inscripcion.id << '\n'
                       << "ID Actividad: " << inscripcion.idActividad << '\n'
                       << "Nombre: " << inscripcion.nombre << '\n'
                       << "Correo: " << inscripcion.correo << '\n'
                       << "Teléfono: " << inscripcion.telefono << '\n'
                       << "Fecha: " << inscripcion.fecha << '\n'
                       << "Hora: " << inscripcion.hora << '\n'
                       << "Estado: " << inscripcion.estado << '\n'
                       << "Tipo: " << inscripcion.tipo << '\n'
                       << "Ubicación: " << inscripcion.ubicacion << '\n'
                       << "Ponente: " << inscripcion.ponente << '\n'
                       << "Es de pago: " << inscripcion.esPago << '\n'
                       << "Precio: " << inscripcion.precio << "€" << '\n'
                       << "Inscritos: " << inscripcion.inscritos << '\n'
                       << "----------------------------------------\n";

    archivoInscripcion.close();
    cout << "Inscripción realizada exitosamente.\n";
}

// Funcion que desinscribe a un usuario de una actividad eliminandola del fichero inscripciones.txt y restando 1 al numero de inscritos

void desinscribirUsuario()
{
    int id;
    cout << "Ingrese el ID de la actividad a la que desea desinscribirse: ";
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

    if (it->estado != "No iniciado")
    {
        cout << "No se puede desinscribir a una actividad que no esté no iniciada.\n";
        return;
    }

    ifstream archivoInscripciones("inscripciones.txt");

    if (!archivoInscripciones.is_open())
    {
        cout << "No se pudo abrir el archivo inscripciones.txt\n";
        return;
    }

    string linea;
    vector<Inscripcion> inscripciones;

    while (getline(archivoInscripciones, linea))
    {
        Inscripcion inscripcion;
        inscripcion.id = stoi(linea.substr(4));
        getline(archivoInscripciones, linea);
        inscripcion.idActividad = stoi(linea.substr(13));
        getline(archivoInscripciones, linea);
        inscripcion.nombre = linea.substr(8);
        getline(archivoInscripciones, linea);
        inscripcion.correo = linea.substr(8);
        getline(archivoInscripciones, linea);
        inscripcion.telefono = linea.substr(11);
        getline(archivoInscripciones, linea);
        inscripcion.fecha = linea.substr(7);
        getline(archivoInscripciones, linea);
        inscripcion.hora = linea.substr(6);
        getline(archivoInscripciones, linea);
        inscripcion.estado = linea.substr(8);
        getline(archivoInscripciones, linea);
        inscripcion.tipo = linea.substr(6);
        getline(archivoInscripciones, linea);
        inscripcion.ubicacion = linea.substr(12);
        getline(archivoInscripciones, linea);
        inscripcion.ponente = linea.substr(10);
        getline(archivoInscripciones, linea);
        inscripcion.esPago = linea.substr(12);
        getline(archivoInscripciones, linea);
        inscripcion.precio = stof(linea.substr(8));
        getline(archivoInscripciones, linea);
        inscripcion.inscritos = stoi(linea.substr(11));
        getline(archivoInscripciones, linea);
        inscripciones.push_back(inscripcion);
    }

    archivoInscripciones.close();

    for (const Inscripcion &inscripcion : inscripciones)
    {
        if (inscripcion.idActividad == id)
        {
            cout << "Nombre: " << inscripcion.nombre << '\n'
                 << "Correo: " << inscripcion.correo << '\n'
                 << "Teléfono: " << inscripcion.telefono << '\n'
                 << "Fecha: " << inscripcion.fecha << '\n'
                 << "Hora: " << inscripcion.hora << '\n'
                 << "Estado: " << inscripcion.estado << '\n'
                 << "Tipo: " << inscripcion.tipo << '\n'
                 << "Ubicación: " << inscripcion.ubicacion << '\n'
                 << "Ponente: " << inscripcion.ponente << '\n'
                 << "Es de pago: " << inscripcion.esPago << '\n'
                 << "Precio: " << inscripcion.precio << "€" << '\n'
                 << "Inscritos: " << inscripcion.inscritos << '\n'
                 << "----------------------------------------\n";
        }
    }

    cout << "¿Está seguro de que desea desinscribirse de esta actividad? (s/n): ";
    char respuesta;
    cin >> respuesta;

    if (respuesta == 's')
    {
        ofstream archivoInscripcionesNuevo("inscripciones.txt");

        if (!archivoInscripcionesNuevo.is_open())
        {
            cout << "No se pudo abrir el archivo inscripciones.txt\n";
            return;
        }

        for (const Inscripcion &inscripcion : inscripciones)
        {
            if (inscripcion.idActividad != id)
            {
                archivoInscripcionesNuevo << "ID: " << inscripcion.id << '\n'
                                          << "ID Actividad: " << inscripcion.idActividad << '\n'
                                          << "Nombre: " << inscripcion.nombre << '\n'
                                          << "Correo: " << inscripcion.correo << '\n'
                                          << "Teléfono: " << inscripcion.telefono << '\n'
                                          << "Fecha: " << inscripcion.fecha << '\n'
                                          << "Hora: " << inscripcion.hora << '\n'
                                          << "Estado: " << inscripcion.estado << '\n'
                                          << "Tipo: " << inscripcion.tipo << '\n'
                                          << "Ubicación: " << inscripcion.ubicacion << '\n'
                                          << "Ponente: " << inscripcion.ponente << '\n'
                                          << "Es de pago: " << inscripcion.esPago << '\n'
                                          << "Precio: " << inscripcion.precio << "€" << '\n'
                                          << "Inscritos: " << inscripcion.inscritos << '\n'
                                          << "----------------------------------------\n";
            }
        }

        archivoInscripcionesNuevo.close();

        Actividad &actividad = *it;
        actividad.inscritos = actividad.inscritos - 1;
        guardarActividades();
        cout << "Desinscripción realizada exitosamente.\n";

        if (actividad.esPago == "Sí")
        {
            cout << "Se ha devuelto " << actividad.precio << "€ a su cuenta.\n";
        }
    }
    else
    {
        cout << "Desinscripción cancelada.\n";
    }
}

// Funcion que muestra las inscripciones de un usuario

void mostrarInscripcionesUsuario()
{
    ifstream archivoInscripciones("inscripciones.txt");

    if (!archivoInscripciones.is_open())
    {
        cout << "No se pudo abrir el archivo inscripciones.txt\n";
        return;
    }

    string linea;
    vector<Inscripcion> inscripciones;

    while (getline(archivoInscripciones, linea))
    {
        Inscripcion inscripcion;
        inscripcion.id = stoi(linea.substr(4));
        getline(archivoInscripciones, linea);
        inscripcion.idActividad = stoi(linea.substr(13));
        getline(archivoInscripciones, linea);
        inscripcion.nombre = linea.substr(8);
        getline(archivoInscripciones, linea);
        inscripcion.correo = linea.substr(8);
        getline(archivoInscripciones, linea);
        inscripcion.telefono = linea.substr(11);
        getline(archivoInscripciones, linea);
        inscripcion.fecha = linea.substr(7);
        getline(archivoInscripciones, linea);
        inscripcion.hora = linea.substr(6);
        getline(archivoInscripciones, linea);
        inscripcion.estado = linea.substr(8);
        getline(archivoInscripciones, linea);
        inscripcion.tipo = linea.substr(6);
        getline(archivoInscripciones, linea);
        inscripcion.ubicacion = linea.substr(12);
        getline(archivoInscripciones, linea);
        inscripcion.ponente = linea.substr(10);
        getline(archivoInscripciones, linea);
        inscripcion.esPago = linea.substr(12);
        getline(archivoInscripciones, linea);
        inscripcion.precio = stof(linea.substr(8));
        getline(archivoInscripciones, linea);
        inscripcion.inscritos = stoi(linea.substr(11));
        getline(archivoInscripciones, linea);
        inscripciones.push_back(inscripcion);
    }

    archivoInscripciones.close();

    cout << "Ingrese su correo: ";
    string correo;
    cin.ignore();
    getline(cin, correo);

    for (const Inscripcion &inscripcion : inscripciones)
    {
        if (inscripcion.correo == correo)
        {
            cout << "Nombre: " << inscripcion.nombre << '\n'
                 << "Correo: " << inscripcion.correo << '\n'
                 << "Teléfono: " << inscripcion.telefono << '\n'
                 << "Fecha: " << inscripcion.fecha << '\n'
                 << "Hora: " << inscripcion.hora << '\n'
                 << "Estado: " << inscripcion.estado << '\n'
                 << "Tipo: " << inscripcion.tipo << '\n'
                 << "Ubicación: " << inscripcion.ubicacion << '\n'
                 << "Ponente: " << inscripcion.ponente << '\n'
                 << "Es de pago: " << inscripcion.esPago << '\n'
                 << "Precio: " << inscripcion.precio << "€" << '\n'
                 << "Inscritos: " << inscripcion.inscritos << '\n'
                 << "----------------------------------------\n";
        }
    }
}

// funcion que recibe un id de actividad y un estado y modifica el estado de la actividad con ese id al estado recibido en el fichero de inscripciones

void modificarEstadoActividad(int id, string estado)
{
    ifstream archivoInscripciones("inscripciones.txt");

    if (!archivoInscripciones.is_open())
    {
        cout << "No se pudo abrir el archivo inscripciones.txt\n";
        return;
    }

    string linea;
    vector<Inscripcion> inscripciones;
    while (getline(archivoInscripciones, linea))
    {
        Inscripcion inscripcion;
        inscripcion.id = stoi(linea.substr(4));
        getline(archivoInscripciones, linea);
        inscripcion.idActividad = stoi(linea.substr(13));
        getline(archivoInscripciones, linea);
        inscripcion.nombre = linea.substr(8);
        getline(archivoInscripciones, linea);
        inscripcion.correo = linea.substr(8);
        getline(archivoInscripciones, linea);
        inscripcion.telefono = linea.substr(11);
        getline(archivoInscripciones, linea);
        inscripcion.fecha = linea.substr(7);
        getline(archivoInscripciones, linea);
        inscripcion.hora = linea.substr(6);
        getline(archivoInscripciones, linea);
        inscripcion.estado = linea.substr(8);
        getline(archivoInscripciones, linea);
        inscripcion.tipo = linea.substr(6);
        getline(archivoInscripciones, linea);
        inscripcion.ubicacion = linea.substr(12);
        getline(archivoInscripciones, linea);
        inscripcion.ponente = linea.substr(10);
        getline(archivoInscripciones, linea);
        inscripcion.esPago = linea.substr(12);
        getline(archivoInscripciones, linea);
        inscripcion.precio = stof(linea.substr(8));
        getline(archivoInscripciones, linea);
        inscripcion.inscritos = stoi(linea.substr(11));
        getline(archivoInscripciones, linea);
        inscripciones.push_back(inscripcion);
    }

    archivoInscripciones.close();

    ofstream archivoInscripcionesNuevo("inscripciones.txt");

    if (!archivoInscripcionesNuevo.is_open())
    {
        cout << "No se pudo abrir el archivo inscripciones.txt\n";
        return;
    }

    for (const Inscripcion &inscripcion : inscripciones)
    {
        if (inscripcion.idActividad == id)
        {
            archivoInscripcionesNuevo << "ID: " << inscripcion.id << '\n'
                                      << "ID Actividad: " << inscripcion.idActividad << '\n'
                                      << "Nombre: " << inscripcion.nombre << '\n'
                                      << "Correo: " << inscripcion.correo << '\n'
                                      << "Teléfono: " << inscripcion.telefono << '\n'
                                      << "Fecha: " << inscripcion.fecha << '\n'
                                      << "Hora: " << inscripcion.hora << '\n'
                                      << "Estado: " << estado << '\n'
                                      << "Tipo: " << inscripcion.tipo << '\n'
                                      << "Ubicación: " << inscripcion.ubicacion << '\n'
                                      << "Ponente: " << inscripcion.ponente << '\n'
                                      << "Es de pago: " << inscripcion.esPago << '\n'
                                      << "Precio: " << inscripcion.precio << "€" << '\n'
                                      << "Inscritos: " << inscripcion.inscritos << '\n'
                                      << "----------------------------------------\n";
        }

        else
        {
            archivoInscripcionesNuevo << "ID: " << inscripcion.id << '\n'
                                      << "ID Actividad: " << inscripcion.idActividad << '\n'
                                      << "Nombre: " << inscripcion.nombre << '\n'
                                      << "Correo: " << inscripcion.correo << '\n'
                                      << "Teléfono: " << inscripcion.telefono << '\n'
                                      << "Fecha: " << inscripcion.fecha << '\n'
                                      << "Hora: " << inscripcion.hora << '\n'
                                      << "Estado: " << inscripcion.estado << '\n'
                                      << "Tipo: " << inscripcion.tipo << '\n'
                                      << "Ubicación: " << inscripcion.ubicacion << '\n'
                                      << "Ponente: " << inscripcion.ponente << '\n'
                                      << "Es de pago: " << inscripcion.esPago << '\n'
                                      << "Precio: " << inscripcion.precio << "€" << '\n'
                                      << "Inscritos: " << inscripcion.inscritos << '\n'
                                      << "----------------------------------------\n";
        }

        archivoInscripcionesNuevo.close();
    }
}

// funcion que a partir del id de actividad crea una carpeta donde almacena un fichero por cada usuario inscrito en una actividad finalizada en el fichero inscripciones.txt, en el certificado se recoge el nombre, correo, telefono, fecha, hora, estado, tipo, ubicacion, ponente, es de pago, precio, inscritos y un mensaje de que ha participado en la actividad

void generarCertificados(const string &nombreUsuario)
{
    int id;
    cout << "Ingrese el ID de la actividad finalizada de la que desea generar los certificados: ";
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

    if (it->estado != "Finalizado")
    {
        cout << "No se puede generar certificados de una actividad que no esté finalizada.\n";
        return;
    }

    ifstream archivoInscripciones("inscripciones.txt");

    if (!archivoInscripciones.is_open())
    {
        cout << "No se pudo abrir el archivo inscripciones.txt\n";
        return;
    }

    string linea;
    vector<Inscripcion> inscripciones;

    while (getline(archivoInscripciones, linea))
    {
        Inscripcion inscripcion;
        inscripcion.id = stoi(linea.substr(4));
        getline(archivoInscripciones, linea);
        inscripcion.idActividad = stoi(linea.substr(13));
        getline(archivoInscripciones, linea);
        inscripcion.nombre = linea.substr(8);
        getline(archivoInscripciones, linea);
        inscripcion.correo = linea.substr(8);
        getline(archivoInscripciones, linea);
        inscripcion.telefono = linea.substr(11);
        getline(archivoInscripciones, linea);
        inscripcion.fecha = linea.substr(7);
        getline(archivoInscripciones, linea);
        inscripcion.hora = linea.substr(6);
        getline(archivoInscripciones, linea);
        inscripcion.estado = linea.substr(8);
        getline(archivoInscripciones, linea);
        inscripcion.tipo = linea.substr(6);
        getline(archivoInscripciones, linea);
        inscripcion.ubicacion = linea.substr(12);
        getline(archivoInscripciones, linea);
        inscripcion.ponente = linea.substr(10);
        getline(archivoInscripciones, linea);
        inscripcion.esPago = linea.substr(12);
        getline(archivoInscripciones, linea);
        inscripcion.precio = stof(linea.substr(8));
        getline(archivoInscripciones, linea);
        inscripcion.inscritos = stoi(linea.substr(11));
        getline(archivoInscripciones, linea);
        inscripciones.push_back(inscripcion);
    }

    archivoInscripciones.close();

    for (const Inscripcion &inscripcion : inscripciones)
    {
        if (inscripcion.idActividad == id)
        {
            string nombreCarpeta = "certificados/" + nombreUsuario;
            mkdir("certificados", 0777);
            mkdir(nombreCarpeta.c_str(), 0777);

            ofstream archivoCertificado(nombreCarpeta + "/certificado.txt");

            if (!archivoCertificado.is_open())
            {
                cout << "No se pudo abrir el archivo certificado.txt\n";
                return;
            }

            archivoCertificado << "Nombre: " << inscripcion.nombre << '\n'
                               << "Correo: " << inscripcion.correo << '\n'
                               << "Teléfono: " << inscripcion.telefono << '\n'
                               << "Fecha: " << inscripcion.fecha << '\n'
                               << "Hora: " << inscripcion.hora << '\n'
                               << "Estado: " << inscripcion.estado << '\n'
                               << "Tipo: " << inscripcion.tipo << '\n'
                               << "Ubicación: " << inscripcion.ubicacion << '\n'
                               << "Ponente: " << inscripcion.ponente << '\n'
                               << "Es de pago: " << inscripcion.esPago << '\n'
                               << "Precio: " << inscripcion.precio << "€" << '\n'
                               << "Inscritos: " << inscripcion.inscritos << '\n'
                               << "----------------------------------------\n"
                               << "Ha participado en la actividad " << inscripcion.idActividad << '\n'
                               << "----------------------------------------\n";

            archivoCertificado.close();
        }
    }

    cout << "Certificados generados exitosamente.\n";
}

// ver mis certificados generados pasandole el usuario como argumento

void verMisCertificados(const string &nombreUsuario)
{
    const string archivoUsuarios = "archivoUsuarios.txt";
    ifstream archivo(archivoUsuarios);
    string nombreUsuarioEnArchivo;

    if (!archivo.is_open())
    {
        cout << "\nError al abrir el archivo de usuarios." << endl;
        return;
    }

    string linea;
    while (getline(archivo, linea))
    {
        size_t pos = linea.find(",");
        nombreUsuarioEnArchivo = linea.substr(0, pos);

        if (nombreUsuarioEnArchivo == nombreUsuario)
        {
            break;
        }
    }

    archivo.close();

    if (nombreUsuarioEnArchivo.empty())
    {
        cout << "No se encontró el usuario " << nombreUsuario << endl;
        return;
    }

    ifstream archivoCertificado("certificados/" + nombreUsuario + "/certificado.txt");

    if (!archivoCertificado.is_open())
    {
        cout << "No se pudo abrir el archivo certificado.txt\n";
        return;
    }

    while (getline(archivoCertificado, linea))
    {
        cout << linea << '\n';
    }

    archivoCertificado.close();
}

// funcion de listadifusion que crea una carpeta donde almacena un fichero por facultad existente donde se almacenan los mensajes que se envien en cada una

void enviarListaDifusion()
{
    string facultad;

    int tipo = 0;

    do
    {
        cout << "Por favor, elija la facultad a la que desea enviar el mensaje: \n";
        cout << "1. Politécnica\n";
        cout << "2. Medicina\n";
        cout << "3. Derecho\n";
        cout << "4. Arte Dramático\n";
        cout << "5. Veterinaria\n";
        cout << "Ingrese el número correspondiente al estado: ";
        cin >> tipo;

    } while (tipo < 1 || tipo > 5);

    switch (tipo)
    {
    case 1:
        facultad = "Politécnica";
        break;
    case 2:
        facultad = "Medicina";
        break;
    case 3:
        facultad = "Derecho";
        break;
    case 4:
        facultad = "Arte Dramático";
        break;
    case 5:
        facultad = "Veterinaria";
        break;
    }

    string nombreCarpeta = "listadifusion/" + facultad;
    mkdir("listadifusion", 0777);       // Crear primero el directorio padre
    mkdir(nombreCarpeta.c_str(), 0777); // Luego crear el subdirectorio

    ofstream archivoMensaje(nombreCarpeta + "/mensaje.txt");

    if (!archivoMensaje.is_open())
    {
        cout << "No se pudo abrir el archivo mensaje.txt\n";
        return;
    }

    cout << "Ingrese el mensaje que desea enviar: ";
    string mensaje;
    cin.ignore();
    getline(cin, mensaje);

    // da formato al mensaje antes de guardarlo, pon fecha y hora, y separarlo por abajo con guiones

    time_t now = time(0);
    tm *ltm = localtime(&now);
    archivoMensaje << "Fecha: " << ltm->tm_mday << "/" << 1 + ltm->tm_mon << "/" << 1900 + ltm->tm_year << '\n';
    archivoMensaje << "Hora: " << ltm->tm_hour << ":" << ltm->tm_min << ":" << ltm->tm_sec << '\n';
    archivoMensaje << mensaje;
    archivoMensaje << "----------------------------------------\n";

    archivoMensaje.close();

    cout << "Mensaje enviado exitosamente.\n";
}

// funcion que lea el fichero de usuarios registrados y dependiendo de su facultad muestre los mensajes de difusion que se hayan enviado

void leerListaDifusion(const string &nombreUsuario)
{
    const string archivoUsuarios = "archivoUsuarios.txt";
    ifstream archivo(archivoUsuarios);
    string faculadUsuarioEnArchivo;

    if (!archivo.is_open())
    {
        cout << "\nError al abrir el archivo de usuarios." << endl;
        return;
    }

    string linea;
    while (getline(archivo, linea))
    {
        size_t pos = linea.find(",");
        string nombreUsuarioEnArchivo = linea.substr(0, pos);

        if (nombreUsuarioEnArchivo == nombreUsuario)
        {
            size_t pos2 = linea.find(",", pos + 1);
            string pwdUsuarioEnArchivo = linea.substr(pos + 1, pos2 - pos - 1);
            size_t pos3 = linea.find(",", pos2 + 1);
            string correoUsuarioEnArchivo = linea.substr(pos2 + 1, pos3 - pos2 - 1);
            size_t pos4 = linea.find(",", pos3 + 1);
            string rolUsuarioEnArchivo = linea.substr(pos3 + 1, pos4 - pos3 - 1);
            size_t pos5 = linea.find(",", pos4 + 1);
            faculadUsuarioEnArchivo = linea.substr(pos4 + 1, pos5 - pos4 - 1);
            break;
        }
    }

    archivo.close();

    if (faculadUsuarioEnArchivo.empty())
    {
        cout << "No se encontró el usuario " << nombreUsuario << endl;
        return;
    }

    string nombreCarpeta = "listadifusion/" + faculadUsuarioEnArchivo + "/mensaje.txt";

    ifstream archivoMensaje(nombreCarpeta);

    if (!archivoMensaje.is_open())
    {
        cout << "No se pudo abrir el archivo mensaje.txt\n";
        return;
    }

    while (getline(archivoMensaje, linea))
    {
        cout << linea << '\n';
    }

    archivoMensaje.close();
}


