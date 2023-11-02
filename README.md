IDENTIFICAÇÃO

NOME: ILO BENEVIDES DE MIRANDA CAVALCANTI
MATRÍCULA: 20220065108
TURMA: 01

COMPILANDO E RODANDO O PROGRAMA:

Iremos compilar e rodar o código usando o Cmake e o g++, então para esse método precisaremos de ambos instalados na máquina.

Primeiramente acesse no terminal a pasta build que estará vazia, e digite <cmake ..>, após isso use o comando make para compilar os arquivos do cmake.
Basta agora executar o executável criado com o comando < ./program>, caso usando algum script de texto usaremos < ./program < script.txt (tenha certeza de que o script se encontra na mesma
pasta que o exécutavel).

COMANDOS:

Sem estar logado:
1. quit -> Sai do programa finalizando sua execução.
2. create-user -> Cria um usuário e é acompanhado de 3 parâmetros, email, senha e nome. Caso já exista um usuário com o mesmo email o novo usuário não poderá ser criado.
3. login -> Loga no sistema e é acompanhado de 2 parâmetros, email e senha. O usuário só loga no sistema caso ele já tenha sido criado e possua os mesmos parâmetros informados.

Após o Login:
1. disconnect -> Sai do estado de logado e volta ao estado inicial.
2. create-server -> Cria um servidor e é acompanhado do parâmetro nome. Caso já exista um servidor com o mesmo nome o novo servidor não pode ser criado, o usuário que criou o
servidor recebe o cargo de dono do servidor.
3. set-server-desc -> Altera ou adiciona (caso não possua) uma descrição ao servidor e é acompanhado de 2 parâmetros, nome e descrição. Caso não exista um servidor com o nome
informado, ou o usuário atualmente logado não seja o dono do servidor, a ação não pode ser realizada.
4. set-server-invite-code -> Altera, adiciona ou remove o código convite do servidor e é acompanhado de 1 ou 2 parâmetros, nome e código convite(opcional). Caso o código não seja informado
o código atual é removido e ele fica aberto para qualquer um entrar. Caso não exista um servidor com o nome
informado, ou o usuário atualmente logado não seja o dono do servidor, a ação não pode ser realizada.
5. list-server -> Lista os servidores existentes no momento.
6. remove-server -> Remove um servidor e é acompanhado do parâmetro nome. Caso não exista um servidor com o nome
informado, ou o usuário atualmente logado não seja o dono do servidor, a ação não pode ser realizada.
7. enter-server -> Entra em um servidor existente e começa a visualiza-lo é acompanhado de 1 ou 2 parâmetros, nome e código convite(opcional). Caso o usuário seja o dono do servidor ou o servidor não possua um
código convite, ele pode entrar apenas com o nome, pelo contrario é nescessario o código convite do servidor. Caso não exista um servidor com o nome
informado a ação não pode ser realizada.
8. leave-server -> Sai de um servidor que você esteja visualizando no momento.
9. list-participants -> Lista todos os participantes do servidor visualizado no momento.

LIMITAÇÕES:
Ao dar um comando sem um dos parâmetros nescessarios para ele funcionar o programa irá aguardar a entrada na próxima linha, podendo ser um problema quando lendo um script, mas caso todos os parâmentros sejam
informados o programa funciona perfeitamente.

DIFICULDADES:
Existiram algumas dificuldades quanto a forma de ler as entradas, principamente relativo ao código convite, que foi consertada, mas após isso foi percebido o problema informado nas limitações.
Fora isso as funções foram feitas de forma bem fluida e funcional, apesar do excesso delas e o tamanho do main.

OBS:
Ao compilar o programa existirão 3 Avisos de funções que podem não retornar um valor caso certo elemento não exista, porém sempre antes de chama-las no código é feito a verificação desse elemento previamente
sendo impossível na prática esse erro ocorrer.
