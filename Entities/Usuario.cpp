#include "Usuario.h"
<<<<<<< HEAD
#include "menu.h"
#include <iostream>
#include <fstream>
=======
#include <iostream>
>>>>>>> main
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

<<<<<<< HEAD
// Iniciar sesión
bool Usuario::iniciarSesion(const string& nombre, const string& pwd) {
    if (nombre == nombreUsuario && pwd == contrasena) {
        cout << "Inicio de sesión exitoso." << endl;
        return true;
    } else {
        cout << "Nombre de usuario o contraseña incorrectos." << endl;
        return false;
    }
}

// Cerrar sesión
void Usuario::cerrarSesion(const string& nombre) {
    cout << "Sesión cerrada." << endl;
    mostrarMenuVisitante();
    // Implementa la lógica para cerrar la sesión
    
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
=======
// // Iniciar sesión
// bool Usuario::iniciarSesion(const string& nombre, const string& pwd) {
//     if (nombre == nombreUsuario && pwd == contrasena) {
//         cout << "Inicio de sesión exitoso." << endl;
//         return true;
//     } else {
//         cout << "Nombre de usuario o contraseña incorrectos." << endl;
//         return false;
//     }
// }

// // Cerrar sesión
// void Usuario::cerrarSesion(const string& nombre) {
//     cout << "Sesión cerrada." << endl;
//     // Implementa la lógica para cerrar la sesión
    
// }
// bool Usuario::verificarExistenciaUsuario(const string& nombre) const {
//     ifstream archivo(archivoUsuarios);

//     if (!archivo.is_open()) {
//         cout << "Error al abrir el archivo de usuarios." << endl;
//         return false;
//     }

//     string linea;
//     while (getline(archivo, linea)) {
//         size_t pos = linea.find(",");
//         string nombreUsuarioEnArchivo = linea.substr(0, pos);
//         if (nombreUsuarioEnArchivo == nombre) {
//             archivo.close();
//             return true; // Usuario encontrado
//         }
//     }

//     archivo.close();
//     return false; // Usuario no encontrado
// }

// void Usuario::registrarUsuario(const string& nombre, const string& pwd, const string& correo) {
//     // Verificar si el usuario ya existe
//     if (Usuario::verificarExistenciaUsuario(nombre)) {
//         cout << "El usuario ya existe." << endl;
//         return;
//     }

//     // Crear un nuevo objeto Usuario
//     Usuario nuevoUsuario(nombre, pwd, "RolPorDefecto", correo);

//     // Abrir el archivo en modo de escritura al final
//     ofstream archivo(archivoUsuarios, ios::app);

//     if (!archivo.is_open()) {
//         cout << "Error al abrir el archivo de usuarios." << endl;
//         return;
//     }

//     archivo << nuevoUsuario.nombreUsuario << "," << nuevoUsuario.contrasena << "," << nuevoUsuario.rol << "," << nuevoUsuario.correo << endl;
//     archivo.close();

//     cout << "Usuario registrado exitosamente." << endl;
// }
>>>>>>> main

