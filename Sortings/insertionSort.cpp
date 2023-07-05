#include <iostream>
using namespace std;
// Function to print an array
void printArray(int array[], int size) {
  for (int i = 0; i < size; i++) {
    cout << array[i] << " ";
  }
  cout << endl;
}
void insertionSort(int array[], int size) {
  for (int step = 1; step < size; step++) {//bcoz iteration is size-1
    int key = array[step];//first is assumes as sorted, second element is key first,
    int j = step - 1;//key agadi ko lai

    // Compare key with each element on the left of it until an element smaller than
    // it is found.
    // For descending order, change key<array[j] to key>array[j].
    while (key < array[j] && j >= 0) {//key lai agadiko haru sanga compare 
      array[j + 1] = array[j];//note arrayj+1 vaneko key ho
      --j;
    }
    array[j + 1] = key;
  }
}
//taking the array
void takeArray(int data[],int size){
    for(int i=0;i<size;i++){
        cin>>data[i];
    }
}
// Driver code
int main() {
    int arraySize;
    cout<<"enter the size of the array:";
    cin>>arraySize;
    cout<<endl;
    int data[arraySize];
    cout<<"enter the elements of the array:";
    takeArray(data,arraySize);
  insertionSort(data, arraySize);
  cout << "Sorted array in ascending order:\n";
  printArray(data, arraySize);
}