#ifndef CPPIMAGEEDITOR_FUNCTIONS_H
#define CPPIMAGEEDITOR_FUNCTIONS_H

#include <iostream>
using namespace std;

#define cimg_use_cpp11 0
#define cimg_display 0

#include "CImg.h"
using namespace cimg_library;

class Image {
    public:

        CImg<unsigned char> *img;

        Image(CImg<unsigned char> *image);

        ~Image();

        void invert();

        void flip(string axis);

        void exposure(float factor);

        void rotate(string dir);

        void rescale(int newWidth, int newHeight);

        void save(char* filename);
};

#endif //CPPIMAGEEDITOR_FUNCTIONS_H
