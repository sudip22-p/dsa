#include<iostream>
#include<array>
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
int main(){
    int array[]={1,4,5,6,7,2,3,4,12,45,34,23,88,90,1,2,0,4,5};
    int n =sizeof(array)/sizeof(array[0]);
    quickSort(array,0,n-1);
    cout<<"array after sorted:- ";
    cout<<"{ ";
    for (int i=0;i<n;i++){
        if(i!=0&&i!=n){
            cout<<" , ";
        }
        cout<<array[i];
    }
    cout<<" }"<<endl;
    return 0;
}