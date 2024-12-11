
#include <string.h>
#include <stdio.h>
#include "utils.h"

void associaLesaoPaciente(Paciente *pacs, int tamPacs, Lesao les) {

    char susPac[SUS_TAM]; 
    char susLes[SUS_TAM];    

    for(int i=0; i< tamPacs; i++) {
        obtemCartaoSusLesao(les, susLes);
        obtemCartaoSusPaciente(pacs[i], susPac);

        if (strcmp(susLes, susPac) == 0) {            
            pacs[i] = insereLesaoPaciente(pacs[i], les);
        }
    }

}