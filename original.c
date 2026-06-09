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
void calcular_por_estudiante(int est, Estudiante *alumnos) {
    for (int i = 0; i < est; i++) {
        float suma = 0.0f;
        alumnos[i].max = alumnos[i].calificaciones[0];
        alumnos[i].min = alumnos[i].calificaciones[0];
        for (int j = 0; j < ASIGNATURAS; j++) {
            float v = alumnos[i].calificaciones[j];
            suma += v;
            if (v > alumnos[i].max) alumnos[i].max = v;
            if (v < alumnos[i].min) alumnos[i].min = v;
        }
        alumnos[i].promedio = suma / ASIGNATURAS;
    }
}


