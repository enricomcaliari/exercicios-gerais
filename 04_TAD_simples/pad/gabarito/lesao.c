#include <stdio.h>
#include <string.h>
#include "lesao.h"

Lesao lerLesao() {    
    Lesao les;    
    scanf("%s\n", les.cartaoSus);
    scanf("%s\n", les.id);
    scanf("%[^\n]\n", les.diagnostico);
    scanf("%[^\n]\n", les.regiao);
    scanf("%d\n", &les.chanceMalig);
    return les;
}

void printLesao(Lesao les) {   

    printf("- Lesao:\n");
    printf("%s\n", les.cartaoSus);
    printf("%s\n", les.id);
    printf("%s\n", les.diagnostico);
    printf("%s\n", les.regiao);
    printf("%d\n", les.chanceMalig);
    printf("- - - - - - - - \n");
}

void obtemCartaoSusLesao(Lesao les, char cartaoSus[]) {
    strcpy(cartaoSus, les.cartaoSus);
}