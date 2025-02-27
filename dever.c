#include <ncurses.h>
#include <stdbool.h>
#include <stdio.h>

// POSIX library que nos permite abrir, ler e fechar diretorios
#include <dirent.h>
#include <string.h>

FILE *file;
DIR *directory; 

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

int main(void) {
    
    // "a" -> append. 
    // "w" -> write
    
    criaLogSeNaoExiste();
    
    // abre o logs.txt
    //fp = fopen("logs.txt", "a");
    
    // se não existe, cria
    // if (fp == NULL) {
    //      fp = fopen("logs.txt", "w");
    // }

    char choice;
    int horasDeConcentracao;
    int dia = 20;
    int mes = 02;
    int ano = 2025;

    // initscr();
    // 
    // refresh();
    // clear();


    // fprintf(fp, "%s\n")
    
    // const char *text = "Logs:\n";
    // fprintf(file, "%s Dia: %d\n Mês: %d\n Ano: %d\n", text, dia, mes, ano);
    // 
    // char ch;
    // file = fopen("logs.txt", "r");
    // 
    // while((ch = fgetc(file)) != EOF) {
    //     printw("%c", ch);
    // }

    // // getch();
    // // endwin();
    // fclose(file);
}
