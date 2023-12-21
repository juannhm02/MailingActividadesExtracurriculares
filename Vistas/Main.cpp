#include <iostream>
#include <limits>
#include <string>

#include "gestionarActividad.h"
#include "Usuario.h"
#include "menu.h"

vector<string> facultadesAdicionales;

using namespace std;

  bool esCorreoValido(const string &correo){
        size_t arrobaPos = correo.find('@');
        size_t puntoPos = correo.find('.', arrobaPos);

        // Verificar que el correo contiene '@' y un punto después del '@'
            if (arrobaPos == string::npos || puntoPos == string::npos || puntoPos <= arrobaPos)
            {
                return false;
            }

            // Verificar la longitud del correo
            if (correo.empty() || correo.length() > 255)
            {
                return false;
            }

            return true;
        }

int main()
{
    cargarActividades();
    int opcion;
    int opcionRegistrado;
    int opcionAdmin;
    int opcionDirectorAcademico;
    string nombre;
    string nombreRegistrado;
    string nombreAdmin;
    string nombreDirectorAcademico;
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
        
//:TODO:------------------------------------------------------------------------------------
        //Inicio de sesión
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
        
//:TODO:------------------------------------------------------------------------------------
        //Inicio de sesión de administrador
        case 5:
            cout << "\nIniciar sesión...\n\n";
            cout << "Por favor, introduce tu nombre de admin: ";
            cin >> nombre;
            nombreAdmin = nombre;
            cout << "Por favor, introduce tu contraseña: ";
            cin >> contraseña;
            if (!iniciarSesionAdmin(nombreAdmin, contraseña))
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

//:TODO:------------------------------------------------------------------------------------
        //Inicio de sesion de Director Academico
        case 6:
            cout << "\nIniciar sesión...\n\n";
            cout << "Por favor, introduce tu nombre de admin: ";
            cin >> nombre;
            nombreDirectorAcademico = nombre;
            cout << "Por favor, introduce tu contraseña: ";
            cin >> contraseña;
            
            if (!iniciarSesionDirectorAcademico(nombreDirectorAcademico, contraseña))
            {
                break;
            }
            do
            {
                mostrarMenuDirectorAcademico();
                if (!(cin >> opcionDirectorAcademico))
                {
                    cin.clear();                                         // Limpia el estado de error de cin
                    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Descarta la entrada incorrecta

                    cout << "\nOpción no válida. Por favor, elige una opción válida.\n";
                    continue; // Continúa con la siguiente iteración del bucle
                }

                switch (opcionDirectorAcademico)
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
                    enviarListaDifusion();
                    break;
                case 8:
                    cout << "\nCerrando sesión...\n";
                    break;
                case 9:
                    cout << "\nSaliendo del sistema...\n\n";
                    exit(0);
                default:
                    cout << "\nOpción no válida. Por favor, intente de nuevo.\n";
                    continue;
                }
            } while (opcionAdmin != 9);
            break;

//:TODO:------------------------------------------------------------------------------------
        //Registro
        case 7:
            cout << "\nRegistro...\n\n";
            cout << "Por favor, introduce tu nombre de usuario: ";
            cin >> nombre;
            cout << "Por favor, introduce tu contraseña: ";
            cin >> contraseña;
            cout << "Por favor, introduce tu correo: ";
            cin >> correo;

            while (!esCorreoValido(correo)) {
                cout << "Correo inválido. Por favor, introduce un correo válido: ";
                cin >> correo;
            }

            do
            {
                cout << "Por favor, elija su facultad: \n";
                cout << "1. Politécnica\n";
                cout << "2. Medicina\n";
                cout << "3. Derecho\n";
                cout << "4. Arte Dramático\n";
                cout << "5. Veterinaria\n";
                cout << "6. Especifique su facultad (si no es ninguna de las anteriores):\n";
                cout << "Ingrese el número correspondiente al estado: ";
                cin >> tipo;

            } while (tipo < 1 || tipo > 6);

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
            case 6:
                cout << "Por favor, introduzca su facultad: ";
                cin.ignore(); // Ignorar el salto de línea
                getline(cin, facultad);
                string facultadNormalizada = normalizarString(facultad);
                    if (find(facultadesAdicionales.begin(), facultadesAdicionales.end(), facultadNormalizada) == facultadesAdicionales.end()) {
                        facultadesAdicionales.push_back(facultadNormalizada);
                    }
            break;
            }

            registrarUsuario(nombre, contraseña, correo, "Estudiante", facultad);
            break;
        case 8:
            cout << "\nSaliendo del sistema...\n\n";
            exit(0);
        default:
            cout << "\nOpción no válida. Por favor, intente de nuevo.\n";
            continue;
        }
    } while (opcion != 8); // El bucle continúa hasta que el usuario elige la opción para salir
    return 0;
}