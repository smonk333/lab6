/*************************
 * Garrett Boling
 * CPSC 2310
 * gboling@g.clemson.edu
 *************************/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "shape.h"
#include "ppm.h"

int main(int argc, char* argv[])
{
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <input_file> <output_file>\n", argv[0]);
        return 1;
    }

    FILE* input = fopen(argv[1], "r");
    FILE* output = fopen(argv[2], "wb");

    assert(input != NULL && output != NULL);

    header_t hdr;
    circle_t cir;

    // Read information from the input file
    readInfo(input, &hdr, &cir);

    // Write the header to the output file
    writeHeader(output, hdr);

    // Call makeCircle to create the circle in the output image
    makeCircle(output, &cir, hdr.width, hdr.height);

    fclose(input);
    fclose(output);

    return 0;
}
