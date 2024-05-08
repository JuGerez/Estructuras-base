#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "alumno.h"

#define DIM 100

int cargaAlumnos (stAlumno a[], int v, int dim);
void muestraAlumnos (stAlumno a[], int v);
stAlumno buscaMenorLegajo (stAlumno a[], int v);
stAlumno buscaMenorApellido (stAlumno a[], int v);
stAlumno buscaPorLegajo (stAlumno a[], int v, int legajo);
int ingresarLegajo();
void ordenarPorSeleccion (stAlumno a[], int v, int dim);

int main()
{
    stAlumno alumnos [DIM];
    int vAlumnos = 0;
    stAlumno alumnoMenorApellido;
    stAlumno alumnoMenorLegajo;
    stAlumno alumnoABuscar;

    vAlumnos = cargaAlumnos (alumnos, vAlumnos, DIM);

    printf("\n Datos: \n");
    muestraAlumnos(alumnos, vAlumnos);

    alumnoMenorApellido = buscaMenorApellido(alumnos, vAlumnos);
    if (alumnoMenorApellido.legajo > -1){
            printf("\nEl alumno con menor apellido: \n");
            muestraUnAlumno(alumnoMenorApellido);
    }

    alumnoMenorLegajo = buscaMenorLegajo(alumnos, vAlumnos);
    if ( alumnoMenorLegajo.legajo > -1){
            printf("\nEl alumno con menor legajo: \n");
            muestraUnAlumno(alumnoMenorLegajo);
    }

    getch();
    system("cls");
    int legajo = ingresarLegajo();

    alumnoABuscar = buscaPorLegajo(alumnos, vAlumnos, legajo);
    if (alumnoABuscar.legajo > -1){
            printf("\nEl alumno que corresponde al legajo %d es: \n", legajo);
            muestraUnAlumno(alumnoABuscar);
    }

    getch();
    system("cls");

    stAlumno alumnosOrdenados [DIM];
    int vAlumnosOrdenados = 0;

    ordenarPorSeleccion(alumnosOrdenados, vAlumnosOrdenados, DIM);
    printf("\n Datos ordenados por legajo: \n");
    muestraAlumnos(alumnosOrdenados, vAlumnosOrdenados);


    return 0;
}

int cargaAlumnos (stAlumno a[], int v, int dim)
{
    char opcion = 0;

    while(opcion != 27 && v < dim){
        a[v] = cargaUnAlumno();
        v++;
        printf("\nESC para salir o cualquier tecla para continuar... \n");
        opcion = getch();
        system("cls");
    }

    return v;
}
void muestraAlumnos (stAlumno a[], int v)
{
    for(int i = 0; i < v; i++){
        muestraUnAlumno(a[i]);
    }
}
stAlumno buscaMenorLegajo (stAlumno a[], int v)
{
    stAlumno alumnoMenor;
    alumnoMenor.legajo = -1;
    int i = 0;
    if(v > 0){
        alumnoMenor = a[i];
        i++;
        while (i < v){
                if(a[i].legajo < alumnoMenor.legajo){
                    alumnoMenor = a[i];
                }
                i++;
        }
    }

    return alumnoMenor;
}
stAlumno buscaMenorApellido (stAlumno a[], int v)
{
    stAlumno alumnoMenor;
    alumnoMenor.legajo = -1;

    int i = 0;
    if(v > 0){
        alumnoMenor = a[i];
        i++;
        while (i < v){
                if(strcmp (a[i].apellido, alumnoMenor.apellido) < 0){
                    alumnoMenor = a[i];
                }
                i++;
        }
    }

    return alumnoMenor;
}
stAlumno buscaPorLegajo (stAlumno a[], int v, int legajo)
{
    stAlumno alumnoABuscar;
    alumnoABuscar.legajo = -1;
    int i = 0;

    while (i < v){
            if(a[i].legajo = legajo){
            alumnoABuscar = a[i];
            }
            i++;
        }

    return alumnoABuscar;
}
int ingresarLegajo ()
{
    int legajo = 0;
    printf("Ingrese el numero de legajo a buscar: \n");
    scanf("%d", &legajo);
    system("cls");

    return legajo;
}
//4.Hacer una función que ordene el arreglo de alumnos por medio del método de selección.
//El criterio de ordenación es el número de matrícula.
void ordenarPorSeleccion (stAlumno a[], int v, int dim)
{
    while(v < dim){
        a[v] = buscaMenorLegajo(a, v);
        v++;
    }
}

