/*
 *
 * Contains the implementation of Image.
 *
 */

#include "image.h"

Image::Image(int width,int height){
    this->height = height;
    this->width = width;
}

int Image::calculateSize() {
    return this->calculateTotalSize();
}




