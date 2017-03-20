/*
 *
 * Derived from PyramidImage, this class contains the functions to be able to
 * calculate the size of a BMP image.
 *
 */

#ifndef ISE_BMP_H
#define ISE_BMP_H

#include "pyramid_image.h"

class BMP: public PyramidImage{
public:
    BMP(int width,int height);
private:
    // Returns the size of a base level BMP image given by width and height.
    int imageSize(int width, int height);
};

#endif //ISE_BMP_H
