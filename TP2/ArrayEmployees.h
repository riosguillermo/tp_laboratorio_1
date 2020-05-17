#ifndef ARRAYEMPLOYEES_H_INCLUDED
#define ARRAYEMPLOYEES_H_INCLUDED

typedef struct
{
    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;
}Employee;

int getInt(char mensaje[],int minimo, int maximo);
int initEmployees(Employee list[], int len);
int buscarLibre(Employee list[], int len);
int cargarUnEmpleado(Employee list[],int len);
int AsignarNuevoID(Employee list[],int len);
int addEmployee(Employee list[], int len, int id, char name[],char lastName[],float salary,int sector);
int findEmployeeById(Employee list[], int len,int id);
int removeEmployee(Employee list[], int len, int id);
int sortEmployees(Employee list[], int len, int order);
int esSoloLetras(char cadena[], int maximo);
float getFloat(char mensaje[]);
int printEmployees(Employee list[], int length);
int editEmployees(Employee list[], int len);
#endif // ARRAYEMPLOYEES_H_INCLUDED
