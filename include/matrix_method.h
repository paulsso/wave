#ifndef SALT_MATRIX_METHOD_H
#define SALT_MATRIX_METHOD_H

#include "salt_types.h"

/**
 * Main simulation function that computes acoustic radiation pressure
 * @param medium Medium properties
 * @param z_pos Positive component properties
 * @param z_neg Negative component properties
 * @param x_span Output x coordinates
 * @param z_span Output z coordinates
 * @param pressure Output pressure matrix
 * @param potential Output potential matrix
 * @return 0 on success, error code otherwise
 */
int matrix_method(
    const MediumProperties* medium,
    const ComponentProperties* z_pos,
    const ComponentProperties* z_neg,
    double** x_span,
    double** z_span,
    double complex** pressure,
    double** potential
);

#endif // SALT_MATRIX_METHOD_H 