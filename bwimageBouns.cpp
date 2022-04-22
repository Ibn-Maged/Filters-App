#include <iostream>
#include "bmplib.cpp"

using namespace std;
unsigned char image[SIZE][SIZE][RGB];

void loadImage ();
void saveImage ();
void BWimageRGB ();

int main()
{
  loadImage();
  BWimageRGB();
  saveImage();
  return 0;
}


void loadImage () {
   char imageFileName[100];
   cout << "Enter the source image file name: ";
   cin >> imageFileName;
   strcat (imageFileName, ".bmp");
   readRGBBMP(imageFileName, image);
}

void saveImage () {
   char imageFileName[100];

   cout << "Enter the target image file name: ";
   cin >> imageFileName;

   strcat (imageFileName, ".bmp");
   writeRGBBMP(imageFileName, image);
}

void BWimageRGB() {
  long average = 0;
// for loop to calculate teh average 
  for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j< SIZE; j++) {
        for (int k =0 ; k<RGB ;k++)
        {
        average += image[i][j][k];
        }
    }
  }
  average /= (SIZE*SIZE*RGB);
  // for loop to convert teh image to B and W image
  for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j< SIZE; j++) {
      for (int k =0 ; k<RGB ;k=k+3)
      {
        if (image[i][j][k] + image[i][j][k+1] + image[i][j][k+2] >= 382)
        {
          // 3 statements for R , G , B 
          image[i][j][k] = 255;
          image[i][j][k+1] = 255;
          image[i][j][k+2] = 255;
        }
        else{
          image[i][j][k] = 0;
          image[i][j][k+1] = 0;
          image[i][j][k+2] = 0;
        }
        }
    }
  }
}
