// Given an infinite sorted array and an element x, find if x is present in the array or not.

#include <iostream>

using namespace std;

int* initialize(int &, int &);
int binary_search (int *, int, int, int);

int main() {
	int size;
	int x;
	int *arr = initialize(size,x);
	if (arr[0] == x) cout<<"Element "<<x<<" found at position 0";
	int i=1;
	while (arr[i] < x) {
		i=i*2;
	}
	if (arr[i] == x) {
		cout<<"Element "<<x<<" found at position "<<i;
	} else {
		cout<<"Element "<<x<<" found at position "<<binary_search(arr,i/2,i,x);
	}
}

int binary_search (int *arr, int l, int r, int x) {
	if (l>r) {
		return -1;
	}
	int mid = l + (r-l)/2;
	if (arr[mid] == x) {
		return mid;
	} else if (arr[mid] > x) {
		return binary_search(arr, l, mid-1, x);
	} else {
		return binary_search(arr, mid+1, r, x);
	} 
}

int* initialize(int &size, int &x) {
	
	cout<<"Enter size of array: ";
	cin>> size;
	int *arr = new int[size];
	
	cout<<"Enter "<<size<<" space separated integers : ";
	for (int i=0; i<size; i++) {
		cin>>arr[i];
	}
	
	cout<<"The entered array is :";
	for (int i=0; i<size; i++) {
		cout<<arr[i]<<" ";
	}
	
	cout<<"\nEnter the integer whose index you would like to search: ";
	cin>>x;
	
	return arr;
}
