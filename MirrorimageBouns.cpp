#include <iostream>
#include "bmplib.cpp"

using namespace std;
unsigned char image[SIZE][SIZE][RGB];

void loadImage ();
void saveImage ();
void down_side ();
void right_side ();
void upper_side();
void left_side();
void MirrorB();

int main()
{
  loadImage();
  MirrorB();
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

void down_side() {
  // for loop to mirror the down side
  for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j< SIZE; j++) {
        for (int k=0 ; k<RGB;k++)
        {
        image[i][j][k]= image[SIZE-i][j][k];
        }

    }
  }
}
void right_side()
{
  // for loop to mirror the right side
  for (int i = 0; i < SIZE; i++) {
  for (int j = 0; j< SIZE; j++) {
      for (int k=0 ; k<RGB;k++)
      {
        image[i][j][k]= image[i][SIZE-j][k];
      }
    }
  }
}
void upper_side()
{
  // for loop to mirror the upper side
  for (int i = 0; i < SIZE; i++) {
  for (int j = 0; j< SIZE; j++) {
      for (int k=0 ; k<RGB;k++)
      {
        image[SIZE-i][j][k]= image[i][j][k];
      }
  }
  }
}
void left_side()
{
  // for loop to mirror the left side
  for (int i = 0; i < SIZE; i++) {
  for (int j = 0; j< SIZE; j++) {
      for (int k=0 ; k<RGB;k++)
      {
        image[i][SIZE-j][k]= image[i][j][k];
      }
    }
  }
}
void MirrorB()
{
  char type;
  //while loop to take the type of mirror from the user
  while (true)
  {
  cout<<"1- mirror of the left half, enter (l) "<<endl;
  cout <<"2- mirror of the right half, enter (r) "<<endl;
  cout <<"3- mirror of the upper half, enter (u) "<<endl;
  cout <<"4- mirror of the down half, enter (d) "<<endl;
  cin >> type;
  if (type =='l')
  {
    left_side();
    break;
  }
  if (type=='r')
  {
    right_side();
    break;
  }
  if (type=='u')
  {
    upper_side();
    break;
  }
  if (type=='d')
  {
    down_side();
    break ;
  }
  // if to check the user input teh correct type or no
  if (type !='l' and type !='r' and type !='u' and type !='d' )
  {
    cout <<"enter the correct choose : "<<endl;
    continue;
  }
  
}

}



