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
    int opcionRegistrado;
    int opcionAdmin;
    string nombre;
    string contraseña;
    string correo;
    string rol;
    string mensaje;
    string idActividad;

    do
    {
        mostrarMenuVisitante();
        if (!(cin >> opcion))
        {
            cin.clear();                                         // Limpia el estado de error de cin
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Descarta la entrada incorrecta

            cout << "\nOpción no válida. Por favor, elige una opción válida.\n";
            continue; // Continúa con la siguiente iteración del bucle
        }

        switch (opcion)
        {
        case 1:
            cargarActividades();
            mostrarActividadesTotales();
            break;
        case 2:
            cout << "\nIniciar sesión...\n\n";
            cout << "Por favor, introduce tu nombre de usuario: ";
            cin >> nombre;
            cout << "Por favor, introduce tu contraseña: ";
            cin >> contraseña;
            if (!iniciarSesion(nombre, contraseña))
            {
                break;
            }
            do
            {
                mostrarMenuRegistrado();
                if (!(cin >> opcionRegistrado))
                {
                    cin.clear();                                         // Limpia el estado de error de cin
                    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Descarta la entrada incorrecta

                    cout << "\nOpción no válida. Por favor, elige una opción válida.\n";
                    continue; // Continúa con la siguiente iteración del bucle
                }

                switch (opcionRegistrado)
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
                    cout << "\nCerrando sesión...\n";
                    break;
                case 5:
                    cout << "\nSaliendo del sistema...\n\n";
                    exit(0);
                default:
                    cout << "\nOpción no válida. Por favor, intente de nuevo.\n";
                    continue;
                    // No hay break aquí para que el bucle continúe
                }
            } while (opcionRegistrado != 4);
            break;
        case 3:
            cout << "\nIniciar sesión...\n\n";
            cout << "Por favor, introduce tu nombre de admin: ";
            cin >> nombre;
            cout << "Por favor, introduce tu contraseña: ";
            cin >> contraseña;
            if (!iniciarSesionAdmin(nombre, contraseña))
            {
                break;
            }
            do
            {
                mostrarMenuAdmin();
                if (!(cin >> opcionAdmin))
                {
                    cin.clear();                                         // Limpia el estado de error de cin
                    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Descarta la entrada incorrecta

                    cout << "\nOpción no válida. Por favor, elige una opción válida.\n";
                    continue; // Continúa con la siguiente iteración del bucle
                }

                switch (opcionAdmin)
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
                    cout << "Por favor, introduce el nombre del usuario: ";
                    cin >> nombre;
                    cout << "Por favor, introduce el rol del usuario: ";
                    cin >> rol;
                    modificarRol(nombre, rol);
                    break;
                case 5:
                    cout << "Por favor, introduce el mensajea enviar: ";
                    cin >> mensaje;
                    enviarMensaje(mensaje);
                    break;
                case 6:
                    generarCertificado(nombre, idActividad);
                    enviarCertificado(nombre, idActividad);
                    break;
                case 7:
                    cout << "\nCerrando sesión...\n";
                    break;
                case 8:
                    cout << "\nSaliendo del sistema...\n\n";
                    exit(0);
                default:
                    cout << "\nOpción no válida. Por favor, intente de nuevo.\n";
                    continue;
                }
            } while (opcionAdmin != 7);
            break;
        case 4:
            cout << "\nRegistro...\n\n";
            cout << "Por favor, introduce tu nombre de usuario: ";
            cin >> nombre;
            cout << "Por favor, introduce tu contraseña: ";
            cin >> contraseña;
            cout << "Por favor, introduce tu correo: ";
            cin >> correo;
            registrarUsuario(nombre, contraseña, correo);
            break;
        case 5:
            cout << "\nSaliendo del sistema...\n\n";
            exit(0);
        default:
            cout << "\nOpción no válida. Por favor, intente de nuevo.\n";
            continue;
        }
    } while (opcion != 5); // El bucle continúa hasta que el usuario elige la opción para salir
    return 0;
}