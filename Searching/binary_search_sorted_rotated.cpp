// Given an array which is sorted and then rotated by an unknown number, find the max element and also an element x;

#include <iostream>

using namespace std;

int* initialize(int &, int &);
int find_max(int*, int, int);
int binary_search_r (int *, int, int, int);

int main() {
	while (1) {
		int size;
		int x;
		int *arr = initialize(size,x);
		int max_element = find_max(arr,0,size-1);
		cout<<"\nMaximum element is: "<<arr[max_element]<<"\n";
		if (x >= arr[0]) {
			cout<<"Index of the integer searched is: "<<binary_search_r(arr,0,max_element,x)<<"\n";
		} else {
		    cout<<"Index of the integer searched is: "<<binary_search_r(arr,max_element+1,size-1,x)<<"\n";
		}
	}
}

int find_max (int *arr, int l, int r) {
	// If left and right indexes are equal, then there is only one element left which will be the maximum
	if (l == r) {
		return l;
	}	
	int mid = l + (r-l)/2;
	// >= is to take care of the case when there are repeated elements
	if (arr[mid] >= arr[l]) {
		// If the element immediately after mid index is lesser, then arr[mid] is the max
		// We check this case because if arr[mid] is the max and making l= mid+1 would exclude the max element from the next binary search array
		// checking arr[mid+1] would not exceed index because if l==r==mid==size-1, we will not reach this point.
		if (arr[mid+1]<arr[mid]) {
			return mid;
		} else {
			find_max (arr,mid+1,r);
		}
	} else {
		find_max(arr,l,mid-1);
	}
}

int binary_search_r (int *arr, int l, int r, int x) {
	if (l>r) {
		return -1;
	}
	int mid = l + (r-l)/2;
	if (arr[mid] == x) {
		return mid;
	} else if (arr[mid] > x) {
		return binary_search_r(arr, l, mid-1, x);
	} else {
		return binary_search_r(arr, mid+1, r, x);
	} 
}

int* initialize(int &size, int &x) {
	
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
	
	cout<<"\nEnter the integer whose index you would like to search: ";
	cin>>x;
	
	return arr;
}
