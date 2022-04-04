#include <iostream>
#include "bmplib.h"
#include "bmplib.cpp"

using namespace std;

void filter1();
void filter2();
void filter3();
void filter4();
void filter5();
void filter6();
void load_image();
void save_image();

unsigned char image_grid[SIZE][SIZE];


int main()
{
    int choice;
    cout << "Hello Dear User!\n" << "what Do You Need Today?\n";
    cout << "1- Filter 1\n" << "2- Filter 2\n" << "3- Filter 3\n" << "4- Filter 4\n" << "5- Filter 5\n" << "6- Filter 6" << endl;
    cin >> choice;
    cin.clear();
    cin.sync();

    if (choice == 1)
    {
        filter1();
    }
    
    else if (choice == 2)
    {
        filter2();
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

void filter1()
{
    cout << "filter 1 test";
}
void filter2()
{
    cout << "filter 2 test";
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
