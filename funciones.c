#include <stdio.h>
#include <stdlib.h>


/** \brief La funcion imprime un mensaje y le pide un entero al usuario validando que el dato sea correcto
 *
 * \param mensaje[] char El mensaje que se le mostrara al usuario
 * \return int La funcion regresa el entero ingresado por el usuario
 *
 */
int getInt(char mensaje[])
{
    int auxiliar;
    printf("%s", mensaje);
    while(scanf("%d", &auxiliar)!=1)
    {
        fflush(stdin);
        printf("Error. Dato invalido\n");
        printf("%s", mensaje);
    }

    return auxiliar;
}

/** \brief La funcion imprime un mensaje y le pide un flotante al usuario validando que el dato sea correcto
 *
 * \param mensaje[] char El mensaje que se le mostrara al usuario
 * \return float La funcion regresa el flotante ingresado por el usuario
 *
 */
float getFloat(char mensaje[])
{
    float auxiliar;
    printf("%s",mensaje);
    while(scanf("%f", &auxiliar)!=1)
    {
        fflush(stdin);
        printf("Error. Dato invalido\n");
        printf("%s", mensaje);
    }
    return auxiliar;
}

/** \brief La funcion recibe dos valores, los suma y devuelve el resultado
 *
 * \param A float Es el primer numero a sumar
 * \param B float Es el segundo numero a sumar
 * \return float Devuelve el resultado de la suma de ambos
 *
 */
float sumar(float A, float B)
{
    float resultadoSuma;
    resultadoSuma = A + B;

    return resultadoSuma;
}

/** \brief La funcion recibe dos valores, los resta y devuelve el resultado
 *
 * \param A float Es el primer numero a restar
 * \param B float Es el segundo numero a restar
 * \return float Devuelve el resultado de la resta de ambos
 *
 */
float restar(float A, float B)
{
    float resultadoResta;
    resultadoResta = A-B;

    return resultadoResta;
}

/** \brief La funcion recibe dos numeros que, si es posible, dividira entre si
 *
 * \param DivisionCero int* Indica con 1 si el divisor es 0, o con 0 si el divisor es cualquier otro numero
 * \param A float El primer numero a dividir
 * \param B float El segundo numero a dividir
 * \return float Devuelve el resultado de la division, en caso de que no haya sido posible realizarla se retornara 0
 *
 */
float dividir(int* DivisionCero, float A, float B)
{
    float resultadoDivision;
    if(B == 0)
    {
        printf("No se puede dividir por 0\n");
        resultadoDivision = 0;
        *DivisionCero = 1;
    }
    else
    {
        *DivisionCero = 0;
        resultadoDivision = A/B;
    }

    return resultadoDivision;
}

/** \brief La funcion recibe dos valores, los multiplica y devuelve el resultado
 *
 * \param A float El primer numero a multiplicar
 * \param B float EL segundo numero a multiplicar
 * \return float Devuelve el resultado de la multiplicacion
 *
 */
float multiplicar(float A, float B)
{
    float resultadoMultiplicacion;
    resultadoMultiplicacion = A*B;

    return resultadoMultiplicacion;
}

/** \brief La funcion recibe un numero, verifica si es posible sacar el factorial, en caso de que lo sea realiza la operacion y devuelve el resultado
 *
 * \param factorialError int* Indica con 1 si el numero tenia decimales y por ende no fue posible sacar el factorial, o con 0 si fue posible
 * \param A float El numero del cual sacaremos el factorial
 * \return long int Se regresa como resultado el factorial del numero
 *
 */
long int factorial(int* factorialError, float A)
{
    long int auxiliar;
    int fact;
    float decimal;
    auxiliar = (int)A;
    fact = (int)A-1;
    decimal = A - auxiliar;
    if(auxiliar >= 0)
    {
        if(decimal == 0)
        {
            *factorialError = 0;
            while(fact>0)
            {
                auxiliar = auxiliar * fact;
                fact--;
            }
            if (auxiliar == 0)
            {
                auxiliar = 1;
            }

        }
        else
        {
            printf("No se puede sacar el factorial de un numero con decimales\n");
            *factorialError = 1;
        }
    }else{
        printf("No se puede sacar el factorial de un numero negativo\n");
        *factorialError = 1;
    }
    return auxiliar;
}
