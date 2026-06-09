#include <stdio.h>
#define ASIGNATURAS 3
 
typedef struct {
    float calificaciones[ASIGNATURAS];
    float promedio;
    float max;
    float min;
} Estudiante;
 
typedef struct {
    float promedio;
    float max;
    float min;
    int estMax;
    int estMin;
    int aprobados;
    int reprobados;
} Asignatura;
 
int leer_estudiantes(int defecto);
void limpiar_buffer(void);
int leer_calificaciones(int est, Estudiante *alumnos);