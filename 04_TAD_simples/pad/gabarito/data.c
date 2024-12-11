#include <stdio.h>
#include "data.h"


Data lerData() {
    Data d;
    scanf("%d/%d/%d\n", &d.dia,
                        &d.mes, 
                        &d.ano);
    return d;
}

void printData(Data d) {
    printf("%d/%d/%d\n", d.dia, d.mes, d.ano);
}

int diferencaAnoData(Data inicial, Data final) {
    int diff;
    diff = final.ano - inicial.ano;
    
    if (final.mes == inicial.mes) {
        if (final.dia < inicial.dia) {
            diff--;
        }
    } else if(final.mes < inicial.mes) {
        diff--;        
    }

    return diff;
}