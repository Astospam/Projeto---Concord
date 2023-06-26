#ifndef USUARIO_H
#define USUARIO_H
#include <iostream>

using namespace std;

class Usuario
{
    private:
        int id;
        string nome;
        string email;
        string senha;
    public:
        Usuario();
        Usuario(int id, string email, string senha, string nome);
        int getId();
        string getNome();
        string getEmail();
        string getSenha();
};


#endif
