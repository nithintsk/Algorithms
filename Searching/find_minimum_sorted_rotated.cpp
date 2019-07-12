// Given an array which is sorted and then rotated by an unknown number, find the max element and also an element x;

#include <iostream>

using namespace std;

int* initialize(int &);
int minNumber(int*, int, int);

int main() {
	while (1) {
		int size;
		int *arr = initialize(size);
		int min_element = minNumber(arr,0,size-1);
		cout<<"\nMinimum element is: "<<arr[min_element]<<"\n";
	}
}

int minNumber(int arr[], int low, int high)
{
    int mid = low + (high - low)/2;
    
    if (low == high) return arr[mid];
    
    if (mid == low) return arr[mid]>arr[mid+1]?arr[mid+1]:arr[mid];
    
    if (arr[mid] < arr[mid-1]) return arr[mid];
    
    if (arr[high] < arr[mid]) minNumber(arr,mid+1,high);
    
    else minNumber(arr,low,mid-1);
    
    /*
    
    // This condition is needed to  
    // handle the case when array is not  
    // rotated at all  
    //if (high < low) return arr[0];   
  
    // If there is only one element left  
    if (high == low) return arr[low];  
  
    // Find mid  
    int mid = low + (high - low)/2;
  
    // Check if element (mid+1) is minimum element. Consider  
    // the cases like {3, 4, 5, 1, 2}  
    if (arr[mid + 1] < arr[mid])  
    return arr[mid + 1];  
  
    // Check if mid itself is minimum element  
    if (mid > low && arr[mid] < arr[mid - 1])  
    return arr[mid];  
  
    // Decide whether we need to go to left half or right half  
    if (arr[high] > arr[mid])  
    return minNumber(arr, low, mid - 1);  
    return minNumber(arr, mid + 1, high);  
    */
    
}


int* initialize(int &size) {
	
	cout<<"Enter size of array: ";
	cin>> size;
	int *arr = new int[size];
	
	cout<<"Enter "<<size<<" space separated integers to form the sorted and rotated array: ";
	for (int i=0; i<size; i++) {
		cin>>arr[i];
	}
	
	cout<<"The entered array is :";
	for (int i=0; i<size; i++) {
		cout<<arr[i]<<" ";
	}
	
	return arr;
}
