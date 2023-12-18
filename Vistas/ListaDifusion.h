#ifndef LISTADIFUSION_H
#define LISTADIFUSION_H

#include <vector>
#include <string>

using namespace std;

struct ListaDifusion {
    vector<string> emails;

};

    void agregarEmail(const string& email);
    void enviarMensaje(const string& mensaje);
    // Agregar más funciones según sea necesario


#endif // LISTADIFUSION_H
