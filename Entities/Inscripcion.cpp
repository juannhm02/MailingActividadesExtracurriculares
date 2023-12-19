#include "Inscripcion.h"

using namespace std;

// Verifica el aforo de una actividad
bool verificarAforo(const string& archivoInscripciones, int actividadId, int aforoMaximo) 
{
    ifstream file(archivoInscripciones);
    string line;
    int contador = 0;
    if (!file.is_open()) 
    {
        cerr << "Error al abrir el archivo de inscripciones." << endl;
        return false;
    }
    while (getline(file, line)) 
    {
        stringstream ss(line);
        int id;
        ss >> id; // Suponiendo que el primer elemento es el ID de la actividad
        if (id == actividadId) 
        {
            contador++;
        }
    }
    file.close();
    return contador < aforoMaximo;
}

// Solicita el pago de una actividad
bool solicitarPago() 
{
    char respuesta;
    cout << "¿Ha realizado el pago? (s/n): ";
    cin >> respuesta;
    return respuesta == 's' || respuesta == 'S';
}

// Inscribir a un usuario a una actividad
void inscribirEnActividad(const string& archivoInscripciones, const Inscripcion& inscripcion) 
{
    if (!verificarAforo(archivoInscripciones, inscripcion.actividad.id, inscripcion.actividad.aforo)) 
    {
        cout << "Aforo completo para la actividad " << inscripcion.actividad.nombre << endl;
        return;
    }

    ofstream file(archivoInscripciones, ios::app);
    if (file.is_open()) 
    {
        file << inscripcion.actividad.id << " " << inscripcion.usuario.nombreUsuario << " " << inscripcion.usuario.correo << " " << inscripcion.pagoRealizado << endl;
        file.close();
    } 
    else 
    {
        cerr << "Error al abrir el archivo de inscripciones." << endl;
    }
}


//Desinscribir a un usuario de una actividad
void desinscribirEnActividad(const string& archivoInscripciones, const Usuario& usuario, int actividadId) 
{
    ifstream fileIn(archivoInscripciones);
    if (!fileIn.is_open()) 
    {
        cerr << "Error al abrir el archivo de inscripciones para desinscribir." << endl;
        return;
    }

    vector<string> inscripciones;
    string line;
    bool inscripcionEncontrada = false;


    while (getline(fileIn, line)) 
    {
        stringstream ss(line);
        int id;
        string nombreUsuario;
        ss >> id >> nombreUsuario;
        
        // Comprueba si la línea corresponde a la inscripción a eliminar
        if (id == actividadId && nombreUsuario == usuario.nombreUsuario) 
        {
            inscripcionEncontrada = true;
            continue; // No añadir esta línea al vector
        }
        inscripciones.push_back(line);
    }
    fileIn.close();

    if (!inscripcionEncontrada) 
    {
        cout << "Inscripción no encontrada." << endl;
        return;
    }

    // Reescribir el archivo sin la inscripción eliminada
    ofstream fileOut(archivoInscripciones);
    if (!fileOut.is_open()) 
    {
        cerr << "Error al abrir el archivo de inscripciones para actualizar." << endl;
        return;
    }

    for (const auto& inscripcion : inscripciones) 
    {
        fileOut << inscripcion << endl;
    }
    fileOut.close();

    cout << "Desinscripción realizada con éxito." << endl;
}


//Mostrar inscripciones de un usuario
void mostrarInscripcionesUsuario(const string& archivoInscripciones, const string& nombreUsuario) 
{
    ifstream file(archivoInscripciones);
    if (!file.is_open()) 
    {
        cerr << "Error al abrir el archivo de inscripciones." << endl;
        return;
    }

    string line;
    bool inscripcionesEncontradas = false;
    while (getline(file, line)) 
    {
        stringstream ss(line);
        int id;
        string nombreUsuarioInscripcion;
        string correoUsuarioInscripcion;
        bool pagoRealizado;
        ss >> id >> nombreUsuarioInscripcion >> correoUsuarioInscripcion >> pagoRealizado;
        if (nombreUsuarioInscripcion == nombreUsuario) 
        {
            inscripcionesEncontradas = true;
            cout << "Actividad: " << id << endl;
            cout << "Nombre de usuario: " << nombreUsuarioInscripcion << endl;
            cout << "Correo: " << correoUsuarioInscripcion << endl;
            cout << "Pago realizado: " << (pagoRealizado ? "Sí" : "No") << endl;
            cout << endl;
        }
    }
    file.close();

    if (!inscripcionesEncontradas) 
    {
        cout << "No se encontraron inscripciones para el usuario " << nombreUsuario << endl;
    }
}