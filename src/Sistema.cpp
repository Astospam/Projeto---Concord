#include <iostream>
#include <vector>
#include "Sistema.h"

Sistema::Sistema()
{   
}

void Sistema::setUsuario(Usuario usuario)
{
    usuarios.push_back(usuario);
}

void Sistema::setServidor(Servidor servidor)
{
    servidores.push_back(servidor);
}

void Sistema::setUsuarioLogado(Usuario usuario)
{
    usuarioLogado = usuario;
}

void Sistema::setServidorVisualizado(Servidor servidor)
{
    servidorVisualizado = servidor;
}

Usuario Sistema::getUsuario(string email, string senha)
{
    int i;
    for (i = 0; i<usuarios.size(); i++)
    {
        if (email == usuarios[i].getEmail() && senha == usuarios[i].getSenha())
        {
            return usuarios[i];
        }
    }
}

Usuario Sistema::getUsuarioFId(int id)
{
        int i;
    for (i = 0; i<usuarios.size(); i++)
    {
        if (id == usuarios[i].getId())
        {
            return usuarios[i];
        }
    }
}

vector<Usuario> Sistema::getUsuarios()
{
    return this->usuarios;
}

vector<Servidor> Sistema::getServidores()
{
    return this->servidores;
}

Usuario Sistema::getUsuarioLogado()
{
    return this->usuarioLogado;
}

Servidor Sistema::getServidorVisualizado()
{
    return this->servidorVisualizado;
}

bool Sistema::verificarEmail(string email)
{   
    int i;
    for (i = 0; i<usuarios.size(); i++)
    {
        if (email == usuarios[i].getEmail())
        {
            return false;
        }
    }
    return true;
}

bool Sistema::verificarLogin(string email, string senha)
{
    int i;
    for (i = 0; i<usuarios.size(); i++)
    {
        if (email == usuarios[i].getEmail() && senha == this->usuarios[i].getSenha())
        {
            return true;
        }
    }
    return false;
}

bool Sistema::verificarServidor(string nome)
{
    int i;
    for (i = 0; i<servidores.size(); i++)
    {
        if (nome == servidores[i].getNome())
        {
            return true;
        }
    }
    return false;
}

Servidor Sistema::getServidor(string nome)
{
    int i;
    for (i = 0; i<servidores.size(); i++)
    {
        if (nome == servidores[i].getNome())
        {
            return servidores[i];
        }
    }
}

void Sistema::removerServidor(string nome)
{
    int i;
    for (i = 0; i<servidores.size(); i++)
    {
        if (nome == servidores[i].getNome())
        {
            servidores.erase(servidores.begin()+ i);
        }
    }
}