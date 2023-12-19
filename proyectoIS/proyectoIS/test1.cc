#include "gestor_usuarios.h"
#include "gtest/gtest.h"
#include <string>
using namespace std;

TEST(GestorUsuarios, AltaUsuario)
{
	GestorUsuario gestor("usuarios.txt");
	srand(time(NULL));
	string nombreRandom = "usuario" + to_string(rand()%10000);
	EXPECT_FALSE(gestor.existeUsuario(nombreRandom));
	Usuario u;
	u.setUsuario(nombreRandom);
	u.setNombre("Nombre de prueba");
	u.setPass("1111prueba");
	EXPECT_TRUE(gestor.altaUsuario(u));
	EXPECT_FALSE(gestor.altaUsuario(u));
	EXPECT_TRUE(gestor.existeUsuario(nombreRandom));
}


