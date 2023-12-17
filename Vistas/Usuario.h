#ifndef USUARIO_H
#define USUARIO_H

#include <string>

using namespace std;

class Usuario {
    string nombreUsuario;
    string contrasena;
    string rol;
    string correo;

<<<<<<< HEAD

=======
>>>>>>> main
public:
    Usuario(const string& nombre, const string& pwd, const string& role, const string& correo);
    bool iniciarSesion(const string& nombre, const string& pwd);
    void cerrarSesion(const string& nombre);
<<<<<<< HEAD
    bool verificarExistenciaUsuario(const string& nombre) const;
=======
    bool verificarExistenciaUsuario(const string& nombre);
>>>>>>> main
    void registrarUsuario(const string& nombre, const string& pwd, const string& correo);
    // Agrega más funciones según sea necesario
};

#endif // USUARIO_H
