#ifndef SALT_GEOMETRIES_H
#define SALT_GEOMETRIES_H

#include "salt_types.h"

/**
 * Creates an array of transducers
 * @param props Component properties
 * @return Geometry structure containing array points
 */
Geometry create_array(const ComponentProperties* props);

/**
 * Creates a single transducer
 * @param props Component properties
 * @return Geometry structure containing transducer points
 */
Geometry create_transducer(const ComponentProperties* props);

/**
 * Creates a reflector
 * @param props Component properties
 * @return Geometry structure containing reflector points
 */
Geometry create_reflector(const ComponentProperties* props);

/**
 * Creates medium points between components
 * @param vx Top component x coordinates
 * @param vz Top component z coordinates
 * @param ux Bottom component x coordinates
 * @param uz Bottom component z coordinates
 * @param v_size Top component size
 * @param u_size Bottom component size
 * @return Medium structure containing points
 */
Medium create_medium(
    const double* vx,
    const double* vz,
    const double* ux,
    const double* uz,
    size_t v_size,
    size_t u_size
);

#endif // SALT_GEOMETRIES_H 