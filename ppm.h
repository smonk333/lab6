#ifndef PPM_H
#define PPM_H

#include <stdio.h>

typedef struct {
    int width;
    int height;
    int max_color;
} header_t;

typedef struct {
    unsigned char red;
    unsigned char green;
    unsigned char blue;
} pixel_t;

void writeHeader(FILE* out, header_t hdr);

void writePixel(FILE* out, pixel_t color);

#endif
