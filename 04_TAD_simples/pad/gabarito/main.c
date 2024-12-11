#include <stdio.h>
#include <stdlib.h>
#include "paciente.h"
#include "constantes.h"
#include "utils.h"

int main() {

    char opcao;
    Paciente pacientes[MAX_TAM_PACIENTES];
    int contPaciente = 0;

    while(TRUE) {
        scanf("%c\n", &opcao);
        // printf("op = %c\n", opcao);
        if (opcao == 'F'){
            break;
        } else if (opcao == 'P') {
            if (contPaciente > MAX_TAM_PACIENTES) {
                printf("Numero maximo de pacientes atingidos.\n");
                break;
            } else {
                pacientes[contPaciente] = lerPaciente();
                // printPaciente(pacientes[contPaciente]);
                contPaciente++;                                
            }
        } else if (opcao == 'L') {
            
            Lesao les;
            les = lerLesao();
            // printLesao(les); 
            associaLesaoPaciente(pacientes, contPaciente, les);

        } else {
            printf("Problema na leitura. Opcao invalida\n");
            exit(1);
        }

    }

    for(int i=0; i<contPaciente; i++)
        printPaciente(pacientes[i]);
    



    return 0;
}