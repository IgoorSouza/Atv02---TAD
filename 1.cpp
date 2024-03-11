#include <stdio.h>
#include<ctime>

struct DateOfBirth {
    int day;
    int month;
    int year;
};

struct Client {
    char name[51];
    char sex;
    int age;
    DateOfBirth dateOfBirth;
    
    time_t date = time(0);
    tm *ltm = localtime(&date);
    int currentDay = ltm->tm_mday;
    int currentMonth = ltm->tm_mon + 1;
    int currentYear = ltm->tm_year + 1900;
    
    void readClient() {
        printf("Digite o nome do cliente: ");
        scanf("%[^\n]%*c", name);
        
        printf("Informe o sexo do cliente (M para masculino e F para feminino): ");
        scanf("%c", &sex);
        
        while (sex != 'M' && sex != 'F') {
            printf("O sexo informado e invalido. Digite novamente: ");
            scanf(" %c", &sex);
        }
        
        bool validDateOfBirth = false;
        
        do {
            printf("Informe o dia de nascimento do cliente: ");
            scanf("%d", &dateOfBirth.day);
        
            while (dateOfBirth.day < 1 || dateOfBirth.day > 31) {
                printf("O dia informado e invalido. Digite novamente: ");
                scanf("%d", &dateOfBirth.day);
            }
        
            printf("Informe o mes de nascimento do cliente: ");
            scanf("%d", &dateOfBirth.month);
        
            while (dateOfBirth.month < 1 || dateOfBirth.month > 12) {
                printf("O mes informado e invalido. Digite novamente: ");
                scanf("%d", &dateOfBirth.month);
            };
        
            printf("Informe o ano de nascimento do cliente: ");
            scanf("%d", &dateOfBirth.year);
        
            while (dateOfBirth.year < 1900 || dateOfBirth.year > currentYear) {
                printf("O ano informado e invalido. Digite novamente: ");
                scanf("%d", &dateOfBirth.year);
            };
            
            if (dateOfBirth.year == currentYear && dateOfBirth.month > currentMonth || dateOfBirth.year == currentYear && dateOfBirth.month == currentMonth && dateOfBirth.day > currentDay) {
                printf("\n");
                printf("Data de nascimento invalida. Tente novamente.\n\n");
            } else {
                validDateOfBirth = true;
            }
        } while(!validDateOfBirth);
        
        printf("\n");
        
        age = currentYear - dateOfBirth.year;
        
        if (currentMonth - dateOfBirth.month < 0 || currentMonth - dateOfBirth.month == 0 && currentDay - dateOfBirth.day < 0) {
            age -= 1;
        }
        
        printf("Cliente cadastrado: \n");
        printf("Nome: %s\n", name);
        printf("Sexo: %c\n", sex);
        printf("Idade: %d\n", age);
        printf("Data de nascimento: %d/%d/%d\n\n", dateOfBirth.day, dateOfBirth.month, dateOfBirth.year);
    }
    
    void showClient() {
        printf("Nome: %s\n", name);
        printf("Sexo: %c\n", sex);
        printf("Idade: %d\n", age);
        printf("Data de nascimento: %d/%d/%d\n\n", dateOfBirth.day, dateOfBirth.month, dateOfBirth.year);
    }
};

struct Clients {
    Client clients[50];
    int amountOfClients = 0;
    
    void readClient() {
        if (amountOfClients == 50) {
            printf("Número máximo de clientes atingido.\n\n");
        } else {
            clients[amountOfClients].readClient();
            amountOfClients++;
        }
    }
    
    void showAllClients() {
        if (amountOfClients == 0) {
            printf("Não há clientes cadastrados.\n\n");
        } else {
            for (int i = 0; i < amountOfClients; i++) {
                printf("Cliente %d:\n", i + 1);
                clients[i].showClient();
            }
        }
    }
};

int main() {
    Clients clients;
    
    int choice = 0;
    
    do {
        printf("O que deseja fazer?\n");
        printf("1. Cadastrar novo cliente (ainda pode cadastrar %d clientes)\n", 50 - clients.amountOfClients);
        printf("2. Listar clientes cadastrados\n");
        printf("3. Sair do programa\n\n");
        
        printf("Digite sua escolha: ");
        scanf("%d%*c", &choice);
        
        printf("\n");
        
        switch(choice) {
            case 1:
                clients.readClient();
                break;
                
            case 2:
                clients.showAllClients();
                break;
                
            case 3:
                break;
                
            default: 
                printf("Opcao invalida.\n\n");
                break;
        }
    } while (choice != 3);

    return 0;
}