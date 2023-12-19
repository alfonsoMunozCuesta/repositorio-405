#include <iostream>
#include <string>
#include "gestor_usuarios.h"
#include "funciones.h"
using namespace std;

int main(int argc, char **argv)
{
    if (argc != 4)
    {
        cout << "Error al ejecutar el programa, debe introducir obligatoriamente el nombre de las bases de datos." << endl;
        cout << "Por ejemplo: <./a.out usuarios.txt actividades.txt inscripciones.txt>" << endl;
        exit(EXIT_FAILURE);
    }

    string nombreFicheroUsuarios(argv[1]);
    string nombreFicheroActividades(argv[2]);
    string nombreFicheroInscripciones(argv[3]);

    GestorUsuario usuarios(nombreFicheroUsuarios);
    cout << usuarios.getInfoUsuarios(rol_enum::USUARIO);

    int opcion;
    Usuario nuevo;
    string usuario, pass;
    string rol_usuario_logueado = "";

    do
    {
        opcion = menu();

        switch (opcion)
        {
        case 0:
            cout << "Saliendo..." << endl;
            break;

        case 1:
            cout << "Usuario: ";
            cin >> usuario;
            cout << "Contraseña: ";
            cin >> pass;
            if (usuarios.login(usuario, pass) == true)
            {
                cout << "Login realizado con éxito!" << endl;
                rol_usuario_logueado = usuarios.getRolUsuario(usuario);
                opcion = 0;
            }
            else
            {
                cout << "Error login!" << endl;
            }
            break;

        case 2:
            pedirDatosUsuario(nuevo);
            if (usuarios.altaUsuario(nuevo) == true)
            {
                cout << "Te has registrado con éxito!!" << endl;
            }
            else
            {
                cout << "Error al registrarte, el nombre de usuario ya existe." << endl;
            }
            break;

        default:
            cout << "Opción incorrecta, introduce una opción válida!" << endl;
            break;
        }

    } while (opcion != 0);

    if (rol_usuario_logueado == "ORGANIZADOR")
    {
        do
        {
            opcion = menuOrganizador();

            switch (opcion)
            {
            case 0:
                cout << "Saliendo..." << endl;
                break;

            case 1:
                break;

            case 2:
                break;
            }

        } while (opcion != 0);
    }
    else if(rol_usuario_logueado == "DIRECTOR_ACADEMICO")
    {

    }

    else if(rol_usuario_logueado == "USUARIO")
    {
        
    }

    exit(EXIT_SUCCESS);
}