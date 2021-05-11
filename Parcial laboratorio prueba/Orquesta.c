#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Orquesta.h"

int subMenuTipoOrquesta()
{
    system("cls");
    int opcion;
    printf("|---TIPOS ORQUESTA---|\n");
    printf("|  1) SINFONICA      |\n");
    printf("|  2) FILARMONICA    |\n");
    printf("|  3) CAMARA         |\n");
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

int subMenuOrquesta()
{
    system("cls");
    int opcion;
    printf("|----MENU ORQUESTA---|\n");
    printf("|  1) ALTA           |\n");
    printf("|  2) BAJA           |\n");
    printf("|  3) IMPRIMIR       |\n");
    printf("|  4) MENU PRINC     |\n");
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

int iniciarOrquesta(eOrquesta orquesta[], int tamOrquesta)
{
    int error=-1;
    if(orquesta!=NULL && tamOrquesta>0)
    {
        error=1;
        for(int i=0; i<tamOrquesta; i++)
        {
            orquesta[i].isEmpty=1;
        }
    }
    return error;
}


int buscarOrquestaVacia(eOrquesta orquesta[], int tamOrquesta, int* error)
{
    *error=-1;
    int posicion=-1;
    if(orquesta!=NULL && tamOrquesta>0)
    {
        for(int i=0; i<tamOrquesta; i++)
        {
            if(orquesta[i].isEmpty==1)
            {
                posicion=i;
                *error=1;
                break;
            }
        }
    }
    return posicion;
}

int altaOrquesta(eOrquesta orquesta[],int tamOrquesta,int posicion,int idOrquesta)
{
    int error=-1;
    int tipoOrquesta;
    if((orquesta!=NULL && tamOrquesta>0) && posicion!=-1)
    {
        orquesta[posicion].isEmpty=0;

        orquesta[posicion].idOrquesta = idOrquesta;

        printf("Ingrese nombre de orquesta: ");
        fflush(stdin);
        scanf("%s", orquesta[posicion].nombreOrquesta);

        printf("Ingrese lugar de orquesta: ");
        fflush(stdin);
        scanf("%s", orquesta[posicion].lugarOrquesta);

        tipoOrquesta=subMenuTipoOrquesta();
        orquesta[posicion].tipoOrquesta=tipoOrquesta;

        error=1;
    }
    return error;
}

void mostrarOrquesta(eOrquesta orquesta)
{
    char descripcionOrquesta[25];
    if(orquesta.tipoOrquesta==1)
    {
        strcpy(descripcionOrquesta, "Sinfonica");
    }
    else if(orquesta.tipoOrquesta==2)
    {
        strcpy(descripcionOrquesta, "Filarmonica");
    }
    else
    {
        strcpy(descripcionOrquesta, "Camara");
    }
    printf(" %d    %s     %s     %s\n",orquesta.idOrquesta,orquesta.nombreOrquesta,orquesta.lugarOrquesta,descripcionOrquesta);
}

int mostrarOrquestas(eOrquesta orquesta[], int tamOrquesta)//QUITAR EL TAM
{
    int error=-1;
    if(orquesta!=NULL && tamOrquesta>0)
    {
        printf("ID-ORQ  NOMBRE    LUGAR     TIPO-ORQ\n");
        for(int i=0; i<tamOrquesta; i++)
        {
            if(orquesta[i].isEmpty==0)
            {
                mostrarOrquesta(orquesta[i]);
                error=0;
            }
        }
    }
    return error;
}
/*
char idTipoOrquestaDescripcion(int id)
{
    char tipoOrquesta[25];
    if(id==1)
    {
        strcpy(tipoOrquesta, "Sinfonica");
    }
    else if(id==2)
    {
        strcpy(tipoOrquesta, "Filarmonica");
    }
    else
    {
        strcpy(tipoOrquesta, "Camara");
    }
    return tipoOrquesta;
}
*/
int bajaOrquesta(eOrquesta orquesta[], int tamOrquesta)
{
    int posicion;
    int error=-1;
    if(orquesta!=NULL && tamOrquesta>0)
    {
        printf("Ingrese id de orquesta a dar de baja: ");
        scanf("%d", &posicion);
        while(posicion<100)
        {
            printf("Incorrecto. Ingres nueva id: ");
            scanf("%d", &posicion);
        }
        for(int i=0; i<tamOrquesta; i++)
        {
            if(orquesta[i].idOrquesta==posicion)
            {
                error=1;
                orquesta[i].isEmpty=1;
                orquesta[i].idOrquesta=' ';
            }
        }
    }
    return error;
}
