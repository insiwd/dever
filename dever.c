#include <ncurses.h>
#include <stdbool.h>
#include <stdio.h>
#include <time.h>

// POSIX library que nos permite abrir, ler e fechar diretorios
#include <dirent.h>
#include <string.h>

// variaveis globais
FILE *file;
DIR *directory; 
int dia, mes, ano;


bool verificaSeExiste() {
    struct dirent *entry;
    bool foundLogs = false;
    
    // diretorio atual
    directory = opendir(".");
    if (directory == NULL) {
        printf("error\n");
        return true;
    }

    while ((entry = readdir(directory)) != NULL) {
        // strcmp para comparar 
        if (strcmp(entry->d_name, "logs.txt") == 0) {
            foundLogs = true;
            break;
        }
    }
    closedir(directory);

    if (foundLogs) {
        printf("Logs encontrados!\n");
        return true;
    }
    else {
        printf("Logs não encontrado.\n");
        return false;
    }
}

void criaLogSeNaoExiste() {
    if (verificaSeExiste() == false) {
        printf("Criando Logs...\n");
        file = fopen("logs.txt", "w");
        if (file == NULL) {
            printf("erro ao criar o arquivo\n");
        }
        else {
            printf("Logs criado com sucesso!\n");
            fclose(file);
        }
    }
}

void verificaSeJaFoiRegistrado() {
    // percorre todo o arquivo Logs
    // não pode ser char
    char linha[256];
    bool encontrado = false;

    file = fopen("logs.txt", "r");
    
    // le linha por linha
    while (fgets(linha, sizeof(linha), file) != NULL) {
        if (strstr(linha, "Logs:") != NULL) {
            encontrado = true;
            break;
        }
    }

    fclose(file);

    if (encontrado) {
        printf("Registrado!\n");
    }
    else {
        printf("Não registrado, escrevendo...\n");
    }
}

void getTempo() {
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);

    int horasDeConcentracao;
    dia = tm.tm_mday;
    mes = tm.tm_mon + 1;
    ano = tm.tm_year + 1900;
}

void escreveLogs() {
    getTempo();
    file = fopen("logs.txt", "w");
    
    // fprintf(fp, "%s\n")

    const char *text = "Logs:\n";
    fprintf(file, "%s Dia: %d\n Mês: %d\n Ano: %d\n", text, dia, mes, ano);

    fclose(file);
}

int main(void) {

    // "a" -> append. 
    // "w" -> write
    
    criaLogSeNaoExiste();
    verificaSeJaFoiRegistrado();
    escreveLogs();
}
