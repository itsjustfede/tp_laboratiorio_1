#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

/** \brief Pide un numero
 *
 * \param num Es onde se guarda el numero
 * \param mensaje Es el enunciado a mostrar
 * \return Devuelve el numero ingresado
 *
 */
float pedirNumeroFlotante(float num, char mensaje[])
{
    printf(mensaje);
    scanf("%f", &num);
    return num;
}

/** \brief Suma dos numeros
 *
 * \param num1 Guarda el primero numero
 * \param num2 Guarda el segundo numero a ser sumado
 *
 */
void suma(float num1, float num2)
{
    float resultado;

    resultado = num1 + num2;

    printf("La suma es: %.2f\n\n", resultado);

}

/** \brief Resta dos numeros
 *
 * \param num1 El numero a ser restado
 * \param num2 Cantidad a ser restada
 *
 */
void resta(float num1, float num2)
{
    float resultado;

    resultado = num1 - num2;

    printf("La resta es: %.2f\n\n", resultado);

}

/** \brief Divide dos numeros
 *
 * \param dividendo Es el numero a dividir
 * \param divisor Es el numero por el cual divide
 *
 */
void division(float dividendo, float divisor)
{
    float resultado;

    if (divisor == 0)
    {
        printf("\nError, el divisor no puede ser 0\n\n");
    }
    else
    {
        resultado = dividendo / divisor;
        printf("\nLa division es: %.2f\n\n", resultado);


    }
}

/** \brief Multiplica dos numeros
 *
 * \param multiplicando El numero a multplicar
 * \param multiplicador El numero que multiplica
 *
 */
void multplicacion(float multiplicando, float multiplicador)
{
    float resultado;

    resultado = multiplicando * multiplicador;

    printf("\nLa multiplicacion es: %.2f\n\n", resultado);

}

/** \brief Calcula el factorial de un numero
 *
 * \param num El numero a ser factoriado
 *
 */
void factorial(int num)
{
    int i, resp = 1;

    num = abs(num);

    num = validarNegativos(num);

    if (num != -1)
    {
       for(i = num; i > 1; i--)
        {
            resp = resp * i;
        }

        printf("\nEl factorial es: %d\n\n", resp);

    }

}


int validarNegativos(int num)
{
    int respuesta = num;

    if (num < 0)
    {
    printf("\nError!!! El numero no puede ser negativo\n\n");
    respuesta = -1;
    }
    return respuesta;
}
