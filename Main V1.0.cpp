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
    cout << "fliter 1 test";
}
void filter2()
{
    cout << "fliter 2 test";
}
void filter3()
{
    cout << "fliter 3 test";
}
void filter4()
{
    cout << "fliter 4 test";
}
void filter5()
{
    cout << "fliter 5 test";
}
void filter6()
{
    cout << "fliter 6 test";
}