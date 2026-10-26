#include <stdio.h>

int main()
{
    FILE * arquivo;
    char equipamento[100];
    int codigo;
    char localizacao[100];
    char linha[100];
    int opcao;
    
    arquivo = fopen("equipamento.txt", "a+");
    
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        return 1;
    }
    
    do {
        printf("\n\n==========MENU DE OPCOES==========\n");
        printf("1 - Adicionar equipamento\n2 - Listar equipamentos\n3 - Sair");
        
        printf("\nEscolha uma opção: ");
        scanf("%d", &opcao);
        getchar();
        
        switch(opcao) {
            case 1:
                printf("\nDigite o nome do equipamento: ");
                
                fgets(equipamento, sizeof(equipamento), stdin);
                fprintf(arquivo, "Equipamento: %s", equipamento);
                
                printf("\nDigite o codigo do equipamento: ");
                scanf("%d", &codigo);
                fprintf(arquivo, "Codigo: %d\n", codigo);
                getchar();
                
                printf("\nDigite a localizacao do equipamento: ");
                fgets(localizacao, sizeof(localizacao), stdin);
                fprintf(arquivo, "Localizacao: %s\n", localizacao);
                break;
                
            case 2:
            rewind(arquivo);
                while(fgets(linha ,sizeof(linha), arquivo) != NULL) {
                    printf("%s", linha);
                }
                break;
            
            case 3:
                fclose(arquivo);
                printf("\n\nEncerrando...");
                break;
                
            default:
                printf("\n\nOpcao invalida!");
                break;
        }
        
    } while (opcao != 3);
    

    return 0;
}
