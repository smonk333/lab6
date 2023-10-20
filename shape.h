/* shape.h */

#ifndef SHAPE_H
#define SHAPE_H

#include <stdio.h>
#include "ppm.h"

typedef struct {
    int x;
    int y;
} point_t;

typedef struct {
    point_t center;
    int radius;
    pixel_t color;
} circle_t;

void readInfo(FILE* in, header_t* hdr, circle_t* cir);

int isHitCir(circle_t c, point_t p);

void makeCircle(FILE* out, circle_t* cir, int w, int h);

#endif
