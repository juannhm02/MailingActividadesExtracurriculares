#ifndef USUARIO_H
#define USUARIO_H

#include <string>

class Usuario {
    std::string nombreUsuario;
    std::string contrasena;
    std::string rol;

public:
    Usuario(const std::string& nombre, const std::string& pwd, const std::string& role);
    bool iniciarSesion(const std::string& nombre, const std::string& pwd);
    void cerrarSesion();
    void registrarUsuario();
    // Agrega más funciones según sea necesario
};

#endif // USUARIO_H
