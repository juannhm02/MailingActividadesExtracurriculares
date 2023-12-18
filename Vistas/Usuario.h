#ifndef USUARIO_H
#define USUARIO_H

#include <string>

using namespace std;

struct Usuario {
    string nombreUsuario;
    string contrasena;
    string rol;
    string correo;

};
    bool iniciarSesion(const string& nombre, const string& pwd);
    void cerrarSesion(const string& nombre);
    bool verificarExistenciaUsuario(const string& nombre);
    void registrarUsuario(const string& nombre, const string& pwd, const string& correo);
    void modificarRol(const string& nombre, const string& rol);


#endif // USUARIO_H
