/*
 *
 * Contains the implementation of JP2.
 *
 */

#include "jp2.h"

JP2::JP2(int width,int height):Image(width,height){}

int JP2::imageSize(int width, int height) {
    return int((width*height*0.4)/(log(log(width*height + 16))));
}

int JP2::calculateTotalSize(){
    return this->imageSize(this->width, this->height);
}