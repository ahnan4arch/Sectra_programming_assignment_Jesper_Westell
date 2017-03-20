/*
 *
 * The main file for the Image Storage Estimator.
 * Handles basic input and output, verifies user commands,
 * and keeps track on the images given by the user.
 *
 * Because stacks of images are stored differently from images,
 * there is no risk of storing the size of a stack in another stack.
 *
 * Created by Jesper Westell, 18th March 2017.
 *
 */


#include <iostream>
#include <vector>
#include <sstream>
#include <set>

#include "type.h"
#include "Image_classes/image.h"
#include "Image_classes/bmp.h"
#include "Image_classes/jpg.h"
#include "Image_classes/jp2.h"

using namespace std;

// Returns the Type corresponding to the input string.
// If the string doesn't match a Type, an exception will be cast.
Type hashType(string s);

// Divides input from the user into a Type and argument integers.
// Verifies that the arguments are numbers, and that the amount of integers is valid.
// If the given numbers are not integers, they will be truncated to integers.
// Returns a pair, containing the Type and a vector of arguments.
pair<Type, vector<int>> divideInput(string input);

// Calculates the total size of an image.
// Creates an Image object using the three parameters Type, width, and height,
// in order to calculate the correct size.
int calculateImageSize(Type type, int width, int height);

// Returns the size of a stack of images given by the indices.
// Verifies that the indices are valid before calculating the size of the stack.
// Removes the size of the relevant images from size_vec,
// making sure the images only can be moved into one stack.
int calculateStackSize(vector<int> indices, vector<int> &size_vec);

// Iterates through a vector<int>, calculating the combined size of the elements.
int totalVectorSize(vector<int> vec);

int main() {
    string input;
    pair<Type, vector<int>> divided_input;
    Type type;
    vector<int> arguments;
    vector<int> image_size_list;
    vector<int> stack_size_list;

    cout << "Storage calculator by Jesper Westell.\nEnter one line for each image/group on the format \"type width"
            " height\", or \"G i, i, ...\".\nExit with \"q\"." << endl << endl;

    while(getline(cin,input), input != "q"){
        try {
            divided_input = divideInput(input);
            type = divided_input.first;
            arguments = divided_input.second;

            if(type != G) image_size_list.push_back(calculateImageSize(type, arguments[0], arguments[1]));
            else stack_size_list.push_back(calculateStackSize(arguments, image_size_list));

        }catch(invalid_argument& ia){
            cout << "Invalid input: " << ia.what()  << endl << "Try again!" << endl;
        }
    }
    int total_size = totalVectorSize(image_size_list) + totalVectorSize(stack_size_list);
    cout << endl << "Total size: " << total_size << " bytes" << endl;

    return 0;
}


Type hashType(string s){
    if(s == "J" || s == "JPG") return JPG;
    if(s == "JPEG2000" || s == "JP2") return JP2;
    if(s == "BMP") return BMP;
    if(s == "G") return G;
    else throw invalid_argument("not a matching picture type!");
}

pair<Type, vector<int>> divideInput(string input){
    Type picture_type;
    vector<int> args;
    stringstream ss(input);

    // Splits input by spaces into a vector<string>
    vector<string> tokens{istream_iterator<string>{ss}, istream_iterator<string>{}};

    if(tokens.size() >= 3){ //Assumes that at least two images are needed for a stack
        picture_type = hashType(tokens[0]);
        if(picture_type != G && tokens.size() > 3) throw invalid_argument("too many arguments!");
        for (vector<string>::const_iterator i = tokens.begin() + 1; i != tokens.end(); ++i) {
            try {
                args.push_back(stoi(*i));
            } catch (invalid_argument) {
                throw invalid_argument("arguments given are not integers!");
            } catch (out_of_range){
                throw invalid_argument("arguments are too large!");
            }
        }
    } else throw invalid_argument("not enough arguments!");
    return pair<Type, vector<int>> (picture_type, args);
}

int calculateImageSize(Type type, int width, int height){
    if(width <= 0 || height <= 0) throw invalid_argument("width and height has to be positive numbers!");
    Image* image;
    switch(type){
        case BMP:
            image = new class BMP(width, height);
            break;
        case JPG:
            image = new class JPG(width, height);
            break;
        case JP2:
            image = new class JP2(width, height);
            break;
        default:
            throw invalid_argument("not a valid type!");
    }
    int result = image->calculateSize();
    if (result < 0) throw invalid_argument("the resulting image size is too large for this program to handle!");
    else return image->calculateSize();
}

int calculateStackSize(vector<int> indices, vector<int> &size_vec){
    int stack_size = 0;

    // It's important to verify the indices before adding
    // to stack_size, because the other loop will modify size_vec.
    set<int> set;
    for (vector<int>::iterator i = indices.begin(); i != indices.end(); ++i) {
        if(*i > size_vec.size()) throw invalid_argument("indices does not match an image!");
        if(size_vec[*i-1] == 0)  throw invalid_argument("images have already been grouped in a stack!");
        //Checking for duplicates, if the set already contains the index, insert() will return false
        if(set.insert(*i).second == false) throw invalid_argument("can't stack the same image twice!");

    }

    for (vector<int>::iterator i = indices.begin(); i != indices.end(); ++i) {
        stack_size += size_vec[*i-1];
        size_vec[*i-1] = 0;
    }

    return int(stack_size/log(indices.size() + 3));
}

int totalVectorSize(vector<int> vec){
    int result = 0;
    for (vector<int>::const_iterator i = vec.begin(); i != vec.end(); ++i){
        result += *i;
    }
    return result;
}
