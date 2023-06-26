#include "Usuario.h"
#include <iostream>

using namespace std;

Usuario::Usuario()
{
    this->id = 0;
    this->nome = "";
    this->email = "";
    this->senha = "";
}

Usuario::Usuario(int id, string email, string senha, string nome)
{
    this->id = id;
    this->nome = nome;
    this->email = email;
    this->senha = senha;
}

int Usuario::getId()
{
    return this->id;
}

string Usuario::getNome()
{
    return this->nome;

}
string Usuario::getEmail()
{
    return this->email;
}

string Usuario::getSenha()
{
    return this->senha;
}