#include<stdio.h>

struct Group {
    int numbers[20] = {}, length = 0;
    
    void createNewGroup() {
        printf("Quantos numeros deseja adicionar ao conjunto? (Maximo de 20 numeros): ");
        scanf("%d", &length);
        
        while (length <= 0 || length > 20) {
            printf("Valor invalido. Tente novamente: ");
            scanf("%d", &length);
        }
        
        printf("\n");
        
        for (int i = 0; i < length; i++) {
            printf("Digite um numero (%d/%d): ", i + 1, length);
            scanf("%d", &numbers[i]);
            
            bool isRepeated = false;
            
            for (int j = 0; j < i; j++) {
                if (numbers[j] == numbers[i]) isRepeated = true;
               
                while (isRepeated) {
                    printf("Este numero ja esta no conjunto. Digite outro: ");
                    scanf("%d", &numbers[i]);
                    
                    bool isRepeatedAgain = false;
                    
                    for (int k = 0; k < i; k++) {
                        if (numbers[k] == numbers[i]) isRepeatedAgain = true;
                    }
                    
                    if (!isRepeatedAgain) isRepeated = false;
               }
           }
        }
        
        printf("\n");
        printf("Conjunto criado.\n\n");
    }
    
    void showGroup() {
        printf("Quantidade de elementos do conjunto: %d\n", length);
        printf("Elementos do conjunto: ");
        printf("{ ");
        for (int i = 0; i < length; i++) {
            if (i == length - 1) {
                printf("%d", numbers[i]);
            } else {
                printf("%d, ", numbers[i]); 
            }
        }
        
        printf(" }");
        printf("\n\n");
    }
};

struct AllGroups {
    Group groups[50];
    int amountOfGroups = 0;
    
    void newEmptyGroup() {
        printf("Conjunto vazio criado.\n\n");
        amountOfGroups++;
    }
    
    void newGroup() {
        groups[amountOfGroups].createNewGroup();
        amountOfGroups++;
    }
    
    void mergeGroups() {
        if (amountOfGroups <= 1) {
            printf("Voce precisa de pelo menos 2 conjuntos para fazer uma uniao.\n\n");
        } else {
            printf("Estes sao seus conjuntos. Escolha dois deles para unir:\n\n");
            
            for (int i = 0; i < amountOfGroups; i++) {
                printf("%d: ", i + 1);
                if (groups[i].length == 0) {
                    printf("Conjunto vazio.\n");
                } else {
                    printf("{ ");
                    for (int j = 0; j < groups[i].length; j++) {
                        if (j == groups[i].length - 1) {
                            printf("%d", groups[i].numbers[j]);
                        } else {
                           printf("%d, ", groups[i].numbers[j]); 
                        }
                    }
                    printf(" }");
                    printf("\n");
                }
            }
            
            printf("\n");
            
            printf("Quais conjuntos deseja unir?\n\n");
            int firstGroupIndex, secondGroupIndex;
            
            printf("Primeiro conjunto: ");
            scanf("%d", &firstGroupIndex);
            
            printf("\n");
            
            while (firstGroupIndex - 1 < 0 || firstGroupIndex > amountOfGroups) {
                printf("Valor invalido. Tente novamente: ");
                scanf("%d", &firstGroupIndex);
                printf("\n");
            }
            
            printf("Segundo conjunto: ");
            scanf("%d", &secondGroupIndex);
            
            printf("\n");
            
            while (secondGroupIndex - 1 < 0 || secondGroupIndex > amountOfGroups || secondGroupIndex == firstGroupIndex) {
                printf("Valor invalido. Tente novamente: ");
                scanf("%d", &secondGroupIndex);
            }
            
            Group firstGroup = groups[firstGroupIndex - 1];
            Group secondGroup = groups[secondGroupIndex - 1];
            
            Group newGroup;
            int counter = 0;
            
            if (firstGroup.length == 0 && secondGroup.length == 0) {
                groups[amountOfGroups] = firstGroup;
            } else if (firstGroup.length == 0) {
                groups[amountOfGroups] = secondGroup;
            } else if (secondGroup.length == 0) {
                groups[amountOfGroups] = firstGroup;
            } else {
                for (int i = 0; i < firstGroup.length; i++) {
                    newGroup.numbers[newGroup.length] = firstGroup.numbers[i];
                    newGroup.length++;
                    counter++;
                }
                
                for (int i = 0; i < secondGroup.length; i++) {
                    bool isRepeated = false;
                        
                    for (int j = 0; j < firstGroup.length; j++) {
                        if (secondGroup.numbers[i] == firstGroup.numbers[j]) {
                            isRepeated = true;
                        }
                    }
                            
                    if (!isRepeated) {
                        newGroup.numbers[newGroup.length] = secondGroup.numbers[i];
                        newGroup.length++;
                        counter++;
                    }
                }
                
                groups[amountOfGroups] = newGroup;
            }
            
            if (counter > 20) {
                printf("Nao foi possivel realizar a uniao: conjunto resultante possui mais de 20 numeros\n\n");
            } else {
                printf("Novo conjunto criado:\n\n");
                groups[amountOfGroups].showGroup();
                amountOfGroups++; 
            }
        }
    }
    
    void intersectGroups() {
        if (amountOfGroups <= 1) {
            printf("Voce precisa de pelo menos 2 conjuntos para fazer uma intersecao.\n\n");
        } else {
            printf("Estes sao seus conjuntos. Escolha dois deles para fazer a intersecao:\n\n");
            
            for (int i = 0; i < amountOfGroups; i++) {
                printf("%d: ", i + 1);
                if (groups[i].length == 0) {
                    printf("Conjunto vazio.\n");
                } else {
                    printf("{ ");
                    for (int j = 0; j < groups[i].length; j++) {
                        if (j == groups[i].length - 1) {
                            printf("%d", groups[i].numbers[j]);
                        } else {
                           printf("%d, ", groups[i].numbers[j]); 
                        }
                    }
                    printf(" }");
                    printf("\n");
                }
            }
            
            printf("\n");
            
            printf("Quais conjuntos deseja interseccionar?\n\n");
            
            int firstGroupIndex, secondGroupIndex;
            
            printf("Primeiro conjunto: ");
            scanf("%d", &firstGroupIndex);
            
            printf("\n");
            
            while (firstGroupIndex - 1 < 0 || firstGroupIndex > amountOfGroups) {
                printf("Valor invalido. Tente novamente: ");
                scanf("%d", &firstGroupIndex);
            }
            
            printf("Segundo conjunto: ");
            scanf("%d", &secondGroupIndex);
            
            printf("\n");
            
            while (secondGroupIndex - 1 < 0 || secondGroupIndex > amountOfGroups || secondGroupIndex == firstGroupIndex) {
                printf("Valor invalido. Tente novamente: ");
                scanf("%d", &secondGroupIndex);
                printf("\n");
            }
            
            Group firstGroup = groups[firstGroupIndex - 1];
            Group secondGroup = groups[secondGroupIndex - 1];
            
            if (!(firstGroup.length == 0 || secondGroup.length == 0)) {
                for (int i = 0; i < firstGroup.length; i++) {
                    for (int j = 0; j < secondGroup.length; j++) {
                        if (firstGroup.numbers[i] == secondGroup.numbers[j]) {
                            groups[amountOfGroups].numbers[groups[amountOfGroups].length] = firstGroup.numbers[i];
                            groups[amountOfGroups].length++;
                        }
                    }
                } 
            }
            
            printf("Novo conjunto criado:\n\n");
            groups[amountOfGroups].showGroup();
            amountOfGroups++;
        }
    }
    
    void showGroups() {
        if (amountOfGroups == 0) {
            printf("Nao ha nenhum conjunto registrado.\n\n");
        } else {
            int choice;
            
            for (int i = 0; i < amountOfGroups; i++) {
                printf("%d: ", i + 1);
                
                if (groups[i].length == 0) {
                    printf("Conjunto vazio.\n");
                } else {
                    printf("{ ");
                    for (int j = 0; j < groups[i].length; j++) {
                        if (j == groups[i].length - 1) {
                            printf("%d", groups[i].numbers[j]);
                        } else {
                            printf("%d, ", groups[i].numbers[j]); 
                        }
                    }
                    printf(" }");
                    printf("\n");
                }
            }
                
            printf("\n");
            
            do {
                printf("Escolha um conjunto para ver detalhes ou digite 0 para sair: ");
                scanf("%d", &choice);
                printf("\n");
                
                while (choice > amountOfGroups || choice < 0) {
                    printf("Valor invalido. Tente novamente: ");
                    scanf("%d", &choice);
                }
                
                if (choice != 0) {
                    groups[choice - 1].showGroup();
                }
            } while (choice != 0);
            
            printf("\n");
        }
    }
};

int main() {
    AllGroups groups;
    
    int choice = 0;
    
    do {
        printf("O que deseja fazer?\n\n");
        printf("1. Criar um conjunto vazio\n");
        printf("2. Adicionar um conjunto\n");
        printf("3. Unir dois conjuntos\n");
        printf("4. Interseccionar dois conjuntos\n");
        printf("5. Mostrar os dados de um conjunto\n");
        printf("6. Sair do programa\n\n");
        
        printf("Digite sua escolha: ");
        scanf("%d%*c", &choice);
        
        printf("\n");
        
        switch(choice) {
            case 1:
                groups.newEmptyGroup();
                break;
                
            case 2:
                groups.newGroup();
                break;
                
            case 3:
                groups.mergeGroups();
                break;
                
            case 4:
                groups.intersectGroups();
                break;
                
            case 5:
                groups.showGroups();
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
