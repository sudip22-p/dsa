//AKA Bucket Sort
#include <iostream>
using namespace std;

// Function to get the largest element from an array
int getMax(int array[], int n) {
  int max = array[0];
  for (int i = 1; i < n; i++)
    if (array[i] > max)
      max = array[i];
  return max;
}

// Using counting sort to sort the elements in the basis of significant places
void countingSort(int array[], int size, int place) {
  const int max = 10;//0-9
  int output[size];
  int count[max];
    //initializing all as 0
  for (int i = 0; i < max; ++i)
    count[i] = 0;

  // Calculate count of elements
  for (int i = 0; i < size; i++){
    //getting the value of desired place
    int temp=(array[i]/place)%10;
    //increasing that indexed value if desired place value  is index 
    count[temp]++;
    //alternative to perform above two step
    // count[(array[i] / place) % 10]++;
  }
  // Calculate cumulative count
  for (int i = 1; i < max; i++)
    count[i] += count[i - 1];
  // Place the elements in sorted order
  for (int i = size - 1; i >= 0; i--) {
    //NOTE:--Hence, starting the loop from the last index to the first index ensures that elements 
    //with the same value are placed correctly, preserving the stability of the counting sort algorithm.
    //calculate ahile saamma kati ota slot reserve cha n assign value to sp. index  
    output[count[(array[i] / place) % 10] - 1] = array[i];
    //reduce count bcoz one place is reserved by that place digit's data in output array
    count[(array[i] / place) % 10]--;
  }
    //transfering intermediate/complete sorted data to original
  for (int i = 0; i < size; i++)
    array[i] = output[i];
}

// Main function to implement radix sort
void radixSort(int array[], int size) {
  // Get maximum element
  int max = getMax(array, size);

  // Apply counting sort to sort elements based on place value.
  for (int place = 1; max / place > 0; place *= 10)
    countingSort(array, size, place);
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
  radixSort(data, arraySize);
  cout << "Sorted array in Acsending Order:\n";
  printArray(data, arraySize);
}
/*
    Certainly! Let's dive into the reason behind calculating the cumulative count in counting sort using an example.

Suppose we have an input array with the following elements: [4, 2, 1, 3, 4, 2, 1, 3]. Our goal is to sort this array using counting sort.

Counting sort involves creating a count array to store the frequency of each element in the input array. In this case, our count array would initially look like this: [0, 0, 0, 0, 0, 0, 0, 0, 0, 0]. Each index of the count array represents a unique element from the input array, and the value at that index represents the frequency of that element.

After counting the frequency of each element from the input array, the count array would look like this: [0, 2, 2, 2, 0, 0, 0, 0, 0, 0]. For example, index 1 represents the element 1, and it has a count of 2 because the element 1 appears twice in the input array.

Now, why do we calculate the cumulative count?

The cumulative count helps us determine the correct position of each element in the sorted output array. It indicates how many elements are less than or equal to a particular element.

To understand this better, let's consider the count array: [0, 2, 2, 2, 0, 0, 0, 0, 0, 0]. We can interpret this array as follows:

There are 0 elements that are less than or equal to 0.
There are 2 elements that are less than or equal to 1.
There are 4 elements that are less than or equal to 2.
There are 6 elements that are less than or equal to 3.
There are 6 elements that are less than or equal to 4.
Now, we can use this information to place each element in the sorted output array. Let's go through the process step by step:

Starting with the input array element 4, we look at the count array and see that there are 6 elements that are less than or equal to 4. So, we place 4 at index 6 in the output array.

Next, we move to the input array element 2. According to the count array, there are 4 elements that are less than or equal to 2. Hence, we place 2 at index 4 in the output array.

We continue this process for the remaining elements and place them in the correct positions based on their cumulative counts.

After completing this process, the sorted output array will be: [1, 1, 2, 2, 3, 3, 4, 4].

By calculating the cumulative count, we can accurately determine the positions of elements in the sorted output array. This step is essential to ensure the stability and correctness of the counting sort algorithm.
*/