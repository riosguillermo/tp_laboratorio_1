#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main()
{
    int opcion;
    float num1 = 0;
    float num2 = 0;
    float suma;
    float resta;
    float division;
    int divisionCero;
    float multiplicacion;
    long int factorialA = 1;
    long int factorialB = 1;
    int factorialErrorA = 0;
    int factorialErrorB = 0;


    do
    {
        printf("--------------------------------------------\n");
        printf("Seleccione una opcion : \n");
        printf("1.Ingresar 1er operando (A=%f)\n",num1);
        printf("2.Ingresar 2do operando (B=%f)\n",num2);
        printf("3.Calcular todas las operaciones \n");
        printf("4.Informar resultados\n");
        printf("5.Salir\n");
        opcion = getInt("Ingrese la opcion : ");
        printf("\n");

        switch (opcion)
        {
        case 1:
            num1 = getFloat("Ingrese el valor del primer operando : ");
            break;
        case 2:
            num2 = getFloat("Ingrese el valor del segundo operando : ");
            break;
        case 3:
            suma = sumar(num1, num2);
            resta = restar(num1, num2);
            division = dividir(&divisionCero,num1,num2);
            multiplicacion = multiplicar(num1,num2);
            factorialA = factorial(&factorialErrorA,num1);
            factorialB = factorial(&factorialErrorB,num2);
            printf("Calculos realizados... \n");
            break;
        case 4:
            printf("El resultado de A+B es: %f\n", suma);
            printf("El resultado de A-B es: %f\n", resta);
            if(divisionCero==0)
            {
                printf("El resultado de A/B es: %f\n", division);
            }
            else
            {
                printf("No se pudo realizar la division\n");
            }
            printf("El resultado de A*B es: %f\n", multiplicacion);
            if(factorialErrorA == 0)
            {
                printf("El factorial de A es: %ld\n", factorialA);
            }
            else
            {
                printf("No se pudo sacar el factorial de A\n");
            }
            if(factorialErrorB == 0)
            {
                printf("El factorial de B es: %ld\n", factorialB);
            }
            else
            {
                printf("No se pudo sacar el factorial de B\n");
            }
            break;
        case 5:
            printf("Hasta luego!\n");
            break;
        default:
            printf("Esa no es una opcion valida\n");
            break;
        }


    }
    while(opcion !=5);

}
