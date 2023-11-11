#include <stdio.h>

#include "point.h"

void print_point(struct point p) {
    printf("(%f, %f)\n", p.x, p.y);
}

struct point translate_point(struct point p,
                             struct point vec) {
    struct point temp = { .x = p.x + vec.x, .y = p.y + vec.y };

    return temp;
}
