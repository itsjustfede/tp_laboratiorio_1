#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>
#include "funciones.h"

#define ARCH    ".\\peliculas.dat"


void agregarPelicula(EMovie movie)
{
    FILE  *peliculas;

    EMovie aux;

    if ((peliculas = fopen(ARCH, "r+b")) == NULL)
    {
        if ((peliculas = fopen(ARCH, "w+b")) == NULL)
        {
            printf("No se pudo abrir el archivo");
            exit(1);
        }
    }

    printf("\nIngrese el nombre de la pelicula: ");
    fflush(stdin);
    gets(movie.titulo);

    while(!feof(peliculas))
    {
        fread(&aux, sizeof(aux), 1, peliculas);

        {
            if (strcmpi(movie.titulo, aux.titulo) == 0 && movie.estado != 0)
            {
                printf("La pelicula ya existe");
                break;
            }
            else
            {
                printf("\nIngrese el genero: ");
                fflush(stdin);
                gets(movie.genero);

                printf("\nIngrese la duracion (minutos): ");
                scanf("%d",&movie.duracion);

                printf("\nIngrese descripcion de la pelicula: ");
                fflush(stdin);
                gets(movie.descripcion);

                printf("\nIngrese el puntaje: ");
                scanf("%d", &movie.puntaje);

                printf("\nIngrese el link de una imagen para la pelicula: ");
                fflush(stdin);
                gets(movie.linkImagen);

                movie.estado = 1;

                fseek(peliculas, 0L, SEEK_END);
                fflush(stdin);
                fwrite(&movie, sizeof(movie), 1, peliculas);

                if ((fclose(peliculas)) == -1)
                {
                    printf("\nNo se pudo guardar la pelicula");
                }
                else
                {
                    printf("\nLa pelicula se guardo exitosamente");
                }

                break;
            }

        }

    }

    fclose(peliculas);
}

void borrarPelicula(EMovie movie)
{

    movie.estado = 0;

    int cantidad;

    char tituloDePelicula[100];

    FILE  *peliculas;

    if ((peliculas = fopen(ARCH, "rb+")) == NULL)
    {
        printf("No se pudo abrir el archivo");
        exit(1);
    }

    printf("Ingrese pelicula a borrar: ");
    fflush(stdin);
    gets(tituloDePelicula);


    while(!feof(peliculas))
    {
        cantidad = fread(&movie, sizeof(movie), 1, peliculas);

        if(cantidad != 1)
        {
            if(feof(peliculas))
            {
                printf("la pelicula no existe");
                break;
            }
        }
        if (strcmpi(tituloDePelicula, movie.titulo) == 0 && movie.estado != 0)
        {
            movie.estado = 0;
            fseek(peliculas, (long) (-1) * (sizeof(movie)), SEEK_CUR);
            fwrite(&movie, sizeof(movie), 1, peliculas);
            printf("Pelicula borrada con exito.");
            break;
        }

    }

    fclose(peliculas);
}

void modificarPelicula(EMovie movie)
{
    char pelicula[100];
    char respuesta;

    int opcion=0;
    int cantidad;
    int validar = 1;

    char auxCadena[500];
    int auxEntero;

    FILE  *peliculas;

    if ((peliculas = fopen(ARCH, "r+b")) == NULL)
    {
        printf("No se pudo abrir el archivo");
        exit(1);
    }

    printf("Ingrese pelicula: ");
    fflush(stdin);
    gets(pelicula);

    while(!feof(peliculas))
    {
        cantidad = fread(&movie, sizeof(movie), 1, peliculas);

        if (strcmpi(pelicula, movie.titulo) == 0 && movie.estado != 0)
        {
            printf("Esta seguro que desea modificar la pelicula \"%s\"? S/N \n", movie.titulo);
            fflush(stdin);
            scanf("%c", &respuesta);

            respuesta = tolower(respuesta);

            while (validar)
            {
                if (respuesta == 's')
                {
                    validar = 0;

                    printf("\nQue desea modificar? \n\n");

                    printf("1- Titulo \"%s\"\n", movie.titulo);
                    printf("2- Genero\"%s\"\n", movie.genero);
                    printf("3- Duracion\"%d\"\n", movie.duracion);
                    printf("4- Descripcion\"%s\"\n", movie.descripcion);
                    printf("5- Puntaje\"%d\"\n", movie.puntaje);
                    printf("6- Link de imagen\"%s\"\n\n", movie.linkImagen);
                    printf("7- Cancelar\n");

                    fflush(stdin);
                    scanf("%d",&opcion);

                    switch(opcion)
                    {
                    case 1:
                        system("cls");
                        printf("Ingrese el nuevo titulo: ");
                        fflush(stdin);
                        gets(auxCadena);
                        strcpy(movie.titulo, auxCadena);
                        system("cls");

                        break;
                    case 2:
                        system("cls");
                        printf("Ingrese el nuevo genero: ");
                        fflush(stdin);
                        gets(auxCadena);
                        strcpy(movie.genero, auxCadena);
                        system("cls");

                        break;
                    case 3:
                        system("cls");
                        printf("Ingrese la nueva duracion: ");
                        scanf("%d", &auxEntero);
                        system("cls");
                        movie.duracion = auxEntero;

                        break;
                    case 4:
                        system("cls");
                        printf("Ingrese el nuevo descripcion: ");
                        fflush(stdin);
                        gets(auxCadena);
                        strcpy(movie.descripcion, auxCadena);
                        system("cls");

                        break;
                    case 5:
                        system("cls");
                        printf("Ingrese el nuevo puntaje: ");
                        scanf("%d", &auxEntero);
                        movie.puntaje = auxEntero;
                        system("cls");

                        break;
                    case 6:
                        system("cls");
                        printf("Ingrese la nueva dirrecion url: ");
                        fflush(stdin);
                        gets(auxCadena);
                        strcpy(movie.linkImagen, auxCadena);
                        system("cls");

                        break;
                    case 7:
                        opcion = 0;
                        break;
                    default:
                        system("cls");
                        printf("Opcion incorrecta.");
                        getch();
                        system("cls");
                        break;
                    }
                    fseek(peliculas, (long) (-1) * (sizeof(movie)), SEEK_CUR);
                    fwrite(&movie, sizeof(movie), 1, peliculas);
                    printf("\n\n peli %s", movie.titulo);
                    printf("\nPelicula modificada con exito.");
                    fclose(peliculas);
                    break;

                }
                else if (respuesta == 'n')
                {
                    validar = 0;
                    printf("\nAccion cancelada");
                    break;

                }
                printf("Ingrese S/N");
                fflush(stdin);
                scanf("%c", &respuesta);
                respuesta = tolower(respuesta);
            }
            break;
        }

        else if(cantidad != 1)
        {
            if(feof(peliculas))
            {
                printf("la pelicula no existe");
                break;
            }
            break;
        }
    }
    fclose(peliculas);
}

void crearArray(EMovie movie)
{
    int cant, i = 0;
    char nombreDelArchivo[500];
    int tamanoDeLista = 20;

    EMovie aux;

    printf("Ingrese el nombre del archivo: ");
    fflush(stdin);
    gets(nombreDelArchivo);

    strcat(nombreDelArchivo, ".html");

    FILE *peliculas;

    EMovie* lista = (EMovie*) malloc(sizeof(EMovie) * tamanoDeLista);

    peliculas = fopen(ARCH, "r+b");

    while(!feof(peliculas))
    {
        cant = fread(&aux, sizeof(aux), 1, peliculas);

        if(cant!=1)
        {
            if(feof(peliculas))
            {
                break;
            }
        }
            if (aux.estado != 0)
            {
                lista[i] = aux;

                if (i == tamanoDeLista)
                {
                    tamanoDeLista+=10;
                    lista = realloc(lista, sizeof(EMovie) * tamanoDeLista);
                }
                i++;
            }

}
        fclose(peliculas);

        printf("valor de i %d\n", i);

        generarPagina(lista, i-1, nombreDelArchivo);
}

void generarPagina(EMovie lista[], int tam, char nombre[])
{
    int i;

    char nombreDeArchivo [] = {".\\template\\"};

    strcat(nombreDeArchivo, nombre);

    FILE *pagina;

    pagina = fopen(nombreDeArchivo, "w");

    fputs("<html lang='en'> \n <head> \n  <meta charset='utf-8'> \n <meta http-equiv='X-UA-Compatible' content='IE=edge'> \n <meta name='viewport' content='width=device-width, initial-scale=1'> \n <title>Lista peliculas</title> \n <link href='css/bootstrap.min.css' rel='stylesheet'> \n <link href='css/custom.css' rel='stylesheet'> \n </head> \n <body> \n <div class='container'> \n <div class='row'> \n", pagina);

    for (i = 0; i <= tam; i++)
    {
        fputs("\n<article class='col-md-4 article-intro'> \n <a href='#'> \n <img class='img-responsive img-rounded' src='", pagina);
        fputs(lista[i].linkImagen, pagina);
        fputs("' alt=''> \n </a> \n <h3> \n <a href='#'>", pagina);
        fputs(lista[i].titulo, pagina);
        fputs("</a> \n </h3> \n <ul> \n <li>Genero:", pagina);
        fputs(lista[i].genero, pagina);
        fputs("</li> \n <li>Puntaje:", pagina);
        fprintf(pagina, "%d", lista[i].puntaje);
        fputs("</li> \n <li>Duracion:", pagina);
        fprintf(pagina, "%d", lista[i].duracion);
        fputs("</li> \n </ul> \n <p>", pagina);
        fputs(lista[i].descripcion, pagina);
        fputs("</p> \n </article> \n", pagina);
    }

    fputs("</div> \n </div> \n <script src='js/jquery-1.11.3.min.js'></script> \n <script src='js/bootstrap.min.js'></script> \n <script src='js/ie10-viewport-bug-workaround.js'></script> \n <script src='js/holder.min.js'></script> \n </body> \n </html>", pagina);

    fclose(pagina);

    printf("\nPagina creada correctamente");
}


