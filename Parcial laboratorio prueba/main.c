#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Orquesta.h"
#include "Intrumento.h"
#include "Musico.h"
//TAMAÑO DE MIS ARRAYS
#define TAM_ORQUESTA 3
#define TAM_INSTRUMENTO 3
#define TAM_MUSICO 1000



int main()
{
    eOrquesta orquestas[TAM_ORQUESTA];
    eInstrumento instrumentos[TAM_INSTRUMENTO];
    eMusico musicos[TAM_MUSICO];

    //VARIABLES DE MENU PRINCIPAL
    int seguirPrincipal=0;
    int seguirOrquesta=0;
    int seguirMusico=0;
    int seguirIntrumento=0;
    //VARIABLES DE ORQUESTAS
    int posicionOrquesta;
    int errorOrquesta;
    int idOrquesta=100;
    int contadorInicialOrquesta=0;
    //VARIABLES DE MUSICO
    int posicionMusico;
    int errorMusico;
    int idMusico=100;
    int contadorInicialMusico=0;
    //VARIABLES DE INSTRUMENTO
    int posicionInstrumento;
    int errorInstrumento;
    int idInstrumento=100;
    int contadorInicialIntrumento=0;
    //INICIALIZADORES
    iniciarOrquesta(orquestas, TAM_ORQUESTA);
    iniciarMusico(musicos, TAM_MUSICO);
    iniciarInstrumento(instrumentos, TAM_INSTRUMENTO);

    do
    {
        switch(MenuPrincipal())
        {
        case 1:
            do
            {
                seguirOrquesta=0;
                switch(subMenuOrquesta())
                {

                case 1:
                    posicionOrquesta = buscarOrquestaVacia(orquestas, TAM_ORQUESTA,&errorOrquesta);
                    if(errorOrquesta!=-1)
                    {
                        altaOrquesta(orquestas, TAM_ORQUESTA,posicionOrquesta,idOrquesta);
                        idOrquesta++;
                        printf("Alta exitosa\n");
                        contadorInicialOrquesta=1;
                    }
                    else
                    {
                        printf("No se encuentra lugar vacio\n");
                    }
                    break;
                case 2:
                    if(contadorInicialOrquesta==1)
                    {
                        mostrarOrquestas(orquestas, TAM_ORQUESTA);
                        if(bajaOrquesta(orquestas, TAM_ORQUESTA)!=-1)
                        {
                            printf("Baja exitosa\n");
                        }
                        else
                        {
                            printf("No se encontro numero de legajo\n");
                        }
                    }
                    else
                    {
                        printf("Debes cargar antes de dar de baja\n");
                    }
                    break;
                case 3:
                    if( mostrarOrquestas(orquestas, TAM_ORQUESTA)==-1)
                    {
                        printf("    No se cargo ninguna orquesta\n");
                    }
                    break;
                case 4:
                    seguirOrquesta=1;
                    break;
                }
                system("pause");
            }
            while(seguirOrquesta==0);
            break;
        case 2:
            do
            {
                seguirMusico=0;
                switch(subMenuMusico())
                {
                case 1:
                    if(contadorInicialIntrumento==0 || contadorInicialOrquesta==0)
                    {
                        printf("Antes de cargar musico deben cargarse intrumento y orquesta\n");
                    }
                    else if(posicionInstrumento!=-1 || posicionOrquesta!=-1)
                    {
                        posicionMusico = buscarMusicoVacio(musicos, TAM_MUSICO,&errorMusico);
                        if(errorMusico!=-1)
                        {
                            altaMusico(musicos, TAM_MUSICO, orquestas, TAM_ORQUESTA,instrumentos, TAM_INSTRUMENTO, posicionMusico, idMusico);
                            idMusico++;
                            printf("Alta exitosa\n");
                            contadorInicialMusico=1;
                        }
                        else
                        {
                            printf("No se encuentra lugar vacio\n");
                        }
                    }
                    break;
                case 2:
                    if(contadorInicialMusico==1)
                    {
                        mostrarMusicos(musicos, TAM_MUSICO, instrumentos);
                        if(bajaMusico(musicos,TAM_MUSICO)!=-1)
                        {
                            printf("Baja exitosa\n");
                        }
                        else
                        {
                            printf("No se encontro numero de id\n");
                        }
                    }
                    else
                    {
                        printf("Debes cargar antes de dar de baja\n");
                    }
                    break;
                case 3:
                    if( mostrarMusicos(musicos, TAM_MUSICO, instrumentos)==-1)
                    {
                        printf("    No se cargo ningun musico\n");
                    }
                    break;
                case 4:
                    if(contadorInicialMusico==1)
                    {
                        errorMusico = modificarMusico(musicos, TAM_MUSICO, instrumentos, orquestas);
                        if(errorMusico!=-1)
                        {
                            printf("Modificacion exitosa\n");
                        }
                        else
                        {
                            printf("No fue posible modificar\n");
                        }
                    }
                    else
                    {
                        printf("Hay que cargar musico antes de modificar\n");
                    }
                    break;
                case 5:
                    seguirMusico=1;
                    break;
                }
                system("pause");
            }
            while(seguirMusico==0);
            break;
        case 3:
            do
            {
                seguirIntrumento=0;
                switch(subMenuInstrumento())
                {
                case 1:
                    printf("DAR ALTA INTRUMENTO\n");
                    posicionInstrumento = buscarInstrumentoVacio(instrumentos, TAM_INSTRUMENTO, &errorInstrumento);
                    if(errorInstrumento!=-1)
                    {
                        altaInstrumento(instrumentos, TAM_INSTRUMENTO, posicionInstrumento, idInstrumento);
                        idInstrumento++;
                        printf("Alta exitosa\n");
                        contadorInicialIntrumento=1;
                    }
                    else
                    {
                        printf("No se encuentra lugar vacio\n");
                    }
                    break;
                case 2 :
                    printf("IMPRIMO INSTRUMENTO\n");
                    if( mostrarIntrumentos(instrumentos, TAM_INSTRUMENTO)==-1)
                    {
                        printf("    No se cargo ningun instrumento\n");
                    }
                    break;
                case 3:
                    seguirIntrumento=1;
                    break;
                }
                system("pause");
            }
            while(seguirIntrumento==0);
            break;
        }
    }
    while(seguirPrincipal==0);

    return 0;
}



