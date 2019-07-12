// Given a sorted array and a sum, find if there is a pair with the given sum

#include <iostream>

using namespace std;

int* initialize(int &, int &);
bool two_pointer_approach (int *, int, int, int);

int main() {
	int size;
	int x;
	while(1) {
		int *arr = initialize(size,x);
		cout<<"Element found? : "<<(two_pointer_approach(arr,0,size-1,x)?"true":"false")<<"\n";
	}
}

bool two_pointer_approach_recursive (int *arr, int l, int r, int x) {
	if (l==r) {
		return -1;
	}
	if (arr[l] + arr[r] == x) {
		return true;
	} else if (arr[l] + arr[r] > x) {
		return two_pointer_approach(arr, l, r-1, x);
	} else {
		return two_pointer_approach(arr, l+1, r, x);
	} 
}

bool two_pointer_approach (int *arr, int l, int r, int x) {
	while( l < r ) {
		if (arr[l] + arr[r] == x) {
			return true;
		} else if (arr[l] + arr[r] > x) {
			r--;
		} else {
			l++;
		} 
	}
	return false;
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
	
	cout<<"\nEnter the sum you would like to search: ";
	cin>>x;
	
	return arr;
}
