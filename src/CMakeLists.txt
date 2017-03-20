cmake_minimum_required(VERSION 3.6)
project(ISE)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp
        type.h
        Image_classes/image.h
        Image_classes/image.cpp
        Image_classes/bmp.h
        Image_classes/bmp.cpp
        Image_classes/pyramid_image.h
        Image_classes/pyramid_image.cpp
        Image_classes/jpg.h
        Image_classes/jpg.cpp
        Image_classes/jp2.h
        Image_classes/jp2.cpp)

add_executable(ISE ${SOURCE_FILES})