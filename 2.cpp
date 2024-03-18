#include<stdio.h>

struct Worker {
    char name[51], role[51];
    double baseSalary, benefits, discounts, netSalary;
    
    void registerWorker() {
        printf("Digite o nome do funcionario: ");
        scanf("%[^\n]%*c", name);
        
        printf("Digite o cargo do funcionario: ");
        scanf("%[^\n]%*c", role);
        
        printf("Digite o salario base do funcionario: ");
        scanf("%lf", &baseSalary);
        
        printf("Digite o valor de beneficios do funcionario: ");
        scanf("%lf", &benefits);
        
        printf("Digite o valor de descontos do funcionario: ");
        scanf("%lf", &discounts);
        
        printf("\n");
        
        netSalary = baseSalary + benefits - discounts;
        
        printf("Funcionario cadastrado: \n\n");
        showWorker();
    }
    
    void showWorker() {
        printf("Nome: %s\n", name);
        printf("Cargo: %s\n", role);
        printf("Salario base: R$%.2lf\n", baseSalary);
        printf("Beneficios: R$%.2lf\n", benefits);
        printf("Descontos: R$%.2lf\n", discounts);
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
        printf("1. Cadastrar funcionarios (ainda pode cadastrar %d funcionarios)\n", 10 - store.amountOfWorkers);
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
