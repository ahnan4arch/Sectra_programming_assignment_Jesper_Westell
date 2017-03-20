/*
 *
 * Derived from Image, this class adds the possibility to account for
 * pyramid level images when calculating the size of an image.
 *
 */
#ifndef ISE_PYRAMID_CALCULATOR_H
#define ISE_PYRAMID_CALCULATOR_H

#include "image.h"

class PyramidImage: public Image{
public:
    PyramidImage(int width, int height);
protected:
    // Returns the total size of the image, accounting for pyramid level images.
    int calculateTotalSize();
};

#endif //ISE_PYRAMID_CALCULATOR_H
