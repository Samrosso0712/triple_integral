#ifndef DENSIDADES_H
#define DENSIDADES_H


extern double A_g;
extern double B_g;
extern double C_g;

double densidad_constante(double x, double y, double z);
double densidad_gaussiana(double x, double y, double z);
double densidad_lineal_wrapper(double x, double y, double z);

#endif