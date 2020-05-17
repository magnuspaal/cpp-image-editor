#include "../include/image.h"

#include <math.h>

Image::Image(CImg<unsigned char> *image) {
    img = image;
}

Image::~Image() {}

void Image::invert() {
    for (int row = 0; row < img->height(); row++) {
        for (int cell = 0; cell < img->width(); cell++) {
            unsigned char red = 255 - *(img->data(cell,row,0,0));
            unsigned char green = 255 - *(img->data(cell,row,0,1));
            unsigned char blue = 255 - *(img->data(cell,row,0,2));
            unsigned char color[] = {red, green, blue};
            img->draw_point(cell, row, color);
        }
    }
}

void Image::flip(string axis) {
    if(axis == "v") {
        for (int row = 0; row < img->height(); row++) {
            for (int cell = 0; cell < img->width(); cell++) {
                if (cell <= img->width() - cell) {

                    unsigned char px1[] = {
                            *(img->data(cell, row, 0, 0)),
                            *(img->data(cell, row, 0, 1)),
                            *(img->data(cell, row, 0, 2))};

                    unsigned char px2[] = {
                            *(img->data(img->width() - cell, row, 0, 0)),
                            *(img->data(img->width() - cell, row, 0, 1)),
                            *(img->data(img->width() - cell, row, 0, 2))};

                    img->draw_point(img->width() - cell, row, px1);
                    img->draw_point(cell, row, px2);
                } else {
                    break;
                }
            }
        }
    } else if (axis == "h") {
        for (int cell = 0; cell < img->width(); cell++) {
            for (int row = 0; row < img->height(); row++) {
                if (row <= img->height() - row) {

                    unsigned char px1[] = {
                            *(img->data(cell, row, 0, 0)),
                            *(img->data(cell, row, 0, 1)),
                            *(img->data(cell, row, 0, 2))};

                    unsigned char px2[] = {
                            *(img->data(cell, img->height() - row, 0, 0)),
                            *(img->data(cell, img->height() - row, 0, 1)),
                            *(img->data(cell, img->height() - row, 0, 2))};

                    img->draw_point(cell, img->height() - row, px1);
                    img->draw_point(cell, row, px2);
                } else {
                    break;
                }
            }
        }
    } else {
        throw invalid_argument("There is no argument " + axis + " for flip. Try 'v' (vertical) or 'h' (horizontal).");
    }
}

void Image::rotate(string dir) {
    CImg<unsigned char> newImg(img->height(), img->width(), 1, 3, 0);

    for (int row = 0; row < img->height(); row++) {
        for (int cell = 0; cell < img->width(); cell++) {

            int a = 0;
            int b = 0;

            if (dir == "r") {
                a = img->height() - row;
                b = cell;
            } else if (dir == "l") {
                a = row;
                b = img->width() - cell;
            }

            unsigned char px[] = {
                    *(img->data(cell, row, 0, 0)),
                    *(img->data(cell, row, 0, 1)),
                    *(img->data(cell, row, 0, 2))};

            newImg.draw_point(a, b, px);
        }
    }
    img = &newImg;
}

void Image::rescale(int newWidth,int newHeight) {

    CImg<unsigned char> newImg(newWidth, newHeight, 1, 3, 0);

    float x_ratio = img->width()/newWidth;
    float y_ratio = img->height()/newHeight;

    float px, py;
    for (int row=0;row < newHeight;row++) {
        for (int cell=0;cell < newWidth;cell++) {
            px = floor(cell * x_ratio);
            py = floor(row * y_ratio);

            unsigned char color[] = {
                    *(img->data(px, py, 0, 0)),
                    *(img->data(px, py, 0, 1)),
                    *(img->data(px, py, 0, 2))};
            newImg.draw_point(cell,row,color);
        }
    }
    img = &newImg;
}

void Image::exposure(float factor) {
    for (int row=0;row < img->height();row++) {
        for (int cell=0;cell < img->width();cell++) {

            int red = (int)*(img->data(cell, row, 0, 0)) * factor;
            int green = (int)*(img->data(cell, row, 0, 1)) * factor;
            int blue = (int)*(img->data(cell, row, 0, 2)) * factor;

            if (red > 255) {
                red = 255;
            }
            if (green > 255) {
                green = 255;
            }
            if (blue > 255) {
                blue = 255;
            }

            unsigned char r = (unsigned char)red;
            unsigned char g = (unsigned char)green;
            unsigned char b = (unsigned char)blue;

            unsigned char color[] = {r,g,b};

            img->draw_point(cell,row,color);
        }
    }
}

void Image::save(char* filename) {
    img->save(filename);
}
