#include <stdio.h>
#include <stdlib.h>
#include "ArrayEmployees.h"
#define CANTIDAD_EMPLEADOS 1000

int main()
{
    Employee empleados[CANTIDAD_EMPLEADOS];
    int opcion;
    int id;
    int r;
    r = initEmployees(empleados,CANTIDAD_EMPLEADOS);
    if(r != -1)
    {

        do
        {
            printf("\tMenu de Opciones: \n1.Alta \n2.Baja \n3.Modificacion \n4.Informar \n5.Salir\n");
            opcion = getInt("Ingrese la opcion : ",1,5);
            switch(opcion)
            {
            case 1:
                r = cargarUnEmpleado(empleados, CANTIDAD_EMPLEADOS);
                if(r == 0)
                {
                    printf("Se ingreso el empleado:\n");
                }
                else
                {
                    printf("Error al cargar nuevo empleado.\n");
                }
                break;
            case 2:
                id = getInt("Ingrese el id del empleado a eliminar: ",0,0);
                r = removeEmployee(empleados,CANTIDAD_EMPLEADOS,id);
                if(r == 0)
                {
                    printf("Se elimino al empleado\n");
                }
                else
                    {
                        printf("No se encontro al empleado\n");
                    }
                break;
            case 3:

                if(editEmployees(empleados,CANTIDAD_EMPLEADOS) == 0)
                {
                    printf("Modificacion exitosa\n");
                }
                else
                {
                    printf("Error al modificar\n");
                }
                break;
            case 4:
                sortEmployees(empleados,CANTIDAD_EMPLEADOS,1);
                printEmployees(empleados,CANTIDAD_EMPLEADOS);
                break;
            case 5:
                printf("SALIR\n");
                break;

            }
        }
        while(opcion!=5);
        return 0;

    }
    else
    {
        printf("Error al iniciar la lista de empleados");
    }
}
