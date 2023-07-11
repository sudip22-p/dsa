#include <iostream>
using namespace std;
void binarySearch(int array[], int low, int high, int key)
{
    int mid = low + (high - low) / 2;
    if (high >= low)
    {
        if (key == array[mid])
        {
            cout<<"***********"<<endl;
            cout << "data found !!!**** Data is placed in index no." << mid << endl;
            cout<<"***********"<<endl;
        }
        else if (key > array[mid])
        {
            binarySearch(array, mid + 1, high, key);
        }
        else if (key < array[mid])
        {
            binarySearch(array, low, mid - 1, key);
        }
    }
    else
    {
        cout<<"***********"<<endl;
        cout << "no such element found!!!******" << endl;
        cout<<"***********"<<endl;
    }
}
int main()
{
    int array[100];
    int i=0;
    int j=1;
    for (i,j;i <100; i++,j++)
    {
        if(j%4==0){
            array[i]=j;
        }
        else{
            i--;
        }
    } // starting an array in ascending order
    cout<<"***********"<<endl;
    cout << "array formed as::" << endl;
    for (int i = 0; i <= 99; i++)
    {
        cout << array[i] << " ";
    }
    cout<<endl;
    cout<<"***********"<<endl;
    int key;
    bool status = true;
    int choice;
    while (status)
    {
        cout<<"***********"<<endl;
        cout<<"*1)Search the element"<<endl;
        cout<<"*2)Exit the program"<<endl;
        cout<<"***********"<<endl;
        cout << "enter the choice (1/2):" << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "enter the key/element to search:" << endl;
            cin >> key;
            binarySearch(array, 0, 99, key);
            break;
        case 2:
            status = false;
            break;
        default:
            cout << "enter a valid choice!!!" << endl;
            break;
        }
    }

    return 0;
}