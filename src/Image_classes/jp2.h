/*
 *
 * Derived from Image, this class contains the functions to be able to
 * calculate the size of a JPEG2000 image.
 *
 */

#ifndef ISE_JP2_H
#define ISE_JP2_H

#include "image.h"
#include <math.h>

class JP2: public Image{
public:
    JP2(int width,int height);
private:
    // Returns the size of a base level JPEG2000 image given by width and height.
    int imageSize(int width, int height);
    // Returns the total size of the image. Because JPEG2000 images doesn't
    // have pyramid level images, his function merely calls on imageSize()
    int calculateTotalSize();
};


#endif //ISE_JP2_H
