#include "ListaDifusion.h"
#include <iostream>

void ListaDifusion::agregarEmail(const std::string& email) {
    emails.push_back(email);
}

void ListaDifusion::enviarMensaje(const std::string& mensaje) {
    for (const auto& email : emails) {
        std::cout << "Enviando mensaje a " << email << ": " << mensaje << std::endl;
    }
}
