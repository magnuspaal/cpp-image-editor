#include <iostream>
using namespace std;
#include <sstream>

#define cimg_use_cpp11 0
#define cimg_display 0

#include "../include/CImg.h"
using namespace cimg_library;

#include "../include/image.h"
#include "../include/functions.h"

int main(int argc, char *argv[])
{

    if (argc < 3) {
        if (strcmp(argv[1],"-h") == 0) {
            help();
            return 0;
        } else {
            throw invalid_argument("A filename and function must be given. ./main -h.");
        }
    } 

    char* filename = argv[1];
    CImg<unsigned char> image(filename);
    Image img(&image);

    char ** itr = argv + 2;
    string function;

    while (itr != argv + argc) {
        function = *itr;
        if (function == "-i") {
            itr++;
            img.invert();
            continue;
        }
        if (function == "-e") {
            itr++;
            float factor = atof(*itr);
            itr++;
            img.exposure(factor);
            continue;
        }
        if (function == "-f") {
            itr++;
            char* axis = *itr;
            itr++;
            img.flip(axis);
            continue;
        }
        if (function == "-o") {
            itr++;
            char* dir = *itr;
            itr++;
            img.rotate(dir);
            continue;
        }
        if (function == "-x") {
            itr++;
            int width = atoi(*itr);
            itr++;
            int height = atoi(*itr);
            itr++;
            img.rescale(width, height);
            continue;
        }
        throw invalid_argument("No argument " + function);
    }
    img.save(filename);
    return 0;
}
