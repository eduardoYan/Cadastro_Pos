#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Paciente {
    char nome[100];
    char telefone[20];
    char endereco[200];
    int idade;
    char cpf[15];
};

struct Medico {
    char nome[100];
    char especialidade[50];
    char telefone[20];
    char crm[10];
};

struct Consulta {
    char cpfPaciente[15];
    char crmMedico[10];
    char dataConsulta[20];
};

struct Paciente pacientes[100];
int qtdPacientes = 0;

struct Medico medicos[100];
int qtdMedicos = 0;

struct Consulta consultas[100];
int qtdConsultas = 0;

void cadastrarPaciente() {
    if (qtdPacientes >= 100) {
        printf("Limite de pacientes atingido.\n");
        return;
    }

    struct Paciente p;
    printf("Nome: ");
    fgets(p.nome, 100, stdin); strtok(p.nome, "\n");
    printf("Telefone: ");
    fgets(p.telefone, 20, stdin); strtok(p.telefone, "\n");
    printf("Endereço: ");
    fgets(p.endereco, 200, stdin); strtok(p.endereco, "\n");
    printf("Idade: ");
    scanf("%d", &p.idade);
    getchar(); // limpar \n
    printf("CPF: ");
    fgets(p.cpf, 15, stdin); strtok(p.cpf, "\n");

    pacientes[qtdPacientes] = p;
    qtdPacientes++;

    printf("Paciente cadastrado com sucesso!\n");
}

void cadastrarMedico() {
    if (qtdMedicos >= 100) {
        printf("Limite de médicos atingido.\n");
        return;
    }

    struct Medico m;
    printf("Nome: ");
    fgets(m.nome, 100, stdin); strtok(m.nome, "\n");
    printf("Especialidade: ");
    fgets(m.especialidade, 50, stdin); strtok(m.especialidade, "\n");
    printf("Telefone: ");
    fgets(m.telefone, 20, stdin); strtok(m.telefone, "\n");
    printf("CRM: ");
    fgets(m.crm, 10, stdin); strtok(m.crm, "\n");

    medicos[qtdMedicos] = m;
    qtdMedicos++;

    printf("Médico cadastrado com sucesso!\n");
}

int buscarPacientePorCPF(char cpf[]) {
    for (int i = 0; i < qtdPacientes; i++) {
        if (strcmp(pacientes[i].cpf, cpf) == 0) {
            return i;
        }
    }
    return -1;
}

int buscarMedicoPorCRM(char crm[]) {
    for (int i = 0; i < qtdMedicos; i++) {
        if (strcmp(medicos[i].crm, crm) == 0) {
            return i;
        }
    }
    return -1;
}

void agendarConsulta() {
    if (qtdConsultas >= 100) {
        printf("Limite de consultas atingido.\n");
        return;
    }

    char cpf[15];
    char crm[10];
    struct Consulta c;

    printf("CPF do paciente: ");
    fgets(cpf, 15, stdin); strtok(cpf, "\n");

    int idxPaciente = buscarPacientePorCPF(cpf);
    if (idxPaciente == -1) {
        printf("Paciente não encontrado.\n");
        return;
    }

    printf("CRM do médico: ");
    fgets(crm, 10, stdin); strtok(crm, "\n");

    int idxMedico = buscarMedicoPorCRM(crm);
    if (idxMedico == -1) {
        printf("Médico não encontrado.\n");
        return;
    }

    strcpy(c.cpfPaciente, cpf);
    strcpy(c.crmMedico, crm);
    printf("Data da consulta (DD/MM/AAAA): ");
    fgets(c.dataConsulta, 20, stdin); strtok(c.dataConsulta, "\n");

    consultas[qtdConsultas] = c;
    qtdConsultas++;

    printf("Consulta agendada com sucesso!\n");
}

void procurarPaciente() {
    char cpf[15];
    printf("Digite o CPF: ");
    fgets(cpf, 15, stdin); strtok(cpf, "\n");

    int idx = buscarPacientePorCPF(cpf);
    if (idx == -1) {
        printf("Paciente não encontrado.\n");
    } else {
        struct Paciente p = pacientes[idx];
        printf("Nome: %s\nTelefone: %s\nEndereço: %s\nIdade: %d\nCPF: %s\n",
               p.nome, p.telefone, p.endereco, p.idade, p.cpf);
    }
}

void procurarMedico() {
    char crm[10];
    printf("Digite o CRM: ");
    fgets(crm, 10, stdin); strtok(crm, "\n");

    int idx = buscarMedicoPorCRM(crm);
    if (idx == -1) {
        printf("Médico não encontrado.\n");
    } else {
        struct Medico m = medicos[idx];
        printf("Nome: %s\nEspecialidade: %s\nTelefone: %s\nCRM: %s\n",
               m.nome, m.especialidade, m.telefone, m.crm);
    }
}

int main() {
    int opcao;
    do {
        printf("\n===== MENU =====\n");
        printf("1. Cadastrar um paciente\n");
        printf("2. Cadastrar um médico\n");
        printf("3. Agendar uma consulta\n");
        printf("4. Procurar paciente pelo CPF\n");
        printf("5. Procurar médico pelo CRM\n");
        printf("6. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        getchar(); // limpar o \n

        switch (opcao) {
            case 1:
                cadastrarPaciente();
                break;
            case 2:
                cadastrarMedico();
                break;
            case 3:
                agendarConsulta();
                break;
            case 4:
                procurarPaciente();
                break;
            case 5:
                procurarMedico();
                break;
            case 6:
                printf("Encerrando o programa.\n");
                break;
            default:
                printf("Opção inválida.\n");
        }

    } while (opcao != 6);

    return 0;
}
