#include "Image.h"
#include <iostream>
#include <fstream>

// Other methods... 

/*
* The saveImage method makes the assumption that the 3 colours for each pixel are stored
* horizontally next to each other.
*/
bool Image::saveImage(std::string filename)
{
    try
    {
        // Open a file for writing.
        std::ofstream myfile;
        myfile.open (filename);
        
        // Write header info
        myfile << "P6\n" << this->pixelWidth << " "
               << this->pixelHeight << "\n255\n";
        
        // Write stored pixel values as rows.
        for (int y = 0; y < this->pixelHeight; y++)
        {
            for (int x = 0; x < this->pixelWidth * 3; x += 3)
            {
                int idx = y * (3 * this->pixelWidth) + 3*x;
                myfile << this->pixelArray[idx] << " "
                       << this->pixelArray[idx+1] << " "
                       << this->pixelArray[idx+2] << " ";
            }
            myfile << "\n";
        }
  
        myfile.close();
    }
    catch (...)
    {
        // If a file-related exception occurs, just return false.
        return false;
    }
    return true;
}
