#ifndef point_h
#define point_h


struct point {
    double x;
    double y;
};

void print_point(struct point p);
struct point translate_point(struct point p,
                             struct point vec);

#endif