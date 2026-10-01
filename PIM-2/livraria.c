#include <stdio.h>
#include <locale.h> //permite utilizar pontuacao sem dar erro

int main(){
    
    setlocale(LC_ALL, "Portuguese");  //atua com locale.h

    //criar variaveis, o struct junta varias variaveis dentro de um nome
    struct Livro{
        char livro[100];
        char autor[100];
        int isbn, estoque;
        float preco;

    };
    
    int resposta;
    char categorias[5][100] = {   //5 linhas e cada nome pode ter ate 99 caracter
        "Engenharia de Software e Boas Práticas",
        "Algoritmos e Ciência da Computação",
        "Inteligência Artificial e Dados",
        "Segurança e Redes",
        "Desenvolvimento Web e Mobile",
        
    };
    

    // fazer menu da livraria
    printf("\n===== PONTO & VÍRGULA EDITORA E LIVRARIA =====\n");
    printf("\n1 - Ver catálogo\n"
        "2 - Pesquisar livro\n"
        "3 - Minhas compras\n" 
        "4 - Sair\n");
    printf("Escolha o número correspondente ao qual você deseja acessar: %i\n\n", resposta);

    return 0;
}