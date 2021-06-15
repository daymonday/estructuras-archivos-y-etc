/*De una persona se conoce los siguientes datos:
• Número de Legajo (int, entre 1 y 10.000)
• Apellido (string, 15 caracteres)
• Nombre (string, 15 caracteres)
• Altura (float, mayor de 0)
• Sexo (char, F o M)
• Día de Nacimiento (int, entre 1 y 31
• Mes de Nacimiento (int, ente 1 y 12)
• Año de Nacimiento (int, ente 1950 y 2019)

Se solicita realizar los siguientes procesos:

a. Con datos ingresados por teclado: Crear una Estructura de Datos con los datos enunciados
anteriormente y llamarla PERSONA.

b. Mostrar los datos de la Estructura de Datos del punto a.

c. Con datos ingresados por teclado: Modificar la Estructura de Datos del punto a., crear una Estructura
de Datos que contenga Nombre y Apellido y otra Estructura de Datos que contenga Día/Mes/Año
utilizarla en una nueva Estructurad de Datos llamada PERSONA2.

d. Mostrar los datos de la Estructura de Datos del punto c.

e. Crear una FUNCION que cargue los datos de la Estructurad de Datos del punto c y que retorne los datos
al programa principal (main).

f. Con datos ingresados por teclado: Modificar la Estructurad de Datos llamada PERSONA2 del punto c.
y agregarle un campo/miembro que contenga los códigos de las Materias Aprobadas (pueden llegar a
ser hasta 36 materias) y llamarla PERSONA3.

g. Crear una FUNCION que realice el punto f.

h. Mostrar los datos de la Lista creada en el punto f.

i. Crear una FUNCION que realice el punto h.*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int legajo[10]; //entre 1 y 10.000
    char apellido[15];
char nombre [15];
    float altura; // dps se valida si es mayor a 0
  //  char sexo; dps se valida con srcmpi si es igual o no a F o M
    int dia [31];
    int mes [12];
    int anio [70];

} PERSONA1;

typedef struct
{
    int dia [31];
    int mes [12];
    int anio [70];
} FECHA;

typedef struct
{
    char apellido[15];
    char nombre[15];
    FECHA nacimiento;

} PERSONA2;

typedef struct
{
    PERSONA2 datos;
    int CodMaterias[36];
} PERSONA3;

float validar1(float lim_inf, char texto[50]);
int validar2(int lim_inf,int lim_sup, char texto[50]);
int cargadatos1(PERSONA1 a[], int n);
int cargadatos2(PERSONA2 a[], int n);
int cargadatos3(PERSONA3 a[], int n);
void mostrar1(PERSONA1 a[],int n);
void mostrar2(PERSONA2 a[],int n);
void mostrar3(PERSONA3 a[],int n);

int main()
{
    // VARIABLES Y CARGA DE DATOS
    PERSONA1 p1[5]; // PUNTO A
    cargadatos1(p1,5);
    PERSONA2 p2[5]; //PUNTO C
    cargadatos2(p2,5);
    PERSONA3 p3[5]; // PUNTO E
    cargadatos3(p3,5);

    //MOSTRAR DATOS
    mostrar1(p1,5);//b
    mostrar2(p2,5); //d
    mostrar3(p3,5);//f
    return 0;
}

int cargadatos1(PERSONA1 a[], int n)
{
    int x=0;
    do
    {
        printf("\n Ingrese apellido");
        fflush(stdin);
        gets(a[x].apellido);
    }
    while(strlen(a[x].apellido)<2);

    while(strlen(a[x].apellido)!=0)
{


    do
    {
        printf("\n Ingrese nombre");
            fflush(stdin);
            gets(a[x].nombre);
        }
        while(strlen(a[x].nombre)<2);

        a[x].legajo = validar2(1,10000,"Nro. Legajo");
        a[x].altura = validar1(1,"Altura");
        a[x].dia = validar2(1,31,"Dia de Nacimiento");
        a[x].mes = validar2(1,12,"Mes de Nacimiento");
        a[x].anio = validar2(1,70,"Anio de Nacimiento");
        x++;
    }

    return x;

};

int cargadatos2(PERSONA2 a[],int n)
{
    int x=0;
    do
    {
        printf("\n Ingrese apellido");
        fflush(stdin);
        gets(a[x].apellido);
    }
    while(strlen(a[x].apellido)<2);

    while(strlen(a[x].apellido)!=0)
{ do
    {
        printf("\n Ingrese nombre");
            fflush(stdin);
            gets(a[x].nombre);
        }
        while(strlen(a[x].nombre)<2);

        a[x].nacimiento.dia = validar2(1,31,"Dia de Nacimiento");
        a[x].nacimiento.mes = validar2(1,12,"Mes de Nacimiento");
        a[x].nacimiento.anio = validar2(1,70,"Anio de Nacimiento");
        x++;
    }
return x;
};

int cargadatos3(PERSONA3 a[],int n)
{ int x=0;
    do
    {
        printf("\n Ingrese apellido");
        fflush(stdin);
        gets(a[x].datos.apellido);
    }
    while(strlen(a[x].datos.apellido)<2);

    while(strlen(a[x].datos.apellido)!=0)
{
do
    {
        printf("\n Ingrese nombre");
            fflush(stdin);
            gets(a[x].datos.nombre);
        }
        while(strlen(a[x].datos.nombre)<2);

        a[x].datos.nacimiento.dia = validar2(1,31,"Dia de Nacimiento");
        a[x].datos.nacimiento.mes = validar2(1,12,"Mes de Nacimiento");
        a[x].datos.nacimiento.anio = validar2(1,70,"Anio de Nacimiento");
        x++;
    }
return x;
};

float validar1(float lim_inf, char texto[50])
{
    float dato;
    do
    {
        printf("\n Ingrese %s:",texto);
        scanf("\n %f",&dato);
    }
    while(dato<lim_inf);
    return dato;
}

int validar2(int lim_inf,int lim_sup, char texto[50])
{
    int dato;
    do
    {
        printf("\n Ingrese %s:",texto);
        scanf("\n %d", &dato);
    }
    while(dato<lim_inf||dato>lim_sup);
    return dato;
}


void mostrar1(PERSONA1 a[],int n) // y s no podria ser c? ¿¿
{
    int x;
    system("cls");
    printf("\n %d %-10s %-10s %8.2f %s %d/%d/%d", "NRO. LEGAJO","APELLIDO","NOMBRE","ALTURA","SEXO","FECHA DE NACIMIENTO", "\n ");
    for(x=0; x<n; x++)
        printf("\n  %d %-10s %-10s %8.2f %s %d/%d/%d ",a[x].legajo,a[x].apellido,a[x].nombre,
               a[x].altura,a[x].sexo,a[x].dia,a[x].mes,(a[x].anio+1949));
};

void mostrar2(PERSONA2 a[],int n)
{
    int x;
    system("cls");
    printf("\n  %-10s %-10s  %d/%d/%d","APELLIDO","NOMBRE","FECHA DE NACIMIENTO", "\n ");
    for(x=0; x<n; x++)
        printf("\n   %-10s %-10s  %d/%d/%d ",a[x].apellido,a[x].nombre,
               a[x].nacimiento.dia,a[x].nacimiento.mes,a[x].nacimiento.anio+1949);
};

void mostrar3(PERSONA3 a[],int n)
{
    int x;
    system("cls");
    printf("\n %-10s %-10s %d/%d/%d   %d","APELLIDO","NOMBRE","FECHA DE NACIMIENTO", "Materias Aprobadas" "\n ");
    for(x=0; x<n; x++)
        printf("\n  %-10s %-10s  %d/%d/%d   %d",a[x].datos.apellido,a[x].datos.nombre,
               a[x].datos.nacimiento.dia,a[x].datos.nacimiento.mes,a[x].datos.nacimiento.anio+1949,a[x].CodMaterias);
};
