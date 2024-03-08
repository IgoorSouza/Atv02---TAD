#include<stdio.h>

struct GroupOfNumbers {
    int numbers[20];
    int length;
}

struct Groups {
    Group groups[50];
}

int main() {
    Groups groups;
    
    int choice = 0;
    
    do {
        printf("O que deseja fazer?\n");
        printf("1. Adicionar um conjunto\n");
        printf("2. Mostrar os numeros de um conjunto\n");
        printf("3. Criar um conjunto vazio\n");
        printf("4. Unir dois conjuntos\n");
        printf("5. Interseccionar dois conjuntos\n");
        printf("6. Sair do programa\n\n");
        
        printf("Digite sua escolha: ");
        scanf("%d%*c", &choice);
        
        printf("\n");
        
        switch(choice) {
            case 1:
                
                break;
                
            case 2:
                
                break;
                
            case 3:
                
                break;
                
            case 4:
                
                break;
                
            case 5:
                
                break;
                
            case 6:
                break;
                
            default: 
                printf("Opcao invalida.\n\n");
                break;
        }
    } while (choice != 6);
    
    return 0;
}