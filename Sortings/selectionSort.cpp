#include <iostream>
using namespace std;

// function to swap the the position of two elements
void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

// function to print an array
void printArray(int array[], int size) {
  for (int i = 0; i < size; i++) {
    cout << array[i] << " ";
  }
  cout << endl;
}

void selectionSort(int array[], int size) {
  for (int step = 0; step < size - 1; step++) {
    int min_idx = step;
    for (int i = step + 1; i < size; i++) {

      // To sort in descending order, change > to < in this line.
      // Select the minimum element in each loop.
      if (array[i] < array[min_idx])
        min_idx = i;
    }

    // put min at the correct position
    swap(&array[min_idx], &array[step]);
  }
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
  cout<<endl;
  int data[arraySize];
  cout<<"enter the elements of the array:";
  takeArray(data,arraySize);
  selectionSort(data, arraySize);
  cout << "Sorted array in Acsending Order:\n";
  printArray(data, arraySize);
}