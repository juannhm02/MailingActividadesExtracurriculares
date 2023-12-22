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

void limpiarArchivoUsuariosTest() {
    ofstream archivo("usuarios_test.txt", ios::trunc);
    archivo.close();
}



void testBuscarActividadPorID_Existente() {
    
    Actividad act;
    act.id = 1;
    act.nombre = "Actividad de prueba";
    act.descripcion = "Descripción de prueba";
    act.tipo = "Tipo de prueba";
    act.estado = "Estado de prueba";
    act.aforo = 10;
    act.fecha = "Fecha de prueba";
    act.hora = "Hora de prueba";
    act.ubicacion = "Ubicación de prueba";
    act.ponente = "Ponente de prueba";
    act.esPago = "Pago de prueba";
    act.precio = 100;
    act.inscritos = 0;

    crearActividadConDatos(act);
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
    limpiarArchivoUsuariosTest();
    ofstream archivo("usuarios_test.txt");
    archivo << "usuario_existente,contraseña,correo,rol,facultad\n";
    archivo.close();
    assert(verificarExistenciaUsuario("usuario_existente", "usuarios_test.txt") == true);
}

void testVerificarExistenciaUsuario_UsuarioNoExiste() {
    limpiarArchivoUsuariosTest();
    ofstream archivo("usuarios_test.txt");
    archivo << "usuario_existente,contraseña,correo,rol,facultad\n";
    archivo.close();
    assert(verificarExistenciaUsuario("usuario_no_existente", "usuarios_test.txt") == false);
}

void testRegistrarUsuario_UsuarioNuevo() {
    limpiarArchivoUsuariosTest();
    registrarUsuario("nuevo_usuario", "contraseña", "correo", "rol", "facultad", "usuarios_test.txt");
    ifstream archivoVerificar("usuarios_test.txt");
    string contenido;
    getline(archivoVerificar, contenido);
    assert(contenido == "nuevo_usuario,contraseña,correo,rol,facultad");
    archivoVerificar.close();
}

void testRegistrarUsuario_UsuarioExistente() {
    limpiarArchivoUsuariosTest();
    // Primero, registra un usuario para asegurarte de que exista
    registrarUsuario("usuario_existente", "contraseña", "correo", "rol", "facultad", "usuarios_test.txt");

    // Redirecciona el stream de salida
    stringstream buffer;
    streambuf *old = cout.rdbuf(buffer.rdbuf());

    // Intenta registrar el mismo usuario de nuevo
    registrarUsuario("usuario_existente", "contraseña", "correo", "rol", "facultad", "usuarios_test.txt");
    
    // Restaura el stream de salida original
    cout.rdbuf(old);

    // Comprueba si el mensaje esperado está en el buffer
    assert(buffer.str().find("El usuario ya existe") != string::npos);
}


int main() {
    testBuscarActividadPorID_Existente();
    testBuscarActividadPorID_NoExistente();
    testBuscarActividadPorID_LimiteInferior();
    testBuscarActividadPorID_LimiteSuperior();
    testVerificarExistenciaUsuario_UsuarioExiste();
    testVerificarExistenciaUsuario_UsuarioNoExiste();
    testRegistrarUsuario_UsuarioNuevo();
    testRegistrarUsuario_UsuarioExistente();

    cout << "TODAS LAS PRUEBAS HAN SIDO PASADAS CON ÉXITO. ENHORABUENA!!!" << endl;
    return 0;
}