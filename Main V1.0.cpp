#include <iostream>
#include <cstring>
#include "bmplib.h"
#include "bmplib.cpp"

using namespace std;

void invert();
void rotate();
void filter3();
void filter4();
void filter5();
void filter6();
void load_image();
void save_image();

unsigned char image_grid[SIZE][SIZE];
unsigned char new_image_grid[SIZE][SIZE];

int main()
{
    int choice;
    cout << "Hello Dear User!\n" << "what Do You Need Today?\n";
    cout << "1- Invert \n" << "2- Rotate \n" << "3- Filter 3\n" << "4- Filter 4\n" << "5- Filter 5\n" << "6- Filter 6" << endl;
    cin >> choice;
    cin.clear();
    cin.sync();

    if (choice == 1)
    {
        invert();
    }
    
    else if (choice == 2)
    {
        rotate();
    }
    
    else if (choice == 3)
    {
        filter3();
    }
    
    else if (choice == 4)
    {
        filter4();
    }
    
    else if (choice == 5)
    {
        filter5();
    }
    
    else if (choice == 6)
    {
        filter6();
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
void filter3()
{
    cout << "filter 3 test";
}
void filter4()
{
    cout << "filter 4 test";
}
void filter5()
{
    cout << "filter 5 test";
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
