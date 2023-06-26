#ifndef SISTEMA_H
#define SISTEMA_H
#include <iostream>
#include <vector>
#include "Usuario.h"
#include "Servidor.h"

using namespace std;

class Sistema
{
    private:
        vector<Usuario> usuarios;
        vector<Servidor> servidores;
        Usuario usuarioLogado;
        Servidor servidorVisualizado;
    public:
        Sistema();
        void setUsuario(Usuario usuario);
        void setServidor(Servidor servidor);
        void setUsuarioLogado(Usuario usuario);
        void setServidorVisualizado(Servidor servidor);
        Usuario getUsuario(string email, string senha);
        Usuario getUsuarioFId(int id);
        vector<Usuario> getUsuarios();
        vector<Servidor> getServidores();
        Usuario getUsuarioLogado();
        Servidor getServidorVisualizado();
        bool verificarEmail(string email);
        bool verificarLogin(string email, string senha);
        bool verificarServidor(string nome);
        Servidor getServidor(string nome);
        void removerServidor(string nome);
};

#endif