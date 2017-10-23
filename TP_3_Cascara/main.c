#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>
#include "funciones.h"


int main()
{
    char seguir='s';
    int opcion=0;
    EMovie peliculita;

    while(seguir=='s')
    {
        printf("1- Agregar pelicula\n");
        printf("2- Borrar pelicula\n");
        printf("3- Modificar pelicula\n");
        printf("4- Generar pagina web\n");
        printf("5- Salir\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                system("cls");
                agregarPelicula(peliculita);
                getch();
                system("cls");
                break;
            case 2:
                system("cls");
                borrarPelicula(peliculita);
                getch();
                system("cls");
                break;
            case 3:
                system("cls");
                modificarPelicula(peliculita);
                getch();
                system("cls");
               break;
            case 4:
                system("cls");
                crearArray(peliculita);
                getch();
                system("cls");
               break;
            case 5:
                seguir = 'n';
                break;
            default:
            system("cls");
            printf("Opcion incorrecta.");
            getch();
            system("cls");
            break;
        }
    }

    return 0;
}
