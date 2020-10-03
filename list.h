#include <stdio.h>
#include <stdlib.h>
typedef struct sarasas
{
    int duom;
    struct sarasas *kitas;

} sar_t;

void sukurti(FILE *duomf, sar_t **pabaiga, sar_t **pradzia, int* reiksme)
{
    if(fscanf(duomf, "%d", reiksme)!=EOF)
    {
        sar_t *elem;
        elem = (struct sarasas*) malloc(sizeof(struct sarasas));
        elem -> duom = (*reiksme);

        if (*pradzia == NULL)
        {
            *pradzia=elem;
            *pabaiga=elem;
            (*pabaiga)-> kitas = (*pabaiga);
        }
        else
        {
            elem -> kitas = (*pradzia);
            (*pabaiga) -> kitas = elem;
            *pabaiga=elem;
        }
        sukurti(duomf, pabaiga, pradzia, reiksme);
    }
}

void iterpimas(sar_t *pabaiga, int pries, int iterpti)
{
    int yra=0;

    sar_t *dabartinis;
    dabartinis = pabaiga -> kitas;

    do
    {
        if((dabartinis -> kitas -> duom) == pries)
        {
            sar_t *elem;
            elem = (struct sarasas*) malloc(sizeof(struct sarasas));

            elem -> duom = iterpti;
            elem -> kitas = dabartinis ->kitas;
            dabartinis -> kitas = elem;
            dabartinis=elem;
            yra=1;
        }
        dabartinis = dabartinis -> kitas;
    }
    while (dabartinis != pabaiga -> kitas);

    if(yra==0)
        printf("Tokio elemento nera!\n");
}


void isvedimas(FILE *rezf, sar_t *pabaiga)
{
    sar_t *dabartinis;
    dabartinis = pabaiga -> kitas;

    do
    {
        fprintf(rezf, "%d\n", dabartinis -> duom);
        dabartinis = dabartinis -> kitas;
    }
    while (dabartinis != pabaiga -> kitas);
}
