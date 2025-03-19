#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <unistd.h>

extern int horas, minutos, segundos;

int cronometro(int *horas, int *minutos, int *segundos) {
 // o cronometro deve iniciar pausado?
    bool pausado = false;
    int caractere; 
    time_t ultimoTempo, tempoAtual;
    double tempoDecorrido;

    printf("Iniciando o cronometro...\n");
    printf("Pressione qualquer tecla para iniciar!\n");

    getchar(); // aguarda o usuário pressionar algo
    time(&ultimoTempo); // captura tempo inicial
    // permite a contagem infinita do cronometro
    while (1) {
        segundos++;

        if (segundos == 60) {
            segundos = 0;
            minutos++;
            if (minutos == 60) {
                minutos = 0;
                horas++;
            }
        }
        printf("%02d:%02d:%02d\r", horas, minutos, segundos);
        // esvazia o buffer de saída 
        fflush(stdout);
        sleep(1);
    }
}
