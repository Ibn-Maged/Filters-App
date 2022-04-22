#include <iostream>
#include "bmplib.cpp"

using namespace std;
unsigned char image[SIZE][SIZE][RGB];
unsigned char newimage[256][256][3];

void loadImage ();
void saveImage ();
void flipimageH ();
void flipimage();
void flipimageV ();

int main()
{
  loadImage();
  flipimage();
  saveImage();
  return 0;
}

void loadImage () {
   char imageName[100];
   cout << "Enter the image  name: ";
   cin >> imageName;
   strcat (imageName, ".bmp");
   readRGBBMP(imageName, image);
}

void saveImage () {
   char imageName[100];
   cout << "Enter the new image  name: ";
   cin >> imageName;
   strcat (imageName, ".bmp");
   writeRGBBMP(imageName, image);
}
void flipimageH() {
  // for loop to flip horizpntal
    for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j< SIZE; j++) {
      for(int k =0;k<3 ; k++)
        newimage[i][j][k]= image[i][j][k];
    }
    }
  for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j< SIZE; j++) {
      for (int k = 0 ; k <RGB ; k++)
      {
        image[i][j][k] = image[SIZE -i][j][k];    
      }
    }
  }
// for loop to store the new matrix in old matrix
  for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j< SIZE; j++) {
      for (int k = 0 ; k <RGB ; k++)
      {
        image[SIZE-i][j][k]=newimage[i][j][k];
      }
    }
    }
}
void flipimageV()
{
  // for loop to flip vertically
  for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j< SIZE; j++) {
      for (int k = 0 ; k <RGB ; k++)
      {
        newimage[i][j][k]= image[i][j][k]; 
      }
    }
    }
  for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j< SIZE; j++) {
      for (int k = 0 ; k <RGB ; k++)
      {
        image[i][j][k] = image[i][SIZE-j][k];     
      }
    }
  }
  // for loop to store the new matrix in old matrix
  for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j< SIZE; j++) {
      for (int k = 0 ; k <RGB ; k++)
      {
        image[i][SIZE-j][k]=newimage[i][j][k]; 
      }
    }
    }

}
void flipimage()
{
  char type;
 // while true to check teh correct input
  while (true)
  {
  cout<<"1- flip image horizontally, enter (h) "<<endl;
  cout <<"2- flip image vertically , enter (v)"<<endl;
  cin >> type;
  if (type =='h')
  {
  flipimageH();
  break;
  }
  if (type=='v')
  {
    flipimageV();
    break;
  }
  if (type!='h' or type !='v')
  {
  cout<<"entre (v) or (h) only"<<endl;
  continue;
  }
  }
}
