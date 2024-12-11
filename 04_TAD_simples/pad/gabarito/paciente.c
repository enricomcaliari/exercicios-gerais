#include <stdio.h>
#include <string.h>
#include "paciente.h"


Paciente lerPaciente() {
    Paciente p;
    scanf("%[^\n]\n", p.nome);     
    p.dataNasc = lerData(p.dataNasc);
    scanf("%s\n", p.cartaoSus);
    scanf("%c\n", &p.genero);
    p.qntLesao = 0;
    return p;
}

void printPaciente(Paciente p) {
    printf("- Paciente:\n");
    printf("%s\n", p.nome); 
    printData(p.dataNasc);
    printf("%s\n", p.cartaoSus);
    printf("%c\n", p.genero);

    for(int i=0; i<p.qntLesao; i++) {
        printLesao(p.lesoes[i]);
    }

    printf("- - - - - - - - \n");
}

void obtemCartaoSusPaciente(Paciente p, char cartaoSus[]) {    
    strcpy(cartaoSus, p.cartaoSus);
}

Paciente insereLesaoPaciente(Paciente p, Lesao les) {

    if (p.qntLesao >= MAX_TAM_LES){
        printf("O paciente nao pode ter mais que 10 lesoes\n");
    } else {
        p.lesoes[p.qntLesao] = les;
        p.qntLesao++;
    }

    return p;
}

