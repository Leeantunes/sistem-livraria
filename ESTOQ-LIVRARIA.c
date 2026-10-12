#include <stdio.h>
#include <locale.h> //permite utilizar pontuacao sem dar erro
#include <string.h> //comparar textos strcmp

int main(){

    setlocale(LC_ALL, "Portuguese");  //atua com locale.h

    //criar variaveis pros livros
    char livro[100];
    char autor[100];
    int isbn;
    int estoque[3] = {0};  //vetor???
    float preco;
    int resposta;
    int local;
    int totalLivros = 0;

    int resposta2;

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
        printf("\nEscolha a opção desejada: ");
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

    while (resposta <= 5){

    printf("\n ===== PONTO & VÍRGULA EDITORA E LIVRARIA SISTEMA DE ESTOQUE ===== \n");
    printf("\n1 - Cadastrar entrada de livros\n"
        "2 - Consultar estoque\n"
        "3 - Registrar saída/venda\n"
        "4 - Consultar estoque por local\n"
        "5 - Sair\n");

    printf("\nEscolha o número correspondente ao qual você deseja acessar: ");
    scanf("%i", &resposta);


        //--------------------------------------------
        if (resposta == 1){
            printf("\nOnde o livro será cadastrado?\n");
            printf("1 - Loja física\n"
            "2 - Loja online\n"
            "3 - Loja central\n"
            "4 - Sair\n");
            printf("Escolha a opção desejada: ");
            scanf("%d", &local);

            if (local == 1){
                printf("\n ===ESTOQUE LOJA FÍSICA=== \n");

                printf("Insira o nome do livro: ");
                //leia tudo, exceto o Enter.
                scanf(" %99[^\n]", &livro);
                printf("Insira o nome do autor: ");
                scanf(" %99[^\n]", &autor);
                printf("Insira o ISBN do livro: ");
                scanf("%i", &isbn);
                printf("Insira a quantidade de livros que irá entrar para o estoque: ");
                scanf("%i", &estoque[0]);

                printf("Insira o preço do livro: ");
                scanf("%f", &preco);

                totalLivros = totalLivros + estoque[0];

                //string pois vamos usar mais que uma letra
                printf("\n--------------------------------------------------------------------------");
                printf("\nLivro cadastrado: %s\n", livro);
                printf("Autor do livro cadastrado: %s\n", autor);
                printf("ISBN do livro cadastrado: %i\n", isbn);
                printf("Quantidade de livro cadastrado que irá entrar no estoque físico: %i\n", estoque[0]);
                printf("Preço do livro cadastrado: %.2f\n", preco);
                printf("Total de livros físicos que foi cadastrado no nome de \"%s\" é de %i livros\n", livro, totalLivros);
                printf("--------------------------------------------------------------------------\n");

            }
            else if (local==2){
                printf("\n ===ESTOQUE LOJA ONLINE=== \n");

                printf("Insira o nome do livro: ");
                //leia tudo, exceto o Enter.
                scanf(" %99[^\n]", &livro);
                printf("Insira o nome do autor: ");
                scanf(" %99[^\n]", &autor);
                printf("Insira o ISBN do livro: ");
                scanf("%i", &isbn);
                printf("Insira a quantidade de livros que irá entrar para o estoque online: ");
                scanf("%i", &estoque[1]);

                printf("Insira o preço do livro: ");
                scanf("%f", &preco);

                totalLivros = totalLivros + estoque[1];

                //string pois vamos usar mais que uma letra
                printf("\n--------------------------------------------------------------------------");
                printf("\nLivro cadastrado: %s\n", livro);
                printf("Autor do livro cadastrado: %s\n", autor);
                printf("ISBN do livro cadastrado: %i\n", isbn);
                printf("Quantidade de livro cadastrado que irá entrar no estoque online: %i\n", estoque[1]);
                printf("Preço do livro cadastrado: %.2f\n", preco);
                printf("Total de livros online que foi cadastrado no nome de \"%s\" é de %i livros\n", livro, totalLivros);
                printf("--------------------------------------------------------------------------\n");

            }
            else if (local==3){
                printf("\n ===ESTOQUE LOJA CENTRAL=== \n");

                printf("Insira o nome do livro: ");
                //leia tudo, exceto o Enter.
                scanf(" %99[^\n]", &livro);
                printf("Insira o nome do autor: ");
                scanf(" %99[^\n]", &autor);
                printf("Insira o ISBN do livro: ");
                scanf("%i", &isbn);
                printf("Insira a quantidade de livros que irá entrar para o estoque central: ");
                scanf("%i", &estoque[2]);

                printf("Insira o preço do livro: ");
                scanf("%f", &preco);

                totalLivros = totalLivros + estoque[2];

                //string pois vamos usar mais que uma letra
                printf("\n--------------------------------------------------------------------------");
                printf("\nLivro cadastrado: %s\n", livro);
                printf("Autor do livro cadastrado: %s\n", autor);
                printf("ISBN do livro cadastrado: %i\n", isbn);
                printf("Quantidade de livro cadastrado que irá entrar no estoque central: %i\n", estoque[2]);
                printf("Preço do livro cadastrado: %.2f\n", preco);
                printf("Total de livros no estoque central que foi cadastrado no nome de \"%s\" é de %i livros\n", livro, totalLivros);
                printf("--------------------------------------------------------------------------\n");

            }
            else {
                printf("\nVoltando a tela inical..\n");
            }
        }
        //--------------------------------------------
        else if (resposta==2){
            printf("1 - Estoque físco\n"
                   "2 - Estoque online\n"
                   "3 - Estoque central\n"
                   "4 - Todo o estoque\n"
                   "5 - Sair\n");
            scanf("%i", &resposta2);

            if (resposta2==1){
                printf("Estoque Físico: %i", estoque[0]);
            }
            else if(resposta==2){
                printf("Estoque online: %i", estoque[1]);
            }
            else if(resposta2==3){
                printf("Estoque Central: %i", estoque[2]);
            }
            else if (resposta2==4){
                printf("Estoque geral: %i", estoque);
            }
            else if (resposta2==5){
                printf("\nVoltando a tela inicial..\n");
            }
            else{
                printf("Opção inválida.\n");
            }
        }
        //---------------------------------------------
        else if (resposta == 5){
            printf("\nVoltando a tela inicial..\n");

        }
    }

    return 0;
}