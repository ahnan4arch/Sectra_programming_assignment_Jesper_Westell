/*
 *
 * Contains the implementation of PyramidImage.
 *
 */

#include "pyramid_image.h"

PyramidImage::PyramidImage(int width, int height): Image(width, height) {}

int PyramidImage::calculateTotalSize(){
    int width = this->width;
    int height = this->height;
    int size = this->imageSize(width, height);
    while(true){
        width = width/2;
        height = height/2;
        if(width < 128 || height < 128) break;
        else size += this->imageSize(width, height);
    }
    return size;
}