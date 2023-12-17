#include <iostream>
#include <limits>
#include "gestionarActividad.h"
#include "Inscripcion.h"
#include "ListaDifusion.h"
#include "Certificado.h"
#include "Usuario.h"
using namespace std;

void mostrarMenuVisitante()
{
    cout << "\nBienvenido al sistema de gestión de actividades extracurriculares 'Visitante'\n\n";
    cout << "1. Ver actividades\n";
    cout << "2. Iniciar sesión\n";
    cout << "3. Registrarse\n";
    cout << "4. Salir\n\n";
    cout << "Seleccione una opción: ";
}

void mostrarMenuRegistrado()
{
    cout << "Bienvenido al sistema de gestión de actividades extracurriculares 'Registrado'\n\n";
    cout << "1. Ver actividades\n";
    cout << "2. Inscribirse en actividad\n";
    cout << "3. Cancelar inscripción\n";
    cout << "4. Log out\n";
    cout << "5. Salir\n\n";
    cout << "Seleccione una opción: ";
}

void mostrarMenuAdmin()
{
    cout << "Bienvenido al sistema de gestión de actividades extracurriculares 'Administrador'\n\n";
    cout << "1. Registrar actividad\n";
    cout << "2. Eliminar actividad\n";
    cout << "3. Modificar actividad\n";
    cout << "4. Modificar roles\n";
    cout << "5. Enviar lista de difusión\n";
    cout << "6. Generar certificado\n";
    cout << "7. Salir\n\n";
    cout << "Seleccione una opción: ";
}

int main()
{
    int opcion;
    do
    {
        mostrarMenuVisitante();
        
        if (!(cin >> opcion))
        {
            cin.clear();                                         // Limpia el estado de error de cin
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Descarta la entrada incorrecta

            cout << "\nOpción inválida. Por favor, elige una opción válida.\n";
            continue; // Continúa con la siguiente iteración del bucle
        }

        switch (opcion)
        {
        case 1:
            cargarActividades();
            mostrarActividadesTotales();
            break;
        case 2:
            // Lógica para inscribirse en actividad
            break;
        case 3:
            break;
        case 4:
            cout << "Saliendo del sistema...\n";
            break;
        default:
            cout << "\nOpción no válida. Por favor, intente de nuevo.\n";
            // No hay break aquí para que el bucle continúe
        }
    } while (opcion != 4); // El bucle continúa hasta que el usuario elige la opción para salir
    return 0;
}
