#include <iostream>

using namespace std;

int* initialize(int &, int &);
int binary_search_r (int *, int, int, int, int);

int main() {
	int size;
	int x;
	int *arr = initialize(size,x);
	cout<<"Index of the element is: "<<binary_search_r(arr,0,size-1,x, size);
}

int binary_search_r (int *arr, int l, int r, int x, int size) {
	if (l>r || r<l) {
		return -1;
	}
	int mid = l + (r-l)/2;
	if (arr[mid] == x) {
		return mid;
	} else if (arr[mid] > x) {
		return binary_search_r(arr, l, mid-1, x, size);
	} else {
		return binary_search_r(arr, mid+1, r, x, size);
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
