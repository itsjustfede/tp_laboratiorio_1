#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main()
{
    char seguir='s';
    int opcion=0;
    float num1 = 0, num2 = 0;
    int bandera1 = 1, bandera2 = 1;

    while(seguir=='s')
    {
        if (bandera1)
        {
            printf("--------------------------------\n");
            printf("1- Ingresar 1er operando (A=x)\n");
        }
        else
        {
            printf("--------------------------------\n");
            printf("1- Ingresar 1er operando (A=%.2f)\n", num1);
        }

        if (bandera2)
        {
            printf("2- Ingresar 2do operando (B=y)\n");
        }
        else
        {
            printf("1- Ingresar 2do operando (A=%.2f)\n", num2);
        }

        printf("3- Calcular la suma (A+B)\n");
        printf("4- Calcular la resta (A-B)\n");
        printf("5- Calcular la division (A/B)\n");
        printf("6- Calcular la multiplicacion (A*B)\n");
        printf("7- Calcular el factorial (A!)\n");
        printf("8- Calcular todas las operaciones\n");
        printf("9- Salir\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                system("cls");
                num1 = pedirNumeroFlotante(num1, "Ingrese primero operando...\n");
                bandera1 = 0;
                system("cls");
                break;
            case 2:
                system("cls");
                num2 = pedirNumeroFlotante(num2, "Ingrese segundo operando...\n");
                bandera2 = 0;
                system("cls");
                break;
            case 3:
                system("cls");
                suma(num1, num2);
                break;
            case 4:
                system("cls");
                resta(num1, num2);
                break;
            case 5:
                system("cls");
                division(num1, num2);
                break;
            case 6:
                system("cls");
                multplicacion(num1, num2);
                break;
            case 7:
                system("cls");
                factorial(num1);
                break;
            case 8:
                system("cls");
                suma(num1, num2);
                resta(num1, num2);
                division(num1, num2);
                multplicacion(num1, num2);
                factorial(num1);
                break;
            case 9:
                seguir = 'n';
                break;
        }

    }
    return 0;
}

