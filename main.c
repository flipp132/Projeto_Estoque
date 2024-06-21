//declaração das bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <Windows.h>

//constantes
#define MAX 100
#define VAR 30
#define M 30
#define N 30

//dados de login
struct p
{
    char login[M];
    char senha[N];
} p_log[1];

//dados dos produtos
struct dados
{
    char nome[VAR];
    char codigo[VAR];
    char preco[VAR];
} dados_lista[MAX];

//dados dos clientes
struct cad
{
    char cliente[VAR];
    char cpf[VAR];
    char cel[VAR];
} cad_pessoa[MAX];

//funções 
void deletar_produto(void), deletar_cliente(void), mostrar_cliente(void), menu_cliente(void), cad_cliente(void), cad_produto(void), init_list(void), login(void), produto_esc(void);
int contagem_produto(void), menu(void), contagem_cliente(void), face_cliente(void), mostrar_produto(void);


//função principal
int main(int argc, char** argv)
{
    //permite acentos, caracteres especiais
    setlocale(LC_ALL,"portuquese");

    //variavel local
    int escolha;
    int a = 1;

	login();
    //laço do switch princcipal
    while(a)
    {
        //variavel que recebe o valor que a funcao "menu();" returna
        escolha = menu();
        //switch principal do sistema
        switch(escolha)
        {
            case 1:
                //funcao para cadastrar produtos
                cad_produto();
                produto_esc();
                break;
            case 2:
                //função para mostrar o estoque
                mostrar_produto();
                break;
            case 3:
                //função para deletar_produto produtos 
                deletar_produto();
                break;
            case 4:
                //funcao para o menu cliente(secundario)
                menu_cliente();
                break;    
            case 5:
                //sair do programa
                exit(0);
                break;
        }
    }
    getchar();
    return 0;
}

void init_list(void) {
    register int t;

    for(t=0; t<MAX; ++t) dados_lista[t].nome[0] = '\0';
    
}

//funcao de login do usuario
void login(void){

    char login[M];
    char senha[N];
    int lop = 1;

    strcpy(p_log[0].login, "lucas");
    strcpy(p_log[0].senha, "12345");

    while(lop == 1)
    {
        system("cls");
        printf("==Login de usuario==\n");
        printf("Nome do usuario: ");
        fflush(stdin);
        scanf("%s", login);
        printf("Senha: ");
        fflush(stdin);
        scanf("%s", senha);

        if((strcmp(login, p_log[0].login) == 0) && (strcmp(senha, p_log[0].senha) == 0))
        {
            printf("\nUsuario logado\n");
            lop = 0; 
            Sleep(1000);
        }else{
            printf("\nLogin e/ou senha incorretos\n");
            printf("Precione ENTER para tentar novamente.");
            fflush(stdin);
            getchar();
        }
    }   
}

//funcao para mostrar as informacoes do menu 
int menu(void)
{
    //variavel local
    char s[80];
    int c;

    //limpa a tela para o usuario
    system("cls");
    printf("===========Menu Principal===========\n");
    printf("Digite 1 para cadastrar produtos.\n");
    printf("-------------------------------------\n");
    printf("Digite 2 para mostrar os cadastros.\n");
    printf("-------------------------------------\n");
    printf("Digite 3 para deletar um produto.\n");
    printf("-------------------------------------\n");
    printf("Digite 4 para entrar no menu cliente.\n");
    printf("-------------------------------------\n");
    printf("Digite 5 para sair do programa.\n");
    printf("-------------------------------------\n");

    do {
        printf("\nDigite sua escolha: ");
        fflush(stdin);
        gets(s);
        c = atoi(s);
    }while(c<0 && c>4);
    return c;
}

//funcao para cadastrar produtos
void cad_produto(void)
{
    //variavel local
    int slot;

        //variavel que recebe o valor que a funcao "contagem_produto();" returna
        slot = contagem_produto();
        //limpa a tela para o usuario
        system("cls");
        if(slot== -1)
        {
            printf("\nlista cheia");
            return;
        }else{
            printf("Digite o nome do produto: ");
            fflush(stdin);
            fgets(dados_lista[slot].nome, VAR, stdin);

            printf("\nDigite o codigo do produto: ");
            fflush(stdin);
            fgets(dados_lista[slot].codigo, VAR, stdin);

            printf("\nDigite o preco do produto: ");
            fflush(stdin);
            fgets(dados_lista[slot].preco, VAR, stdin);

        }
}

//funcao para cadastrar mais um produto ou voltar ao menu inicial
void produto_esc(void) {

    int time = 1;
    int op;

		while(time)
		{			
            printf("\n\n");
            printf("========================================\n");
            printf("Digite 1 para cadastrar mais um produto:\n");
            printf("----------------------------------------\n");
            printf("Digite 2 para voltar ao menu principal:\n");
            printf("----------------------------------------\n");
            printf("Digite sua escolha: ");
            fflush(stdin);
            scanf("%d", &op);

            if(op == 1) {
                cad_produto();
            } else if (op == 2) {
                break;
            }
		}	
}

//funcao para cadastrar os clientes 
void cad_cliente(void)
{
    //variavel local
    int code;

    //variavel que recebe o valor da funcao "contagem_cliente();" retorna
    code = contagem_cliente();
    //limpa a tela para o usuario
    system("cls");
    if(code == -1)
    {
        printf("\nLista cheia");
        return;
    }else{
        printf("Digite o nome do cliente: ");
        fflush(stdin);
        fgets(cad_pessoa[code].cliente, VAR, stdin);

        printf("\nDigite o CPF do cliente: ");
        fflush(stdin);
        fgets(cad_pessoa[code].cpf, VAR, stdin);

        printf("\nDigite o numero telefonico: ");
        fflush(stdin);
        fgets(cad_pessoa[code].cel, VAR, stdin);

        Sleep(1000);
    }   
}

//funcao que conta quantos produtos tem
int contagem_produto(void) 
{
    register int t;
    for(t=0; dados_lista[t].nome[0] && t<MAX; t++);

    if(t==MAX) return -1;
    return t;
}

//funcao que mostrao estoque dos produtos
int mostrar_produto(void)
{
    register int t;
    int ton = 0;

    system("cls");
        for(t=0; t<MAX; t++)
        {
            if(dados_lista[t].nome[0])
            {
                ton++;
                printf("Nome: %s", dados_lista[t].nome);
                printf("Codigo: %s", dados_lista[t].codigo);
                printf("Preco: %s", dados_lista[t].preco);
                printf("\n\n");
            }
        }
    printf("Total de unidades no estoque: %d\n\n", ton);
    printf("\t\tAperte ENTER para voltar ao menu:");
    getchar();    
    return 0;    
}

//funcao que mostrar o menu cliente parar o usuario
void menu_cliente(void)
{
    //variavel local
    int escolha;
    int p = 1;

    //laço de repetição para a escolha do usuario
    do 
    {
        escolha = face_cliente();
        switch (escolha)
        {
        case 1:
            cad_cliente();
            break;
        case 2:
            mostrar_cliente();
            break;
        case 3:
            deletar_cliente();
            break;
        case 4:    
            p = 0;
            break;    
        }
    }while (p);
    
}

//Menu de cadastro de clientes
int face_cliente(void)
{
    char s[80];
    int c;

    system("cls");
    printf("==============Menu Cliente==============\n");
    printf("Digite 1 para cadastrar o cliente.\n");
    printf("----------------------------------------\n");
    printf("Digite 2 para mostrar os cadastros.\n");
    printf("----------------------------------------\n");
    printf("Digite 3 para deletar um cadastro.\n");
    printf("----------------------------------------\n");
    printf("Digite 4 para voltar ao menu principal.\n");
    printf("----------------------------------------\n");
    do {
        printf("\nDigite sua escolha: ");
        fflush(stdin);
        gets(s);
        c = atoi(s);
    }while(c<0 && c>4);
    return c;
}

//funcao para mostrar os clientes cadastrados
void mostrar_cliente(void)
{
    register int t, ton=0;

    system("cls");
        for(t=0; t<MAX; t++)
        {
            if(cad_pessoa[t].cliente[0])
            {
                ton++;
                printf("Cliente: %s", cad_pessoa[t].cliente);
                printf("CPF: %s", cad_pessoa[t].cpf);
                printf("Celular: %s", cad_pessoa[t].cel);
                printf("\n\n");    
            }
        }
        printf("Total de clientes cadastrados: %d\n\n", ton);
        printf("\t\tAperte ENTER para voltar ao menu:");
        getchar();
}

//funcao que conta qunatos cliente foram cadastrados
int contagem_cliente(void)
{
    register int w;
    for(w=0; cad_pessoa[w].cliente[0] && w<MAX; w++);

    if(w == MAX) return -1;
    return w;
}    

//funcao para apagar os produtos do estoque
void deletar_produto(void)
{
    register int slot;
    char s[80];

    system("cls");
    printf("Digite o registro #: ");
    gets(s);
    slot = atoi(s);
    if(slot>=0 && slot < MAX)
    {
        dados_lista[slot].nome[0] = '\0';
    }
    printf("Aperte ENTER para voltar:");
    getchar();
}

//funcao para apagar os cadastro dos cliente
void deletar_cliente(void)
{
    register int slot;
    char s[80];

    system("cls");
    printf("Digite o registro #: ");
    gets(s);
    slot = atoi(s);
    if(slot>=0 && slot < MAX)
    {
        cad_pessoa[slot].cliente[0] = '\0';
    }
    printf("Aperte ENTER para voltar:");
    getchar();
}