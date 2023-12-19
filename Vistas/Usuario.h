#ifndef USUARIO_H
#define USUARIO_H

#include <string>

using namespace std;

struct Usuario {
    string nombreUsuario;
    string contrasena;
    string rol; // Puede ser "visitante", "registrado", "director academico" o "admin"
    string correo;

};
    bool iniciarSesion(const string& nombre, const string& pwd);
    bool iniciarSesionAdmin(const string& nombre, const string& pwd);
    bool verificarExistenciaUsuario(const string& nombre);
    void registrarUsuario(const string& nombre, const string& pwd, const string& correo);
    void eliminarUsuario(const string& nombre);
    void modificarRol(const string& nombre, const string& rol);
    void mostrarUsuarios();


#endif // USUARIO_H
