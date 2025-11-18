#include <math.h>
#include "densidades.h"

// Variables globales
double A_g = 0;
double B_g = 0;
double C_g = 0;

// ρ = 1
double densidad_constante(double x, double y, double z) {
    return 1.0;
}

// ρ = exp(-(x² + y² + z²))
double densidad_gaussiana(double x, double y, double z) {
    return exp(-(x*x + y*y + z*z));
}

// ρ = A_g x + B_g y + C_g z
double densidad_lineal_wrapper(double x, double y, double z) {
    return A_g*x + B_g*y + C_g*z;
}