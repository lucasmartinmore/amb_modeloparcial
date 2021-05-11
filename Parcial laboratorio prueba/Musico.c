#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Musico.h"

int subMenuMusico()
{
    system("cls");
    int opcion;
    printf("|-----MENU MUSICO----|\n");
    printf("|  1) ALTA           |\n");
    printf("|  2) BAJA           |\n");
    printf("|  3) IMPRIMIR       |\n");
    printf("|  4) MODIFICAR      |\n");
    printf("|  5) MENU PRINC     |\n");
    printf("|--------------------|\n\n");
    printf("----------------------\n");
    printf("   Ingrese opcion: ");
    scanf("%d", &opcion);
    while(opcion<1 || opcion>5)
    {
        printf("Reingrese opcion: ");
        scanf("%d", &opcion);
    }
    return opcion;
}

int iniciarMusico(eMusico musico[], int tamMusico)
{
    int error=-1;
    if(musico!=NULL && tamMusico>0)
    {
        error=1;
        for(int i=0; i<tamMusico; i++)
        {
            musico[i].isEmptyMusico=1;
        }
    }
    return error;
}


int buscarMusicoVacio(eMusico musico[], int tamMusico, int* error)
{
    *error=-1;
    int posicion=-1;
    if(musico!=NULL && tamMusico>0)
    {
        for(int i=0; i<tamMusico; i++)
        {
            if(musico[i].isEmptyMusico==1)
            {
                posicion=i;
                *error=1;
                break;
            }
        }
    }
    return posicion;
}

int altaMusico(eMusico musico[],int tamMusico,eOrquesta orquesta[], int tamOrquesta, int posicion,int idMusico)
{
    int error=-1;
    int tipoInstrumento;
    if((musico!=NULL && tamMusico>0) && posicion!=-1)
    {
        musico[posicion].isEmptyMusico=0;

        musico[posicion].idMusico = idMusico;

        printf("Ingrese nombre de musico: ");
        fflush(stdin);
        scanf("%s", musico[posicion].nombreMusico);

        printf("Ingrese apellido de musico: ");
        fflush(stdin);
        scanf("%s", musico[posicion].apellidoMusico);

        printf("Ingrese edad de musico: ");
        scanf("%d", &musico[posicion].edadMusico);
        while(musico[posicion].edadMusico>100 || musico[posicion].edadMusico<18)
        {
            printf("Edad invalida. Ingrese edad de musico: ");
            scanf("%d", &musico[posicion].edadMusico);
        }

        mostrarOrquestas(orquesta, tamOrquesta);
        printf("Ingrese id de orquesta perteneciente: ");
        scanf("%d", &musico[posicion].idOrquesta);

        tipoInstrumento=subMenuTipoInstrumento();
        musico[posicion].idInstrumento = tipoInstrumento;

        error=1;
    }
    return error;
}

void mostrarMusico(eMusico musico, eInstrumento instrumento)
{
    char nombreInstrumento[25];
    char tipoInstrumento[25];
    if(musico.idInstrumento == instrumento.idInstrumento)
    {
        strcpy(nombreInstrumento, instrumento.nombreInstrumento);
        strcpy(tipoInstrumento, instrumento.tipoInstrumento);
    }
    printf(" %d      %s       %s       %d      %s       %s\n",musico.idMusico,musico.nombreMusico,
    musico.apellidoMusico,musico.edadMusico,nombreInstrumento,tipoInstrumento);
}

int mostrarMusicos(eMusico musico[],int tamMusico, eInstrumento instrumento[])
{
    int error=-1;
    if(musico!=NULL && instrumento!=NULL)
    {
        printf("ID-MUSIC  NOMBRE    APELLIDO     EDAD     NOMBRE-INTR    TIPO-INTR\n");
        for(int i=0; i<tamMusico; i++)
        {
            if(musico[i].isEmptyMusico==0)
            {
                mostrarMusico(musico[i],instrumento[i]);
                error=0;
            }
        }
    }
    return error;
}


int bajaMusico(eMusico musico[], int tamMusico)
{
    int posicion;
    int error=-1;
    if(musico!=NULL && tamMusico>0)
    {
        printf("Ingrese id de musico a dar de baja: ");
        scanf("%d", &posicion);
        while(posicion<100)
        {
            printf("Incorrecto. Ingres nueva id: ");
            scanf("%d", &posicion);
        }
        for(int i=0; i<tamMusico; i++)
        {
            if(musico[i].idMusico==posicion)
            {
                error=1;
                musico[i].isEmptyMusico=1;
                musico[i].idMusico=' ';
                musico[i].idOrquesta=' ';
            }
        }
    }
    return error;
}


int submenuModificarMusico()
{
    system("cls");
    int opcion;
    printf("|---MENU MODIFICAR---|\n");
    printf("|  1) EDAD           |\n");
    printf("|  2) ID ORQUESTA    |\n");
    printf("|--------------------|\n\n");
    printf("----------------------\n");
    printf("   Ingrese opcion: ");
    scanf("%d", &opcion);
    while(opcion<1 || opcion>2)
    {
        printf("Reingrese opcion: ");
        scanf("%d", &opcion);
    }
    return opcion;
}

int modificarMusico(eMusico musico[], int tamMusico, eInstrumento instrumento[], eOrquesta orquesta[])
{
    int posicion;
    int nuevaEdad;
    int nuevaOrquesta;
    int error=-1;
    if(musico!=NULL && tamMusico>0)
    {
        mostrarMusicos(musico, tamMusico, instrumento);
        printf("Ingrese id a modificar: ");
        scanf("%d", &posicion);
        while(posicion<100)
        {
            printf("Incorrecto. Ingres nueva pos: ");
            scanf("%d", &posicion);
        }
        for(int i=0; i<tamMusico; i++)
        {
            if(musico[i].idMusico==posicion)
            {
                switch(submenuModificarMusico())
                {
                case 1:
                    printf("Ingrese nueva edad: ");
                    scanf("%d", &nuevaEdad);
                    musico[i].edadMusico = nuevaEdad;
                    printf("Cambio edad exitoso\n");
                    error=1;
                    break;
                case 2:
                    mostrarOrquestas(orquesta,TAM_ORQUESTA);
                    printf("Ingrese nuevo idOrquesta: ");
                    scanf("%d", &nuevaOrquesta);
                    musico[i].idOrquesta = nuevaOrquesta;
                    printf("Cambio de orquesta exitoso\n");
                    error=1;
                    break;
                default:
                    printf("Opcion incorrecta\n");
                    break;
                }
            }
        }
    }
    return error;
}

