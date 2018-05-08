#include "Image.h"
#include <iostream>
#include <fstream>

using namespace std;

Image::Image(unsigned int w, unsigned int h, unsigned char* pxArray): pixelWidth(w), pixelHeight(h), pixelArray(pxArray){};

Image::~Image()
{
	// Makrks the pixel array for deletion
	delete [] pixelArray;
	// Then makes it nullptr so memory can't be messed with
	pixelArray = nullptr;
}

Image::Image(const Image& other)
{
	// Create the dimensions of the image and the array of pixels
	this->pixelHeight = other.getHeight();
	this->pixelWidth = other.getWidth();
	this->pixelArray = new unsigned char[other.getHeight()*3*other.getWidth()];

	// Loop through all the pixels of the photo (Modified for loop from Dr. House)
	for (int y = 0; y < this->pixelHeight; y++)
    {
        for (int x = 0; x < this->pixelWidth * 3; x +=3)
        {
			// Then set each rgb value to the same as what image was passed in 
			*(pixelArray+y * (3 * pixelWidth) + x) = other.getRedPixel(x,y);
			*(pixelArray+y * (3 * pixelWidth) + x + 1) = other.getGreenPixel(x,y);
			*(pixelArray+y * (3 * pixelWidth) + x + 2) = other.getBluePixel(x,y);
		}
	}
}

Image& Image::operator = (const Image& pretty)
{
	// If the image is gonna downsize, mark the memory for deletion and make sure it can't be modified
	delete [] this->pixelArray;
	this->pixelArray = nullptr;
	// Make a new image from what is being passed in to the assignment
	Image* newImage = new Image(pretty);
	// Then return it to make it equal the new photo
	return *newImage;
}

Image* Image::Create(unsigned int width, unsigned int height)
{	
	// Create the size of the image and it's memory for pixels
	unsigned int size = width*3*height;
	unsigned char* pixArray = new unsigned char[size];
	
	// Call the private constructor using the passed in values
	Image* temp = new Image(width, height, pixArray);
	
	// If it exists return it
	if(temp)
		return(temp);

	return nullptr;
}

unsigned int Image::getHeight() const
{
	return pixelHeight;
}

unsigned int Image::getWidth() const
{
	return pixelWidth;
}

void Image::setPixel(unsigned int x, unsigned int y, unsigned char r, unsigned char g, unsigned char b)
{
	//Goes to index and sets each r g b value individually
	int index = 3*y*(this->pixelWidth) + x*3;
	this->pixelArray[index] = r;
	this->pixelArray[index + 1] = g;
	this->pixelArray[index + 2] = b;
}

unsigned char Image::getRedPixel(unsigned int x, unsigned int y) const
{
	return *(pixelArray + y * (3 * pixelWidth) + x);
}

unsigned char Image::getGreenPixel(unsigned int x, unsigned int y) const
{
	return *(pixelArray + y * (3 * pixelWidth) + x + 1);
}

unsigned char Image::getBluePixel(unsigned int x, unsigned int y) const
{
	return *(pixelArray + y * (3 * pixelWidth) + x + 2);
}

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
            for (int x = 0; x < this->pixelWidth * 3; x +=3)
            {
                int idx = y * (3 * this->pixelWidth) + x;
                myfile << this->pixelArray[idx]
                       << this->pixelArray[idx+1]
                       << this->pixelArray[idx+2];
            }
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
