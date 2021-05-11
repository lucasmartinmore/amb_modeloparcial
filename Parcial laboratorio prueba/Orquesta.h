#ifndef ORQUESTA_H_INCLUDED
#define ORQUESTA_H_INCLUDED

typedef struct
{
    char nombreOrquesta[25];
    char lugarOrquesta[25];
    int tipoOrquesta;
    int idOrquesta;
    int isEmpty;
} eOrquesta;

#endif // ORQUESTA_H_INCLUDED

int subMenuTipoOrquesta();
int subMenuOrquesta();
int iniciarOrquesta(eOrquesta orquesta[], int tamOrquesta);
int buscarOrquestaVacia(eOrquesta orquesta[], int tamOrquesta, int* error);
char idTipoOrquestaDescripcion(int id);
int altaOrquesta(eOrquesta orquesta[],int tamOrquesta,int posicion,int idOrquesta);
int bajaOrquesta(eOrquesta orquesta[], int tamOrquesta);
void mostrarOrquesta(eOrquesta orquesta);
int mostrarOrquestas(eOrquesta orquesta[], int tamOrquesta);

