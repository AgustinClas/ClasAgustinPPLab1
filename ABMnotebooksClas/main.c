#include <stdio.h>
#include <stdlib.h>
#include "UTN.h"
#include "UTNnotebook.h"
#include "UTNtrabajoyservicio.h"

#define TAMNOT 1000
#define TAMTRB 10000


int mostrarMenu();


int main()
{
    int proximoIdTrabajo = 1000;
    int altaTrabajoOk;
    eMarca marcas[4]={ {1, "Compaq"},{2, "Asus"},{3, "Acer"},{4,"HP"}};
    eTipo tipos[4]={ {1, "Gamer"},{2, "Disenio"},{3, "Ultrabook"},{4, "Normalita"}};
    eServicio servicios[4]= {{20000, "Bateria", 250 },{20001, "Antivirus", 300},{20002, "Actualizacion", 400},{20003, "Fuente", 600}};

    eTrabajo trabajos[TAMTRB];
    inicializarTrabajos(trabajos, TAMTRB);


    eNotebook notebooks[TAMNOT];
    inicializarNotebooks(notebooks, TAMNOT);

    int opcionMenu;

    do
    {
        //No uso system("cls") aqui ya que en mi consola no hace pausa automatioca entonces al listar algo no podria llegar a leerlo
        opcionMenu = mostrarMenu();

        switch(opcionMenu)
        {
        case 1:
            altaNotebook(notebooks, TAMNOT);
            break;
        case 2:
            modificarNotebook(notebooks, TAMNOT);
            break;
        case 3:
            bajaNotebook(notebooks, TAMNOT);
            break;
        case 4:
            listarNotebooks(notebooks, TAMNOT);
            break;
        case 5:
            listarMarcas(marcas, 4);
            break;
        case 6:
            listarTipos(tipos, 4);
            break;
        case 7:
            listarServicios(servicios, 4);
            break;
        case 8:
            altaTrabajoOk = altaTrabajo(trabajos, TAMTRB, notebooks, TAMNOT, servicios, 4, proximoIdTrabajo);
            if(altaTrabajoOk == 1){
                    proximoIdTrabajo++;
            }else{
                printf("\nOcurrio un error en el sistema\n");
            }

            break;
        case 9:
            listarTrabajos(trabajos, TAMTRB);
            break;

        }
    }
    while(opcionMenu!=10);


}


int mostrarMenu()
{
    int opcion;

    printf("\n****Menu****:\n\n1.Alta notebook\n");
    printf("2.Modificar notebook\n3.Baja notebook\n");
    printf("4.Listar notebooks\n5.Listar marcas\n");
    printf("6.Listar tipos\n7.Listar servicios\n8.Alta trabajo\n9.Listar trabajos\n10.Salir\n");


    utn_getNumeroEntero(&opcion, "Ingrese opcion: ", "\nEsa opcion no es valida. ", 1, 10, 10);


    return opcion;

}

