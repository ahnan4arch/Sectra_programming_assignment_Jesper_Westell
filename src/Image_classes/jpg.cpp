/*
 *
 * Contains the implementation of JPG.
 *
 */

#include "jpg.h"

JPG::JPG(int width,int height):PyramidImage(width,height){}

int JPG::imageSize(int width, int height) {
    return int(width*height*0.2);
}