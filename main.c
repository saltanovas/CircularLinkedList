#include <stdio.h>
#include <stdlib.h>
#include "sarasas.c"

int main(int argc, char *argv[])
{
    int reiksme;
    int pries;
    int iterpti;

    sar_t *pradzia=NULL;
    sar_t *pabaiga=NULL;


    FILE *duomf=fopen(*(argv+1), "r");
    if  (duomf==NULL)
    {
        printf("Neimanoma atidaryti duomenu failo!\n");
        return 1;
    }

    fseek(duomf, 0, SEEK_END);
    if (ftell(duomf) == 0)
    {
        printf("Duomenu failas yra tuscias!\n");
        return 0;
    }
    fseek(duomf, 0, SEEK_SET);

    FILE *rezf=fopen(*(argv+2), "w");
    if  (rezf==NULL)
    {
        printf("Neimanoma atidaryti rezultatu failo!\n");
        return 1;
    }


    printf("Iveskite nauja reiksme:");
    scanf("%d", &iterpti);

    printf("Pries koki elementa norite iterpti %d:", iterpti);
    scanf("%d", &pries);


    sukurti(duomf, &pabaiga, &pradzia, &reiksme);
    iterpimas(pabaiga, pries, iterpti);
    isvedimas(rezf, pabaiga);

    return 0;
}
