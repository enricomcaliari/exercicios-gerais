#include <stdio.h>
#include "tadgen.h"

int main()
{
    int type;
    int numElem;

    scanf("%d %d\n", &type, &numElem);

    tGeneric *gen = CriaGenerico(type, numElem);
    
    printf("tad_gen_01\nDigite o tipo e numero de elementos:\n");
    LeGenerico(gen);
    ImprimeGenerico(gen);
    DestroiGenerico(gen);

    return 0;
}