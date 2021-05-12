#ifndef INTRUMENTO_H_INCLUDED
#define INTRUMENTO_H_INCLUDED



typedef struct
{
    char nombreInstrumento[25];
    int tipoInstrumento;
    int idInstrumento;
    int isEmptyInstrumento;
} eInstrumento;


#endif // INTRUMENTO_H_INCLUDED

int subMenuTipoInstrumento();
int subMenuInstrumento();
int iniciarInstrumento(eInstrumento instrumento[], int tamInstrumento);
int buscarInstrumentoVacio(eInstrumento instrumento[], int tamInstrumento, int* error);
int altaInstrumento(eInstrumento instrumento[],int tamIntrumento, int posicion, int idInstrumento);
void mostrarIntrumento(eInstrumento instrumento);
int mostrarIntrumentos(eInstrumento instrumento[],int tamInstrumento);

