#ifndef UTNNOTEBOOK_H_INCLUDED
#define UTNNOTEBOOK_H_INCLUDED


typedef struct
{
    int id;
    char descripcion[20];

}eMarca;

typedef struct
{
    int id;
    char descripcion[20];

}eTipo;

typedef struct
{
    int id;
    char modelo[20];
    int idMarca;
    int idTipo;
    float precio;
    int isEmpty;

}eNotebook;
#endif // UTNNOTEBOOK_H_INCLUDED

void altaNotebook (eNotebook notebooks[], int tam);
int buscarLibre(eNotebook vec[], int tam);
void inicializarNotebooks (eNotebook notebooks[], int tam);
int buscarNotebook (int id, eNotebook vec[], int tam);
void modificarNotebook(eNotebook vec[], int tam);
void bajaNotebook(eNotebook vec[], int tam);
void mostrarNotebook(eNotebook vec);
void listarNotebooks(eNotebook vec[], int tam);
void listarMarcas(eMarca marcas[], int tam);
void listarTipos(eTipo tipos[], int tam);
