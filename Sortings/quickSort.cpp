#include<iostream>
using namespace std;
int partition(int array[],int low,int high){
    int pivot=array[high];
    int i=low-1;
    for (int j=low;j<high;j++){
        if(array[j]<pivot){
            i++;
            // swaping
            int temp=array[i];
            array[i]=array[j];
            array[j]=temp;
        }
    }
    //placing the pivot to right place
    i++;
    int temp=array[i];
    array[i]=pivot;
    array[high]=temp;
    return i;
}
void quickSort(int array[],int low,int high){
    if(high>low){
        int pivotIndex=partition(array,low,high);
        quickSort(array,0,pivotIndex-1);
        quickSort(array,pivotIndex+1,high);
    }
}
// Print an array
void printArray(int array[], int size) {
  int i;
  for (i = 0; i < size; i++)
    cout << array[i] << " ";
  cout << endl;
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
  quickSort(data,0,arraySize);
  cout << "Sorted array in Acsending Order:\n";
  printArray(data, arraySize);
    return 0;
}