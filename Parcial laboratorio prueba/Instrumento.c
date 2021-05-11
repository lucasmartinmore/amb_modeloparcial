#include "Intrumento.h"

int subMenuTipoInstrumento()
{
    system("cls");
    int opcion;
    printf("|--TIPO INSTRUMENTO--|\n");
    printf("|  1) CUERDAS        |\n");
    printf("|  2) VIENTO-MADERA  |\n");
    printf("|  3) VIENTO-METAL   |\n");
    printf("|  4) PERCUSION      |\n");
    printf("|--------------------|\n\n");
    printf("----------------------\n");
    printf("   Ingrese opcion: ");
    scanf("%d", &opcion);
    while(opcion<1 || opcion>4)
    {
        printf("Reingrese opcion: ");
        scanf("%d", &opcion);
    }
    return opcion;
}

int subMenuInstrumento()
{
    system("cls");
    int opcion;
    printf("|--MENU INSTRUMENTO--|\n");
    printf("|  1) ALTA           |\n");
    printf("|  2) IMPRIMIR       |\n");
    printf("|  3) MENU PRINC     |\n");
    printf("|--------------------|\n\n");
    printf("----------------------\n");
    printf("   Ingrese opcion: ");
    scanf("%d", &opcion);
    while(opcion<1 || opcion>3)
    {
        printf("Reingrese opcion: ");
        scanf("%d", &opcion);
    }
    return opcion;
}




