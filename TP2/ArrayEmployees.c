#include "ArrayEmployees.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/** \brief To indicate that all position in the array are empty,
 * this function put the flag (isEmpty) in TRUE in all
 * position of the array
 * \param list Employee* Pointer to array of employees
 * \param len int Array length
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int initEmployees(Employee list[], int len)
{
    int i;
    if(len > 0 && list != NULL)
    {

        for(i=0; i<len; i++)
        {
            list[i].isEmpty = 1;
            list[i].id = 0;
        }
        return 0;
    }
    return -1;
}



/** \brief  add in a existing list of employees the values received as parameters
 *          in the first empty position
 * \param list[] Employee
 * \param len int
 * \param id int
 * \param name[] char
 * \param lastName[] char
 * \param salary float
 * \param sector int
 * \return int
 *
 */
int addEmployee(Employee list[], int len, int id, char name[],char lastName[],float salary,int sector)
{
    if(id>0 && salary > 0 && sector >= 0)
    {

        list[len].id = id;
        list[len].isEmpty = 0;
        strcpy(list[len].name,name);
        strcpy(list[len].lastName,lastName);
        list[len].salary = salary;
        list[len].sector = sector;
        return 0;
    }


    return -1;
}


/** \brief La funcion busca en la lista de empleados la primer posicion libre y la devuelve
 *
 * \param list[] Employee - La lista de empleados donde se buscara
 * \param len int - El tamaño de la lista
 * \return int - La funcion retornara como int la posicion en el array del primer espacio libre, o -1 si no hay ningun espacio libre
 *
 */
int buscarLibre(Employee list[], int len)
{
    int i;
    int indice=-1;
    for(i=0; i<len; i++)
    {
        if(list[i].isEmpty==1)
        {
            indice=i;
            break;
        }
    }
    if(indice == -1)
    {
        printf("No quedan espacios libres\n");
    }
    return indice;
}


/** \brief La funcion verificara si es posible añadir un nuevo empleado, y en caso de que se pueda, le pedira al usuario los datos correspondientes para la carga
 *
 * \param list[] Employee - La lista de empleados donde se realizara la carga
 * \param len int - El tamañano de la lista
 * \return int - La funcion retornara 0 si pudo realizar la carga o -1 si no fue posible
 *
 */
int cargarUnEmpleado(Employee list[],int len)
{
    int indice;
    int retorno;
    indice=buscarLibre(list, len);

    if(indice!=-1)
    {
        Employee nuevoEmpleado;


        nuevoEmpleado.id = AsignarNuevoID(list,len);

        printf ("Ingrese el nombre(maximo 50 caracteres): ");
        fflush(stdin);
        gets(nuevoEmpleado.name);
        while(esSoloLetras(nuevoEmpleado.name, sizeof(nuevoEmpleado.name))!=1)
        {
            if(esSoloLetras(nuevoEmpleado.name, sizeof(nuevoEmpleado.name))==-1)
            {
                printf("Error, caracteres invalidos\n");
            }
            if(esSoloLetras(nuevoEmpleado.name, sizeof(nuevoEmpleado.name))==-2)
            {
                printf("Error, ingrese como maximo 50 caracteres\n");
            }
            printf ("Ingrese el nombre :");
            fflush(stdin);
            gets(nuevoEmpleado.name);
        }

        printf ("Ingrese el apellido(maximo 50 caracteres): ");
        fflush(stdin);
        gets(nuevoEmpleado.lastName);
        while(esSoloLetras(nuevoEmpleado.lastName, sizeof(nuevoEmpleado.lastName))!=1)
        {
            if(esSoloLetras(nuevoEmpleado.lastName, sizeof(nuevoEmpleado.lastName))==-1)
            {
                printf("Error, caracteres invalidos\n");
            }
            if(esSoloLetras(nuevoEmpleado.lastName, sizeof(nuevoEmpleado.lastName))==-2)
            {
                printf("Error, ingrese como maximo 50 caracteres\n");
            }
            printf ("Ingrese el apellido :");
            fflush(stdin);
            gets(nuevoEmpleado.lastName);
        }

        nuevoEmpleado.salary = getFloat("Ingrese el salario : ");
        while(nuevoEmpleado.salary <= 0)
        {
            printf("Ingrese un salario mayor a 0\n");
            nuevoEmpleado.salary = getFloat("Ingrese el salario : ");
        }


        nuevoEmpleado.sector = getInt("Ingrese el sector : ",0,0);
        while(nuevoEmpleado.sector < 0)
        {
            printf("El sector no puede ser un numero negativo\n");
            nuevoEmpleado.sector = getInt("Ingrese el sector : ",0,0);
        }

        retorno = addEmployee(list,indice,nuevoEmpleado.id,nuevoEmpleado.name,nuevoEmpleado.lastName,nuevoEmpleado.salary,nuevoEmpleado.sector);
    }
    else
    {
        retorno=-1;
    }
    return retorno;
}



/** \brief La funcion le pedira un entero un entero al usuario y valida que el usuario ingrese un numero dentro del rango determinado, si el minimo y el maximo son iguales, la funcion solo validara que lo ingresado sea un numero
 *
 * \param mensaje[] char - El mensaje que se le mostrara al usuario
 * \param minimo int - El minimo del rango
 * \param maximo int - El maximo del rango
 * \return int - La funcion retornara valor ingresado por el usuario
 *
 */
int getInt(char mensaje[],int minimo, int maximo)
{
    int auxiliar;
    printf("%s", mensaje);
    if((maximo - minimo) == 0)
    {
        while(scanf("%d", &auxiliar)!=1)
        {
            fflush(stdin);
            printf("Error. Dato invalido\n");
            printf("%s", mensaje);
        }
    }
    else
    {
        while(scanf("%d", &auxiliar)!=1 || auxiliar < minimo || auxiliar > maximo)
        {
            fflush(stdin);
            printf("Error. Dato invalido\n");
            printf("%s", mensaje);
        }
    }

    return auxiliar;
}


/** \brief La funcion buscara el ID mas alto entre la lista de empleados y devolvere ese valor + 1
 *
 * \param list[] Employee - La lista de empleados donde se leeran los ID
 * \param len int - El tamaño maximo de la lista
 * \return int - La funcion retorna el id mas alto que encontro + 1
 *
 */
int AsignarNuevoID(Employee list[],int len)
{
    int i;
    int maximo;
    maximo = 0;
    for(i=0; i<len; i++)
    {
        if(list[i].id > maximo)
        {
            maximo = list[i].id;
        }
    }
    return maximo+1;
}

/** \brief find an Employee by Id en returns the index position in array.
 *
 * \param list Employee*
 * \param len int
 * \param id int
 * \return Return employee index position or (-1) if [Invalid length or NULL pointer received or employee not found]
 *
 */
int findEmployeeById(Employee list[], int len,int id)
{
    int i;
    for(i=0; i<len; i++)
    {
        if(list[i].id == id && list[i].id != 0 && list[i].isEmpty == 0)
        {
            return i;
        }
    }
    return -1;
}


/** \brief Remove a Employee by Id (put isEmpty Flag in 1)
 *
 * \param list Employee*
 * \param len int
 * \param id int
 * \return int Return (-1) if Error [Invalid length or NULL pointer or if can't find a employee] - (0) if Ok
 *
 */

int removeEmployee(Employee list[], int len, int id)
{
    int i;
    for(i=0; i<len; i++)
    {
        if(list[i].id == id && list[i].id != 0 && list[i].isEmpty == 0)
        {
            list[i].isEmpty = 1;
            return 0;
        }
    }
    return -1;
}

/** \brief Sort the elements in the array of employees, the argument order indicate UP or DOWN order
 *
 * \param list Employee*
 * \param len int
 * \param order int [1] indicate UP - [0] indicate DOWN
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int sortEmployees(Employee list[], int len, int order)
{
    Employee auxiliar;
    int i;
    int j;

    if(order == 0)
    {

        for(i=0; i<len-1; i++)
        {
            for(j=i+1; j<len; j++)
            {

                if(strcmp(list[i].lastName,list[j].lastName) < 0)
                {
                    auxiliar = list[i];
                    list[i] = list[j];
                    list[j] = auxiliar;
                }
                if (strcmp(list[i].lastName,list[j].lastName) == 0)
                {
                    if(list[i].sector < list[j].sector)
                    {
                        auxiliar = list[i];
                        list[i] = list[j];
                        list[j] = auxiliar;
                    }
                }
            }
        }
    }
    if(order == 1)
    {
        for(i=0; i<len-1; i++)
        {
            for(j=i+1; j<len; j++)
            {

                if(strcmp(list[i].lastName,list[j].lastName) > 0)
                {
                    auxiliar = list[i];
                    list[i] = list[j];
                    list[j] = auxiliar;
                }
                if (strcmp(list[i].lastName,list[j].lastName) == 0)
                {
                    if(list[i].sector > list[j].sector)
                    {
                        auxiliar = list[i];
                        list[i] = list[j];
                        list[j] = auxiliar;
                    }
                }
            }
        }
    }

    return 0;
}


/** \brief La funcion recibira una cadena de caractares y el tamaño maximo de dicha de cadena y verificara que todos los elementos sean una letra o un espacio, tambien verificara que la cadena no supere su tamaño maximo
 *
 * \param cadena[] char - La cadena que se analizara
 * \param maximo int - El tamaño maximo de la cadena
 * \return int - La funcion retorna 1 si la cadena no tiene errores, -1 si hay algun caracter invalido y -2 si la cadena supera su tamaño maximo
 *
 */
int esSoloLetras(char cadena[], int maximo)
{
    int i = 0;
    while(cadena[i] != '\0')
    {
        if(i < maximo-1)
        {

            if((cadena[i] != ' ') && (cadena[i] < 'a' || cadena[i] > 'z') && (cadena[i] < 'A' || cadena[i] > 'Z'))
            {

                return -1;
            }
        }
        else
        {

            return -2;
        }
        i++;
    }
    return 1;
}

/** \brief La funcion imprime un mensaje y le pide al usuario un numero flotante, si el dato ingresado no es valido imprimira un mensaje de error y volvera a pedir el numero
 *
 * \param mensaje[] char - El mensaje que se le mostrara al usuario
 * \return float - La funcion retornara el flotante que ingreso el usuario
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


/** \brief print the content of employees array
 *
 * \param list Employee*
 * \param length int
 * \return int
 *
 */
int printEmployees(Employee list[], int length)
{
    int i;

    printf("ID \t\t Apellido \t Nombre \t Salario \t Sector\n");
    for(i=0; i<length; i++)
    {
        if(list[i].isEmpty == 0)
        {
            printf("%d \t\t %s \t %s \t\t %.2f \t\t %d\n",list[i].id,list[i].lastName,list[i].name,list[i].salary,list[i].sector);

        }
    }

    return 0;
}


/** \brief La funcion le pedira un ID al usuario para buscar un empleado y si lo encuentre le permitira al usuario modificar diferentes campos
 *
 * \param list[] Employee - La lista de empleados donde se buscara el empleado a modificar
 * \param len int - El tamaño maximo de la lista
 * \return int - La funcion retorna -1 si no se pudo modificar al empleado y 0 si la modificacion fue exitosa
 *
 */
int editEmployees(Employee list[], int len)
{
    int id;
    int empleadoAEditar;
    int opcion;
    id = getInt("Ingrese el ID del empleado que desea editar : ",0,0);
    empleadoAEditar = findEmployeeById(list,len,id);
    if(empleadoAEditar != -1)
    {
        printf("\nSeleccione el campo que desea modificar: \n1.Nombre: %s \n2.Apellido: %s \n3.Salario: %.2f \n4.Sector: %d \n5.Cancelar\n",list[empleadoAEditar].name,list[empleadoAEditar].lastName,list[empleadoAEditar].salary,list[empleadoAEditar].sector);
        opcion = getInt("Ingrese la opcion : ",1,5);
        switch(opcion)
        {
        case 1:
            printf ("Ingrese el nombre(maximo 50 caracteres): ");
            fflush(stdin);
            gets(list[empleadoAEditar].name);
            while(esSoloLetras(list[empleadoAEditar].name, sizeof(list[empleadoAEditar].name))!=1)
            {
                if(esSoloLetras(list[empleadoAEditar].name, sizeof(list[empleadoAEditar].name))==-1)
                {
                    printf("Error, caracteres invalidos\n");
                }
                if(esSoloLetras(list[empleadoAEditar].name, sizeof(list[empleadoAEditar].name))==-2)
                {
                    printf("Error, ingrese como maximo 50 caracteres\n");
                }
                printf ("Ingrese el nombre :");
                fflush(stdin);
                gets(list[empleadoAEditar].name);
            }
            break;
        case 2:
            printf ("Ingrese el apellido(maximo 50 caracteres): ");
            fflush(stdin);
            gets(list[empleadoAEditar].lastName);
            while(esSoloLetras(list[empleadoAEditar].lastName, sizeof(list[empleadoAEditar].lastName))!=1)
            {
                if(esSoloLetras(list[empleadoAEditar].lastName, sizeof(list[empleadoAEditar].lastName))==-1)
                {
                    printf("Error, caracteres invalidos\n");
                }
                if(esSoloLetras(list[empleadoAEditar].lastName, sizeof(list[empleadoAEditar].lastName))==-2)
                {
                    printf("Error, ingrese como maximo 50 caracteres\n");
                }
                printf ("Ingrese el apellido :");
                fflush(stdin);
                gets(list[empleadoAEditar].lastName);
            }
            break;
        case 3:
            list[empleadoAEditar].salary = getFloat("Ingrese el salario : ");
            while(list[empleadoAEditar].salary <= 0)
            {
                printf("Ingrese un salario mayor a 0\n");
                list[empleadoAEditar].salary = getFloat("Ingrese el salario : ");
            }
            break;
        case 4:
            list[empleadoAEditar].sector = getInt("Ingrese el sector : ",0,0);
            while(list[empleadoAEditar].sector < 0)
            {
                printf("El sector no puede ser un numero negativo\n");
                list[empleadoAEditar].sector = getInt("Ingrese el sector : ",0,0);
                break;
            case 5:
                printf("Operacion cancelada\n");
                return -1;
                break;
            }
        }
    }
    else
    {
        printf("No se encontro a ese empleado\n");
        return -1;
    }


    return 0;
}
