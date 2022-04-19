#include <iostream>
#include <cstring>
#include "bmplib.h"
#include "bmplib.cpp"

using namespace std;


void invert();
void rotate();
void BWimage ();
void merge_images();
void flipimageH ();
void choose();
void flipimageV ();
void load_image();
void save_image();
void darken_ligthen();
void darken();
void ligthen();
void shrink_image();
void blur_image();
//void detect_image_edges();
//void enlarge_image();
//void mirror_image();
//void shuffle_image();

unsigned char image_grid[SIZE][SIZE];
unsigned char new_image_grid[SIZE][SIZE];
unsigned char newimage[SIZE][SIZE];



int main()
{
    int choice;
    cout << "Hello Dear User!\n" << "what Do You Need Today?\n";
    do
    {
        cout << "1- Black and White \n" << "2- invert \n" << "3- merge\n" << "4- flip\n" << "5-rotate \n" << "6- Darken and Lighten \n"<<"7- Detect Image Edges \n"<<"8- Enlarge Image \n"<<"9- Shrink Image \n"<<"a- Mirror Image \n" <<"b- Shuffle Image \n" <<"c- Blur Image" << endl;
        cin >> choice;
        cin.clear();
        cin.sync();
    }while (choice>9||choice<1);

    load_image();

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
        //detect_image_edges();
    }
    else if (choice == 8)
    {
       // enlarge_image();
    }
    else if (choice == 9)
    {
        shrink_image();
    }
    else if (choice == 'a')
    {
        //mirror_image();
    }
    else if (choice == 'b')
    {
        //shuffle_image();
    }
    else if (choice == 'c')
    {
        blur_image();
    }


    save_image();

}

void invert()
{
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            image_grid[i][j] = 255 - image_grid[i][j];       // subtract from 255 to get the negative value for the color
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
    } while (choice != 90 && choice != 180 && choice != 270   ) ;

    if (choice == 90)
    {
        for (int i =0; i < SIZE - 1; i++)           // to rotate into a new grid
        {
            for (int j = 0; j < SIZE - 1; j++)
            {
                new_image_grid[j][i] = image_grid[SIZE-i-1][j];
            }
        }

        for (int i = 0; i < SIZE - 1; i++)         // return the image to the original grid
        {
            for (int j = 0; j < SIZE - 1; j++)
            {
                image_grid[i][j] = new_image_grid[i][j];
            }
        }

    }
    else if (choice == 180)
    {
        for (int i = 0; i < (SIZE/2)-1; i++)        // to (SIZE / 2) to prevent Swaping An Already Swapped Pixel
        {
            for (int j = 0; j < SIZE-1 ; j++)
            {
                swap(image_grid[i][j] , image_grid[SIZE-1-i][j]);
            }
        }
    }
    else if (choice == 270)
    {
        for (int i = 0; i < SIZE - 1; i++)         // to rotate into a new grid
        {
            for (int j = 0; j < SIZE - 1; j++)
            {
                new_image_grid[j][i] = image_grid[i][SIZE-j-1];
            }
        }

        for (int i = 0; i < SIZE - 1; i++)         // to return the image to the original grid
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

void flipimageV(){
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

void choose(){
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

void merge_images(){
    // Get gray scale image file name of the image to merge with
    unsigned char image2[SIZE][SIZE];
    char second_image[100];
    cout << "Please enter name of image file to merge with: ";
    cin >> second_image;

   // Add to it .bmp extension and load image
   strcat (second_image, ".bmp");
   readGSBMP(second_image, image2);
   //merge the two images
   for(int i=0;i<256;i++){
        for(int j=0;j<256;j++){
            image_grid[i][j]=(image_grid[i][j]+image2[i][j])/2;
        }
   }
}

void darken_ligthen(){
  char choose;
  load_image();
  cout<<"Do you want to (d)arken or (l)ighten?";
  cin>>choose;
  if (choose=='d'){
    darken();
  }
  else if (choose=='l'){
    ligthen();
  }
  save_image();
}
void ligthen(){
    //make the photo ligter
    for(int i=0;i<256;i++){
        for(int j=0;j<256;j++){
            image_grid[i][j]=(256+image_grid[i][j])/2;
        }
    }
}
void darken(){

    //make the photo darker
    for(int i=0;i<256;i++){
        for(int j=0;j<256;j++){
            image_grid[i][j]=(image_grid[i][j])/2;
        }
    }
}
void shrink_image() {
    string shrink_size;
    cout<<"Shrink to (1/2), (1/3) or (1/4)?"<<endl;
    cin>>shrink_size;

    if(shrink_size=="1/2"){
        for(int i=0;i<256;i+=2){
            for(int j=0;j<256;j+=2){
                new_image_grid[i/2][j/2]=image_grid[i][j];
            }
        }
    }
    else if(shrink_size=="1/3"){
        for(int i=0;i<256;i+=3){
            for(int j=0;j<256;j+=3){
                new_image_grid[i/3][j/3]=image_grid[i][j];
            }
        }
    }
    else{
        for(int i=0;i<256;i+=4){
            for(int j=0;j<256;j+=4){
                new_image_grid[i/4][j/4]=image_grid[i][j];
            }
        }
    }
    for(int i=0;i<256;i++){
        for(int j=0;j<256;j++){
            image_grid[i][j]=new_image_grid[i][j];
        }
    }
}

void blur_image() {
    char color;
    for(int j=1;j<255;j++){
        for(int i=1;i<255;i++){
            image_grid[i][j]=(image_grid[i-1][j-1]+image_grid[i-1][j]+image_grid[i-1][j+1]+image_grid[i][j-1]+image_grid[i][j+1]+image_grid[i+1][j-1]+image_grid[i+1][j]+image_grid[i+1][j+1])/8;
        }
    }
}



void load_image(){
    char image_name[50];
    cout << "Please Enter Image Name: ";
    cin >> image_name;
    strcat(image_name , ".bmp");
    readGSBMP(image_name , image_grid);
}

void save_image(){
    char new_name[50];
    cout << "Please Enter a New Name: ";
    cin >> new_name;
    strcat(new_name , ".bmp");
    writeGSBMP(new_name , image_grid );
}
