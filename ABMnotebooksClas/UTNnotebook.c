#include "UTNnotebook.h"
#include <stdio.h>
#include <stdlib.h>
#include "UTN.h"

void altaNotebook (eNotebook notebooks[], int tam)
{
    int indiceLibre;
    int id;
    int existe;
    eNotebook auxNotebook;

    system("cls");
    printf("***Alta Notebook***\n\n");

    indiceLibre=buscarLibre(notebooks, tam);

    if(indiceLibre==-1)
    {
        printf("\nSistema completo\n");
    }
    else
    {
        utn_getNumeroEntero(&id, "Ingrese Id: ", "\n Error.", 999, 9999, 10);

        existe=buscarNotebook(id, notebooks, tam);

        if(existe!=-1)
        {
            printf("\nYa existe una notebook registrado con este id\n");
        }
        else
        {
            auxNotebook.id = id;
            utn_getString(auxNotebook.modelo, "\nIngrese  el modelo: ", "\nError. ", 10);
            utn_getNumeroEntero(&auxNotebook.idTipo, "\nIngrese el tipo: ", "\nError. ", 1, 4, 10);
            utn_getNumeroEntero(&auxNotebook.idMarca, "\nIngrese la marca: ", "\nError. ", 1, 4, 10);
            utn_getNumeroFlotante(&auxNotebook.precio, "\nIngrese el precio: ", "\nError. ", 1, 400000, 10);
            auxNotebook.isEmpty = 0;

            notebooks[indiceLibre] = auxNotebook;


        }
    }
}

int buscarLibre(eNotebook vec[], int tam)
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

void inicializarNotebooks (eNotebook notebooks[], int tam)
{
    for(int i=0; i<tam; i++)
    {
        notebooks[i].isEmpty = 1;
    }
}

int buscarNotebook (int id, eNotebook vec[], int tam)
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

void modificarNotebook(eNotebook vec[], int tam)
{
    int id;
    int indice;
    int opcion;

    system("cls");
    printf("***Modificar Notebook***\n");

    utn_getNumeroEntero(&id, "Ingrese id: ", "Error. ", 999, 9999, 10);

    indice=buscarNotebook(id, vec, tam);


    if(indice==-1)
    {
        printf("\nEste id no existe\n");

    }else{

            printf("\nQue desea modificar?\n");
            printf("1. Precio: %.2f\n", vec[indice].precio);
            printf("2. tipo: %d\n", vec[indice].idTipo);
            utn_getNumeroEntero(&opcion, "Ingrese su opcion: ", "Error. ", 1, 2, 10);

            if(opcion == 1){

                printf("\n");
                utn_getNumeroFlotante(&vec[indice].precio,"Ingrese el nuevo precio: ", "Error. ", 1, 400000, 10);
            }else{
                printf("\n");
                utn_getNumeroEntero(&vec[indice].idTipo, "Ingrese el nuevo tipo: ", "Error. ", 1, 4, 10);

            }

            printf("\nOperacion realizada con exito\n");

    }

}

void bajaNotebook(eNotebook vec[], int tam)
{
    int id;
    int indice;
    char confirmacion;

    system("cls");
    printf("***Baja Notebook***\n");

    utn_getNumeroEntero( &id, "Ingrese id: ", "\nError. ", 999, 9999, 10);

    indice=buscarNotebook(id, vec, tam);

    if(indice==-1)
    {
        printf("Este id no existe");
    }
    else
    {
        printf("\nSeguro que desea dar de baja esta Notebook s/n:  ");
        fflush(stdin);
        scanf("%c", &confirmacion);

        if(confirmacion=='s')
        {
            vec[indice].isEmpty=1;
            printf("Operacion realizada con exito");
        }
        else
        {
            printf("Se cancela la operacion");
        }

    }

}

void listarNotebooks(eNotebook vec[], int tam)
{
    int flag=1;
    eNotebook auxNotebook;
    system("cls");
    printf("****Lista de notebooks****");

    for(int i=0; i<tam-1; i++)
    {
        for(int j=1; j<tam;j++)
        {
            if(vec[i].idMarca < vec[j].idMarca)
            {
                auxNotebook = vec[i];
                vec[i] = vec[j];
                vec[j] = auxNotebook;

            }else if(vec[i].idMarca == vec[j].idMarca)
            {
                if(vec[i].precio < vec[j].precio){
                    auxNotebook = vec[i];
                    vec[i] = vec[j];
                    vec[j] = auxNotebook;
                    }
            }
        }
    }

    printf("\nId  Marca  Tipo        Modelo         Precio\n");

    for(int i=0; i<tam; i++)
    {
        if(vec[i].isEmpty==0)
        {
            mostrarNotebook(vec[i]);
            flag=0;
        }

    }

    if(flag==1)
    {
        printf("No hay empleados para mostrar");
    }

}

void mostrarNotebook(eNotebook vec)
{
    printf("%d   %d    %d  %15s     %.2f\n", vec.id, vec.idMarca, vec.idTipo, vec.modelo, vec.precio);

}

void listarMarcas(eMarca marcas[], int tam)
{
    printf("****Marcas****\n\n");
    printf("Id      Marca\n");

    for(int i=0; i<tam; i++)
    {
        printf("%d       %s\n", marcas[i].id, marcas[i].descripcion);
    }

    printf("\n\n");
}

void listarTipos(eTipo tipos[], int tam)
{
    printf("****Tipos****\n\n");
    printf("Id       tipo\n");

    for(int i=0; i<tam; i++)
    {
        printf("%d       %s\n", tipos[i].id, tipos[i].descripcion);
    }

    printf("\n\n");

}
