// FCAI - Programming 1 - 2022 - Assignment 3
// Program Name: Simple Photo Editor for Colored Images
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

void invert_colored();
void rotate_colored();
//void BWimage();
//void merge_images();
//void flipimageH();
//void choose();
//void flipimageV();
void load_colored();
void save_colored();
//void darken_ligthen();
//void darken();
//void ligthen();
//void shrink_image();
//void blur_image();
//void Detectimage();
void enlarge_colored();
//void down_side();
//void right_side();
//void upper_side();
//void left_side();
//void Mirrorimage();
void shuffle_colored();

unsigned char colored_image[SIZE][SIZE][RGB];
unsigned char image[SIZE][SIZE][RGB];
unsigned char detectimage[SIZE][SIZE][RGB];
unsigned char new_colored[SIZE][SIZE][RGB];
unsigned char newimage[SIZE][SIZE][RGB];
unsigned char first_quarter_colored[128][128][3];
unsigned char second_quarter_colored[128][128][3];
unsigned char third_quarter_colored[128][128][3];
unsigned char fourth_quarter_colored[128][128][3];
unsigned char next_part_colored[128][128][3];

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
        int choice;
        cout << "Please Choose from the Menu above: ";
        do
        {
            cin >> choice;
            cin.clear();
            cin.sync();
        } while (choice < 0 || choice > 13);
        
        load_colored();
        if (choice == 1)
        {
            //BWimage();
        }

        else if (choice == 2)
        {
            invert_colored();
        }

        else if (choice == 3)
        {
            //merge_images();
        }

        else if (choice == 4)
        {
            //choose();
        }

        else if (choice == 5)
        {
            rotate_colored();
        }

        else if (choice == 6)
        {
            //darken_ligthen();
        }
        else if (choice == 7)
        {
            //Detectimage();
        }
        else if (choice == 8)
        {
            enlarge_colored();
        }
        else if (choice == 9)
        {
            //shrink_image();
        }
        else if (choice == 10)
        {
            //Mirrorimage();
        }
        else if (choice == 11)
        {
            shuffle_colored();
        }
        else if (choice == 12)
        {
            //blur_image();
        }
        else if (choice == 13)
        {
            //save_colored();
        }
        else if (choice == 0)
        {
            break;
        }
    }
}

void load_colored()
{
    char image_name[50];
    cout << "Please Enter Image Name: ";
    cin >> image_name;
    strcat(image_name, ".bmp");
    readRGBBMP(image_name, colored_image);
}

void save_colored()
{
    char new_name[50];
    cout << "Please Enter a New Name: ";
    cin >> new_name;
    strcat(new_name, ".bmp");
    writeRGBBMP(new_name, colored_image);
}

void shuffle_colored()
{
    string order;
    int counter = 0;
    int rows = 0;
    int columns = 0;
        
    do 
    {
        cout << "Please Enter The Order of The New Image: ";
        cin >> order;
    } while (!is_valid_order(order));
    

    for (int i = 0; i < 128; i++)
    {
        for (int j = 0; j < 128; j++)
        {
            for (int k = 0; k < 3 ; k++)
            {
                first_quarter_colored[i][j][k] = colored_image[i][j][k];
            }
        }
    }

    for (int i = 0; i < 128; i++)
    {
        for (int j = 0; j < 128; j++)
        {
            for (int k = 0; k < 3 ; k++)
            {
                second_quarter_colored[i][j][k] = colored_image[i][j + 127][k];
            }
        }
    }

    for (int i = 0; i < 128; i++)
    {
        for (int j = 0; j < 128; j++)
        {
            for (int k = 0; k < 3 ; k++)
            {
                third_quarter_colored[i][j][k] = colored_image[i + 127][j][k];
            }
        }
    }

    for (int i = 0; i < 128; i++)
    {
        for (int j = 0; j < 128; j++)
        {
            for (int k = 0; k < 3 ; k++)
            {
                fourth_quarter_colored[i][j][k] = colored_image[i + 127][j + 127][k];
            }
        }
    }

    while (counter < 4)
    {
        
        if (counter == 0)
        {
            rows = 0;
            counter = 0;
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

        if (order[counter] == '1')
        {
            for (int i = 0; i < 128; i++)
            {
                for (int j = 0; j < 128 ; j++)
                {
                    for (int k = 0; k < 3 ; k++)
                    {
                        next_part_colored[i][j][k] = first_quarter_colored[i][j][k];
                    }
                }
            }
        }
        else if (order[counter] == '2')
        {
            for (int i = 0; i < 128; i++)
            {
                for (int j = 0; j < 128 ; j++)
                {
                    for (int k = 0; k < 3 ; k++)
                    {
                        next_part_colored[i][j][k] = second_quarter_colored[i][j][k];
                    }
                }
            }
        }
        else if (order[counter] == '3')
        {
            for (int i = 0; i < 128; i++)
            {
                for (int j = 0; j < 128 ; j++)
                {
                    for (int k = 0; k < 3 ; k++)
                    {
                        next_part_colored[i][j][k] = third_quarter_colored[i][j][k];
                    }
                }
            }
        }
        else if (order[counter] == '4')
        {
            for (int i = 0; i < 128; i++)
            {
                for (int j = 0; j < 128 ; j++)
                {
                    for (int k = 0; k < 3 ; k++)
                    {
                        next_part_colored[i][j][k] = fourth_quarter_colored[i][j][k];
                    }
                }
            }
        }

        for (int i = 0; i < 128 ; i++)
        {
            for (int j = 0; j < 128 ; j++)
            {
                for (int k = 0; k < 3 ; k++)
                {
                    new_colored[i+columns][j+rows][k] = next_part_colored[i][j][k];
                }
            }
        }
        
        counter++ ;
    }

    for (int i = 0; i < SIZE ; i++)
    {
        for (int j = 0; j < SIZE ; j++)
        {
            for (int k = 0; k < 3 ; k++)
            {
                colored_image[i][j][k] = new_colored[i][j][k];
            }
        }
    }
}

void enlarge_colored()
{
    int chosen_part;
    cout << "Which Part Do Want to Enlarge? ";
    cin >> chosen_part;

    if (chosen_part == 1)
    {
        for (int i = 0 , k = 0; i < SIZE; i+=2 , k++)
        {
            for (int j = 0 , l =0; j < SIZE ; j+=2 , l++)
            {
                for (int m = 0; m<RGB ; m++)
                {
                    new_colored[i][j][m] = colored_image[k][l][m];
                    new_colored[i][j + 1][m] = colored_image[k][l][m];
                    new_colored[i + 1][j][m] = colored_image[k][l][m];
                    new_colored[i + 1][j + 1][m] = colored_image[k][l][m];
                }
            }
        }

        for (int i = 0; i < SIZE; i++)
        {
            for (int j = 0; j < SIZE; j++)
            {
                for (int k = 0; k <RGB ; k++)
                {
                    colored_image[i][j][k] = new_colored[i][j][k];
                }
            }
        }
    }
    else if (chosen_part == 2)
    {
        for (int i = 0 , k = 0; i < SIZE; i+=2 , k++)
        {
            for (int j = 0 , l =127; j < SIZE ; j+=2 , l++)
            {
                for (int m = 0; m <RGB ; m++)
                {
                    new_colored[i][j][m] = colored_image[k][l][m];
                    new_colored[i][j + 1][m] = colored_image[k][l][m];
                    new_colored[i + 1][j][m] = colored_image[k][l][m];
                    new_colored[i + 1][j + 1][m] = colored_image[k][l][m];
                }
            }
        }

        for (int i = 0; i < SIZE; i++)
        {
            for (int j = 0; j < SIZE; j++)
            {
                for (int k =0 ; k <RGB ; k++)
                {
                    colored_image[i][j][k] = new_colored[i][j][k];
                }
            }
        }
    }
    else if (chosen_part == 3)
    {
        for (int i = 0 , k = 127; i < SIZE; i+=2 , k++)
        {
            for (int j = 0 , l =0; j < SIZE ; j+=2 , l++)
            {
                for (int m = 0; m<RGB; m++)
                {
                    new_colored[i][j][m] = colored_image[k][l][m];
                    new_colored[i][j + 1][m] = colored_image[k][l][m];
                    new_colored[i + 1][j][m] = colored_image[k][l][m];
                    new_colored[i + 1][j + 1][m] = colored_image[k][l][m];
                }
            }
        }

        for (int i = 0; i < SIZE; i++)
        {
            for (int j = 0; j < SIZE; j++)
            {
                for (int k = 0; k <RGB ; k++)
                {
                    colored_image[i][j][k] = new_colored[i][j][k];
                }
            }
        }
    }
    else if (chosen_part == 4)
    {
        for (int i = 0 , k = 127; i < SIZE; i+=2 , k++)
        {
            for (int j = 0 , l =127; j < SIZE ; j+=2 , l++)
            {
                for (int m =0; m <RGB; m++)
                {
                    new_colored[i][j][m] = colored_image[k][l][m];
                    new_colored[i][j + 1][m] = colored_image[k][l][m];
                    new_colored[i + 1][j][m] = colored_image[k][l][m];
                    new_colored[i + 1][j + 1][m] = colored_image[k][l][m];
                }
            }
        }

        for (int i = 0; i < SIZE; i++)
        {
            for (int j = 0; j < SIZE; j++)
            {
                for (int k = 0; k<RGB; k++)
                {
                    colored_image[i][j][k] = new_colored[i][j][k];
                }
            }
        }
    }
}

void invert_colored()
{
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            for (int k = 0; k < RGB; k++)
            {
                colored_image[i][j][k] = 255 - colored_image[i][j][k];
            }
        }
    }
}

void rotate_colored()
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
                for (int k = 0; k < RGB ; k++)
                {
                    new_colored[j][i][k] = colored_image[SIZE-i-1][j][k];
                }
            }
        }
 
        for (int i = 0; i < SIZE - 1; i++)         // returning the new grid to the old one 
        {
            for (int j = 0; j < SIZE - 1; j++)
            {
                for (int k = 0; k < RGB ; k++)
                {
                    colored_image[i][j][k] = new_colored[i][j][k];
                }
            }
        }
            
    }
    else if (choice == 180)
    {
        for (int i = 0; i < (SIZE/2)-1; i++)
        {
            for (int j = 0; j < SIZE-1 ; j++)
            {
                for (int k = 0; k <RGB ; k++)
                {
                    swap(colored_image[i][j][k] , colored_image[SIZE-1-i][j][k]);
                }
            }
        }
    }
    else if (choice == 270)
    {
        for (int i = 0; i < SIZE - 1; i++)
        {
            for (int j = 0; j < SIZE - 1; j++)
            {
                for (int k = 0; k<RGB ; k++)
                {
                    new_colored[j][i][k] = colored_image[i][SIZE-j-1][k];
                }
            }
        }

        for (int i = 0; i < SIZE - 1; i++)          
        {
            for (int j = 0; j < SIZE - 1; j++)
            {
                for (int k = 0; k<RGB ; k++)
                {
                    colored_image[i][j][k] = new_colored[i][j][k];
                }
            }
        }

    }
}


// to validate user order used in shuffle filter using regex
bool is_valid_order(string &order)
{
    regex valid_order("[1-4][1-4][1-4][1-4]");
    return regex_match(order, valid_order);
}