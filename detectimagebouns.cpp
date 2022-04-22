#include <iostream>
#include "bmplib.cpp"

using namespace std;
unsigned char image[SIZE][SIZE][RGB];
unsigned char detectimage[SIZE][SIZE][RGB];


void loadImage ();
void saveImage ();
void DetectimageRGB ();

int main()
{
  loadImage();
  DetectimageRGB();
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

void DetectimageRGB() {
    long avarage = 0;
    int x=0;
    // for loop to convert the image to black and white
    for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j< SIZE; j++) {
        for (int k =0 ; k<RGB ;k++)
        {
          detectimage[i][j][k]=255;
        }
    }
     }
     for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j< SIZE; j++) {
        for (int k =0 ; k<RGB ;k++)
        {
        avarage += image[i][j][k];
        }
    }
  }
  avarage /= (SIZE*SIZE*RGB);
  for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j< SIZE; j++) {
        for (int k =0 ; k<RGB ;k=k+3)
        {
        if (image[i][j][k] + image[i][j][k+1] + image[i][j][k+2] >= 382)
        {
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
    // for loop to detcet the image
  for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j< SIZE; j++) {
      if(x==1)
        {
          detectimage[i][j][0]=255;
          if (image[i][j+1][0]==255)
          {
            x=0;
          }
         
        }

        if(x==0)
        {
        if (image[i][j][0]==0)
        {
          detectimage[i][j][0]=0;
          detectimage[i][j][1]=0;
          detectimage[i][j][2]=0;
           x=1;
          if(image[i-1][j][0]==255 or image[i+1][j][0]==255 or image[i-1][j+1][0]==255 or image[i-1][j-1][0]==255 or image[i+1][j+1][0]==255 or image[i+1][j-1][0]==255)
          {
          detectimage[i][j][0]=0;
          detectimage[i][j][1]=0;
          detectimage[i][j][2]=0;
          x=0;
          }
        }
        }
    }

  }
   for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j< SIZE; j++) {
      for (int k=0; k<RGB;k++)
      image[i][j][k]=detectimage[i][j][k];
    }
  }
}
