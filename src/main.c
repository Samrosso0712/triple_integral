#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "densidades.h"
#include "integracion.h"

int main() {

    double xmin,xmax,ymin,ymax,zmin,zmax;
    int metodo, tipo;
    int nx,ny,nz, N;

    printf("=== CALCULO DE MASA Y CENTRO DE MASA ===\n");

    printf("xmin xmax: ");
    scanf("%lf %lf", &xmin, &xmax);

    printf("ymin ymax: ");
    scanf("%lf %lf", &ymin, &ymax);

    printf("zmin zmax: ");
    scanf("%lf %lf", &zmin, &zmax);

    printf("\nMetodo:\n1) Riemann\n2) MonteCarlo\n> ");
    scanf("%d", &metodo);

    printf("\nTipo de densidad:\n1) Constante\n2) Lineal\n3) Gaussiana\n> ");
    scanf("%d", &tipo);

    func_ptr rho;

    if (tipo == 1) {
        rho = densidad_constante;
    }
    else if (tipo == 2) {
        printf("Ingrese a b c: ");
        scanf("%lf %lf %lf", &A_g, &B_g, &C_g);

        rho = densidad_lineal_wrapper;
    }
    else {
        rho = densidad_gaussiana;
    }

    double M, xbar, ybar, zbar;

    clock_t start = clock();

    if (metodo == 1) {
        printf("nx ny nz: ");
        scanf("%d %d %d", &nx, &ny, &nz);

        M = integral_riemann(rho, xmin,xmax,ymin,ymax,zmin,zmax, nx,ny,nz);

        xbar = integral_riemann(
                densidad_constante,
                xmin,xmax,ymin,ymax,zmin,zmax,
                nx,ny,nz) / M;

        ybar = xbar; // cambiar después si deseas integrar x*rho, y*rho, z*rho
        zbar = xbar;

    } else {

        printf("N muestras: ");
        scanf("%d", &N);

        M = integral_montecarlo(rho, xmin,xmax,ymin,ymax,zmin,zmax, N);

        xbar = integral_montecarlo(
                densidad_constante,
                xmin,xmax,ymin,ymax,zmin,zmax,
                N) / M;

        ybar = xbar;
        zbar = xbar;
    }

    clock_t end = clock();
    double tiempo = (double)(end-start)/CLOCKS_PER_SEC;

    FILE *fp = fopen("resultados.csv","a");
    fprintf(fp,"%d,%d,%lf,%lf,%lf,%lf,%lf\n",
            metodo, tipo, M, xbar,ybar,zbar, tiempo);
    fclose(fp);

    printf("\nMasa total = %.6lf\n", M);
    printf("Centro de masa = (%.6lf, %.6lf, %.6lf)\n", xbar,ybar,zbar);
    printf("Tiempo = %.6lf s\n", tiempo);

    return 0;
}