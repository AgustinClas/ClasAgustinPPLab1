#include "UTN.h"
#include "UTNtrabajoyservicio.h"
#include <stdio.h>
#include <stdlib.h>

void listarServicios(eServicio servicios[], int tam)
{
    printf("****Servicios****\n");
    printf("Id              Servicio          Precio\n\n");

    for(int i=0; i<tam; i++)
    {
        printf("%d     %15s       %.2f\n", servicios[i].id, servicios[i].descripcion, servicios[i].precio);
    }

    printf("\n\n");
}

int altaTrabajo (eTrabajo trabajos[], int tam, eNotebook notebooks[], int tamNot, eServicio servicios[], int tamSer, int proximoId)
{
    int todoOk=0;
    int indiceLibre;
    eTrabajo auxTrabajo;

    system("cls");
    printf("***Alta Trabajo***\n\n");

    indiceLibre=buscarLibreTrabajo(trabajos, tam);

    if(indiceLibre==-1)
    {
        printf("\nSistema completo\n");
    }
    else{

            auxTrabajo.id = proximoId;
            utn_getNumeroEntero(&auxTrabajo.idNotebook, "Ingrese el id de la notebook: ", "\nError. ", 999, 9999, 10);

            while(buscarNotebook(auxTrabajo.idNotebook, notebooks, tamNot)==-1)
                {
                    printf("Este id de notebook no existe. \n");
                    utn_getNumeroEntero(&auxTrabajo.idNotebook, "Ingrese el id de la notebook: ", "\nError. ", 999, 9999, 10);
                }

            printf("\n");
            utn_getNumeroEntero(&auxTrabajo.idServicio, "Ingrese id del servicio: ", "\nError. ", 20000, 20003, 10);

            utn_getNumeroEntero(&auxTrabajo.fecha.dia, "Ingrese el dia: ", "\nError. ", 1, 31, 10);
            utn_getNumeroEntero(&auxTrabajo.fecha.mes, "Ingrese el mes: ", "\nError. ", 1, 12, 10);

            //Podra dar de alta trabajos por los proximos 10 años
            utn_getNumeroEntero(&auxTrabajo.fecha.anio, "Ingrese el anio: ", "\nError. ", 2020, 2030, 10);

            auxTrabajo.isEmpty = 0;

            trabajos[indiceLibre] = auxTrabajo;

            todoOk=1;

    }


    return todoOk;
}

int buscarLibreTrabajo(eTrabajo vec[], int tam)
{
    int indice=-1;
    for(int i=0; i<tam; i++)
    {
        if(vec[i].isEmpty==1)
        {
            indice=i;
            break;
        }
    }

    return indice;
}

void inicializarTrabajos (eTrabajo trabajos[], int tam)
{
    for(int i=0; i<tam; i++)
    {
        trabajos[i].isEmpty = 1;
    }
}

int buscarTrabajo (int id, eTrabajo vec[], int tam)
{
    int indice=-1;

    for(int i=0; i<tam; i++)
    {
        if(vec[i].id==id && vec[i].isEmpty == 0)
        {
            indice=i;
            break;
        }
    }

    return indice;
}


void listarTrabajos (eTrabajo trabajos[], int tam)
{
    system("cls");
    printf("****Trabajos****\n\n");
    printf("Id   Id notebook  Id servicio    Fecha");

    for(int i=0; i<tam; i++)
    {
        if(trabajos[i].isEmpty==0){
        printf("%d  %d  %d    %d/%d/%d \n", trabajos[i].id, trabajos[i].idNotebook, trabajos[i].idServicio, trabajos[i].fecha.dia, trabajos[i].fecha.mes, trabajos[i].fecha.anio);
        }
    }

    printf("\n\n");

}

