#ifndef FUNCIONES_H
#define FUNCIONES_H

#include <iostream>
using namespace std;
#include "usuario.h"

int menu()
{
    cout << "***********************************" << endl;
    cout << "            MENÚ PRINCIPAL" << endl;
    cout << "***********************************" << endl;
    cout << "1) Login" << endl;
    cout << "2) Registrarme" << endl;
    cout << "3) Mostrar actividades" << endl;
    cout << "0) SALIR" << endl;
    cout << "***********************************" << endl;
    cout << "Introduce el número de la opción deseada: ";
    int opcion;
    cin >> opcion;
    return opcion;
}

int menuOrganizador()
{
    cout << "***********************************" << endl;
    cout << "            MENÚ ORGANIZADOR" << endl;
    cout << "***********************************" << endl;
    cout << "1) Crear actividad" << endl;
    cout << "2) Modificar actividad" << endl;
    cout << "3) Mostrar actividades" << endl;
    cout << "0) SALIR" << endl;
    cout << "***********************************" << endl;
    cout << "Introduce el número de la opción deseada: ";
    int opcion;
    cin >> opcion;
    return opcion;
}

void pedirDatosUsuario(Usuario &nuevo)
{
    string usuario, nombre, pass;
    cout << "Introduce tu nombre de usuario: ";
    cin >> usuario;
    cout << "Introduce tu nombre completo: ";
    getchar();
    getline(cin,nombre);
    cout << "Introduce la contraseña: ";
    cin >> pass;
    nuevo.setUsuario(usuario);
    nuevo.setNombre(nombre);
    nuevo.setPass(pass);
    nuevo.setRol(rol_enum::USUARIO);
    nuevo.setEstado(estado_usuario_enum::VISITANTE);
}

#endif