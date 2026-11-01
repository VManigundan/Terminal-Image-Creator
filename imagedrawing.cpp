#include <string>
#include <iostream>
#include <vector>
#include <cstdint>

//image processing helper header
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"


//define each pixel rgb
struct Pixel{
    std::uint8_t r = 0;
    std::uint8_t g = 0;
    std::uint8_t b = 0;

};

int main() {
    //create the filename from input
    std::string filename;
    std::cout << "Enter a filename to create an image of: ";
    std::cin >> filename;

    int width, height, channels;

    //load image data using header
    unsigned char* imgData = stbi_load(filename.c_str(), &width, &height, &channels, 3);

    //See if file can be parsed
    if(imgData == nullptr){
        std::cerr << "Coud not load image file titled: " << filename << "\n";
        return 1;
    }

    std::cout << "Loaded image: " << width << "x" << height << " pixels.\n";

    //Then adjust image dimensions to fit terminal dimensions (using 60 as example) 
    //Will skip pixels, lower resolution 
    //int targetWidth = 60;
    
    //input validation
    int targetWidth;
    std::cout << "Enter a target width value (example - 40, 80, 120): ";

    if (!(std::cin >> targetWidth) || targetWidth <= 0) {
        std::cerr << "Invalid target width.\n";
        stbi_image_free(imgData);
        return 1;
    }

    int stepX = (width + targetWidth -1) / targetWidth;
    if(stepX <1){
        stepX = 1;
    }

    //Maintain an aspect ratio for height (square)
    int stepY = stepX;

    //Create the image matrix (2d vector)
    std::vector<std::vector<Pixel>> matrix;

    for(int y=0; y < height; y += stepY){
        std::vector<Pixel> row;
        for(int x = 0; x < width; x+=stepX){

            int index = (y * width + x) * 3;
            
            Pixel p;
            p.r = imgData[index];
            p.g = imgData[index + 1];
            p.b = imgData[index + 2];
            row.push_back(p);

        }
        matrix.push_back(row);
    }

    stbi_image_free(imgData);



    for(const auto& row : matrix){
        for(const auto& p : row){

            std::cout << "\033[48;2;" << (int)p.r << ";" << (int)p.g << ";" << (int)p.b << "m  ";
        }
        
       std::cout << "\033[0m\n"; // Reset row formatting
    }
    return 0;

}
