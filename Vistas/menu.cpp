#include <iostream>
#include <limits>
#include "gestionarActividad.h"
#include "Inscripcion.h"
#include "ListaDifusion.h"
#include "Certificado.h"
<<<<<<< HEAD
#include "Usuario.h"
#include "menu.h"

=======
>>>>>>> main
using namespace std;

void mostrarMenuVisitante()
{
    cout << "\nBienvenido al sistema de gestión de actividades extracurriculares 'Visitante'\n\n";
    cout << "1. Ver actividades\n";
    cout << "2. Iniciar sesión\n";
<<<<<<< HEAD
    cout << "3. Iniciar sesión (Admin)\n";
    cout << "4. Registrarse\n";
    cout << "5. Salir\n\n";
=======
    cout << "3. Registrarse\n";
    cout << "4. Salir\n\n";
>>>>>>> main
    cout << "Seleccione una opción: ";
}

void mostrarMenuRegistrado()
{
<<<<<<< HEAD
    cout << "\nBienvenido al sistema de gestión de actividades extracurriculares 'Registrado'\n\n";
=======
    cout << "Bienvenido al sistema de gestión de actividades extracurriculares 'Registrado'\n\n";
>>>>>>> main
    cout << "1. Ver actividades\n";
    cout << "2. Inscribirse en actividad\n";
    cout << "3. Cancelar inscripción\n";
    cout << "4. Log out\n";
    cout << "5. Salir\n\n";
    cout << "Seleccione una opción: ";
}

void mostrarMenuAdmin()
{
<<<<<<< HEAD
    cout << "\nBienvenido al sistema de gestión de actividades extracurriculares 'Administrador'\n\n";
=======
    cout << "Bienvenido al sistema de gestión de actividades extracurriculares 'Administrador'\n\n";
>>>>>>> main
    cout << "1. Registrar actividad\n";
    cout << "2. Eliminar actividad\n";
    cout << "3. Modificar actividad\n";
    cout << "4. Modificar roles\n";
    cout << "5. Enviar lista de difusión\n";
    cout << "6. Generar certificado\n";
<<<<<<< HEAD
    cout << "7. Log out\n";
    cout << "8. Salir\n\n";
    cout << "Seleccione una opción: ";
}


=======
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

            cout << "Opción inválida. Por favor, elige una opción válida.\n";
            continue; // Continúa con la siguiente iteración del bucle
        }

        switch (opcion)
        {
        case 1:
            // Lógica para registrar actividad
            break;
        case 2:
            // Lógica para inscribirse en actividad
            break;
        case 3:
            cout << "Saliendo del sistema...\n";
            break;
        case 4:
            cout << "Salaiendo del sistema...\n";
            break;
        default:
            cout << "\nOpción no válida. Por favor, intente de nuevo.\n";
            // No hay break aquí para que el bucle continúe
        }
    } while (opcion != 4); // El bucle continúa hasta que el usuario elige la opción para salir
    return 0;
}
>>>>>>> main
