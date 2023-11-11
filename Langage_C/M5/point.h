/**
 * @file point.h
 *
 * @brief Definition and functions for 2D points with cartesian coordinates
 *
 * @author Christophe Garion
 *
 * This is a simple definition of 2D cartesian points. The fields of
 * the `point` structure are classically named `x` and `y`.
 *
 * The API of point is defined as follows:
 *
 * - a function to print a point
 * - a function to translate a point
 */

#ifndef POINT_H
#define POINT_H

/**
 * @brief The structure representing the point
 */
struct point {
    /** the abscissa of the point */
    double x;
    /** the ordinate of the point */
    double y;
};

/**
 * @brief Print a point.
 *
 * @param p the point to be printed
 *
 * @post after the call, the point is printed in the form `(x, y)`
 *       and a newline is added
 */
void print_point(struct point p);

/**
 * @brief Translate a point.
 *
 * @param p   the point to be translated
 * @param vec a point representing the translation vector
 *
 * @return a point corresponding to the translation of `p` with
 *         translation vector `vec`
 */
struct point translate_point(struct point p,
                             struct point vec);

#endif
