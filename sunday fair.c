#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//********************************************************************
//***                                                              ***
//***               PROGRAMA FEIRA DE DOMINGO                      ***
//***                                                              ***
//*** ( Busca_binaria de strings c/ alocacao dinamica de memoria ) ***
//*** ( 	     Ordena pelo Método da Bolha                 ) ***
//*** (              Autor: Carlos A. Martinhon                  ) ***
//***                                                              ***
//********************************************************************


struct Feira
{
    char fruta[15];
    float quantidade;                  // quantidade em em Kg
    float preco;                       // preço em R$
    char validade[11];
};

//===============================================================
//==================   Programa Principal =======================
//===============================================================

int main()
{
    char senha[15];
    int tentativa =3;
    int Executa_Feira();              // protótipo de função

    system("Color 1F");               // Munda fundo p/ cor azul c/ letras brancas

    printf("\n********************************* ");
    printf("\n**  Programa Feira de Domingo  ** ");
    printf("\n********************************* ");

    do {
        printf("\n\nEntre com a senha --> ");
        scanf("%s", senha);

        if (strcmp(senha,"seriguela")==0)
            tentativa = Executa_Feira();   // tentativa recebe 0

        else
        {
            tentativa = tentativa-1;
            printf("\n\nSenha incorreta !! Mais %d tentativas !", tentativa);
            if (tentativa == 0)
                printf("\n\n\a LAMENTO! CONTA BLOQUEADA !!\n\n");
        }
    }
    while (tentativa != 0);

    return 0;
}
//===============================================================

int Executa_Feira()
{
    int n=0;                                     // Inicializa n (total de frutas) com 0
    struct Feira **F;

    void Ordena(struct Feira **, int);           // Protótipo da função de ordenação
    struct Feira**  preenche_dados(int*);        // Protótipo de funções
    void imprime_relatorio(struct Feira **, int);

    F = preenche_dados(&n);     // n representa o total de frutas

    Ordena(F, n);               // Função para ordenação dos registros pelo campo nome das frutas

    imprime_relatorio(F, n);    // Imprime relatório final com registros ordenados por fruta

    return 0;
}
//===============================================================

struct Feira** preenche_dados(int* tam)
{
    struct Feira** F;
    int i;

    printf("\n******************************************\n");
    printf("\nBem vindo(a) 'a Feira de Domingo !! ");
    printf("\n\nEntre com o tamanho da lista de frutas --> ");
    scanf("%d", tam);            // Nota: tam é ponteiro para inteiro

    F = (struct Feira**)malloc((*tam)*sizeof(struct Feira*));
    for (i=0; i<(*tam); i++)
        F[i]=(struct Feira*)malloc(sizeof(struct Feira));

    printf("\n");
    for (i=0; i<(*tam); i++)    // Preenche campos da struct
    {
        printf("\n");
        printf("Entre com a fruta %d = ", i+1);
        scanf("%s", F[i]->fruta);
        printf("Entre com a quantidade de %ss (em Kg) = ", F[i]->fruta);
        scanf("%f", &F[i]->quantidade);
        printf("Entre com valor unitario (em Reais) = ");
        scanf("%f", &F[i]->preco);
        printf("Entre com a data de validade (dd/mm/aaaa) = ");
        scanf("%s", F[i]->validade);
    }

    return F;        // Retorna ponteiro pra ponteiro do registro
}
//===============================================================

void imprime_relatorio(struct Feira** F, int n)
{
    float custo_total = 0;    // Inicializa custo total das mercadorias
    float custo_unit;         // custo de uma mercadoria

    printf("\n************  Relatorio Final ****************\n");

    for (int i=0;i<n;i++)
    {
        printf("\n");
        printf("Fruta[%d] --> %s\n", i+1, F[i]->fruta);
        printf("Valor unitario --> %.2f R$\n", F[i]->preco);
        printf("Quantidade --> %f \n", F[i]->quantidade);
        printf("Validade --> %s\n", F[i]->validade);
        custo_unit = F[i]->preco * F[i]->quantidade;
        printf("Custo total do(a) %s --> %.2f R$ \n", F[i]->fruta, custo_unit);

        custo_total = custo_total + custo_unit;       // Atualiza custo das mercadorias
    }
    printf("\nCusto total das mercadorias --> %.2f R$\n", custo_total);
    printf("\n*********************************************\n");
}

//===============================================================

 void troca_ponteiro(struct Feira **a, struct Feira **b)
{
    struct Feira *aux;

    aux = (*a);
    (*a) = (*b);
    (*b) = aux;
}
//===============================================================

void Ordena(struct Feira **FD, int tam)      // Ordena registros pelo método da bolha
{
    int i, j;

    for(i=tam-2;i>=0;i--)
        for(j=0;j<=i;j++)
            if (strcmp((*FD[j]).fruta, (*FD[j+1]).fruta)>0)
                troca_ponteiro(&FD[j], &FD[j+1]);          // Troca ponteiro p/ struct Feira. Entre FD[j] e FD[j+1].
}
//===============================================================
