#include <stdio.h>
#include <stdlib.h>

typedef struct
{
	char nome[15];
    int cpf;
    float saldo;
}campos;

void abrirConta(campos contas[10], int *prox);
void mostrarConta(campos contas[10], int *prox);
void saque(campos contas[10], int *prox);
void deposito(campos contas[10], int *prox);
void transferencia (campos contas[10], int *prox);

int main()
{
    campos contas[10];
    int opcao, prox=0;

    printf("\nMenu:\n");
    printf("\n1- Abrir conta;\n2- Mostrar conta;\n3- Saque;\n4- Deposito;\n5-Transferencia;\n6- Sair;\n");

    do
    {
        printf("\nOpcao:\n");
        scanf("%d", &opcao);

        switch(opcao)
        {
            case 1:
                if(prox<10)
                {
                    abrirConta(contas, &prox);
                }
                else
                {
                    printf("\nSistema incapaz de gerenciar mais de 10 contas.\n");
                }
            break;

            case 2:
                mostrarConta(contas, &prox);
            break;

            case 3:
                saque(contas, &prox);
            break;

            case 4:
                deposito(contas, &prox);
            break;

            case 5:
            	transferencia(contas, &prox);
            break;
            
            case 6:
            break;

            default:
                printf("\nOpcao invalida.\n");
            break;

        }


    }while(opcao!=6);

    return 0;
}

void abrirConta(campos contas[10], int *prox)
{
	printf("\nNome:\n");
	scanf("%s", &contas[*prox].nome);
	
    printf("\nCPF:\n");
    scanf("%d", &contas[*prox].cpf);

    printf("\nSaldo atual:\n");
    scanf("%f", &contas[*prox].saldo);

    *prox=*prox+1;
}

void mostrarConta(campos contas[10], int *prox)
{
    int i;

    for(i=0;i<*prox;i++)
    {
    	printf("\nNome: %s\n", contas[i].nome);
        printf("\nSaldo Atual: R$%.2f\n", contas[i].saldo);  
    }
}

void saque(campos contas[10], int *prox)
{
    int i, cpf;
    float retirada;

    printf("\nDigite o CPF:\n");
    scanf("%d", &cpf);

    for(i=0;i<*prox;i++)
    {
        if(cpf==contas[i].cpf)
        {
            printf("\nValor do saque:\n");
            scanf("%f", &retirada);

            printf("\nValor retirado: %.2f\n", retirada);

            contas[i].saldo = contas[i].saldo-retirada;

            printf("\nNome: %s\n", contas[i].nome);
            printf("\nSaldo Atual: R$%.2f\n", contas[i].saldo);
		}
        else
        {
            printf("\nConta nao cadastrada.\n");
        }
    }
}

void deposito(campos contas[10], int *prox)
{
    int i, cpf;
    float adicao;

    printf("\nDigite o CPF:\n");
    scanf("%d", &cpf);

    for(i=0;i<*prox;i++)
    {
        if(cpf==contas[i].cpf)
        {
            printf("\nValor do deposito:\n");
            scanf("%f", &adicao);

            printf("\nValor depositado: %.2f\n", adicao);

            contas[i].saldo= contas[i].saldo+adicao;

            printf("\nNome: %s\n", contas[i].nome);
            printf("\nSaldo Atual: R$%.2f\n", contas[i].saldo);
        }
        else
        {
            printf("\nConta nao cadastrada.\n");
        }
    }
}

void transferencia (campos contas[10], int *prox)
{
	int i, j, cpfRemetente, cpfDestinatario;
	float valor;
	
	printf("\nCPF remetente:\n");
	scanf("%d", &cpfRemetente);
	
	for(i=0;i<*prox;i++)
	{
		if(cpfRemetente==contas[i].cpf)
		{
			printf("\nCPF destinatario:\n");
			scanf("%d", &cpfDestinatario);
			
			for(j=0;j<*prox;j++)
			{
				if(cpfDestinatario==contas[j].cpf)
				{
					printf("\nDigite o valor a ser transferido:\n");
					scanf("%f", &valor);
					
					contas[i].saldo=contas[i].saldo-valor;
					contas[j].saldo=contas[j].saldo+valor;
					
					printf("\nNome: %s\n", contas[i].nome);
            		printf("\nSaldo Atual: R$%.2f\n", contas[i].saldo);
            		
            		printf("\nNome: %s\n", contas[j].nome);
            		printf("\nSaldo Atual: R$%.2f\n", contas[j].saldo);
				}
				else
				{
					printf("\nConta nao encontrada.\n");
				}
			}
		}
		else
		{
			printf("\nConta nao encontrada.\n");
		}
	}
}
