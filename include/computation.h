#ifndef SALT_COMPUTATION_H
#define SALT_COMPUTATION_H

#include "salt_types.h"

/**
 * Computes pressure matrix using the matrix method
 * @param medium Medium properties
 * @param z_pos Positive component properties
 * @param z_neg Negative component properties
 * @param nT Number of transducers
 * @param nR Number of reflectors
 * @param nM Number of medium points
 * @return Complex pressure matrix
 */
double complex* compute_pressure(
    const MediumProperties* medium,
    const ComponentProperties* z_pos,
    const ComponentProperties* z_neg,
    size_t nT,
    size_t nR,
    size_t nM
);

/**
 * Computes relative acoustic potential
 * @param p_total Total pressure matrix
 * @param medium Medium properties
 * @param z_pos Positive component properties
 * @return Relative potential matrix
 */
double* compute_relative_potential(
    const double complex* p_total,
    const MediumProperties* medium,
    const ComponentProperties* z_pos,
    size_t rows,
    size_t cols
);

#endif // SALT_COMPUTATION_H 