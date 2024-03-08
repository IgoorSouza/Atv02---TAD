#include<stdio.h>

struct Worker {
    char name[51];
    char role[51];
    double baseSalary;
    double benefits[50];
    double discounts[50];
    double netSalary; //tirar ?
    int amountOfBenefits; //tirar ?
    int amountOfDiscounts; //tirar ?
    
    void registerWorker() {
        printf("Digite o nome do funcionario: ");
        scanf("%[^\n]%*c", name);
        
        printf("Digite o cargo do funcionario: ");
        scanf("%[^\n]%*c", role);
        
        printf("Digite o salario base do funcionario: ");
        scanf("%lf", &baseSalary);
        
        netSalary = baseSalary;
        
        printf("Quantos beneficios o funcionario possui? ");
        scanf("%d", &amountOfBenefits);
        
        for (int i = 0; i < amountOfBenefits; i++) {
            printf("Digite o valor do benefício (%d/%d): ", i + 1, amountOfBenefits);
            scanf("%lf", &benefits[i]);
            netSalary += benefits[i];
        }
        
        printf("Quantos descontos o funcionario possui? ");
        scanf("%d", &amountOfDiscounts);
        
        for (int i = 0; i < amountOfDiscounts; i++) {
            printf("Digite o valor do desconto (%d/%d): ", i + 1, amountOfDiscounts);
            scanf("%lf", &discounts[i]);
            netSalary -= discounts[i];
        }
    
        printf("\n");
        
        printf("Funcionario cadastrado: \n");
        showWorker();
    }
    
    void showWorker() {
        printf("Nome: %s\n", name);
        printf("Cargo: %s\n", role);
        printf("Salario base: R$%.2lf\n", baseSalary);
        printf("Beneficios: ");
        
        if (amountOfBenefits == 0) {
            printf("nenhum");
        } else {
            for (int i = 0; i < amountOfBenefits; i++) {
                printf("R$%.2lf ", benefits[i]);
            }
        }
        
        printf("\n");
        
        printf("Descontos: ");
        if (amountOfDiscounts == 0) {
            printf("nenhum");
        } else {
            for (int i = 0; i < amountOfDiscounts; i++) {
                printf("R$%.2lf ", discounts[i]);
            }
        }
        
        printf("\n");
        
        printf("Salario liquido: R$%.2lf\n\n", netSalary);
    }
};

struct Store {
    Worker workers[10];
    Worker highestPaidWorker;
    int amountOfWorkers = 0;
    
    void registerWorkers() {
        if (amountOfWorkers == 10) {
            printf("Nao e possivel cadastrar mais funcionarios.\n\n");
        } else {
            workers[amountOfWorkers].registerWorker();
            if (workers[amountOfWorkers].netSalary > highestPaidWorker.netSalary) {
                highestPaidWorker = workers[amountOfWorkers];
            }
            
            amountOfWorkers++;
        }
    }
    
    void showAllWorkers() {
        if (amountOfWorkers == 0) {
            printf("A loja nao possui funcionarios.\n\n");
        } else {
            for (int i = 0; i < amountOfWorkers; i++) {
                printf("Funcionario %d:\n", i + 1);
                workers[i].showWorker();
            }
        }
    }
    
    void showAverageWage() {
        if (amountOfWorkers == 0) {
            printf("A loja nao possui funcionarios.\n\n");
        } else {
            double averageWage = 0;
            
            for (int i = 0; i < amountOfWorkers; i++) {
                averageWage += workers[i].netSalary;
            }
            
            printf("A media salarial da loja e de R$%.2lf.\n\n", averageWage / amountOfWorkers);
        }
    }
    
    void showHighestPaidWorker() {
        if (amountOfWorkers == 0) {
            printf("A loja nao possui funcionarios.\n\n");
        } else {
            printf("Funcionario com o maior salario:\n");
            highestPaidWorker.showWorker();
        }
    }
};

int main() {
    Store store;
    
    int choice = 0;
    
    do {
        printf("O que deseja fazer?\n");
        printf("1. Cadastrar funcionarios\n");
        printf("2. Exibir funcionarios cadastrados\n");
        printf("3. Exibir media salarial da loja\n");
        printf("4. Mostrar o funcionario com o maior salario\n");
        printf("5. Sair do programa\n\n");
        
        printf("Digite sua escolha: ");
        scanf("%d%*c", &choice);
        
        printf("\n");
        
        switch(choice) {
            case 1:
                store.registerWorkers();
                break;
                
            case 2:
                store.showAllWorkers();
                break;
                
            case 3:
                store.showAverageWage();
                break;
                
            case 4:
                store.showHighestPaidWorker();
                break;
                
            case 5:
                break;
                
            default: 
                printf("Opcao invalida.\n\n");
                break;
        }
    } while (choice != 5);
    
    return 0;
}