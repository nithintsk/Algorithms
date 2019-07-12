/*
Given a sorted array arr[] of size N without duplicates, and given a value x. Find the floor of x in given array. Floor of x is defined as the largest element K in arr[] such that K is smaller than or equal to x.

Input:
First line of input contains number of testcases T. For each testcase, first line of input contains number of elements in the array and element whose floor is to be searched. Last line of input contains array elements.

Output:
Output the index of floor of x if exists, else print -1.

User Task:
The task is to complete the function findFloor() which finds the floor of x.

Constraints:
1 = T = 100
1 = N = 107
1 = arr[i] = 1018
0 = X = arr[n-1]

Example:
Input:
3
7 0
1 2 8 10 11 12 19
7 5
1 2 8 10 11 12 19
7 10
1 2 8 10 11 12 19

Output:
-1
1
3

Explanation:
Testcase 1: No element less than 0 is found. So output is "-1".
Testcase 2: Number less than 5 is 2, whose index is 1(0-based indexing).
*/

#include <bits/stdc++.h> 
#include <iostream>

using namespace std;

int findFloor(vector<long long> v, long long x);

int main() {
	while (1) {
	
		int size;
		cout<<"Enter size of array: ";
		cin>> size;
	
		vector <long long> v;
		cout<<"Enter "<<size<<" space separated integers : ";
		long long temp;
		for (int i=0; i<size; i++) {
			cin>>temp;
			v.push_back(temp);
		}
	
		cout<<"The entered array is :";
		for (int i=0; i<size; i++) {
			cout<<v[i]<<" ";
		}
		
		long long x;
		cout<<"\nEnter the element for which the floor needs to be found :";
		cin>>x;
		int ans = findFloor(v,x);
		if (ans == -1) {
			cout<<"\nMajority element is not found!";
		} else
		cout<<"\nMajority element is "<<v[ans]<<"\n";
	}
}

int findFloor(vector<long long> v, long long x){
    
    int l = 0;
    int n=v.size();
    int r = n-1;
    int mid;
    if (x < v[l]) return -1;
    while (l<=r) {
        mid = l + (r-l)/2;
        if ((mid == n-1 && v[mid] <= x) || x >= v[mid] && x < v[mid+1])
        {
            return mid;
        }
        if ( x < v[mid] ) r = mid-1;
        else l = mid+1;
    }
}

