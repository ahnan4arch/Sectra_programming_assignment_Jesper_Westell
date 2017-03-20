/*
 *
 * An abstract base class for the images used in the project.
 * Declares size functions implemented by derived classes.
 *
 */

#ifndef ISE_PICTURE_H
#define ISE_PICTURE_H

#include "../type.h"

class Image{
public:
    // Basic constructor, assign the values of width and height.
    Image(int width,int height);
    // Calculates the size of the image using the unique size functions of the derived classes.
    int calculateSize();

protected:
    int width;
    int height;
    // Pure virtual function, returns the size of a base level image given by width and height.
    virtual int imageSize(int width, int height) = 0;
    //Pure virtual function, returns the total size of the image.
    virtual int calculateTotalSize() = 0;
};

#endif //ISE_PICTURE_H
