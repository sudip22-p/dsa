#include <iostream>
using namespace std;

// perform bubble sort
void bubbleSort(int array[], int size) {

  // loop to access each array element
  for (int step = 0; step < size; ++step) {
      
    // loop to compare array elements
    for (int i = 0; i < size - step; ++i) {

      // compare two adjacent elements
      // change > to < to sort in descending order
      if (array[i] > array[i + 1]) {

        // swapping elements if elements
        // are not in the intended order
        int temp = array[i];
        array[i] = array[i + 1];
        array[i + 1] = temp;
      }
    }
  }
}

// print array
void printArray(int array[], int size) {
  for (int i = 0; i < size; ++i) {
    cout << "  " << array[i];
  }
  cout << "\n";
}

//taking the array
void takeArray(int data[],int size){
    for(int i=0;i<size;i++){
        cin>>data[i];
    }
}
// driver code
int main() {
  int arraySize;
  cout<<"enter the size of the array:";
  cin>>arraySize;
  int data[arraySize];
  cout<<"enter the elements of the array:";
  takeArray(data,arraySize);
  bubbleSort(data, arraySize);
  cout << "Sorted array in Acsending Order:\n";
  printArray(data, arraySize);
}