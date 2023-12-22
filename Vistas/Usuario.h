#ifndef USUARIO_H
#define USUARIO_H

#include <string>

using namespace std;

struct Usuario {
    string nombreUsuario;
    string contrasena;
    string rol; // Puede ser "visitante", "registrado", "director academico" u "organizador"
    string correo;
    string facultad;

};
    bool iniciarSesion(const string& nombre, const string& pwd);
    bool iniciarSesionAdmin(const string& nombre, const string& pwd);
    bool iniciarSesionDirectorAcademico(const string& nombre, const string& pwd);
    bool verificarExistenciaUsuario(const string &nombre, const string &nombreArchivo);
void registrarUsuario(const string& nombre, const string& pwd, const string& correo, const string& rol, const string& facultad, const string& nombreArchivo = "archivoUsuarios.txt");    void eliminarUsuario(const string& nombre);
    void modificarRol(const string& nombre, const string& rol);
    void mostrarUsuarios();


#endif // USUARIO_H
