#include <cassert> // Necesario para assert
#include <iostream>
#include "gestionarActividad.h"


using namespace std;



void testBuscarActividadPorID_Existente() {
    
    crearActividadConDatos();
    // crea una actividad y rellena sus campos con datos de prueba
    assert(buscarActividadPorID(1) == true); // Debe retornar verdadero si la actividad existe
}

void testBuscarActividadPorID_NoExistente() {
    
    assert(buscarActividadPorID(999) == false); // Debe retornar falso si la actividad no existe
}

void testBuscarActividadPorID_LimiteInferior() {
    
    assert(buscarActividadPorID(0) == false); // Asumiendo que los IDs son positivos y comienzan en 1
}

void testBuscarActividadPorID_LimiteSuperior() {
    
    // Asumiendo que el ID más alto en las actividades de prueba es 2
    assert(buscarActividadPorID(3) == false); // Debe retornar falso si se busca un ID mayor al más alto existente
}

// Este es un ejemplo de cómo ejecutar las pruebas.
int main() {
    testBuscarActividadPorID_Existente();
    testBuscarActividadPorID_NoExistente();
    testBuscarActividadPorID_LimiteInferior();
    testBuscarActividadPorID_LimiteSuperior();

    cout << "Todas las pruebas pasaron exitosamente." << endl;
    return 0;
}
