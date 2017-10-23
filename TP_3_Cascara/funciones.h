#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct{
    char titulo[100];
    char genero[20];
    int duracion;
    char descripcion[1000];
    int puntaje;
    char linkImagen[500];
    int estado;
}EMovie;

/**
 *  Agrega una pelicula al archivo binario
 *  @param movie la estructura a ser agregada al archivo
 */
void agregarPelicula(EMovie movie);

/**
 *  Borra una pelicula del archivo binario
 *  @param movie la estructura a ser eliminada al archivo
 */
void borrarPelicula(EMovie movie);

/** \brief Modifica una pelicula del archivo binario
 *
 * @param movie la estructura a ser modificada al archivo
 */
void modificarPelicula(EMovie movie);

/**
 *  Genera un archivo html a partir de las peliculas cargadas en el archivo binario.
 *  @param lista la lista de peliculas a ser agregadas en el archivo.
 *  @param nombre el nombre para el archivo.
 */
void generarPagina(EMovie lista[], int tam, char nombre[]);

/**
 *  Busca el pimer lugar vacio
 *  @return la cantidad de registros hasta el lugar vacio
 */


void crearArray(EMovie movie);
#endif // FUNCIONES_H_INCLUDED
