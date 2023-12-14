#include <iostream>
#include "gestionarActividad.h"
#include "Inscripcion.h"
#include "ListaDifusion.h"
#include "Certificado.h"

void mostrarMenu() {
    std::cout << "Bienvenido al sistema de gestión de actividades extracurriculares\n";
    std::cout << "1. Registrar actividad\n";
    std::cout << "2. Inscribirse en actividad\n";
    std::cout << "3. Enviar lista de difusión\n";
    std::cout << "4. Generar certificado\n";
    std::cout << "5. Salir\n";
    std::cout << "Seleccione una opción: ";
}

int main() {
    int opcion;
    mostrarMenu();
    std::cin >> opcion;
    
    switch(opcion) {
        case 1:
            // Lógica para registrar actividad
            break;
        case 2:
            // Lógica para inscribirse en actividad
            break;
        case 3:
            // Lógica para enviar lista de difusión
            break;
        case 4:
            // Lógica para generar certificado
            break;
        case 5:
            std::cout << "Saliendo del sistema...\n";
            break;
        default:
            std::cout << "Opción no válida. Por favor, intente de nuevo.\n";
    }
    return 0;
}
