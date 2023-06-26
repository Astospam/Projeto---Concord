#include <iostream>
#include <string>
#include "Usuario.h"
#include "Servidor.h"
#include "Sistema.h"

using namespace std;

int main()
{   
    Sistema sistema;
    cout << "Bem vindo ao Concord!" << endl;
    string comando;
    string estado = "inicio";
    while(true)
    {
        cin >> comando;
//----------COMANDO QUIT-----------------------------------------------------
        if (comando == "quit")
        {
            cout << "Saindo da aplicação." <<endl;
            return 0;
        }
//------ESTADO INICIAL-------------------------------------------------------
        if (estado == "inicio")
        {
//----------COMANDO CREATE_USER----------------------------------------------
            if (comando == "create-user")
            {   
                string email, senha, nome;
                cin >> email;
                cin >> senha;
                cin.ignore();
                getline(cin, nome);
                if (sistema.verificarEmail(email) == true)
                {
                    sistema.setUsuario(Usuario(sistema.getUsuarios().size() + 1, email, senha, nome));
                    cout << "Usuário " + nome + " criado com sucesso." <<endl;
                }
                else
                {
                    cout << "O email " + email + " já está sendo usado." << endl;
                }
            }
//----------COMANDO LOGIN----------------------------------------------------
            else if (comando == "login")
            {
                string email, senha;
                cin >> email;
                cin >> senha;
                if (sistema.verificarLogin(email, senha) == true)
                {
                    sistema.setUsuarioLogado(sistema.getUsuario(email, senha));
                    estado = "logado";
                    cout << "Logado como " +  sistema.getUsuario(email, senha).getNome() + "."<< endl;
                }
                else
                {
                    cout << "Email ou senha incorretos." << endl;
                }
            }
//----------COMANDO INVÁLIDO------------------------------------------------
            else
            {
                string free;
                getline(cin, free);
                cout << "Comando inválido." <<endl;
            }
        }
//------ESTADO LOGADO--------------------------------------------------------
        else if(estado == "logado" || estado == "visualizado")
        {
//----------COMANDO DISCONNECT-----------------------------------------------
            if (comando == "disconnect")
            {
                estado = "inicio";
                cout << "Usuário " + sistema.getUsuarioLogado().getNome() + " desconectado." << endl;
                sistema.setUsuarioLogado(Usuario());
            }
//----------COMANDO CREATE-SERVER--------------------------------------------
            else if(comando == "create-server")
            {
                string nome;
                cin >> nome;
                if (sistema.verificarServidor(nome) == false)
                {
                    sistema.setServidor(Servidor(sistema.getUsuarioLogado().getId(), nome));
                    cout << "Servidor " + nome + " criado com sucesso." << endl;
                }
                else
                {
                    cout << "Já existe um servidor com este nome." << endl;
                }
            }
//----------COMANDO SET-SERVER-DESC------------------------------------------
            else if(comando == "set-server-desc")
            {
                string nome, descricao;
                cin >> nome;
                cin.ignore();
                getline(cin, descricao);
                if (sistema.verificarServidor(nome) == true)
                {
                    if (sistema.getServidor(nome).getUsuarioDonoId() == sistema.getUsuarioLogado().getId())
                    {
                        sistema.getServidor(nome).setDescricao(descricao);
                        cout << "Descrição alterada para " + descricao + "." << endl;
                    }
                    else
                    {
                        cout << "Apenas o dono do servidor pode alterar sua descrição." << endl;
                    }
                }
                else
                {
                    cout << "Não existe um servidor com esse nome." << endl;
                }
            }
//---------COMANDO SET-SERVER-INVITE-CODE----------------------------------
            else if(comando == "set-server-invite-code")
            {
                string nome, codigo, test;
                cin >> nome;
                getline(cin, codigo);
                codigo.erase(0,1);
                if (sistema.verificarServidor(nome) == true)
                {
                    if (sistema.getServidor(nome).getUsuarioDonoId() == sistema.getUsuarioLogado().getId())
                    {
                        sistema.getServidor(nome).setCodigoConvite(codigo);
                        if (codigo == "")
                        {
                            cout << "Código convite removido." << endl;
                        }
                        else
                        {
                            cout << "Código convite alterado para " + codigo + "." <<endl;
                        }
                    }
                    else
                    {
                        cout << "Apenas o dono do servidor pode alterar seu código convite." << endl;
                    }
                }
                else
                {
                    cout << "Não existe um servidor com esse nome." << endl;
                }
            }
//----------COMANDO LIST-SERVERS--------------------------------------------
            else if (comando == "list-servers")
            {
                int i;
                for (i=0;i<sistema.getServidores().size();i++)
                {
                    cout << sistema.getServidores()[i].getNome() << endl;
                }
            }
//----------COMANDO REMOVE-SERVER--------------------------------------------
            else if (comando == "remove-server")
            {
                string nome;
                cin >> nome;
                if (sistema.verificarServidor(nome) == true)
                {
                    if (sistema.getServidor(nome).getUsuarioDonoId() == sistema.getUsuarioLogado().getId())
                    {
                        sistema.removerServidor(nome);
                        cout << "Servidor " + nome + " removido." <<endl;
                    }
                    else
                    {
                        cout << "Apenas o dono do servidor pode remove-lo." << endl;
                    }
                }
                else
                {
                    cout << "Não existe um servidor com esse nome." << endl;
                }
            }
//----------COMANDO ENTER-SERVER--------------------------------------------
            else if (comando == "enter-server")
            {
                string nome;
                cin >> nome;
                if (sistema.verificarServidor(nome) == true)
                {
                    if (sistema.getServidor(nome).getCodigoConvite() == "" || sistema.getServidor(nome).getUsuarioDonoId() == sistema.getUsuarioLogado().getId())
                    {
                        sistema.setServidorVisualizado(sistema.getServidor(nome));
                        sistema.getServidorVisualizado().setParticipante(sistema.getUsuarioLogado().getId());
                        estado = "visualizando";
                        cout << "Visualizando servidor " + nome + "." << endl;
                    }   
                    else
                    {
                        string codigo;
                        cin >> codigo;
                        if (sistema.getServidor(nome).getCodigoConvite() == codigo)
                        {
                            sistema.setServidorVisualizado(sistema.getServidor(nome));
                            sistema.getServidorVisualizado().setParticipante(sistema.getUsuarioLogado().getId());
                            estado = "visualizando";
                            cout << "Visualizando servidor " + nome + "." << endl;
                        }
                        else
                        {
                            cout << "Código convite incorreto." << endl;
                        }
                    }
                }
                else
                {
                    cout << "Não existe um servidor com esse nome." << endl;
                }
            }
//----------COMANDO LEAVE-SERVER------------------------------------------------
            else if (comando == "leave-server" && estado == "visualizando")
            {
                estado = "logado";
                cout << "Usuário saiu do servidor " +  sistema.getServidorVisualizado().getNome() + "." << endl;
                sistema.setServidorVisualizado(Servidor());
            }    
//----------COMANDO LIST-PARTICIPANTS------------------------------------------------
            else if (comando == "list-participants" && estado == "visualizando")
            {
                int i;
                int id;
                cout << "Lista de Participantes do servidor " + sistema.getServidorVisualizado().getNome() + ":" << endl;
                for (i=0;i<sistema.getServidorVisualizado().getParticipantesIDs().size();i++)
                {
                    cout << sistema.getUsuarioFId(sistema.getServidorVisualizado().getParticipantesIDs()[i]).getNome() << endl;
                }
            }
//----------COMANDO INVÁLIDO------------------------------------------------
            else
            {
                string free;
                getline(cin, free);
                cout << "Comando inválido." <<endl;
            }
        }
    }

    return 0;
}