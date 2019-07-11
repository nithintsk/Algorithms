// Given an array which is sorted and then rotated by an unknown number, find the max element and also an element x;

#include <iostream>

using namespace std;

int* initialize(int &);
int find_func(int*, int, int);

int main() {
	while (1) {
		int size;
		int *arr = initialize(size);
		int element = find_func(arr,0,size-1);
		cout<<"\nElement that is not smaller than neighbours is: "<<arr[element]<<"\n";
	}
}

int find_func (int *arr, int l, int r) {
	int mid = l + (r-l)/2;
	if (l == r) {
		return l;
	}
	
	if (r == l+1) {
		return arr[r]>arr[l]?r:l;
	}
	
	if (arr[mid] >= arr[mid-1] && arr[mid]>=arr[mid+1]) {
		return mid;
	}
	
	if (arr[mid] < arr[mid+1]) {
		find_func (arr,mid+1,r);
	} else {
		find_func(arr,l,mid-1);
	}
}

int* initialize(int &size) {
	
	cout<<"Enter size of array: ";
	cin>> size;
	int *arr = new int[size];
	
	cout<<"Enter "<<size<<" space separated integers to form the unsorted array: ";
	for (int i=0; i<size; i++) {
		cin>>arr[i];
	}
	
	cout<<"The entered array is :";
	for (int i=0; i<size; i++) {
		cout<<arr[i]<<" ";
	}
	
	return arr;
}
