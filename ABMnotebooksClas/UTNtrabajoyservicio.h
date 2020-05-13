#include "UTNnotebook.h"

#ifndef UTNTRABAJOYSERVICIO_H_INCLUDED
#define UTNTRABAJOYSERVICIO_H_INCLUDED


typedef struct
{
    int dia;
    int mes;
    int anio;

} eFecha;

typedef struct
{
    int id;
    char descripcion[20];
    float precio;

}eServicio;

typedef struct
{
    int id;
    int idNotebook;
    int idServicio;
    eFecha fecha;
    int isEmpty;

}eTrabajo;

#endif // UTNTRABAJOYSERVICIO_H_INCLUDED

void listarServicios(eServicio servicios[], int tam);
int buscarLibreTrabajo(eTrabajo vec[], int tam);
int buscarTrabajo (int id, eTrabajo vec[], int tam);
void inicializarTrabajos (eTrabajo trabajos[], int tam);
int altaTrabajo (eTrabajo trabajos[], int tam, eNotebook notebooks[], int tamNot, eServicio servicios[], int tamSer, int proximoId);
void listarTrabajos (eTrabajo trabajos[], int tam);

