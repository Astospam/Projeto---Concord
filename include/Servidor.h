#ifndef SERVIDOR_H
#define SERVIDOR_H
#include <iostream>
#include <vector>

using namespace std;

class Servidor
{
    private:
        int usuarioDonoId;
        string nome;
        string descricao;
        string codigoConvite;
        vector<int> participantesIDs;
    public:
        Servidor();
        Servidor(int usuarioDonoId, string nome);
        string getNome();
        string getCodigoConvite();
        vector<int> getParticipantesIDs();
        int getUsuarioDonoId();
        void setDescricao(string descricao);
        void setCodigoConvite(string codigoConvite);
        void setParticipante(int id);
};

#endif