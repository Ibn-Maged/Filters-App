// FCAI - Programming 1 - 2022 - Assignment 3
// Program Name: Simple Photo Editor
// Last Modification Date: 21/4/2022
// Author1 and ID: Ahmad Saad       20210020
// Author2 and ID: Hassan Magdi     20210126
// Author3 and ID: Mohamed Maged    20210352
// TA: Hagar Ali

#include <iostream>
#include <cstring>
#include "bmplib.h"
#include "bmplib.cpp"
#include <cmath>
#include <regex>

using namespace std;

void invert();
void rotate();
void BWimage();
void merge_images();
void flipimageH();
void choose();
void flipimageV();
void load_image();
void save_image();
void darken_ligthen();
void darken();
void ligthen();
void shrink_image();
void blur_image();
void Detectimage();
void enlarge();
void down_side();
void right_side();
void upper_side();
void left_side();
void Mirrorimage();
void shuffle_image();

unsigned char image_grid[SIZE][SIZE];
unsigned char image[SIZE][SIZE];
unsigned char detectimage[SIZE][SIZE];
unsigned char new_image_grid[SIZE][SIZE];
unsigned char newimage[SIZE][SIZE];
unsigned char first_quarter[128][128];
unsigned char second_quarter[128][128];
unsigned char third_quarter[128][128];
unsigned char fourth_quarter[128][128];
unsigned char next_part[128][128];

bool is_valid_order(string &order);

int main()
{
    cout << "Hello Dear User!\n";
    cout << "Please Choose From the Menu Below: \n";
    cout << "1- Black and White \n"
         << "2- invert \n"
         << "3- merge\n"
         << "4- flip\n"
         << "5- rotate \n"
         << "6- Darken and Lighten \n"
         << "7- Detect Image Edges \n"
         << "8- Enlarge Image \n"
         << "9- Shrink Image \n"
         << "10- Mirror Image \n"
         << "11- Shuffle Image \n"
         << "12- Blur Image \n"
         << "13- Save \n"
         << "0- Exit " << endl;
    // the main loop
    while (true)
    {
        load_image();
        char load_choice;
        while (true)
        {
            int choice;
            do
            {
                cout << "Please Choose from the Menu above: ";
                cin >> choice;
                cin.clear();
                cin.sync();
            } while (choice < 0 || choice > 13);

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
                merge_images();
            }

            else if (choice == 4)
            {
                choose();
            }

            else if (choice == 5)
            {
                rotate();
            }

            else if (choice == 6)
            {
                darken_ligthen();
            }
            else if (choice == 7)
            {
                Detectimage();
            }
            else if (choice == 8)
            {
                enlarge();
            }
            else if (choice == 9)
            {
                shrink_image();
            }
            else if (choice == 10)
            {
                Mirrorimage();
            }
            else if (choice == 11)
            {
                shuffle_image();
            }
            else if (choice == 12)
            {
                blur_image();
            }
            else if (choice == 13)
            {
                save_image();
            }
            else if (choice == 0)
            {
                break;
            }

            cout << "Done! \n\n";
        }
        while (true)
        {
            cout << "Press L to Load Another Image or Press Q to quit: ";
            cin >> load_choice;
            tolower(load_choice);
            cin.clear();
            cin.sync();
            if (load_choice == 'q')
            {
                break;
            }
            else if (load_choice == 'l')
            {
                break;
            }
        }
        if (load_choice == 'q')
        {
            break;
        }
    }
}
void invert()
{
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            image_grid[i][j] = 255 - image_grid[i][j]; // subtract from 255 to get the negative value for the color
        }
    }
}
void rotate()
{
    int choice;
    do
    {
        cout << "Do You Want Rotate by 90 or 180 or 270? ";
        cin >> choice;
    } while (choice != 90 && choice != 180 && choice != 270);

    if (choice == 90)
    {
        for (int i = 0; i < SIZE - 1; i++) // to rotate into a new grid
        {
            for (int j = 0; j < SIZE - 1; j++)
            {
                new_image_grid[j][i] = image_grid[SIZE - i - 1][j];
            }
        }

        for (int i = 0; i < SIZE - 1; i++) // return the image to the original grid
        {
            for (int j = 0; j < SIZE - 1; j++)
            {
                image_grid[i][j] = new_image_grid[i][j];
            }
        }
    }
    else if (choice == 180)
    {
        for (int i = 0; i < (SIZE / 2) - 1; i++) // to (SIZE / 2) to prevent Swaping An Already Swapped Pixel
        {
            for (int j = 0; j < SIZE - 1; j++)
            {
                swap(image_grid[i][j], image_grid[SIZE - 1 - i][j]);
            }
        }
    }
    else if (choice == 270)
    {
        for (int i = 0; i < SIZE - 1; i++) // to rotate into a new grid
        {
            for (int j = 0; j < SIZE - 1; j++)
            {
                new_image_grid[j][i] = image_grid[i][SIZE - j - 1];
            }
        }

        for (int i = 0; i < SIZE - 1; i++) // to return the image to the original grid
        {
            for (int j = 0; j < SIZE - 1; j++)
            {
                image_grid[i][j] = new_image_grid[i][j];
            }
        }
    }
}
void BWimage()
{
    long avarage = 0;
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            avarage += image_grid[i][j];
        }
    }
    avarage /= (SIZE * SIZE);
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {

            if (image_grid[i][j] > avarage)
                image_grid[i][j] = 255;
            else
                image_grid[i][j] = 0;
        }
    }
}

void flipimageH()
{
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            newimage[i][j] = image_grid[i][j];
        }
    }
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            image_grid[i][j] = image_grid[SIZE - i][j];
        }
    }
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            image_grid[SIZE - i][j] = newimage[i][j];
        }
    }
}

void flipimageV()
{
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            newimage[i][j] = image_grid[i][j];
        }
    }
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            image_grid[i][j] = image_grid[i][SIZE - j];
        }
    }
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            image_grid[i][SIZE - j] = newimage[i][j];
        }
    }
}

void choose()
{
    int type;

    while (true)
    {
        cout << "1- flip image horizontally " << endl;
        cout << "2- flip image vertically " << endl;
        cin >> type;
        if (type == 1)
        {
            flipimageH();
            break;
        }
        if (type == 2)
        {
            flipimageV();
            break;
        }
        if (type != 1 or type != 2)
        {
            cout << "entre 1 or 2 only" << endl;
            continue;
        }
    }
}

void merge_images()
{
    // Get gray scale image file name of the image to merge with
    unsigned char image2[SIZE][SIZE];
    char second_image[100];
    cout << "Please enter name of image file to merge with: ";
    cin >> second_image;

    // Add to it .bmp extension and load image
    strcat(second_image, ".bmp");
    readGSBMP(second_image, image2);
    // merge the two images
    for (int i = 0; i < 256; i++)
    {
        for (int j = 0; j < 256; j++)
        {
            image_grid[i][j] = (image_grid[i][j] + image2[i][j]) / 2;
        }
    }
}

void darken_ligthen()
{
    char choose;
    cout << "Do you want to (d)arken or (l)ighten?";
    cin >> choose;
    if (choose == 'd')
    {
        darken();
    }
    else if (choose == 'l')
    {
        ligthen();
    }
}
void ligthen()
{
    // make the photo ligter
    for (int i = 0; i < 256; i++)
    {
        for (int j = 0; j < 256; j++)
        {
            image_grid[i][j] = (256 + image_grid[i][j]) / 2;
        }
    }
}
void darken()
{

    // make the photo darker
    for (int i = 0; i < 256; i++)
    {
        for (int j = 0; j < 256; j++)
        {
            image_grid[i][j] = (image_grid[i][j]) / 2;
        }
    }
}
void shrink_image()
{
    string shrink_size;
    cout << "Shrink to (1/2), (1/3) or (1/4)?" << endl;
    cin >> shrink_size;

    if (shrink_size == "1/2")
    {
        for (int i = 0; i < 256; i += 2)
        {
            for (int j = 0; j < 256; j += 2)
            {
                new_image_grid[i / 2][j / 2] = image_grid[i][j];
            }
        }
    }
    else if (shrink_size == "1/3")
    {
        for (int i = 0; i < 256; i += 3)
        {
            for (int j = 0; j < 256; j += 3)
            {
                new_image_grid[i / 3][j / 3] = image_grid[i][j];
            }
        }
    }
    else
    {
        for (int i = 0; i < 256; i += 4)
        {
            for (int j = 0; j < 256; j += 4)
            {
                new_image_grid[i / 4][j / 4] = image_grid[i][j];
            }
        }
    }
    for (int i = 0; i < 256; i++)
    {
        for (int j = 0; j < 256; j++)
        {
            image_grid[i][j] = new_image_grid[i][j];
        }
    }
}

void blur_image()
{
    char color;
    for (int j = 1; j < 255; j++)
    {
        for (int i = 1; i < 255; i++)
        {
            image_grid[i][j] = (image_grid[i - 1][j - 1] + image_grid[i - 1][j] + image_grid[i - 1][j + 1] + image_grid[i][j - 1] + image_grid[i][j + 1] + image_grid[i + 1][j - 1] + image_grid[i + 1][j] + image_grid[i + 1][j + 1]) / 8;
        }
    }
    for (int j = 1; j < 255; j++)
    {
        for (int i = 1; i < 255; i++)
        {
            image_grid[i][j] = (image_grid[i - 1][j - 1] + image_grid[i - 1][j] + image_grid[i - 1][j + 1] + image_grid[i][j - 1] + image_grid[i][j + 1] + image_grid[i + 1][j - 1] + image_grid[i + 1][j] + image_grid[i + 1][j + 1]) / 8;
        }
    }
}

void load_image()
{
    char image_name[50];
    cout << "Please Enter Image Name: ";
    cin >> image_name;
    strcat(image_name, ".bmp");
    readGSBMP(image_name, image_grid);
}

void save_image()
{
    char new_name[50];
    cout << "Please Enter a New Name: ";
    cin >> new_name;
    strcat(new_name, ".bmp");
    writeGSBMP(new_name, image_grid);
}
void Detectimage()
{
    long Gx = 0, Gy = 0;
    int x = 0;
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            if ((i - 1 >= 0) and (i + 1 <= 255) and (j - 1 >= 0) and (j + 1 <= 255))
            {
                // Gx to detect the edges in vertical
                Gx = (image[i - 1][j - 1] * -1) + (image[i - 1][j + 1] * 1) + (image[i][j - 1] * -2) + (image[i][j + 1] * 2) + (image[i + 1][j - 1] * -1) + (image[i + 1][j + 1] * 1);
                // Gy to detect the edges in horizontal
                Gy = (image[i - 1][j - 1] * -1) + (image[i - 1][j + 1] * -1) + (image[i - 1][j] * -2) + (image[i + 1][j] * 2) + (image[i + 1][j - 1] * 1) + (image[i + 1][j + 1] * 1);
                x = sqrtf((Gx * Gx) + (Gy * Gy)); // x to detcet the edges in both side
                                                  // if to check if x>255 or not
                if (x > 255)
                {
                    x = 255;
                }
                detectimage[i][j] = x;
            }
            else
            {
                detectimage[i][j] = 0;
            }
        }
        // for loop to detect the edges more
        for (int i = 0; i < SIZE; i++)
        {
            for (int j = 0; j < SIZE; j++)
            {
                if (detectimage[i][j] > 127)
                {
                    detectimage[i][j] = 255;
                }
                if (detectimage[i][j] != 255)
                {
                    detectimage[i][j] = 0;
                }
            }
        }
    }
    // for loop to invert the image
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            detectimage[i][j] = 255 - detectimage[i][j];
        }
    }
    // for loop to move the image to the old matrix
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            image[i][j] = detectimage[i][j];
        }
    }
}
void down_side()
{
    // for loop to mirror the lower half of the image
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            image[i][j] = image[SIZE - i][j];
        }
    }
}
void right_side()
{
    // for loop to mirror the right half of the image
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            image[i][j] = image[i][SIZE - j];
        }
    }
}
void upper_side()
{
    // for loop to mirror the upper half of the image
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            image[SIZE - i][j] = image[i][j];
        }
    }
}
void left_side()
{
    // for loop to mirror the left half of the image
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            image[i][SIZE - j] = image[i][j];
        }
    }
}
void Mirrorimage()
{
    char type;
    // while loop to take the type of mirror from the user
    while (true)
    {
        cout << "1- mirror of the left half, enter (l) " << endl;
        cout << "2- mirror of the right half, enter (r) " << endl;
        cout << "3- mirror of the upper half, enter (u) " << endl;
        cout << "4- mirror of the down half, enter (d) " << endl;
        cin >> type;
        if (type == 'l')
        {
            left_side();
            break;
        }
        if (type == 'r')
        {
            right_side();
            break;
        }
        if (type == 'u')
        {
            upper_side();
            break;
        }
        if (type == 'd')
        {
            down_side();
            break;
        }
        // if to check the user input teh correct type or no
        if (type != 'l' and type != 'r' and type != 'u' and type != 'd')
        {
            cout << "enter the correct choose : " << endl;
            continue;
        }
    }
}

void enlarge()
{
    // to enlarge repeat the pixel 4 times in a square shape
    int chosen_part;
    cout << "Which Part Do Want to Enlarge? ";
    cin >> chosen_part;

    if (chosen_part == 1)
    {
        for (int i = 0, k = 0; i < SIZE; i += 2, k++)
        {
            for (int j = 0, l = 0; j < SIZE; j += 2, l++)
            {
                // copying the target pixel 4 times in a new matrix
                new_image_grid[i][j] = image_grid[k][l];
                new_image_grid[i][j + 1] = image_grid[k][l];
                new_image_grid[i + 1][j] = image_grid[k][l];
                new_image_grid[i + 1][j + 1] = image_grid[k][l];
            }
        }

        for (int i = 0; i < SIZE; i++)
        {
            for (int j = 0; j < SIZE; j++)
            {
                // return the image to the original matrix
                image_grid[i][j] = new_image_grid[i][j];
            }
        }
    }
    else if (chosen_part == 2)
    {
        for (int i = 0, k = 0; i < SIZE; i += 2, k++)
        {
            for (int j = 0, l = 127; j < SIZE; j += 2, l++)
            {
                // copying the target pixel 4 times in a new matrix
                new_image_grid[i][j] = image_grid[k][l];
                new_image_grid[i][j + 1] = image_grid[k][l];
                new_image_grid[i + 1][j] = image_grid[k][l];
                new_image_grid[i + 1][j + 1] = image_grid[k][l];
            }
        }

        for (int i = 0; i < SIZE; i++)
        {
            for (int j = 0; j < SIZE; j++)
            {
                // return the image to the original matrix
                image_grid[i][j] = new_image_grid[i][j];
            }
        }
    }
    else if (chosen_part == 3)
    {
        for (int i = 0, k = 127; i < SIZE; i += 2, k++)
        {
            for (int j = 0, l = 0; j < SIZE; j += 2, l++)
            {
                // copying the target pixel 4 times in a new matrix
                new_image_grid[i][j] = image_grid[k][l];
                new_image_grid[i][j + 1] = image_grid[k][l];
                new_image_grid[i + 1][j] = image_grid[k][l];
                new_image_grid[i + 1][j + 1] = image_grid[k][l];
            }
        }

        for (int i = 0; i < SIZE; i++)
        {
            for (int j = 0; j < SIZE; j++)
            {
                // return the image to the original matrix
                image_grid[i][j] = new_image_grid[i][j];
            }
        }
    }
    else if (chosen_part == 4)
    {
        for (int i = 0, k = 127; i < SIZE; i += 2, k++)
        {
            for (int j = 0, l = 127; j < SIZE; j += 2, l++)
            {
                // copying the target pixel 4 times in a new matrix
                new_image_grid[i][j] = image_grid[k][l];
                new_image_grid[i][j + 1] = image_grid[k][l];
                new_image_grid[i + 1][j] = image_grid[k][l];
                new_image_grid[i + 1][j + 1] = image_grid[k][l];
            }
        }

        for (int i = 0; i < SIZE; i++)
        {
            for (int j = 0; j < SIZE; j++)
            {
                // return the image to the original matrix
                image_grid[i][j] = new_image_grid[i][j];
            }
        }
    }
}

void shuffle_image()
{
    string order;
    int counter = 0;
    int rows = 0;
    int columns = 0;

    // do while loop to validate user input using regex
    do
    {
        cout << "Please Enter The Order of The New Image: ";
        cin >> order;
    } while (!is_valid_order(order));

    for (int i = 0; i < 128; i++)
    {
        for (int j = 0; j < 128; j++)
        {
            // to  copy the upper left quarter of the image in a new matrix
            first_quarter[i][j] = image_grid[i][j];
        }
    }

    for (int i = 0; i < 128; i++)
    {
        for (int j = 0; j < 128; j++)
        {
            // to  copy the upper right quarter of the image in a new matrix
            second_quarter[i][j] = image_grid[i][j + 127];
        }
    }

    for (int i = 0; i < 128; i++)
    {
        for (int j = 0; j < 128; j++)
        {
            // to  copy the lower left quarter of the image in a new matrix
            third_quarter[i][j] = image_grid[i + 127][j];
        }
    }

    for (int i = 0; i < 128; i++)
    {
        for (int j = 0; j < 128; j++)
        {
            // to  copy the lower right quarter of the image in a new matrix
            fourth_quarter[i][j] = image_grid[i + 127][j + 127];
        }
    }

    while (counter < 4)
    {
        // rows and columns used in accessing the 4 image parts in the right order
        if (counter == 0)
        {
            rows = 0;
            columns = 0;
        }
        else if (counter == 1)
        {
            rows = 127;
            columns = 0;
        }
        else if (counter == 2)
        {
            rows = 0;
            columns = 127;
        }
        else if (counter == 3)
        {
            rows = 127;
            columns = 127;
        }
        // copying the chosen quarter in the matrix used in moving the image
        if (order[counter] == '1')
        {
            for (int i = 0; i < 128; i++)
            {
                for (int j = 0; j < 128; j++)
                {
                    next_part[i][j] = first_quarter[i][j];
                }
            }
        }
        else if (order[counter] == '2')
        {
            for (int i = 0; i < 128; i++)
            {
                for (int j = 0; j < 128; j++)
                {
                    next_part[i][j] = second_quarter[i][j];
                }
            }
        }
        else if (order[counter] == '3')
        {
            for (int i = 0; i < 128; i++)
            {
                for (int j = 0; j < 128; j++)
                {
                    next_part[i][j] = third_quarter[i][j];
                }
            }
        }
        else if (order[counter] == '4')
        {
            for (int i = 0; i < 128; i++)
            {
                for (int j = 0; j < 128; j++)
                {
                    next_part[i][j] = fourth_quarter[i][j];
                }
            }
        }
        // copying selected quarter in the image matrix
        for (int i = 0; i < 128; i++)
        {
            for (int j = 0; j < 128; j++)
            {
                new_image_grid[i + columns][j + rows] = next_part[i][j];
            }
        }

        counter++;
    }
    // return the image to the original matrix
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            image_grid[i][j] = new_image_grid[i][j];
        }
    }
}

// to validate user order used in shuffle filter using regex
bool is_valid_order(string &order)
{
    regex valid_order("[1-4][1-4][1-4][1-4]");
    return regex_match(order, valid_order);
}
