#include "shape.h"
#include "ppm.h"
#include <math.h>
#include <stdio.h>

int isHitCir(circle_t c, point_t p)
{
    // Calculate the distance from the point to the center of the circle
    double distance = sqrt(pow(p.x - c.center.x, 2) + pow(p.y - c.center.y, 2));

    return distance <= c.radius;
}

void readInfo(FILE* in, header_t* hdr, circle_t* cir)
{
    // Read the header information
    fscanf(in, "%*s %d %d %d", &hdr->width, &hdr->height, &hdr->max_color);

    // Read circle information (center x, center y, radius)
    fscanf(in, "%d %d %d", &cir->center.x, &cir->center.y, &cir->radius);

    // Read circle color (R, G, B)
    fscanf(in, "%d %d %d", &cir->color.red, &cir->color.green, &cir->color.blue);
}

void makeCircle(FILE* out, circle_t* cir, int w, int h)
{
    // Define a default background color (e.g., white)
    pixel_t bg_color = {255, 255, 255};

    for (int y = 0; y < h; y++) {
        for (int x = 0; x < w; x++) {
            point_t p = {x, y};
            // Check if the point is within the circle
            if (isHitCir(*cir, p)) {
                // If it's inside the circle, use the circle's color
                writePixel(out, cir->color);
            } else {
                // Otherwise, use the background color
                writePixel(out, bg_color);
            }
        }
    }
}
