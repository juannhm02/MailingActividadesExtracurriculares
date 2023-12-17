#include "ListaDifusion.h"
#include <iostream>
#include <string>

using namespace std;

void ListaDifusion::agregarEmail(const string& email) {
    emails.push_back(email);
}

void ListaDifusion::enviarMensaje(const string& mensaje) {
    for (const auto& email : emails) {
        cout << "Enviando mensaje a " << email << ": " << mensaje << endl;
    }
}
