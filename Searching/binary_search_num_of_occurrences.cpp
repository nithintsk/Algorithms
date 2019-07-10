#include <iostream>

using namespace std;

int* initialize(int &, int &);
int binary_search_l (int *, int, int, int);
int binary_search_r (int *, int, int, int, int);

int main() {
	int size;
	int x;
	int *arr = initialize(size,x);
    int left = binary_search_l(arr,0,size-1,x);
    int right = binary_search_r(arr,0,size-1,x, size);
    cout<< "Number of occcurences is: "<<right-left+1;
}

int binary_search_l (int *arr, int l, int r, int x) {
	if (l>r) return -1;
	int mid = l + (r-l)/2;
	// Added ===========> && (mid==0 || arr[mid-1] !=x)
	if (arr[mid] == x && (mid==0 || arr[mid-1] !=x)) {
		return mid;
	// Changed arr[mid] > x to arr[mid] >= x
	} else if (arr[mid] >= x) {
		return binary_search_l(arr, l, mid-1, x);
	} else if (arr[mid] < x){
		return binary_search_l(arr, mid+1, r, x);
	} else {
		return -1;
	}
}

int binary_search_r (int *arr, int l, int r, int x, int size) {
	if (l>r) return -1;
	int mid = l + (r-l)/2;
	// Added ===========> && (mid==0 || arr[mid-1] !=x)
	if (arr[mid] == x && (mid==size-1 || arr[mid+1] !=x)) {
		return mid;
	// Changed arr[mid] > x to arr[mid] >= x
	} else if (arr[mid] > x) {
		return binary_search_r(arr, l, mid-1, x, size);
	} else if (arr[mid] <= x){
		return binary_search_r(arr, mid+1, r, x, size);
	} else {
		return -1;
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
