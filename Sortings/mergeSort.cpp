#include<iostream>
using namespace std;
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
void conquer(int array[],int si,int mid,int ei){
    //creating merged new array 
    int size=ei-si+1;
    int merged[size];
    //variable for placind data in new array
    int index=0;
    //creating two comparison variable
    int index1=si;
    int index2=mid+1;
    //sorting like this untill each terms are placed properly in newly formed array
    while (index1<=mid&&index2<=ei){
        //comparison
        //if index1 ko sano or equal cha then put it firstly on merged[]...
        if(array[index1]<=array[index2]){
            merged[index]=array[index1];//sanolai
            index++;//previous is feed with data
            index1++;//prev is placed/sorted properly in new array
            //shorthand
            // merged[index++]=array[index1++];

        }
        else{
            //natra index 2 wala ko sano huncha so performing as above similarly.........
            merged[index]=array[index2];//sanolai
            index++;//previous is feed with data
            index2++;//
            //shorthand
            // merged[index++]=array[index2++];
        }
    }
        //if a case exist in which all one sublists are sorted using above while loop tara arko 
        //sublist ko rahyo re elemets haru then tyo raheko lai merged ma rakhna paryo for this we do....
        while (index1<=mid){

            merged[index++]=array[index1++];
        }
        while (index2<=ei){

            merged[index++]=array[index2++];
        }
    //now replacing sorted array i.e. merged to original array
    int i,j;
    for(i=0,j=si;i<size;i++,j++){
        array[j]=merged[i];//2var bcoz array ko index is not necessary to be 0, 1,2,.....
    }
}
void divide(int array[],int si,int ei){
    if(si>=ei){
        return;
    }
    int mid=si+(ei-si)/2;
    divide(array,si,mid);
    divide(array,mid+1,ei);
    conquer(array,si,mid,ei);
}
// driver code
int main() {
  int arraySize;
  cout<<"enter the size of the array:";
  cin>>arraySize;
  int data[arraySize];
  cout<<"enter the elements of the array:";
  takeArray(data,arraySize);
  divide(data,0,arraySize-1);
  cout << "Sorted array in Acsending Order:\n";
  printArray(data, arraySize);
    return 0;
}