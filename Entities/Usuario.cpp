#include "Usuario.h"
#include "menu.h"
#include <iostream>
#include <fstream>
using namespace std;

// Ruta al archivo de usuarios
const string archivoUsuarios = "archivoUsuarios.txt";

// Implementación del constructor de Usuario
Usuario::Usuario(const string& nombre, const string& pwd, const string& role, const string& correo) {
    nombreUsuario = nombre;
    contrasena = pwd;
    rol = role;
    this->correo = correo;
}

bool Usuario::verificarExistenciaUsuario(const string& nombre) const {
    ifstream archivo(archivoUsuarios);

    if (!archivo.is_open()) {
        cout << "Error al abrir el archivo de usuarios." << endl;
        return false;
    }

    string linea;
    while (getline(archivo, linea)) {
        size_t pos = linea.find(",");
        string nombreUsuarioEnArchivo = linea.substr(0, pos);
        if (nombreUsuarioEnArchivo == nombre) {
            archivo.close();
            return true; // Usuario encontrado
        }
    }

    archivo.close();
    return false; // Usuario no encontrado
}

// Iniciar sesión
bool Usuario::iniciarSesion(const string& nombre, const string& pwd) {
    //llama a la funcion verificarExistenciaUsuario y si es true, entonces verifica la contraseña
    if (!verificarExistenciaUsuario(nombre)) {
        cout << "El usuario no existe." << endl;
        return false;
    }

    ifstream archivo(archivoUsuarios);

    if (!archivo.is_open()) {
        cout << "Error al abrir el archivo de usuarios." << endl;
        return false;
    }

    string linea;
    while (getline(archivo, linea)) {
        size_t pos = linea.find(",");
        string nombreUsuarioEnArchivo = linea.substr(0, pos);
        if (nombreUsuarioEnArchivo == nombre) {
            size_t pos2 = linea.find(",", pos + 1);
            string pwdEnArchivo = linea.substr(pos + 1, pos2 - pos - 1);
            if (pwdEnArchivo == pwd) {
                archivo.close();
                cout << "Inicio de sesión exitoso." << endl;
                return true; // Contraseña correcta
            } else {
                archivo.close();
                cout << "Contraseña incorrecta." << endl;
                return false; // Contraseña incorrecta
            }
        }
    }
}

// Cerrar sesión
void Usuario::cerrarSesion(const string& nombre) {
    cout << "Sesión cerrada." << endl;
    mostrarMenuVisitante();
    // Implementa la lógica para cerrar la sesión
    
 }

void Usuario::registrarUsuario(const string& nombre, const string& pwd, const string& correo) {
    // Verificar si el usuario ya existe
    if (Usuario::verificarExistenciaUsuario(nombre)) {
        cout << "El usuario ya existe." << endl;
        return;
    }

    // Crear un nuevo objeto Usuario
    Usuario nuevoUsuario(nombre, pwd, "RolPorDefecto", correo);

    // Abrir el archivo en modo de escritura al final
    ofstream archivo(archivoUsuarios, ios::app);

    if (!archivo.is_open()) {
        cout << "Error al abrir el archivo de usuarios." << endl;
        return;
    }

    archivo << nuevoUsuario.nombreUsuario << "," << nuevoUsuario.contrasena << "," << nuevoUsuario.rol << "," << nuevoUsuario.correo << endl;
    archivo.close();

    cout << "Usuario registrado exitosamente." << endl;
}

