#include <stdio.h>
#include <locale.h> //permite utilizar pontuacao sem dar erro
#include <string.h> //comparar textos strcmp

#define MAX_LIVROS 50 // numero maximo de livros q o sistema pode guardar

int main(){

    setlocale(LC_ALL, "Portuguese");  //atua com locale.h

    //criar variaveis pros livros
    char livro[MAX_LIVROS][200]; //matriz
    char autor[MAX_LIVROS][200];
    char isbn[MAX_LIVROS][50];
    int estoque[MAX_LIVROS][3] = {0};  //vetor
    float preco[MAX_LIVROS];

    int indiceAtual = 0; //o primeiro livro cadastrado vai para a posição 0
    int posicaoLivro = 0; //acessar a posição dos livros

    int resposta = 0;
    int local;
    int totalLivros[3] = {0};
    int totalAposRetirada[3] = {0};
    int contaRetirada[3] = {0};

    int resposta2;
    int respostaSaida;

    //registrar quant livros entrando
    char isbnDigitado[50];
    int quantidade;

    //variavel para cadastrar logins
    char usuarioCadastro[50] = "";
    char senhaCadastro[50]= "";
    int resp;
    //variavel para entrar logins
    char usuarioLogin[50] = "";
    char senhaLogin[50] = "";

    //usar while pros menu de login
    int loginCerto = 0;

    //LOGIN
    while (loginCerto == 0){

        printf("\n===========================================\n");
        printf("SISTEMA DE ESTOQUE PONTO & VIRGULA LOGIN\n");
        printf("===========================================\n");
        printf("1 - Cadastrar funcionário\n"
                "2 - Entrar");
        printf("\nEscolha o número da opção desejada: ");
        scanf("%i", &resp);

        if (resp == 1){
            printf("\nInsira o nome do seu usuário: ");
            scanf("%50s", &usuarioCadastro);

            printf("Insira a sua nova senha: ");
            scanf("%50s", &senhaCadastro);

            printf("Cadastrado! \n");

            printf("\n--Faça seu login agora--\n");
            printf("Usuário: ");
            scanf("%50s", usuarioLogin);

            printf("Senha: ");
            scanf("%50s", senhaLogin);

            //vai comparar se o usuarioLogin é igual o usuarioCadastro e se for vai prosseguir
            if (strcmp(usuarioLogin, usuarioCadastro) == 0 && strcmp(senhaLogin, senhaCadastro) == 0) {
                printf("\nConcluido! Prosseguindo..\n");
                //informa ao while que o login foi concluído
                loginCerto = 1;
            } else {
                printf("\nUsuário ou senha incorreta!\n");

            }
        }

        else if (resp == 2){

            printf("\nUsuário: ");
            scanf("%50s", &usuarioLogin);

            printf("Senha: ");
            scanf("%50s", &senhaLogin);

            //vai comparar se o usuarioLogin é igual o usuarioCadastro e se for vai prosseguir
            if (strcmp(usuarioLogin, usuarioCadastro) == 0 && strcmp(senhaLogin, senhaCadastro) == 0) {
                printf("\nLogin realizado com sucesso!\n");
                //informa ao while que o login foi concluído
                loginCerto = 1;
        }

            else{
                printf("\nUsuário ou senha incorreta!\n");
        }
    }
        else {
            printf("Opção inválida.\n");
        }
    }

    // fazer menu da livraria

    while (resposta <= 4){

    printf("\n ===== PONTO & VÍRGULA EDITORA E LIVRARIA SISTEMA DE ESTOQUE ===== \n");
    printf("\n1 - Cadastrar entrada de livros\n"
        "2 - Registrar entrada de estoque\n"
        "3 - Registrar saída/venda\n"
        "4 - Consultar estoque\n"
        "5 - Sair\n");

    printf("\nEscolha o número correspondente ao qual você deseja acessar: ");
    scanf("%i", &resposta);


        //--------------------------------------------
        if (resposta == 1){
            if (indiceAtual >= MAX_LIVROS) {
                printf("\nErro: Limite máximo de %i livros cadastrados atingido!\n", MAX_LIVROS);
                continue;
            }

            printf("\nOnde o livro será cadastrado?\n");
            printf("1 - Loja física\n"
            "2 - Loja online\n"
            "3 - Loja central\n"
            "4 - Sair\n");
            printf("Escolha o número da opção desejada: ");
            scanf("%d", &local);

            if (local == 1){
                printf("\n ===ESTOQUE LOJA FÍSICA=== \n");

                printf("Insira o nome do livro: ");
                //leia tudo, exceto o Enter.
                scanf(" %199[^\n]s", &livro[indiceAtual]);
                printf("Insira o nome do autor: ");
                scanf(" %199[^\n]s", &autor[indiceAtual]);
                printf("Insira o ISBN-13 do livro: ");
                scanf("%50s", &isbn[indiceAtual]);
                printf("Insira a quantidade de livros que irá entrar para o estoque: ");
                scanf("%i", &estoque[indiceAtual][0]);

                printf("Insira o preço do livro: ");
                scanf("%f", &preco[indiceAtual]);

                totalLivros[0] = totalLivros[0] + estoque[indiceAtual][0];

                //string pois vamos usar mais que uma letra
                printf("\n--------------------------------------------------------------------------");
                printf("\nLivro cadastrado: %s\n", livro[indiceAtual]);
                //printf("\nLivro cadastrado no ID [%i]: %s\n", indiceAtual, livro[indiceAtual]);
                printf("Autor do livro cadastrado: %s\n", autor[indiceAtual]);
                printf("ISBN-13 do livro cadastrado: %50s\n", isbn[indiceAtual]);
                printf("Quantidade de livro cadastrado que irá entrar no estoque físico: %i\n", estoque[indiceAtual][0]);
                printf("Preço do livro cadastrado: %.2f\n", preco[indiceAtual]);
                printf("Total de livros físicos que foi cadastrado no nome de \"%s\" é de %i livros\n", livro[indiceAtual], totalLivros[0]);
                printf("--------------------------------------------------------------------------\n");
                indiceAtual++;

            }
            else if (local==2){
                printf("\n ===ESTOQUE LOJA ONLINE=== \n");

                printf("Insira o nome do livro: ");
                //leia tudo, exceto o Enter.
                scanf(" %199[^\n]s", &livro[indiceAtual]);
                printf("Insira o nome do autor: ");
                scanf(" %199[^\n]s", &autor[indiceAtual]);
                printf("Insira o ISBN-13 do livro: ");
                scanf("%50s", &isbn[indiceAtual]);
                printf("Insira a quantidade de livros que irá entrar para o estoque online: ");
                scanf("%i", &estoque[indiceAtual][1]);

                printf("Insira o preço do livro: ");
                scanf("%f", &preco[indiceAtual]);

                totalLivros[1] = totalLivros[1] + estoque[indiceAtual][1];

                //string pois vamos usar mais que uma letra
                printf("\n--------------------------------------------------------------------------");
                //printf("\nLivro cadastrado: %s\n", livro);
                printf("\nLivro cadastrado no ID [%i]: %s\n", indiceAtual, livro[indiceAtual]);
                printf("Autor do livro cadastrado: %s\n", autor[indiceAtual]);
                printf("ISBN-13 do livro cadastrado: %50s\n", isbn[indiceAtual]);
                printf("Quantidade de livro cadastrado que irá entrar no estoque online: %i\n", estoque[indiceAtual][1]);
                printf("Preço do livro cadastrado: %.2f\n", preco[indiceAtual]);
                printf("Total de livros online que foi cadastrado no nome de \"%s\" é de %i livros\n", livro[indiceAtual], totalLivros[1]);
                printf("--------------------------------------------------------------------------\n");
                indiceAtual++;

            }
            else if (local==3){
                printf("\n ===ESTOQUE LOJA CENTRAL=== \n");

                printf("Insira o nome do livro: ");
                //leia tudo, exceto o Enter.
                scanf(" %199[^\n]s", &livro[indiceAtual]);
                printf("Insira o nome do autor: ");
                scanf(" %199[^\n]s", &autor[indiceAtual]);
                printf("Insira o ISBN-13 do livro: ");
                scanf("%50s", &isbn[indiceAtual]);
                printf("Insira a quantidade de livros que irá entrar para o estoque central: ");
                scanf("%i", &estoque[indiceAtual][2]);

                printf("Insira o preço do livro: ");
                scanf("%f", &preco[indiceAtual]);

                totalLivros[2] = totalLivros[2] + estoque[indiceAtual][2];

                //string pois vamos usar mais que uma letra
                printf("\n--------------------------------------------------------------------------");
                //printf("\nLivro cadastrado: %s\n", livro);
                printf("\nLivro cadastrado no ID [%i]: %s\n", indiceAtual, livro[indiceAtual]);
                printf("Autor do livro cadastrado: %s\n", autor[indiceAtual]);
                printf("ISBN-13 do livro cadastrado: %50s\n", isbn[indiceAtual]);
                printf("Quantidade de livro cadastrado que irá entrar no estoque central: %i\n", estoque[indiceAtual][2]);
                printf("Preço do livro cadastrado: %.2f\n", preco[indiceAtual]);
                printf("Total de livros no estoque central que foi cadastrado no nome de \"%s\" é de %i livros\n", livro[indiceAtual], totalLivros[2]);
                printf("--------------------------------------------------------------------------\n");
                indiceAtual++;

            }
            else {
                printf("\nVoltando a tela inicial..\n");
            }
        }
        //--------------------------------------------
       else if (resposta==2){
            printf("\n=== REGISTRAR ENTRADA DE ESTOQUE ===\n");

            printf("Digite o ISBN-13 do livro: ");
            scanf(" %49[^\n]", isbnDigitado);

            // Procurar o livro cadastrado pelo ISBN
            posicaoLivro = -1;

            for (int i = 0; i < indiceAtual; i++) {
                if (strcmp(isbn[i], isbnDigitado) == 0) {
                    posicaoLivro = i;
                    break;
                }
                }

                // Verificar se o livro existe
                if (posicaoLivro == -1) {
                        printf("\nLivro nao encontrado!\n");
                        printf("Cadastre o livro primeiro na opcao 1.\n");
                } else {
                printf("\nLivro encontrado: %s\n", livro[posicaoLivro]);

                printf("\nEscolha o local de entrada:\n");
                printf("1 - Loja fisica\n");
                printf("2 - Loja online\n");
                printf("3 - Loja central\n");
                printf("Opcao: ");
                scanf("%d", &local);

                if (local < 1 || local > 3) {
                printf("\nLocal invalido!\n");
                }
            else {

                printf("Quantidade de livros que chegaram: ");
                scanf("%d", &quantidade);

                if (quantidade <= 0) {
                printf("\nQuantidade invalida!\n");
            }
            else {
                // Adicionar ao estoque existente
                estoque[posicaoLivro][local - 1] += quantidade;

                totalLivros[local - 1] += quantidade;

                printf("\nEntrada registrada com sucesso!\n");
                printf("Livro: %s\n", livro[posicaoLivro]);
                printf("Estoque atualizado: %d livros\n",
                       estoque[posicaoLivro][local - 1]);
                    }
                }
            }
        }
        //---------------------------------------------
        else if (resposta==3){
            printf("\nSaída de livros\n"
                   "\n1 - Saída estoque físico\n"
                   "2 - Saída estoque online\n"
                   "3 - Saída estoque central\n"
                   "4 - Sair\n"
                   "Escolha o número da opção desejada: ");
            scanf("%i", &respostaSaida);

            contaRetirada[0] = totalLivros[0] - totalAposRetirada[0];

            if (respostaSaida==1){

                printf("\nInsira o nome do livro que se deseja retirar: ");
                scanf(" %199[^\n]s", livro);
                printf("Quantos livros \"%s\" você deseja retira do estoque?: ", livro);
                scanf("%i", totalAposRetirada[0]);

                printf("Total de livros fisícos após retirada do estoque é de %i\n", contaRetirada[0]);
            }
            else if (respostaSaida==2){

                contaRetirada[1] = totalLivros[1] - totalAposRetirada[1];

                printf("\nInsira o nome do livro que se deseja retirar: ");
                scanf(" %199[^\n]s", livro);
                printf("Quantos livros \"%s\" você deseja retira do estoque?: ", livro);
                scanf("%i", totalAposRetirada[1]);

                printf("Total de livros online após retirada do estoque é de %i\n", contaRetirada[1]);
            }
            else if(respostaSaida==3){
                contaRetirada[2] = totalLivros[2] - totalAposRetirada[2];

                printf("\nInsira o nome do livro que se deseja retirar: ");
                scanf(" %199[^\n]s", livro);
                printf("Quantos livros \"%s\" você deseja retira do estoque?: ", livro);
                scanf("%i", totalAposRetirada[2]);

                printf("Total de livros centrais após retirada do estoque é de %i\n", contaRetirada[2]);
            }
            else if (respostaSaida==4){
                printf("\nVoltando à tela inicial...\n");
            }
            else{
                printf("Opção inválida.\n");
            }
        }
        //---------------------------------------------
        else if (resposta==4){
            printf("\n1 - Estoque físico\n"
                   "2 - Estoque online\n"
                   "3 - Estoque central\n"
                   "4 - Todo o estoque\n"
                   "5 - Sair\n");
            printf("Escolha o número da opção desejada: ");
            scanf("%i", &resposta2);

             if (resposta2 == 1) {
                printf("\n== Estoque físico ==\n");

                //enquanto a posição do livro for menor que a quantidade de livros cadastrados, o laço continua
                for (int posicaoLivro = 0; posicaoLivro < indiceAtual; posicaoLivro++) {
                    printf("%s | Estoque: %i livros\n", livro[posicaoLivro], estoque[posicaoLivro][0]);
            }
        }
            else if (resposta2 == 2) {
                printf("\n== Estoque online ==\n");

            for (int posicaoLivro = 0; posicaoLivro < indiceAtual; posicaoLivro++) {

                    printf("%s | Estoque: %i livros\n",
                    livro[posicaoLivro], estoque[posicaoLivro][1]);
            }
        }
            else if (resposta2 == 3) {
                printf("\n== Estoque central ==\n");

            for (int posicaoLivro = 0; posicaoLivro < indiceAtual; posicaoLivro++) {

                    printf("%s | Estoque: %i livros\n",
                    livro[posicaoLivro], estoque[posicaoLivro][2]);
            }
        }
            else if (resposta2 == 4) {

                    printf("\n== Estoque geral ==\n");

            for (int posicaoLivro = 0; posicaoLivro < indiceAtual; posicaoLivro++) {

                    printf("\nLivro: %s", livro[posicaoLivro]);
                    printf("Estoque Físico: %i livros\n", estoque[posicaoLivro][0]);
                    printf("Estoque Online: %i livros\n", estoque[posicaoLivro][1]);
                    printf("Estoque Central: %i livros\n", estoque[posicaoLivro][2]);

            int total = estoque[posicaoLivro][0]
                      + estoque[posicaoLivro][1]
                      + estoque[posicaoLivro][2]; // percorrer todos os estoques

            printf("Total Geral: %i livros", total);
                }
            }
            else if (resposta2 == 5) {

                    printf("\nVoltando à tela inicial...\n");
            }
            else {

                    printf("Opção inválida.\n");
            }
        }
        //---------------------------------------------
        else if (resposta == 5){
            printf("\nEncerrando o sistema Ponto & Vírgula...\n");
            break;
        }
        //---------------------------------------------
        else {
            printf("Opção inválida.\n");
        }
    }
    return 0;
}
