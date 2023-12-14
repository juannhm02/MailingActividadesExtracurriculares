#ifndef LISTADIFUSION_H
#define LISTADIFUSION_H

#include <vector>
#include <string>

class ListaDifusion {
    std::vector<std::string> emails;

public:
    void agregarEmail(const std::string& email);
    void enviarMensaje(const std::string& mensaje);
    // Agregar más funciones según sea necesario
};

#endif // LISTADIFUSION_H
