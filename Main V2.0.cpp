#include <iostream>
#include <cstring>
#include "bmplib.h"
#include "bmplib.cpp"

using namespace std;


void invert();
void rotate();
void BWimage ();
void flipimageH ();
void chose();
void flipimageV ();
void load_image();
void save_image();

unsigned char image_grid[SIZE][SIZE];
unsigned char new_image_grid[SIZE][SIZE];
unsigned char newimage[SIZE][SIZE];



int main()
{
    int choice;
    cout << "Hello Dear User!\n" << "what Do You Need Today?\n";
    cout << "1- Black and White \n" << "2- invert \n" << "3- merge\n" << "4- flip\n" << "5-rotate \n" << "6- Darken and Lighten" << endl;
    cin >> choice;
    cin.clear();
    cin.sync();

    if (choice == 1)
    {
        BWimage();     
    }
    
    else if (choice == 2)
    {
        invert();
    }
    
    else if (choice == 3)
    {
        //filter3();
    }
    
    else if (choice == 4)
    {
        chose();
    }
    
    else if (choice == 5)
    {
        rotate();
    }
    
    else if (choice == 6)
    {
        //filter6();
    }
}

void invert()
{
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            image_grid[i][j] = 255 - image_grid[i][j];
        }
    }
}
void rotate()
{
    int choice;
    cout << "Do You Want Rotate by 90 or 180 or 270? ";
    cin >> choice;
    
    if (choice == 90)
    {
        for (int i =0; i < SIZE - 1; i++)           // copy from the image grid to a new grid 
        {
            for (int j = 0; j < SIZE - 1; j++)
            {
                new_image_grid[j][i] = image_grid[SIZE-i-1][j];
            }
        }
 
        for (int i = 0; i < SIZE - 1; i++)         // returning the new grid to the old one 
        {
            for (int j = 0; j < SIZE - 1; j++)
            {
                image_grid[i][j] = new_image_grid[i][j];
            }
        }
            
    }
    else if (choice == 180)
    {
        for (int i = 0; i < (SIZE/2)-1; i++)
        {
            for (int j = 0; j < SIZE-1 ; j++)
            {
                swap(image_grid[i][j] , image_grid[SIZE-1-i][j]);
            }
        }
    }
    else if (choice == 270)
    {
        for (int i = 0; i < SIZE - 1; i++)
        {
            for (int j = 0; j < SIZE - 1; j++)
            {
                new_image_grid[j][i] = image_grid[i][SIZE-j-1];
            }
        }

        for (int i = 0; i < SIZE - 1; i++)          
        {
            for (int j = 0; j < SIZE - 1; j++)
            {
                image_grid[i][j] = new_image_grid[i][j];
            }
        }

    }
}
void BWimage() {
    long avarage = 0;
  for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j< SIZE; j++) {
        avarage += image_grid[i][j];

    }
  }
  avarage /= (SIZE*SIZE);
  for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j< SIZE; j++) {



        if (image_grid[i][j] > avarage)
            image_grid[i][j] = 255;
        else
            image_grid[i][j] = 0;


    }
  }
}
void flipimageH() {
    for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j< SIZE; j++) {
         newimage[i][j]= image_grid[i][j];
    }
    }
  for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j< SIZE; j++) {
            image_grid[i][j] = image_grid[SIZE -i][j];
    }
  }
  for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j< SIZE; j++) {
        image_grid[SIZE-i][j]=newimage[i][j];
    }
    }
}
void flipimageV()
{
  for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j< SIZE; j++) {
         newimage[i][j]= image_grid[i][j];
    }
    }
  for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j< SIZE; j++) {
            image_grid[i][j] = image_grid[i][SIZE-j];
    }
  }
  for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j< SIZE; j++) {
        image_grid[i][SIZE-j]=newimage[i][j];
    }
    }

}
void chose()
{
  int type;
 
  while (true)
  {
  cout<<"1- flip image horizontally "<<endl;
  cout <<"2- flip image vertically "<<endl;
  cin >> type;
  if (type ==1)
  {
  flipimageH();
  break;
  }
  if (type==2)
  {
    flipimageV();
    break;
  }
  if (type!=1 or type !=2)
  {
  cout<<"entre 1 or 2 only"<<endl;
  continue;
  }

    
  }
  
}
void filter3()
{
    cout << "filter 4 test";
}


void filter6()
{
    cout << "filter 6 test";
}


void load_image()
{
    char image_name[50];
    cout << "Please Enter Image Name: ";
    cin >> image_name;
    strcat(image_name , ".bmp");
    readGSBMP(image_name , image_grid);
}

void save_image()
{
    char new_name[50];
    cout << "Please Enter a New Name: ";
    cin >> new_name;
    strcat(new_name , ".bmp");
    writeGSBMP(new_name , image_grid );
}