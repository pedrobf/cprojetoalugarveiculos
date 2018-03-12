#include <stdio.h>
#include <stdlib.h>
#include<locale.h>
#include<string.h>
#include<time.h>
#define GOL 50,00
#define PALIO 80,00;
#define ONIX 150,00;
#define CRUZE 400,00;
void pagamento();
int tipos(int *tipos);
void entrada(char enter[1000],char opcao,int tamanho);
void devolucao();
void fechararquivo(FILE*arq);
void listar();
FILE*Abrirarquivo(char caminho[30],char modo);
void opinvalida2(int *q);
void opinvalida(int *p);
typedef struct Cliente{
int op;
char cpf[16];
char contato[13];
char endereco[100];
char email[50];
char nome[200];
char rg[200];
char user[200];
char senha[100];
char enderecoemp[200];
char nomemp[200];
char cnpj[15];
char tf[12];
int dias;
}Cliente;
Cliente cliente;
char log(int ***pfouj);
int testecadastro(int *escolha,int *pfouj);
void descontos(double desc,int *p);
void pf(int **pfouj);
void pj(int **pfouj);
int main(){
/*system("color 1E");
system("mode con:cols=100 lines=30");*/
setlocale(LC_ALL,"");
double valor;
do{
printf("\t\t\t============================================\n");//Área  do menu de opções para o usuário escolher o carro desejado para alugar!!
printf("\t\t\t\t   ***SEJA BEM-VINDO***\n");
printf("\t\t\t============================================\n");
printf("\t\t\t\t= A PLATAFORMA DO ALUGUE JÁ!!\t   =\n");
printf("\t\t\t============================================\n");
printf("-----------------------------");
printf("Lista de Carros Disponíveis para Alugar!!-----------------------------\n");
printf("\t======================\n");
printf("\t=\tCARROS       =\n");
printf("\t\======================\n");
printf("\t=[1]-GOL             =\n");
printf("\t=[2]-PALIO           =\n");
printf("\t=[3]-ONIX            =\n");
printf("\t=[4]-CRUZE           =\n");
printf("\t=[5]-SAIR            =\n");
printf("\t======================\n");
printf("\t=\tDiária       =\n");
printf("\t\======================\n");
printf("\t=[1]-GOL   -  50,00  =\n");
printf("\t=[2]-PALIO -  80,00  =\n");
printf("\t=[3]-ONIX  - 150,00  =\n");
printf("\t=[4]-CRUZE - 400,00  =\n");
printf("\t======================\n");
printf("\tEscolha uma das opções acima para prosseguirmos com o aluguel do veículo!!\n");
scanf("%d",&cliente.op);
opinvalida(&cliente.op);
switch(cliente.op){
case 1 :
    printf("Quantos dias irá reservar o veículo?\n");
    scanf("%d",&cliente.dias);
    if(cliente.dias<=0){
        printf("Valor Invalido \n");
        system ("pause");
        system ("cls");
    }else{
        valor=cliente.dias*GOL;
        descontos(valor,&cliente.op);
    }
break;
case 2 :
    printf("Quantos dias irá reservar o veículo?\n");
    scanf("%d",&cliente.dias);
    if(cliente.dias<=0){
        printf("Valor Invalido \n");
        system ("pause");
        system ("cls");
    }else{
        valor=cliente.dias*PALIO;
        descontos(valor,&cliente.op);
    }
break;
case 3 :
    printf("Quantos dias irá reservar o veículo?\n");
    scanf("%d",&cliente.dias);
     if(cliente.dias<=0){
        printf("Valor Invalido \n");
        system ("pause");
        system ("cls");
    }else{
        valor=cliente.dias* ONIX;
        descontos(valor,&cliente.op);
    }
break;
case 4:
    printf("Quantos dias irá reservar o veículo?\n");
    scanf("%d",&cliente.dias);
    if(cliente.dias<=0){
        printf("Valor Invalido \n");
        system ("pause");
        system ("cls");
    }else{
        valor=cliente.dias*CRUZE;
        descontos(valor,&cliente.op);
    }
break;
case 5:
    printf("Encerrando......\n");
    break;
}
}while(cliente.op!=5);
return 0;
}
void descontos(double desc,int *p){//Sessão onde são calculados os descontos para o usuário e se  o mesmo deseja alugar o carro o carro!!
FILE*arq;
char verifica;
double valor;
valor=desc;
int carros;
int dev;
int op1,op2,op3,op4;
int idade;
int opong;
int pfouj;
printf("Você é pessoa física[1] ou[2] jurídica(empresa)?\n");//Área reservada para teste para verificar se o usuário é uma pessoa ou  uma empresa!!
scanf("%d",&pfouj);
opinvalida2(&pfouj);
switch(pfouj){
case 1:
    printf("Entre com sua idade para calcularmos o desconto\n");
    scanf("%d",&idade);
    if(idade<18){
            printf("Voce é novo para dirigir\nTENHA UM BOM DIA....\n");
             system("pause");
            system("cls");
            return ;
    }
    if(idade>=60){
        desc=desc*0.9;
        printf("Desconto de 10%% com relação a idade=IDOSO\n");
        printf("Valor de R$ %.2f\n\n",desc);
        }
    else{
        printf("Você não possui Descontos!!\n");
        printf("Valor de R$ %.2f\n",desc);
        }
    if(*p==1){
            printf("Você Escolheu a opção 1-GOL\n\nDeseja realmente este carro?\n[1]-SIM\n[2]-Não\nValor normal:%0.2lf\n",valor);
            scanf("%d",&op1);
            opinvalida2(&op1);
            switch(op1){
                case 1:
                     arq=Abrirarquivo("Golestoque.txt",'l');
                   fscanf(arq,"%d",&carros);
                    if(carros<1){
                        printf("O carro já esta alugado\n");
                        printf("Você é a pessoa que alugou o  1-Sim\t2-Não\n");
                        scanf("%d",&dev);
                    if(dev==1){
                            system("cls");
                             testecadastro(&op1,&pfouj);
                            break;

                    }else{
                        system("pause");
                        system("cls");
                        break;
                   }
                    }
                    if(idade>=18){
                        fechararquivo(arq);
                        arq=Abrirarquivo("Golestoque.txt",'g');
                        fprintf(arq,"0");
                        fechararquivo(arq);
                    }
                    arq=Abrirarquivo("golvalor.txt",'l');
                    while(!feof(arq)){
                            fscanf(arq,"%c",verifica);
                            if(verifica=='x'){
                                printf("Carro alugado");
                                system("pause");
                                system("cls");
                            }
                    }
                    if(idade>=18){
                        arq=Abrirarquivo("golvalor.txt",'g');
                        fprintf(arq,"x %.2f",desc);
                    }
                fechararquivo(arq);
                testecadastro(&op1,&pfouj);
                break;
                case 2:
                    system("cls");
                break;

            }
            }
    if(*p==2){
            printf("Você Escolheu a opção 2-PALIO\n\nDeseja realmente este carro?\n[1]-SIM\n[2]-Não\nValor normal:%0.2lf\n",valor);
            scanf("%d",&op2);
            opinvalida2(&op2);
            switch(op2){
                    case 1:
                         arq=Abrirarquivo("Palioestoque.txt",'l');
                        fscanf(arq,"%d",&carros);
                        if(carros<1){
                            printf("O carro  ja esta alugado\n");
                            printf("Você é a pessoa que alugou o carro 1-Sim\t2-Não\n");
                            scanf("%d",&dev);
                        if(dev==1){
                                system("cls");
                                testecadastro(&op2,&pfouj);
                                break;
                        }else{
                            system("pause");
                            system("cls");
                            break;
                        }
                    }
                        fechararquivo(arq);
                        if(idade>=18){
                            arq=Abrirarquivo("Palioestoque.txt",'g');
                            fprintf(arq,"0");
                            fechararquivo(arq);
                            }
                            arq=Abrirarquivo("paliovalor.txt",'l');
                        while(!feof(arq)){
                                fscanf(arq,"%c",verifica);
                            if(verifica=='x'){
                                printf("Carro alugado");
                                system("pause");
                                system("cls");
                            }
                        }
                        fechararquivo(arq);
                        if(idade>=18){
                            arq=Abrirarquivo("paliovalor.txt",'g');
                            fprintf(arq,"x %.2f",desc);
                        }
                        fechararquivo(arq);
                        testecadastro(&op2,&pfouj);
                    break;
                    case 2:
                        system("cls");
                    break;

                        }
            }
    if(*p==3){
            printf("Você Escolheu a opção 3-ONIX\n\nDeseja realmente este carro?\n[1]-SIM\n[2]-Não\nValor normal:%0.2lf\n",valor);
            scanf("%d",&op3);
            opinvalida2(&op3);
            switch(op3){
                case 1:
                     arq=Abrirarquivo("Onixestoque.txt",'l');
                    fscanf(arq,"%d",&carros);
                   if(carros<1){
                        printf("O carro  ja esta alugado\n");
                        printf("Você é a pessoa que alugou o carro? 1-Sim\t2-Não\n");
                        scanf("%d",&dev);
                    if(dev==1){
                            system("cls");
                             testecadastro(&op3,&pfouj);
                              break;
                    }else{
                        system("pause");
                        system("cls");
                        break;
                    }
                }
                    fechararquivo(arq);
                    if(idade>=18){
                        arq=Abrirarquivo("Onixestoque.txt",'g');
                        fprintf(arq,"0");
                        fechararquivo(arq);
                    }
                    arq=Abrirarquivo("onixvalor.txt",'l');
                    while(!feof(arq)){
                            fscanf(arq,"%c",verifica);
                            if(verifica=='x'){
                                printf("Carro alugado");
                                system("pause");
                                system("cls");
                            }
                    }
                    fechararquivo(arq);
                    if(idade>=18){
                        arq=Abrirarquivo("onixvalor.txt",'g');
                        fprintf(arq,"x %.2f",desc);
                    }
                    fechararquivo(arq);
                    testecadastro(&op3,&pfouj);
                break;
                case 2:
                    system("cls");
                break;
                        }
            }

    if(*p==4){
            printf("Você Escolheu a opção 4-CRUZE\n\nDeseja realmente este carro?\n[1]-SIM\n[2]-Não\nValor normal:%0.2lf\n",valor);
            scanf("%d",&op4);
            opinvalida2(&op4);
            switch(op4){
                case 1:
                     arq=Abrirarquivo("Cruzeestoque.txt",'l');
                   fscanf(arq,"%d",&carros);
                    if(carros<1){
                        printf("O carro ja esta alugado\n");
                        printf("Você é a pessoa que alugou o carro ?1-Sim\t2-Não\n");
                        scanf("%d",&dev);
                    if(dev==1){
                            system("cls");
                             testecadastro(&op4,&pfouj);
                              break;
                    }else{
                        system("pause");
                        system("cls");
                        break;

                   }
                }
                    fechararquivo(arq);
                     if(idade>=18){
                        arq=Abrirarquivo("Cruzeestoque.txt",'g');
                        fprintf(arq,"0");
                        fechararquivo(arq);
                     }
                     arq=Abrirarquivo("cruzevalor.txt",'l');
                    while(!feof(arq)){
                            fscanf(arq,"%c",verifica);
                            if(verifica=='x'){
                                printf("Carro alugado");
                                system("pause");
                                system("cls");
                            }
                    }
                    fechararquivo(arq);
                    if(idade>=18){
                        arq=Abrirarquivo("cruzevalor.txt",'g');
                        fprintf(arq,"x %.2f",desc);
                    }
                    fechararquivo(arq);
                    testecadastro(&op4,&pfouj);
                break;
                case 2:
                    system("cls");
                break;
                        }

            }
break;
case 2:
    printf("É parceira da ONG?\n[1]-Sim\n[2]-Não\n");
    scanf("%d",&opong);
    opinvalida2(&opong);
    if(opong==1){
        desc=desc*0.95;
        printf("Desconto de 5%% com relação a parceria com a ONG!!\n");
        printf("Valor de R$ %.2f\n\n",desc);
    }else{
        printf("Você não possui Descontos!!\n");
        printf("Valor de R$ %.2f\n",desc);
    }
    if(*p==1){
        printf("Você Escolheu a opção 1-GOL\n\nDeseja realmente este carro?\n[1]-SIM\n[2]-Não\nValor normal:%0.2lf\n",valor);
        scanf("%d",&op1);
        opinvalida2(&op1);
        switch(op1){
                case 1:
                    arq=Abrirarquivo("Golestoque.txt",'l');
                    fscanf(arq,"%d",&carros);
                        if(carros<1){
                            printf("O carro ja esta alugado\n");
                            printf("Você é a pessoa que alugou o carro ? 1-Sim\t2-Não\n");
                            scanf("%d",&dev);
                            if(dev==1){
                                system("cls");
                                testecadastro(&op1,&pfouj);
                                break;
                            }else{
                                system("pause");
                                system("cls");
                                break;
                            }
                        }
                    fechararquivo(arq);
                        arq=Abrirarquivo("Golestoque.txt",'g');
                        fprintf(arq,"0");
                        fechararquivo(arq);
                     arq=Abrirarquivo("golvalor.txt",'l');
                    while(!feof(arq)){
                            fscanf(arq,"%c",verifica);
                            if(verifica=='x'){
                                printf("Carro alugado");
                                system("pause");
                                system("cls");
                            }else{ arq=Abrirarquivo("golvalor.txt",'g');
                                    fprintf(arq,"x %.2f",desc);
                                    fechararquivo(arq);
                                    testecadastro(&op1,&pfouj);
                            }
                    }


            break;
            case 2:
                system("cls");
            break;
                }
            }
    if(*p==2){
    printf("Você Escolheu a opção 2-PALIO\n\nDeseja realmente este carro?\n[1]-SIM\n[2]-Não\nValor normal:%0.2lf\n",valor);
    scanf("%d",&op2);
    opinvalida2(&op2);
    switch(op2){
        case 1:
             arq=Abrirarquivo("Palioestoque.txt",'l');
                   fscanf(arq,"%d",&carros);
                    if(carros<1){
                        printf("O carro ja esta alugado\n");
                        printf("Você é a pessoa que alugou o carro ? 1-Sim\t2-Não\n");
                        scanf("%d",&dev);
                    if(dev==1){
                            system("cls");
                             testecadastro(&op2,&pfouj);
                              break;
                    }else{
                        system("pause");
                        system("cls");
                        break;
                    }
                }
                    fechararquivo(arq);
                        arq=Abrirarquivo("Palioestoque.txt",'g');
                        fprintf(arq,"0");
                        fechararquivo(arq);
                     arq=Abrirarquivo("paliovalor.txt",'l');
                    while(!feof(arq)){
                            fscanf(arq,"%c",verifica);
                            if(verifica=='x'){
                                printf("Carro alugado");
                                system("pause");
                                system("cls");
                            }else{
                                    arq=Abrirarquivo("paliovalor.txt",'g');
                                    fprintf(arq,"x %.2f",desc);
                                    fechararquivo(arq);
                                    testecadastro(&op2,&pfouj);
        break;
                            }
                    }

        case 2:
            system("cls");
        break;

                }
            }
    if(*p==3){
    printf("Você Escolheu a opção 3-ONIX\n\nDeseja realmente este carro?\n[1]-SIM\n[2]-Não\nValor normal:%0.2lf\n",valor);
    scanf("%d",&op3);
    opinvalida2(&op3);
    switch(op3){
        case 1:
            arq=Abrirarquivo("Onixestoque.txt",'l');
                   fscanf(arq,"%d",&carros);
                    if(carros<1){
                        printf("O carro  ja esta alugado\n");
                        printf("Você é a pessoa que alugou o carro ? 1-Sim\t2-Não\n");
                        scanf("%d",&dev);
                    if(dev==1){
                            system("cls");
                             testecadastro(&op3,&pfouj);
                              break;
                    }else{
                        system("pause");
                        system("cls");
                        break;

                    }
                }
                    fechararquivo(arq);
                        arq=Abrirarquivo("Onixestoque.txt",'g');
                        fprintf(arq,"0");
                        fechararquivo(arq);
                      arq=Abrirarquivo("onixvalor.txt",'l');
                    while(!feof(arq)){
                            fscanf(arq,"%c",verifica);
                            if(verifica=='x'){
                                printf("Carro alugado");
                                system("pause");
                                system("cls");
                            }else{
                                    arq=Abrirarquivo("onixvalor.txt",'g');
                                    fprintf(arq,"x %.2f",desc);
                                    fechararquivo(arq);
                                    testecadastro(&op3,&pfouj);
                            }
                    }

        break;
        case 2:
            system("cls");
        break;
                }
            }
 if(*p==4){
    printf("Você Escolheu a opção 4-CRUZE\n\nDeseja realmente este carro?\n[1]-SIM\n[2]-Não\nValor normal:%0.2lf\n",valor);
    scanf("%d",&op4);
    opinvalida2(&op4);
        switch(op4){
            case 1:
                 arq=Abrirarquivo("Cruzeestoque.txt",'l');
                   fscanf(arq,"%d",&carros);
                    if(carros<1){
                        printf("O carro  ja esta alugado\n");
                        printf("Você é a pessoa que alugou o carro ? 1-Sim\t2-Não\n");
                        scanf("%d",&dev);
                    if(dev==1){
                            system("cls");
                             testecadastro(&op4,&pfouj);
                              break;
                    }else{
                        system("pause");
                        system("cls");
                        break;

                   }
                }
                    fechararquivo(arq);
                        arq=Abrirarquivo("Cruzeestoque.txt",'g');
                        fprintf(arq,"0");
                        fechararquivo(arq);
                     arq=Abrirarquivo("cruzevalor.txt",'l');
                    while(!feof(arq)){
                            fscanf(arq,"%c",verifica);
                            if(verifica=='x'){
                                printf("Carro alugado");
                                system("pause");
                                system("cls");
                            }else{
                                    arq=Abrirarquivo("golvalor.txt",'g');
                                    fprintf(arq,"x %.2f",desc);
                                    fechararquivo(arq);
                                    testecadastro(&op4,&pfouj);
            break;
                            }
                    }

            case 2:
                system("cls");
            break;
                    }
        }
 }
return descontos;
}
void pf(int **pfouj){//Indica a área reservada ao cadastro de usuários que são pessoas físicas!!
FILE*arq;
FILE*aq;
system("cls");
printf("\t\t==================================================\n");
printf("\t\t= \t\tÁREA DE CADASTRO\t         =\n");
printf("\t\t\==================================================\n");
printf("=================================================================================================\n");
arq=Abrirarquivo("clientes.txt",'a');
printf("Entre com os seus dados:\n");//Indica o começo da entrada de dados da pessoa fisica!!
printf("Nome:\n");
fflush(stdin);
fgets(cliente.nome,sizeof(cliente.nome),stdin);
cliente.nome[strlen(cliente.nome)-1]=cliente.nome[strlen(cliente.nome)];
entrada(cliente.nome,'l',100);
aq=Abrirarquivo("nomes.txt",'a');
fprintf(aq,"%s\n",cliente.nome);
fclose(aq);
switch(cliente.op){
    case 1:
        aq=Abrirarquivo("golnome.txt",'g');
        fprintf(aq,"%s",cliente.nome);
        fechararquivo(aq);
    break;
    case 2:
        aq=Abrirarquivo("palionome.txt",'g');
        fprintf(aq,"%s",cliente.nome);
        fechararquivo(aq);
    break;
    case 3:
        aq=Abrirarquivo("onixnome.txt",'g');
        fprintf(aq,"%s",cliente.nome);
        fechararquivo(aq);
    break;
    case 4:
        aq=Abrirarquivo("cruzenome.txt",'g');
        fprintf(aq,"%s",cliente.nome);
        fechararquivo(aq);
    break;
}
printf("Endereço:\n");
fflush(stdin);
fgets(cliente.endereco,sizeof(cliente.endereco),stdin);
entrada(cliente.endereco,'x',7);
printf("RG:\n");
scanf("%199s",&cliente.rg);
entrada(cliente.rg,'x',7);
printf("CPF:\n");
scanf("%15s",&cliente.cpf);
entrada(cliente.cpf,'n',11);
printf("E-mail:\n");
scanf("%49s",&cliente.email);
entrada(cliente.email,'x',5);
printf("Contato Celular ou Telefone Fixo:\n");
scanf("%12s",&cliente.contato);
entrada(cliente.contato,'n',11);
fprintf(arq,"%s %s%s %s\n%s %s\n",cliente.nome,cliente.endereco,cliente.contato,cliente.email,cliente.rg,cliente.cpf);
fechararquivo(arq);
printf("\n\n\n\n");
system("cls");
printf("***Seus Dados***\n");
printf("Nome:%s\tEndereço:%sCPF:%s\tRG:%s\nE-mail:%s ",cliente.nome,cliente.endereco,cliente.cpf,cliente.rg,cliente.email);//exibição de dados da pessoa física!!
printf("Contato:%s",cliente.contato);
devolucao();
return pf;
}
void pj(int **pfouj){//Área reservada ao cadastro de empresas!!
FILE*arq;
FILE *aq;
arq=Abrirarquivo("empresas.txt",'g');
system("cls");
printf("\t\t==================================================\n");
printf("\t\t= \t\tÁREA DE CADASTRO\t         =\n");
printf("\t\t\==================================================\n");
printf("=================================================================================================\n");
printf("Entre com seus dados:\n");//Indica o começo da entrada dos dados da empresa!!
printf("Nome:\n");
fflush(stdin);
fgets(cliente.nomemp,sizeof(cliente.nomemp),stdin);
cliente.nomemp[strlen(cliente.nomemp)-1]=cliente.nomemp[strlen(cliente.nomemp)];
entrada(cliente.nomemp,'l',3);
aq=Abrirarquivo("nomes.txt",'a');
fprintf(aq,"%s\n",cliente.nomemp);
fechararquivo(aq);
switch(cliente.op){
    case 1:
        aq=Abrirarquivo("golnome.txt",'g');
        fprintf(aq,"%s",cliente.nomemp);
        fechararquivo(aq);
    break;
    case 2:
        aq=Abrirarquivo("palionome.txt",'g');
        fprintf(aq,"%s",cliente.nomemp);
        fechararquivo(aq);
    break;
    case 3:
        aq=Abrirarquivo("onixnome.txt",'g');
        fprintf(aq,"%s",cliente.nomemp);
        fechararquivo(aq);
    break;
    case 4:
        aq=Abrirarquivo("cruzenome.txt",'g');
        fprintf(aq,"%s",cliente.nomemp);
        fechararquivo(aq);
    break;
}
printf("CNPJ:\n");
scanf("%14s",&cliente.cnpj);
entrada(cliente.cnpj,'n',14);
printf("Endereço:\n");
fflush(stdin);
fgets(cliente.enderecoemp,sizeof(cliente.enderecoemp),stdin);
entrada(cliente.enderecoemp,'x',5);
printf("Telefone de contato:\n");
scanf("%11s",&cliente.tf);
entrada(cliente.tf,'n',11);
fprintf(arq,"%s %s%s %s\n",cliente.nomemp,cliente.enderecoemp,cliente.tf,cliente.cnpj);
fechararquivo(arq);
system("cls");
printf("***Seus Dados***\n");
printf("Nome:%s\tCNPJ:%s Endereço:%sTelefone:%s",cliente.nomemp,cliente.cnpj,cliente.enderecoemp,cliente.tf);//exibição dos dados da empresa!!
devolucao();
return pj;}
int testecadastro(int *escolha,int *pfouj){/*Função com objetivo de verficar se o usuário possui cadastro na plataforma
    e direcioná-lo a parte de acesso a plataforma ou cadastro!!*/
int resp;
FILE *arq;
FILE*aq;
char nomeaux[1000];
char nome[200];
int cad;
char acess;
switch(*escolha){
case 1:
    printf("Você jà possui Cadastro na plataforma?\n");
    printf("[1]-Sim\n");
    printf("[2]-Não\n");
    scanf("%d",&cad);
    opinvalida2(&cad);
break;
case 2:
	system("cls");
break;
}
    switch(cad){
case 1:
    printf("Deseja realizar devolução ou cadastrar novo veículo?\nPara devolução digite <s> ou  qualquer tecla diferente para Cadastrar!!\n");
    fflush(stdin);
    scanf("%c",&acess);
    if(acess=='s'){
            system("cls");
        printf("\t\t==================================================\n");
        printf("\t\t= \t\t     Acesso\t                 =\n");
        printf("\t\t\==================================================\n");
        printf("Digite o nome cadastrado\n");
         fflush(stdin);
       fgets(nome,sizeof(nome),stdin);
            nome[strlen(nome)-1]=nome[strlen(nome)];
    if(*pfouj==1){
        system("cls");
        switch(cliente.op){
            case 1:
                arq=Abrirarquivo("golnome.txt",'l');
            break;
            case 2:
                arq=Abrirarquivo("palionome.txt",'l');
            break;
            case 3:
                arq=Abrirarquivo("onixnome.txt",'l');
            break;
            case 4:
                arq=Abrirarquivo("cruzenome.txt",'l');
            break;
        }
    while(fgets(nomeaux,1000,arq)!=NULL){
        if(strcmp(nome,nomeaux)==0){
                 printf("***BEM VINDO***\n");printf("Nome:%s\n",nome); printf("\nQuer devolver o carro ou cadastrar novo veículo? \n1-Devolver \n2-Cadastrar\n");
                setbuf(stdin,NULL);
                scanf("%d",&resp);
                opinvalida2(&resp);
            }else{
                     printf("Usuário Não cadastrado");
                    switch(cliente.op){
                    case 1:
                            arq=Abrirarquivo("Golestoque.txt",'g');
                            fprintf(arq,"1");
                            fechararquivo(arq);
                            arq=Abrirarquivo("golvalor.txt",'g');
                            fprintf(arq,"");
                            fechararquivo(arq);
                    break;
                    case 2:
                            arq=Abrirarquivo("Palioestoque.txt",'g');
                            fprintf(arq,"1");
                            fechararquivo(arq);
                            arq=Abrirarquivo("paliovalor.txt",'g');
                            fprintf(arq,"");
                            fechararquivo(arq);
                    break;
                    case 3:
                            arq=Abrirarquivo("Onixestoque.txt",'g');
                            fprintf(arq,"1");
                            fechararquivo(arq);
                            arq=Abrirarquivo("onixvalor.txt",'g');
                            fprintf(arq,"");
                            fechararquivo(arq);
                    break;
                    case 4:
                            arq=Abrirarquivo("Cruzeestoque.txt",'g');
                            fprintf(arq,"1");
                            fechararquivo(arq);
                            arq=Abrirarquivo("cruzevalor.txt",'g');
                            fprintf(arq,"");
                            fechararquivo(arq);
                            system("cls");
                    break;}
            }
    }
    if(resp==1){
            switch(cliente.op){
                case 1:
                    pagamento();
                    arq=Abrirarquivo("Golestoque.txt",'g');
                    fprintf(arq,"1");
                    printf("Devolução efetuada com sucesso\n");
                    fechararquivo(arq);
                    arq=Abrirarquivo("golnome.txt",'g');
                    fprintf(arq,"1");
                    fechararquivo(arq);
                    arq=Abrirarquivo("golvalor.txt",'g');
                    fprintf(arq,"");
                    fechararquivo(arq);
                    arq=Abrirarquivo("Goldata.txt",'g');
                    fprintf(arq,"");
                    fechararquivo(arq);

                break;
                case 2:
                    pagamento();
                    arq=Abrirarquivo("Palioestoque.txt",'g');
                    fprintf(arq,"1");
                    printf("Devolução efetuada com sucesso\n");
                    fechararquivo(arq);
                    arq=Abrirarquivo("palionome.txt",'g');
                    fprintf(arq,"1");
                    fechararquivo(arq);
                    arq=Abrirarquivo("paliovalor.txt",'g');
                    fprintf(arq,"");
                    fechararquivo(arq);
                    arq=Abrirarquivo("Paliodata.txt",'g');
                    fprintf(arq,"");
                    fechararquivo(arq);
                break;
                case 3:
                    pagamento();
                    arq=Abrirarquivo("Onixestoque.txt",'g');
                    fprintf(arq,"1");
                    printf("Devolução efetuada com sucesso\n");
                    fechararquivo(arq);
                    arq=Abrirarquivo("onixnome.txt",'g');
                    fprintf(arq,"1");
                    fechararquivo(arq);
                    arq=Abrirarquivo("onixvalor.txt",'g');
                    fprintf(arq,"");
                    fechararquivo(arq);
                    arq=Abrirarquivo("Onixdata.txt",'g');
                    fprintf(arq,"");
                    fechararquivo(arq);
                break;
                case 4:
                    pagamento();
                    arq=Abrirarquivo("Cruzeestoque.txt",'g');
                    fprintf(arq,"1");
                    printf("Devolução efetuada com sucesso\n");
                    fechararquivo(arq);
                    arq=Abrirarquivo("cruzenome.txt",'g');
                    fprintf(arq,"1");
                    fechararquivo(arq);
                    arq=Abrirarquivo("cruzevalor.txt",'g');
                    fprintf(arq,"");
                    fechararquivo(arq);
                    arq=Abrirarquivo("Cruzedata.txt",'g');
                    fprintf(arq,"");
                    fechararquivo(arq);
                break;
            }
        }
fechararquivo(arq);
system("cls");
system("pause");
cliente.op=5;
    if(resp==2){
        system("cls");
    }
}else{
    system("cls");
   switch(cliente.op){
        case 1:
            arq=Abrirarquivo("golnome.txt",'l');
        break;
        case 2:
            arq=Abrirarquivo("palionome.txt",'l');
        break;
        case 3:
            arq=Abrirarquivo("onixnome.txt",'l');
        break;
        case 4:
            arq=Abrirarquivo("cruzenome.txt",'l');
        break;
    }
   while(fgets(nomeaux,1000,arq)!=NULL){
          if(strcmp(nome,nomeaux)==0){
            printf("***BEM VINDO***\n"); printf("Nome:%s\n",nome);printf("\nQuer devolver o carro ou cadastrar novo veículo? \n1-Devolver \n2-Cadastrar\n");
            setbuf(stdin,NULL);
            scanf("%d",&resp);
            opinvalida2(&resp);
          }else{
                printf("Usuário Não cadastrado");
                 switch(cliente.op){
            case 1:
                    arq=Abrirarquivo("Golestoque.txt",'g');
                    fprintf(arq,"1");
                    fechararquivo(arq);
                    arq=Abrirarquivo("golvalor.txt",'g');
                    fprintf(arq,"");
                    fechararquivo(arq);
                break;
            case 2:
                    arq=Abrirarquivo("Palioestoque.txt",'g');
                    fprintf(arq,"1");
                    fechararquivo(arq);
                    arq=Abrirarquivo("paliovalor.txt",'g');
                    fprintf(arq,"");
                    fechararquivo(arq);
            break;
            case 3:
                    arq=Abrirarquivo("Onixestoque.txt",'g');
                    fprintf(arq,"1");
                    fechararquivo(arq);
                    arq=Abrirarquivo("onixvalor.txt",'g');
                    fprintf(arq,"");
                    fechararquivo(arq);
            break;
            case 4:
                    arq=Abrirarquivo("Cruzeestoque.txt",'g');
                    fprintf(arq,"1");
                    fechararquivo(arq);
                    arq=Abrirarquivo("cruzevalor.txt",'g');
                    fprintf(arq,"");
                    fechararquivo(arq);
                    system("cls");
            break;}
          }
    }
     if(cliente.op=1){
        if(resp==1){
                pagamento();
                arq=Abrirarquivo("Golestoque.txt",'g');
                fprintf(arq,"1");
                printf("Devolução efetuada com sucesso\n");
                fechararquivo(arq);
                arq=Abrirarquivo("golnome.txt",'g');
                fprintf(arq,"1");
                fechararquivo(arq);
                arq=Abrirarquivo("golvalor.txt",'g');
                fprintf(arq,"");
                fechararquivo(arq);
                arq=Abrirarquivo("Goldata.txt",'g');
                fprintf(arq,"");
                fechararquivo(arq);
                }
        if(cliente.op=2){
                pagamento();
                arq=Abrirarquivo("Palioestoque.txt",'g');
                fprintf(arq,"1");
                printf("Devolução efetuada com sucesso\n");
                fechararquivo(arq);
                arq=Abrirarquivo("palionome.txt",'g');
                fprintf(arq,"");
                fechararquivo(arq);
                arq=Abrirarquivo("paliovalor.txt",'g');
                fprintf(arq,"");
                fechararquivo(arq);
                arq=Abrirarquivo("Paliodata.txt",'g');
                fprintf(arq,"");
                fechararquivo(arq);
            }
        if(cliente.op=3){
                pagamento();
                arq=Abrirarquivo("Onixestoque.txt",'g');
                fprintf(arq,"1");
                printf("Devolução efetuada com sucesso\n");
                fechararquivo(arq);
                arq=Abrirarquivo("onixnome.txt",'g');
                fprintf(arq,"1");
                fechararquivo(arq);
                arq=Abrirarquivo("onixvalor.txt",'g');
                fprintf(arq,"");
                fechararquivo(arq);
                arq=Abrirarquivo("Onixdata.txt",'g');
                fprintf(arq,"");
                fechararquivo(arq);
            }
        if(cliente.op=4){
                pagamento();
                arq=Abrirarquivo("Cruzeestoque.txt",'g');
                fprintf(arq,"1");
                printf("Devolução efetuada com sucesso\n");
                fechararquivo(arq);
                arq=Abrirarquivo("cruzenome.txt",'g');
                fprintf(arq,"1");
                fechararquivo(arq);
                arq=Abrirarquivo("cruzevalor.txt",'g');
                fprintf(arq,"");
                fechararquivo(arq);
                arq=Abrirarquivo("Cruzedata.txt",'g');
                fprintf(arq,"");
                fechararquivo(arq);
            }
        }
    fechararquivo(arq);
    if(resp==2){
        system("cls");
    }
}
}else{
    switch(cliente.op){
    case 1:
        arq=Abrirarquivo("golnome.txt",'l');break;
    case 2:
        arq=Abrirarquivo("palionome.txt",'l');break;
    case 3:
       arq=Abrirarquivo("onixnome.txt",'l');break;
    case 4:
        arq=Abrirarquivo("cruzenome.txt",'l');break;
}
    int x;
    while(fgets(nomeaux,1000,arq)!=NULL){

    }
     for(x=0;x<1000;x++){
            if(nomeaux[x]=='1'){
            printf("Carro Liberado!!\n");break;}else{printf("Carro alugado!!\n\n");return 1;
            }
        }
     fechararquivo(arq);
    printf("\nUsuário Consta na base de Dados?\nSim aperte <s> ou qualquer tecla diferente para Não!!\n");
    listar();
    fflush(stdin);
    scanf("%c",&acess);
    if(acess=='s'){
            printf("Digite seu nome\n");
            fflush(stdin);
            fgets(nome,sizeof(nome),stdin);
            nome[strlen(nome)-1]=nome[strlen(nome)];
      switch(cliente.op){
        case 1:
                arq=Abrirarquivo("golnome.txt",'g');
                fprintf(arq,"%s",nome);
                tipos(&cliente.op);
                devolucao();
                fechararquivo(arq);
        break;
        case 2:
                arq=Abrirarquivo("palionome.txt",'g');
                fprintf(arq,"%s",nome);
                tipos(&cliente.op);
                devolucao();
                fechararquivo(arq);
        break;
        case 3:
                arq=Abrirarquivo("onixnome.txt",'g');
                fprintf(arq,"%s",nome);
                tipos(&cliente.op);
                devolucao();
                    fechararquivo(arq);
        break;
        case 4:
                arq=Abrirarquivo("cruzenome.txt",'g');
                fprintf(arq,"%s",nome);
                tipos(&cliente.op);
                devolucao();
                fechararquivo(arq);
                system("cls");
    break;}
    }else{
        switch(cliente.op){
        case 1:
            arq=Abrirarquivo("Golestoque.txt",'g');
            fprintf(arq,"1");
            fechararquivo(arq);
            arq=Abrirarquivo("golvalor.txt",'g');
            fprintf(arq,"");
            fechararquivo(arq);
        break;
        case 2:
            arq=Abrirarquivo("Palioestoque.txt",'g');
            fprintf(arq,"1");
            fechararquivo(arq);
            arq=Abrirarquivo("paliovalor.txt",'g');
            fprintf(arq,"");
            fechararquivo(arq);
        break;
        case 3:
            arq=Abrirarquivo("Onixestoque.txt",'g');
            fprintf(arq,"1");
            fechararquivo(arq);
            arq=Abrirarquivo("onixvalor.txt",'g');
            fprintf(arq,"");
            fechararquivo(arq);
        break;
        case 4:
            arq=Abrirarquivo("Cruzeestoque.txt",'g');
            fprintf(arq,"1");
            fechararquivo(arq);
            arq=Abrirarquivo("cruzevalor.txt",'g');
            fprintf(arq,"");
            fechararquivo(arq);
            system("cls");
        break;}
    }

break;
case 2:
	system("cls");
	if(*pfouj==1){
        pf(&pfouj);
    	}else{
            pj(&pfouj);
    	}
break;
default :
    system("pause");
     fflush(stdin);
      system("cls");
break;
      }
      fechararquivo(arq);
      fechararquivo(aq);

return cad;
    }
}
void opinvalida(int *p){//Verifica se a escolha condiz com as opções de 1 a 5!!
do{
    if(*p>=1&&*p<=5){

    }else{
        printf("\nOpção Invalida!! Verifique o MENU Novamente!!");
        printf("\nEscolha uma das opções acima para prosseguirmos com o aluguel do veículo!!\n");
        scanf("%d",&*p);
        printf("\n");
    }
}while(*p>5);
}
void opinvalida2(int *q){//Verifica se a escolha condiz com as opções de 1 a 2!!
do{
    if(*q>=1&&*q<=2){

    }else{
        printf("\nOpção Invalida!! Verifique o MENU Novamente!!");
        printf("\nEscolha uma das opções acima para prosseguirmos com o aluguel do veículo!!\n");
        scanf("%d",&*q);
        printf("\n");
    }
}while(*q>2);
}
FILE*Abrirarquivo(char caminho[30],char modo){//Permite a escolha da opção desejada de modo de abertura de arquivos!!
FILE*arq;
switch(modo){
case 'g':
    arq=fopen(caminho,"wt");
    break;
case 'l':
    arq=fopen(caminho,"rt");
    break;
case 'a':
    arq=fopen(caminho,"a");
    break;
case'x':
    arq=fopen(caminho,"wb");
    break;
case 'y':
    arq=fopen(caminho,"rb");
    break;
case 'b':
    arq=fopen(caminho,"ab");
    break;
}
return arq;
}
void fechararquivo(FILE*arq){
fclose(arq);
}
void devolucao(){ //Função responsável pelo cálculo da data e horário da devolução do veículo!!
char nometicket[200];
FILE*arq;
FILE*aq;
int dev;
struct tm *local;
time_t t;
t=(time(NULL));
local=localtime(&t);
int dia,mes,ano;
int hora,min;
dia=local->tm_mday;
mes=local->tm_mon+1;
ano=local->tm_year+1900;
hora=local->tm_hour;
min=local->tm_min;
double h;
double mn;
h=(double)hora;
mn=(double)(min*0.01);
double horaat=h+mn;
double horadev;
printf("\nData de hoje\n%d/%d/%d\tHoras:%0.2lf\n\n",dia,mes,ano,horaat);
printf("Digite a hora da retirada como mostrado acima\n");
scanf("%lf",&horadev);
while(horadev<=horaat){
            printf("Hora menor do que a hora atual\nDigite novamente\n");
            scanf("%lf",&horadev);
    }
while(horadev<1||horadev>24.00){
        printf("Horario inexistente\n");
        scanf("%lf",&horadev);
    }
dev=cliente.dias+dia;
if(dev>30&&mes==11||mes==4||mes==9||mes==6){
            dev=dev-30;
            mes=mes+1;
            printf("Data da devolução %d/%d/%d %0.2lf\n",dev,mes,ano,horadev);
    switch(cliente.op){
        case 1:arq=Abrirarquivo("golnome.txt",'l');break;
        case 2:arq=Abrirarquivo("palionome.txt",'l');break;
        case 3:arq=Abrirarquivo("onixnome.txt",'l');break;
        case 4:arq=Abrirarquivo("cruzenome.txt",'l');break;
        }
    while(fgets(nometicket,200,arq)!=NULL){
        printf("\n===TICKET===\n");
        printf("Data do aluguel:%d/%d/%d Horario:%0.2lf\n",dia,mes,ano,horaat);
        printf("Data da devolução:%d/%d/%d Horario:%0.2lf\n",dev,mes,ano,horadev);
        printf("Nome:%s\n",nometicket);
        tipos(&cliente.op);
    }
    switch(cliente.op){
        case 1:
                arq=Abrirarquivo("Goldata.txt",'g');
                fprintf(arq,"%d/%d/%d %d %0.2lf",dev,mes,ano,cliente.dias,horadev);
                fechararquivo(arq);
        break;
        case 2:
                arq=Abrirarquivo("Paliodata.txt",'g');
                fprintf(arq,"%d/%d/%d %d %0.2lf",dev,mes,ano,cliente.dias,horadev);
                fechararquivo(arq);
        break;
        case 3:
                arq=Abrirarquivo("Onixdata.txt",'g');
                fprintf(arq,"%d/%d/%d %d %0.2lf",dev,mes,ano,cliente.dias,horadev);
                fechararquivo(arq);
        break;
        case 4:
                arq=Abrirarquivo("Cruzedata.txt",'g');
                fprintf(arq,"%d/%d/%d %d %0.2lf",dev,mes,ano,cliente.dias,horadev);
                fechararquivo(arq);
        break;
    }
        system("pause");
        system("cls");
        return;
}
if(dev>31&&mes==1||mes==3||mes==5||mes==8||mes==10||mes==7){
        dev=dev-31;
        mes=mes+1;
        printf("Data da devolução %d/%d/%d %0.2lf",dev,mes,ano,horadev);
        switch(cliente.op){
            case 1:arq=Abrirarquivo("golnome.txt",'l');break;
            case 2:arq=Abrirarquivo("palionome.txt",'l');break;
            case 3:arq=Abrirarquivo("onixnome.txt",'l');break;
            case 4:arq=Abrirarquivo("cruzenome.txt",'l');break;
        }
    while(fgets(nometicket,200,arq)!=NULL){
        printf("===TICKET===\n");
        printf("Data do aluguel:%d/%d/%d Horario:%0.2lf\n",dia,mes,ano,horaat);
        printf("Data da devolução:%d/%d/%d Horario:%0.2lf\n",dev,mes,ano,horadev);
        printf("Nome:%s\n",nometicket);
        tipos(&cliente.op);
        }
        system("pause");
        system("cls");
        return;
}
if(ano%4==0){
    if(mes==2){
        if(dia>29&&mes==2){
                dev-=29;
            mes=mes+1;
             while(fgets(nometicket,200,arq)!=NULL){
                printf("===TICKET===\n");
                printf("Data do aluguel:%d/%d/%d Horario:%0.2lf\n",dia,mes,ano,horaat);
                printf("Data da devolução:%d/%d/%d Horario:%0.2lf\n",dev,mes,ano,horadev);
                printf("Nome:%s\n",nometicket);
                tipos(&cliente.op);
        }
        system("pause");
        system("cls");
        return;

        }
    }
}else{
        if(dia>28&&mes==2){
                dev-=28;
            mes=mes+1;
             while(fgets(nometicket,200,arq)!=NULL){
                printf("===TICKET===\n");
                printf("Data do aluguel:%d/%d/%d Horario:%0.2lf\n",dia,mes,ano,horaat);
                printf("Data da devolução:%d/%d/%d Horario:%0.2lf\n",dev,mes,ano,horadev);
                printf("Nome:%s\n",nometicket);
                tipos(&cliente.op);
        }
        system("pause");
        system("cls");
        return;

        }

    }
if(dev>31&&mes==12){
        dev=dev-31;
        mes=1;
        ano=ano+1;
        printf("Data da devolução %d/%d/%d %0.2lf",dev,mes,ano,horadev);
        switch(cliente.op){
            case 1:arq=Abrirarquivo("golnome.txt",'l');break;
            case 2:arq=Abrirarquivo("palionome.txt",'l');break;
            case 3:arq=Abrirarquivo("onixnome.txt",'l');break;
            case 4:arq=Abrirarquivo("cruzenome.txt",'l');break;
        }
    while(fgets(nometicket,200,arq)!=NULL){
        printf("\n===TICKET===\n");
        printf("Data do aluguel:%d/%d/%d Horario:%0.2lf\n",dia,mes,ano,horaat);
        printf("Data da devolução:%d/%d/%d Horario:%0.2lf\n",dev,mes,ano,horadev);
        printf("Nome:%s\n",nometicket);
        tipos(&cliente.op);
        }
        switch(cliente.op){
        case 1:
                arq=Abrirarquivo("Goldata.txt",'g');
                fprintf(arq,"%d/%d/%d %d %0.2lf",dev,mes,ano,cliente.dias,horadev);
                fechararquivo(arq);
        break;
        case 2:
                arq=Abrirarquivo("Paliodata.txt",'g');
                fprintf(arq,"%d/%d/%d %d %0.2lf",dev,mes,ano,cliente.dias,horadev);
                fechararquivo(arq);
        break;
        case 3:
                arq=Abrirarquivo("Onixdata.txt",'g');
                fprintf(arq,"%d/%d/%d %d %0.2lf",dev,mes,ano,cliente.dias,horadev);
                fechararquivo(arq);
        break;
        case 4:
                arq=Abrirarquivo("Cruzedata.txt",'g');
                fprintf(arq,"%d/%d/%d %d %0.2lf",dev,mes,ano,cliente.dias,horadev);
                fechararquivo(arq);
        break;
    }
        system("pause");
        system("cls");
        return;
}
printf("Data da devolução %d/%d/%d %0.2lf\n",dev,mes,ano,horadev);
switch(cliente.op){
case 1:arq=Abrirarquivo("golnome.txt",'l');break;
case 2:arq=Abrirarquivo("palionome.txt",'l');break;
case 3:arq=Abrirarquivo("onixnome.txt",'l');break;
case 4:arq=Abrirarquivo("cruzenome.txt",'l');break;
}
while(fgets(nometicket,200,arq)!=NULL){
    printf("\n===TICKET===\n");
    printf("Data do aluguel:%d/%d/%d Horario:%0.2lf\n",dia,mes,ano,horaat);
    printf("Data da devolução:%d/%d/%d Horario:%0.2lf\n",dev,mes,ano,horadev);
    printf("Nome:%s\n",nometicket);
    tipos(&cliente.op);
}
switch(cliente.op){
        case 1:
                arq=Abrirarquivo("Goldata.txt",'g');
                fprintf(arq,"%d/%d/%d %d %0.2lf",dev,mes,ano,cliente.dias,horadev);
                fechararquivo(arq);
        break;
        case 2:
                arq=Abrirarquivo("Paliodata.txt",'g');
                fprintf(arq,"%d/%d/%d %d %0.2lf",dev,mes,ano,cliente.dias,horadev);
                fechararquivo(arq);
        break;
        case 3:
                arq=Abrirarquivo("Onixdata.txt",'g');
                fprintf(arq,"%d/%d/%d %d %0.2lf",dev,mes,ano,cliente.dias,horadev);
                fechararquivo(arq);
        break;
        case 4:
                arq=Abrirarquivo("Cruzedata.txt",'g');
                fprintf(arq,"%d/%d/%d %d %0.2lf",dev,mes,ano,cliente.dias,horadev);
                fechararquivo(arq);
        break;
    }

system("pause");
system("cls");
}
void entrada(char enter[1000],char opcao,int tamanho){/*Função com objetivo de validar a entrada
para não permitir valores indevidos nos campos*/
int x;
switch(opcao){
case 'n':
    for(x=0;x<strlen(enter);x++){
        while(isalpha(enter[x])){
            printf("O valor de entrada nao pode ser do tipo letra\nDigite Novamente\n");
            fflush(stdin);
            scanf("%s",&enter[x]);
        }
        while(strlen(enter)<tamanho||strlen(enter)>tamanho){
                if(strlen(enter)<tamanho){
                    printf("Valor muito curto \nDigite novamente\n");
                    fflush(stdin);
                    scanf("%s",&enter[x]);
                }
                if(strlen(enter)>tamanho){
                        printf("Valor muito grande \nDigite novamente\n");
                        fflush(stdin);
                        scanf("%s",&enter[x]);
                }
        }
    }
break;
case 'l':
    for(x=0;x<strlen(enter);x++){
        while(isdigit(enter[x])){
            printf("O valor de entrada nao pode ser do tipo numerico\nDigite Novamente\n");
            fflush(stdin);
           fgets(enter,tamanho,stdin);
           }
}
break;
case 'x':
     while(strlen(enter)<tamanho){
                    printf("entrada muito curta \nDigite novamente\n");
                    fflush(stdin);
                   fgets(enter,tamanho,stdin);
                }
    break;
    }
}
int tipos(int *tipos){//Função responsável por ler do arquivo a respectiva placa do veículo e exibir na Tela!!
FILE*arq;
char placas[1000];
switch(*tipos){
case 1:
        arq=Abrirarquivo("GolPlaca.txt",'l');
        while(fgets(placas,1000,arq)!=NULL){
            printf("Gol Placa:%s\n",placas);
        }
    fechararquivo(arq);
    break;
case 2:
     arq=Abrirarquivo("PalioPlaca.txt",'l');
      while(fgets(placas,1000,arq)!=NULL){
            printf("Palio Placa:%s\n",placas);
      }
    fechararquivo(arq);
    break;
case 3:
     arq=Abrirarquivo("OnixPlaca.txt",'l');
      while(fgets(placas,1000,arq)!=NULL){
        printf("Onix Placa:%s\n",placas);
      }
    fechararquivo(arq);
    break;
case 4:
     arq=Abrirarquivo("CruzePlaca.txt",'l');
      while(fgets(placas,1000,arq)!=NULL){
        printf("Cruze Placa:%s\n",placas);
      }
    fechararquivo(arq);
    break;
    }
}
void listar(){//Função com objetivo de exibir na Tela os nomes dos clientes cadastrados para próximos alugueis!!
FILE *arq;
char teste[1000];
arq=Abrirarquivo("nomes.txt",'l');
while(fgets(teste,1000,arq)!=NULL){
    printf("%s",teste);
}
fechararquivo(arq);
}
void pagamento(){/*Área reservada para pagamento da diária do veículo e Cálculo
da multa de atraso e do troco se houver*/
double valor_rec;
double valoraux;
int dias;
FILE*arq;
FILE*aq;
int datual,mesatual,anoatual,diadev,mesdev,anodev,hora,min;
double h,mn;
double valor;
double hatual,horadev;
struct tm*local;
time_t t;
t=time(NULL);
local=localtime(&t);
datual=local->tm_mday;
mesatual=local->tm_mon+1;
anoatual=local->tm_year+1900;
hora=local->tm_hour;
min=local->tm_min;
h=(double)hora;
mn=(double)(min*0.01);
hatual=(h+mn);
char x;
switch(cliente.op){
case 1:
    arq=Abrirarquivo("golvalor.txt",'l');
break;
case 2:
    arq=Abrirarquivo("paliovalor.txt",'l');
break;
case 3:
    arq=Abrirarquivo("onixvalor.txt",'l');
break;
case 4:
    arq=Abrirarquivo("cruzevalor.txt",'l');
break;
 }
fscanf(arq,"%c %lf",&x,&valor);
fechararquivo(arq);
switch(cliente.op){
case 1:
    arq=Abrirarquivo("Goldata.txt",'l');
break;
case 2:
    arq=Abrirarquivo("Paliodata.txt",'l');
break;
case 3:
    arq=Abrirarquivo("Onixdata.txt",'l');
break;
case 4:
    arq=Abrirarquivo("Cruzedata.txt",'l');
break;
 }
fscanf(arq,"%d/%d/%d %d %lf",&diadev,&mesdev,&anodev,&dias,&horadev);
fechararquivo(arq);
if(diadev==datual&&mesatual==mesdev&&anoatual==anodev){
    if(hatual>horadev){
            dias*=24;
            hatual-=horadev;
            hatual*=valor;
            hatual/=dias;
            valoraux=hatual;

    }
}else{
valoraux=0;
}
if(datual>diadev&&mesatual==mesdev&&anoatual==anodev){
        dias*=24;
        if(hatual>horadev){
            datual-=diadev;
            datual*=24;
            hatual-=horadev;
            hatual+=datual;
            hatual*=valor;
            hatual/=dias;
            valoraux=hatual;
        }else{
            datual-=diadev;
            datual*=24;
            horadev-=hatual;
            horadev+=datual;
            horadev*=valor;
            horadev/=dias;
            valoraux=horadev;
           }

}else{
    valoraux=0;
}
if(mesatual>mesdev){
    if(diadev==datual&&mesatual!=mesdev&&anoatual==anodev){
            dias*=24;
            mesatual-=mesdev;
            mesatual*=30;
            mesatual*=24;
            mesatual*=valor;
            mesatual/=dias;
            valoraux=mesatual;
            }

    if(diadev!=datual&&mesatual!=mesdev&&anoatual==anodev){
            int d;
            if(diadev>datual){
                diadev-=datual;
                d=diadev;
            }else{datual-=diadev;
                    d=datual;
                }
    dias*=24;
    d*=24;
    mesatual-=mesdev;
    mesatual*=30;
    mesatual*=24;
    mesatual+=d;
    mesatual*=valor;
    mesatual/=dias;
    valoraux=mesatual;
    }
}else{
    valoraux=0;
}
valor+=valoraux;
printf("Valor a ser pago:%0.2lf\nMulta de atraso no valor de %0.2lf  \n",valor,valoraux);
printf("Valor recebido como pagamento!!\n");
scanf("%lf",&valor_rec);
while(valor_rec<valor){
        printf("Digite novemente o valor\nValor menor do o previsto\n");
scanf("%lf",&valor_rec);
}
if(valor_rec>valor){
    valor_rec-=valor;
    printf("Troco de %.2f reais \n",valor_rec);
    system("pause");
    printf("\nSair....\n");
    system("cls");
    cliente.op=5;
    }
}
