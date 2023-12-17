#include <iostream>
#include <limits>
#include "gestionarActividad.h"
#include "Inscripcion.h"
#include "ListaDifusion.h"
#include "Certificado.h"
#include "Usuario.h"
#include "menu.h"
using namespace std;

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

            int opcion;
            do
            {
                mostrarMenuRegistrado();
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
                    cargarActividades();
                    inscribirseActividad();
                    guardarActividades();
                    break;
                case 3:
                    cargarActividades();
                    desinscribirseActividad();
                    guardarActividades();
                    break;
                case 4:
                    cout << "Log out...\n";
                    break;
                case 5:
                    cout << "Saliendo del sistema...\n";
                    exit(0);
                default:
                    cout << "\nOpción no válida. Por favor, intente de nuevo.\n";
                    // No hay break aquí para que el bucle continúe
                }
            } while (opcion != 5); // El bucle continúa hasta que el usuario elige la opción para salir
        case 3:
            int opcion;
            do
            {
                mostrarMenuAdmin();
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
                    crearActividad();
                    guardarActividades();
                    break;

                case 2:
                    cargarActividades();
                    eliminarActividad();
                    guardarActividades();
                    break;
                case 3:
                    cargarActividades();
                    editarActividad();
                    guardarActividades();
                    break;
                case 4:
                case 5:
                case 6:
                case 7:
                    cout << "Log out...\n";
                    break;
                case 8:
                    cout << "Saliendo del sistema...\n";
                    exit(0);
                default:
                    cout << "\nOpción no válida. Por favor, intente de nuevo.\n";
                    // No hay break aquí para que el bucle continúe
                }
            } while (opcion != 8); // El bucle continúa hasta que el usuario elige la opción para salir
        case 4:
        case 5:
            cout << "Saliendo del sistema...\n";
            exit(0);
        default:
            cout << "\nOpción no válida. Por favor, intente de nuevo.\n";
            // No hay break aquí para que el bucle continúe
        }
    } while (opcion != 5); // El bucle continúa hasta que el usuario elige la opción para salir
    return 0;
}