#ifndef INTEGRACION_H
#define INTEGRACION_H

typedef double (*func_ptr)(double, double, double);

double integral_riemann(func_ptr f,
                        double xmin, double xmax,
                        double ymin, double ymax,
                        double zmin, double zmax,
                        int nx, int ny, int nz);

double integral_montecarlo(func_ptr f,
                           double xmin, double xmax,
                           double ymin, double ymax,
                           double zmin, double zmax,
                           int N);

#endif