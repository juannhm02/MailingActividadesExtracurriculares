#include "../Vistas/Usuario.h"
#include "menu.h"
#include <iostream>
#include <fstream>
using namespace std;

// Ruta al archivo de usuarios
const string archivoUsuarios = "archivoUsuarios.txt";

// verificarExistenciaUsuario
bool verificarExistenciaUsuario(const string &nombre)
{
    ifstream archivo(archivoUsuarios);

    if (!archivo.is_open())
    {
        cout << "\nError al abrir el archivo de usuarios." << endl;
        return false;
    }

    string linea;
    while (getline(archivo, linea))
    {
        size_t pos = linea.find(",");
        string nombreUsuarioEnArchivo = linea.substr(0, pos);
        if (nombreUsuarioEnArchivo == nombre)
        {
            archivo.close();
            return true;
        }
    }

    archivo.close();
    return false;
}

// registarUsuario
void registrarUsuario(const string &nombre, const string &pwd, const string &correo, const string &rol, const string &facultad)
{
    if (verificarExistenciaUsuario(nombre))
    {
        cout << "\nEl usuario ya existe." << endl;
        return;
    }

    ofstream archivo(archivoUsuarios, ios::app);

    if (!archivo.is_open())
    {
        cout << "\nError al abrir el archivo de usuarios." << endl;
        return;
    }

    archivo << nombre << "," << pwd << "," << correo << "," << rol << "," << facultad << endl;
    archivo.close();
    cout << "\nUsuario registrado." << endl;
}

// modifcar Rol

void modificarRol(const string &nombre, const string &rol)
{
    if (!verificarExistenciaUsuario(nombre))
    {
        cout << "\nEl usuario no existe." << endl;
        return;
    }

    ifstream archivo(archivoUsuarios);
    ofstream archivoTemporal("archivoTemporal.txt");

    if (!archivo.is_open())
    {
        cout << "\nError al abrir el archivo de usuarios." << endl;
        return;
    }

    if (!archivoTemporal.is_open())
    {
        cout << "\nError al abrir el archivo temporal." << endl;
        return;
    }

    string linea;
    while (getline(archivo, linea))
    {
        size_t pos = linea.find(",");
        string nombreUsuarioEnArchivo = linea.substr(0, pos);
        if (nombreUsuarioEnArchivo != nombre)
        {
            archivoTemporal << linea << endl;
        }
        else
        {
            size_t pos2 = linea.find(",", pos + 1);
            size_t pos3 = linea.find(",", pos2 + 1);
            string pwd = linea.substr(pos + 1, pos2 - pos - 1);
            string correo = linea.substr(pos2 + 1, pos3 - pos2 - 1);
            archivoTemporal << nombre << "," << pwd << "," << correo << "," << rol << endl;
        }
    }

    archivo.close();
    archivoTemporal.close();

    remove(archivoUsuarios.c_str());
    rename("archivoTemporal.txt", archivoUsuarios.c_str());

    cout << "\nRol modificado." << endl;
}

// eliminarUsuario
void eliminarUsuario(const string &nombre)
{
    // Verificar si el usuario existe
    if (!verificarExistenciaUsuario(nombre))
    {
        cout << "\nEl usuario no existe." << endl;
        return;
    }

    // Eliminar el usuario
    ifstream archivo(archivoUsuarios);
    ofstream archivoTemporal("archivoTemporal.txt");

    if (!archivo.is_open())
    {
        cout << "\nError al abrir el archivo de usuarios." << endl;
        return;
    }

    if (!archivoTemporal.is_open())
    {
        cout << "\nError al abrir el archivo temporal." << endl;
        return;
    }

    string linea;
    while (getline(archivo, linea))
    {
        size_t pos = linea.find(",");
        string nombreUsuarioEnArchivo = linea.substr(0, pos);
        if (nombreUsuarioEnArchivo != nombre)
        {
            archivoTemporal << linea << endl;
        }
    }

    archivo.close();
    archivoTemporal.close();

    remove(archivoUsuarios.c_str());
    rename("archivoTemporal.txt", archivoUsuarios.c_str());

    cout << "\nUsuario eliminado." << endl;
}

// Iniciar sesión verificando existencia usuario

bool iniciarSesion(const string &nombre, const string &pwd)
{
    if (!verificarExistenciaUsuario(nombre))
    {
        cout << "\nEl usuario no existe." << endl;
        return false;
    }

    ifstream archivo(archivoUsuarios);

    if (!archivo.is_open())
    {
        cout << "\nError al abrir el archivo de usuarios." << endl;
        return false;
    }

    string linea;
    while (getline(archivo, linea))
    {
        size_t pos = linea.find(",");
        string nombreUsuarioEnArchivo = linea.substr(0, pos);
        size_t pos2 = linea.find(",", pos + 1);
        string pwdUsuarioEnArchivo = linea.substr(pos + 1, pos2 - pos - 1);
        if (nombreUsuarioEnArchivo == nombre && pwdUsuarioEnArchivo == pwd)
        {
            cout << "\nSesión iniciada." << endl;
            return true;
        }
    }

    archivo.close();
    cout << "\nContraseña incorrecta." << endl;
    return false;
}

// mostrarUsuarios

void mostrarUsuarios()
{
    ifstream archivo(archivoUsuarios);

    if (!archivo.is_open())
    {
        cout << "\nError al abrir el archivo de usuarios." << endl;
        return;
    }

    cout << "\nUsuarios registrados:" << endl;
    string linea;
    while (getline(archivo, linea))
    {
        size_t pos = linea.find(",");
        string nombreUsuarioEnArchivo = linea.substr(0, pos);
        cout << nombreUsuarioEnArchivo << endl;
    }

    archivo.close();
}

// Iniciar sesión (admin) verificando rol "Admin"

bool iniciarSesionAdmin(const string &nombre, const string &pwd)
{
    if (!verificarExistenciaUsuario(nombre))
    {
        cout << "\nEl usuario no existe." << endl;
        return false;
    }

    ifstream archivo(archivoUsuarios);

    if (!archivo.is_open())
    {
        cout << "\nError al abrir el archivo de usuarios." << endl;
        return false;
    }

    string linea;
    while (getline(archivo, linea))
    {
        size_t pos = linea.find(",");
        string nombreUsuarioEnArchivo = linea.substr(0, pos);
        size_t pos2 = linea.find(",", pos + 1);
        string pwdUsuarioEnArchivo = linea.substr(pos + 1, pos2 - pos - 1);
        size_t pos3 = linea.find(",", pos2 + 1);
        string correoUsuarioEnArchivo = linea.substr(pos2 + 1, pos3 - pos2 - 1);
        size_t pos4 = linea.find(",", pos3 + 1);
        string rolUsuarioEnArchivo = linea.substr(pos3 + 1, pos4 - pos3 - 1);
        if (nombreUsuarioEnArchivo == nombre && pwdUsuarioEnArchivo == pwd && rolUsuarioEnArchivo == "Admin")
        {
            cout << "\nSesión iniciada." << endl;
            return true;
        }
    }

    archivo.close();
    cout << "\nContraseña incorrecta." << endl;
    return false;
}

// Iniciar sesion (Director academico) verificando rol "Director Academico"
bool iniciarSesionDirectorAcademico(const string &nombre, const string &pwd)
{
    if (!verificarExistenciaUsuario(nombre))
    {
        cout << "\nEl usuario no existe." << endl;
        return false;
    }

    ifstream archivo(archivoUsuarios);

    if (!archivo.is_open())
    {
        cout << "\nError al abrir el archivo de usuarios." << endl;
        return false;
    }

    string linea;
    while (getline(archivo, linea))
    {
        size_t pos = linea.find(",");
        string nombreUsuarioEnArchivo = linea.substr(0, pos);
        size_t pos2 = linea.find(",", pos + 1);
        string pwdUsuarioEnArchivo = linea.substr(pos + 1, pos2 - pos - 1);
        size_t pos3 = linea.find(",", pos2 + 1);
        string correoUsuarioEnArchivo = linea.substr(pos2 + 1, pos3 - pos2 - 1);
        size_t pos4 = linea.find(",", pos3 + 1);
        string rolUsuarioEnArchivo = linea.substr(pos3 + 1, pos4 - pos3 - 1);
        if (nombreUsuarioEnArchivo == nombre && pwdUsuarioEnArchivo == pwd && rolUsuarioEnArchivo == "Director Academico")
        {
            cout << "\nSesión iniciada." << endl;
            return true;
        }
    }

    archivo.close();
    cout << "\nContraseña incorrecta." << endl;
    return false;
}








