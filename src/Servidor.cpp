#include <iostream>
#include "Servidor.h"

Servidor::Servidor()
{
    this->usuarioDonoId = 0;
    this->nome = "";
    this->descricao = "";
    this->codigoConvite = "";
}

Servidor::Servidor(int usuarioDonoId, string nome)
{
    this->usuarioDonoId = usuarioDonoId;
    this->nome = nome;
}

string Servidor::getNome()
{
    return this->nome;
}

string Servidor::getCodigoConvite()
{
    return this->codigoConvite;
}

int Servidor::getUsuarioDonoId()
{
    return this->usuarioDonoId;
}

vector<int> Servidor::getParticipantesIDs()
{
    return this-> participantesIDs;
}

void Servidor::setDescricao(string descricao)
{
    this->descricao = descricao;
}

void Servidor::setCodigoConvite(string codigoConvite)
{
    this->codigoConvite = codigoConvite;
}

void Servidor::setParticipante(int id)
{
    participantesIDs.push_back(id);
}

