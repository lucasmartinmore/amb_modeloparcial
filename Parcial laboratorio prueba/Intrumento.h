#ifndef INTRUMENTO_H_INCLUDED
#define INTRUMENTO_H_INCLUDED



typedef struct
{
    char nombreInstrumento[25];
    char tipoInstrumento[25];
    int idInstrumento;
    int isEmptyInstrumento;
} eInstrumento;


#endif // INTRUMENTO_H_INCLUDED

int subMenuTipoInstrumento();
int subMenuInstrumento();

