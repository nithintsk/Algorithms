/*
Count 1's in binary array

Given a binary sorted non-increasing array arr of size N. You need to print the count of 1's in the binary array.

Input:
The input line contains T, denotes the number of testcases. Each input contains two lines. The first line contains N(size of binary array). The second line contains N elements of binary array separated by space.

Output:
For each testcase in new line, print the count 1's in binary array.

User Task:
The task is to complete the function countOne() which return count of 1s in the input array.

Constraint:
1 <= T <= 100
1 <= N <= 5*106
0 <= arr[i] <= 1

Example:
Input:
2
8
1 1 1 1 1 0 0 0
8
1 1 0 0 0 0 0 0

Output:
5
2

Explanation:
Testcase 1: Number of 1's in given binary array : 1 1 1 1 1 0 0 0 is 5.
*/
#include <iostream>

using namespace std;

int* initialize(int &);
int countOnes(int*, int);

int main() {
	while (1) {
		int size;
		int *arr = initialize(size);
		cout<<"\nNumber of 1s in the array are: "<<countOnes(arr,size)<<"\n";
	}
}

int countOnes(int *arr, int n)
{
    int l=0;
    int r=n-1;
    int mid;
    //if (arr[0] == 0) return 0;
    //if (arr[n-1] == 1) return n;
    while (l<=r) {
        mid = l + (r-l)/2;
        if (arr[mid] == 1 && (mid==n-1 || arr[mid+1]==0)) {
            return mid+1;
        } 
        else if (arr[mid]==1)
        {
            l=mid+1;
        } else 
        {
            r=mid-1;
        }
    }
    
}

int* initialize(int &size) {
	
	cout<<"Enter size of array: ";
	cin>> size;
	int *arr = new int[size];
	
	cout<<"Enter "<<size<<" space separated integers to form the BINARY array: ";
	for (int i=0; i<size; i++) {
		cin>>arr[i];
	}
	
	cout<<"The entered array is :";
	for (int i=0; i<size; i++) {
		cout<<arr[i]<<" ";
	}
	
	return arr;
}
