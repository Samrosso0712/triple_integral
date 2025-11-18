#include <stdlib.h>
#include <math.h>
#include "integracion.h"

// ----------------------
// Riemann
// ----------------------
double integral_riemann(func_ptr f,
                        double xmin, double xmax,
                        double ymin, double ymax,
                        double zmin, double zmax,
                        int nx, int ny, int nz) {

    double dx = (xmax - xmin) / nx;
    double dy = (ymax - ymin) / ny;
    double dz = (zmax - zmin) / nz;

    double suma = 0;

    for (int i = 0; i < nx; i++)
        for (int j = 0; j < ny; j++)
            for (int k = 0; k < nz; k++) {

                double x = xmin + (i + 0.5)*dx;
                double y = ymin + (j + 0.5)*dy;
                double z = zmin + (k + 0.5)*dz;

                suma += f(x, y, z);
            }

    return suma * dx * dy * dz;
}

// ----------------------
// MONTECARLO
// ----------------------
double integral_montecarlo(func_ptr f,
                           double xmin, double xmax,
                           double ymin, double ymax,
                           double zmin, double zmax,
                           int N) {

    double V = (xmax - xmin)*(ymax - ymin)*(zmax - zmin);
    double suma = 0;

    for (int i = 0; i < N; i++) {

        double x = xmin + (double)rand()/RAND_MAX * (xmax-xmin);
        double y = ymin + (double)rand()/RAND_MAX * (ymax-ymin);
        double z = zmin + (double)rand()/RAND_MAX * (zmax-zmin);

        suma += f(x,y,z);
    }

    return V * (suma / N);
}

   