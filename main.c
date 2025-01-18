#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void tela(int *tabuleiro);
void tutorial();
int inicia(int *tabuleiro);
int jogada(int *tabuleiro, int jogador);
int vencedor(int *tabuleiro);

int main()
{
    srand(time(NULL));
    
    int jog=0,venc=0;

    int tabuleiro[9];
    int modo = inicia(tabuleiro);
    tutorial();
    while(venc==0)
    {
        tela(tabuleiro);
        if(jog%2==0)
        {
            jog += jogada(tabuleiro,1);
        }
        else if(modo==2)
        {
            jog += jogada(tabuleiro,2);
        }
        else if(modo==1)
        {
            jog += jogada(tabuleiro,-1);
        }
        venc = vencedor(tabuleiro);
        if(jog==9)
        {
            printf("EMPATE");
            tela(tabuleiro);
            break;
        }
    }
    printf("\n");
    if(venc == 1)
    {
        printf("Jogador 1 e o vencedor\n");
    }
    if(venc == 2)
    {
        if(modo == 2)
        {
            printf("Jogador 2 e o vencedor\n");
        }
        else
        {
            printf("Computador e o vencedor\n");
        }
    }
    tela(tabuleiro);
    return 0;
}

void tela(int *tabuleiro)
{
    int i;
    for(i=0; i<9; i++)
    {
        if(tabuleiro[i]==1)
        {
            printf("x|");
        }
        if(tabuleiro[i]==2)
        {
            printf("o|");
        }
        if(tabuleiro[i]==0)
        {
            printf(" |");
        }
        if((i==2)||(i==5)||(i==8))
        {
            printf("\n");
        }
    }
}
void tutorial()
{
    printf("Mapa de posicoes:\n\n");
    printf("_1_|_2_|_3_\n");
    printf("_4_|_5_|_6_\n");
    printf("_7_|_8_|_9_\n\n");
}
int inicia(int *tabuleiro)
{
    int n=0,i;
    while(n==0)
    {
        printf("Digite 1 para jogar contra o computador e 2 para jogar contra outra pessoa:\n");
        scanf("%d",&n);
        if(n>2)
        {
            printf("Comando invalido!!!\n");
            n=0;
        }
    }
    for(i=0; i<9; i++)
    {
        tabuleiro[i]=0;
    }
    printf("\ninicializando\n\n\n");
    return n;
}
int jogada(int *tabuleiro, int jogador)
{
    int pos, valido=0;
    if(jogador==-1)
    {
        printf("Computador: \n");
        while(valido==0)
        {
            pos = rand()%9;
            if(tabuleiro[pos]==0)
            {
                tabuleiro[pos]=2;
                valido = 1;
            }
        }
        return 1;
    }
    printf("Jogador %d:",jogador);
    scanf("%d",&pos);
    pos--;
    if(tabuleiro[pos]!=0)
    {
        printf("Jogada Invalida!!!\n");
        return 0;
    }
    else
    {
        tabuleiro[pos]=jogador;
        return 1;
    }
}
int vencedor(int *tabuleiro)
{
    if((tabuleiro[0]==tabuleiro[1])&&(tabuleiro[1]==tabuleiro[2]))
    {
        if(tabuleiro[0]!=0)
        {
            return tabuleiro[0];
        }
    }
    if((tabuleiro[3]==tabuleiro[4])&&(tabuleiro[4]==tabuleiro[5]))
    {
        if(tabuleiro[3]!=0)
        {
            return tabuleiro[3];
        }
    }
    if((tabuleiro[6]==tabuleiro[7])&&(tabuleiro[7]==tabuleiro[8]))
    {
        if(tabuleiro[6]!=0)
        {
            return tabuleiro[6];
        }
    }
    if((tabuleiro[0]==tabuleiro[3])&&(tabuleiro[3]==tabuleiro[6]))
    {
        if(tabuleiro[0]!=0)
        {
            return tabuleiro[0];
        }
    }
    if((tabuleiro[1]==tabuleiro[4])&&(tabuleiro[4]==tabuleiro[7]))
    {
        if(tabuleiro[1]!=0)
        {
            return tabuleiro[1];
        }
    }
    if((tabuleiro[2]==tabuleiro[5])&&(tabuleiro[5]==tabuleiro[8]))
    {
        if(tabuleiro[2]!=0)
        {
            return tabuleiro[2];
        }
    }
    if((tabuleiro[0]==tabuleiro[4])&&(tabuleiro[4]==tabuleiro[8]))
    {
        if(tabuleiro[0]!=0)
        {
            return tabuleiro[0];
        }
    }
    if((tabuleiro[2]==tabuleiro[4])&&(tabuleiro[4]==tabuleiro[6]))
    {
        if(tabuleiro[2]!=0)
        {
            return tabuleiro[2];
        }
    }
    return 0;
}
