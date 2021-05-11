#ifndef MUSICO_H_INCLUDED
#define MUSICO_H_INCLUDED

typedef struct
{
    char nombreMusico[25];
    char apellidoMusico[25];
    int edadMusico;
    int idOrquesta;
    int idInstrumento;
    int idMusico;
    int isEmptyMusico;
} eMusico;

//AGREGO LAS OTRAS ESTRUCTURAS QUE NECESITO



#endif // MUSICO_H_INCLUDED

int subMenuMusico();
int iniciarMusico(eMusico musico[], int tamMusico);
int buscarMusicoVacio(eMusico musico[], int tamMusico, int* error);
int altaMusico(eMusico musico[],int tamMusico,eOrquesta orquesta[], int tamOrquesta, int posicion,int idMusico);
int bajaMusico(eMusico musico[], int tamMusico);
void mostrarMusico(eMusico musico, eInstrumento instrumento);
int mostrarMusicos(eMusico musico[],int tamMusico, eInstrumento instrumento[]);
int modificarMusico(eMusico musico[], int tamMusico, eInstrumento instrumento[], eOrquesta orquesta[]);
int submenuModificarMusico();


