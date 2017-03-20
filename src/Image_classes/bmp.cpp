/*
 *
 * Contains the implementation of BMP.
 *
 */

#include "bmp.h"

BMP::BMP(int width,int height):PyramidImage(width,height){}

int BMP::imageSize(int width, int height) {
    return width*height;
}

