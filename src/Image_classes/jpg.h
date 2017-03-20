/*
 *
 * Derived from PyramidImage, this class contains the functions to be able to
 * calculate the size of a JPG image.
 *
 */

#ifndef ISE_JPG_H
#define ISE_JPG_H

#include "pyramid_image.h"

class JPG: public PyramidImage{
public:
    JPG(int width,int height);
private:
    // Returns the size of a base level JPG image given by width and height.
    int imageSize(int width, int height);
};

#endif //ISE_JPG_H
