#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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


int iniciarInstrumento(eInstrumento instrumento[], int tamInstrumento)
{
    int error=-1;
    if(instrumento!=NULL && tamInstrumento>0)
    {
        error=1;
        for(int i=0; i<tamInstrumento; i++)
        {
            instrumento[i].isEmptyInstrumento=1;
        }
    }
    return error;
}


int buscarInstrumentoVacio(eInstrumento instrumento[], int tamInstrumento, int* error)
{
    *error=-1;
    int posicion=-1;
    if(instrumento!=NULL && tamInstrumento>0)
    {
        for(int i=0; i<tamInstrumento; i++)
        {
            if(instrumento[i].isEmptyInstrumento==1)
            {
                posicion=i;
                *error=1;
                break;
            }
        }
    }
    return posicion;
}

int altaInstrumento(eInstrumento instrumento[],int tamIntrumento, int posicion, int idInstrumento)
{
    int error=-1;
    int tipoInstrumento;
    if((instrumento!=NULL && tamIntrumento>0) && posicion!=-1)
    {
        instrumento[posicion].idInstrumento = idInstrumento;

        instrumento[posicion].isEmptyInstrumento=0;

        printf("Ingrese nombre de instrumento: ");
        fflush(stdin);
        scanf("%s", instrumento[posicion].nombreInstrumento);

        tipoInstrumento=subMenuTipoInstrumento();
        instrumento[posicion].tipoInstrumento = tipoInstrumento;

        error=1;
    }
    return error;
}

void mostrarIntrumento(eInstrumento instrumento)
{
    char tipoInstrumento[25];
    if(instrumento.tipoInstrumento==1)
    {
        strcpy(tipoInstrumento, "Cuerdas");
    }
    else if(instrumento.tipoInstrumento==2)
    {
        strcpy(tipoInstrumento, "Viento-Madera");
    }
    else if(instrumento.tipoInstrumento==3)
    {
        strcpy(tipoInstrumento, "Viento-Metal");
    }
    else
    {
        strcpy(tipoInstrumento, "Percusion");
    }
    printf(" %d      %s       %s\n",instrumento.idInstrumento,instrumento.nombreInstrumento,tipoInstrumento);
}

int mostrarIntrumentos(eInstrumento instrumento[],int tamInstrumento)
{
    int error=-1;
    if(instrumento!=NULL && tamInstrumento>0)
    {
        printf("ID-INTRU  NOMBRE    TIPO\n");
        for(int i=0; i<tamInstrumento; i++)
        {
            if(instrumento[i].isEmptyInstrumento==0)
            {
                mostrarIntrumento(instrumento[i]);
                error=0;
            }
        }
    }
    return error;
}






