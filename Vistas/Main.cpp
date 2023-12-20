#include <iostream>
#include <limits>
#include <string>
#include "gestionarActividad.h"
#include "Inscripcion.h"
#include "ListaDifusion.h"
#include "Certificado.h"
#include "Usuario.h"
#include "menu.h"
using namespace std;

int main()
{
    cargarActividades();
    int opcion;
    int opcionRegistrado;
    int opcionAdmin;
    string nombre;
    string nombreRegistrado;
    string nombreAdmin;
    string contraseña;
    string correo;
    string rol;
    string facultad;
    int tipo = 0;

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
            mostrarActividadesNoIniciadas();
            break;
        case 2:
            mostrarActividadesEnCurso();
            break;
        case 3:
            mostrarActividadesFinalizadas();
            break;
        case 4:
            cout << "\nIniciar sesión...\n\n";
            cout << "Por favor, introduce tu nombre de usuario: ";
            cin >> nombre;
            nombreRegistrado = nombre;
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

                    mostrarActividadesNoIniciadas();
                    break;

                case 2:

                    mostrarActividadesEnCurso();
                    break;

                case 3:

                    mostrarActividadesFinalizadas();
                    break;

                case 4:

                    inscribirUsuario();

                    break;
                case 5:

                    desinscribirUsuario();

                    break;
                case 6:

                    mostrarInscripcionesUsuario();

                    break;
                case 7:

                    leerListaDifusion(nombreRegistrado);

                    break;
                    case 8: 
                    verMisCertificados(nombreRegistrado);
                    break;

                case 9:
                    cout << "\nCerrando sesión...\n";
                    break;
                case 10:
                    cout << "\nSaliendo del sistema...\n\n";
                    exit(0);
                default:
                    cout << "\nOpción no válida. Por favor, intente de nuevo.\n";
                    continue;
                    // No hay break aquí para que el bucle continúe
                }
            } while (opcionRegistrado != 9);
            break;
        case 5:
            cout << "\nIniciar sesión...\n\n";
            cout << "Por favor, introduce tu nombre de admin: ";
            cin >> nombre;
            nombreAdmin = nombre;
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

                    mostrarActividadesNoIniciadas();

                    break;
                case 2:

                    mostrarActividadesEnCurso();

                    break;
                case 3:

                    mostrarActividadesFinalizadas();

                    break;

                case 4:

                    crearActividad();

                    break;

                case 5:

                    eliminarActividad();

                    break;
                case 6:

                    editarActividad();

                    break;
                case 7:
                    cout << "Por favor, introduce el nombre del usuario: ";
                    cin >> nombre;
                    cout << "Por favor, introduce el rol del usuario: ";
                    cin >> rol;
                    modificarRol(nombre, rol);
                    break;
                case 8:
                    enviarListaDifusion();
                    break;
                case 9:
                    generarCertificados(nombreAdmin);
                    break;
                case 10:

                    mostrarUsuarios();
                    break;
                case 11:
                    cout << "\nCerrando sesión...\n";
                    break;
                case 12:
                    cout << "\nSaliendo del sistema...\n\n";
                    exit(0);
                default:
                    cout << "\nOpción no válida. Por favor, intente de nuevo.\n";
                    continue;
                }
            } while (opcionAdmin != 11);
            break;
        case 6:
            cout << "\nRegistro...\n\n";
            cout << "Por favor, introduce tu nombre de usuario: ";
            cin >> nombre;
            cout << "Por favor, introduce tu contraseña: ";
            cin >> contraseña;
            cout << "Por favor, introduce tu correo: ";
            cin >> correo;

            do
            {
                cout << "Por favor, elija su facultad: \n";
                cout << "1. Politécnica\n";
                cout << "2. Medicina\n";
                cout << "3. Derecho\n";
                cout << "4. Arte Dramático\n";
                cout << "5. Veterinaria\n";
                cout << "Ingrese el número correspondiente al estado: ";
                cin >> tipo;

            } while (tipo < 1 || tipo > 5);

            switch (tipo)
            {
            case 1:
                facultad = "Politécnica";
                break;
            case 2:
                facultad = "Medicina";
                break;
            case 3:
                facultad = "Derecho";
                break;
            case 4:
                facultad = "Arte Dramático";
                break;
            case 5:
                facultad = "Veterinaria";
                break;
            }

            registrarUsuario(nombre, contraseña, correo, "Estudiante", facultad);
            break;
        case 7:
            cout << "\nSaliendo del sistema...\n\n";
            exit(0);
        default:
            cout << "\nOpción no válida. Por favor, intente de nuevo.\n";
            continue;
        }
    } while (opcion != 7); // El bucle continúa hasta que el usuario elige la opción para salir
    return 0;
}