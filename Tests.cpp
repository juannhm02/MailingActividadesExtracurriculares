#include <cassert> // Necesario para assert
#include <iostream>
#include <cassert>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>
#include <iomanip>
#include <ctime>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cctype>
#include <cmath>
#include <limits>

#include "gestionarActividad.h"
#include "Usuario.h"


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

void testVerificarExistenciaUsuario_UsuarioExiste() {
    ofstream archivo("usuarios_test.txt", ios::trunc); // Crea o limpia el archivo
    archivo << "usuario_existente,contraseña,correo,rol,facultad\n";
    archivo.close();

    assert(verificarExistenciaUsuario("usuario_existente") == true);
}

void testVerificarExistenciaUsuario_UsuarioNoExiste() {
    ofstream archivo("usuarios_test.txt", ios::trunc);
    archivo << "usuario_existente,contraseña,correo,rol,facultad\n";
    archivo.close();

    assert(verificarExistenciaUsuario("usuario_no_existente") == false);
}

void testRegistrarUsuario_UsuarioNuevo() {
    ofstream archivo("usuarios_test.txt", ios::trunc);
    archivo.close();

    registrarUsuario("nuevo_usuario", "contraseña", "correo", "rol", "facultad");
    ifstream archivoVerificar("usuarios_test.txt");
    string contenido;
    getline(archivoVerificar, contenido);
    assert(contenido == "nuevo_usuario,contraseña,correo,rol,facultad");
    archivoVerificar.close();
}

void testRegistrarUsuario_UsuarioExistente() {
    ofstream archivo("usuarios_test.txt", ios::trunc);
    archivo << "usuario_existente,contraseña,correo,rol,facultad\n";
    archivo.close();

    // Redirecciona el stream de salida para capturar el mensaje de consola
    stringstream buffer;
    streambuf *old = cout.rdbuf(buffer.rdbuf());

    registrarUsuario("usuario_existente", "contraseña", "correo", "rol", "facultad");
    
    // Restaura el stream de salida original
    cout.rdbuf(old);

    assert(buffer.str().find("El usuario ya existe") != string::npos);
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
