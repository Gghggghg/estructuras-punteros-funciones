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
void limpiar_buffer(void) {
    int c;
    while ((c = getchar()) != EOF && c != '\n');
}

int leer_estudiantes(int defecto) {
    int estudiantes, r;
    do {
        printf("Numero por defecto de estudiantes: %d\n", defecto);
        printf("Ingrese nuevo numero de estudiantes (0 para usar %d): ", defecto);
        r = scanf("%d", &estudiantes);
        if (r != 1) {
            printf("Entrada invalida. Debe ser un numero.\n");
            limpiar_buffer();
            estudiantes = -1;
        } else {
            if (estudiantes == 0) estudiantes = defecto;
            if (estudiantes <= 0) {
                printf("Valor invalido. Intente otra vez.\n");
            }
        }
    } while (estudiantes <= 0);
    return estudiantes;
}

int leer_calificaciones(int est, Estudiante *alumnos) {
    for (int i = 0; i < est; i++) {
        for (int j = 0; j < ASIGNATURAS; j++) {
            float v;
            int r;
            do {
                printf("Ingrese la calificacion del estudiante %d en la asignatura %d (0-10): ", i+1, j+1);
                r = scanf("%f", &v);
                if (r != 1) {
                    printf("Entrada invalida. Debe ser un numero.\n");
                    limpiar_buffer();
                    v = -1.0f;
                } else if (v < 0.0f || v > 10.0f) {
                    printf("Valor fuera de rango. Intente otra vez.\n");
                }
            } while (v < 0.0f || v > 10.0f);
            alumnos[i].calificaciones[j] = v;
        }
    }
    return 0;
}

