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

void calcular_por_asignatura(int est, Estudiante *alumnos, Asignatura *materias) {
    for (int j = 0; j < ASIGNATURAS; j++) {
        float suma = 0.0f;
        materias[j].max = alumnos[0].calificaciones[j];
        materias[j].min = alumnos[0].calificaciones[j];
        materias[j].estMax = 1;
        materias[j].estMin = 1;
        materias[j].aprobados = materias[j].reprobados = 0;
        for (int i = 0; i < est; i++) {
            float v = alumnos[i].calificaciones[j];
            suma += v;
            if (v > materias[j].max) { materias[j].max = v; materias[j].estMax = i+1; }
            if (v < materias[j].min) { materias[j].min = v; materias[j].estMin = i+1; }
            if (v >= 6.0f) materias[j].aprobados++; else materias[j].reprobados++;
        }
        materias[j].promedio = suma / est;
    }
}

