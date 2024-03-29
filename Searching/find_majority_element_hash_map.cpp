/*
Given an array A of N elements. Find the majority element in the array. A majority element in an array A of size N is an element that appears more than N/2 times in the array.

Input:  
The first line of the input contains T denoting the number of testcases. The first line of the test case will be the size of array and second line will be the elements of the array.

Output: 
For each test case the output will be the majority element of the array. Output "-1" if no majority element is there in the array.

User Task:
The task is to complete the function findMajority() which finds the majority element in the array. If no majority exists, return -1.

Constraints:
1 <= T<= 100
1 <= N <= 107
0 <= Ai <= 106

Example:
Input:
2
5
3 1 3 3 2
3
1 2 3

Output:
3
-1

Explanation:
Testcase 1: Since, 3 is present more than N/2 times, so it is the majority element.
 
*/
#include <bits/stdc++.h> 
#include <iostream>

using namespace std;

int* initialize(int &);
int majorityElement(int a[], int size);

int main() {
	while (1) {
	int size;
	int *arr = initialize(size);
	cout<<"\nMajority element is "<<majorityElement(arr,size)<<"\n";
	}
}

int majorityElement(int a[], int size)
{
    
    unordered_map<int,int> hash;
    for (int i=0;i<size;i++)
    {
        hash[a[i]]++;
    }
    
    int max=0;
    int ans;
    
    for (auto it : hash)
    {
        if (it.second > max) 
        {
            max = it.second;
            ans = it.first;
        }
    }
    
    if (max > size/2) {
        return ans;
    } else {
        return -1;
    }
    
}

int* initialize(int &size) {
	
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
	
	return arr;
}
