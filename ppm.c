#include "ppm.h"

void writeHeader(FILE* out, header_t hdr)
{
    fprintf(out, "P6 %d %d %d\n", hdr.width, hdr.height, hdr.max_color);
}

void writePixel(FILE* out, pixel_t color)
{
    fputc(color.red, out);
    fputc(color.green, out);
    fputc(color.blue, out);
}
