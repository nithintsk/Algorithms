/*
Given an array arr[] of N positive integers, where elements are consecutive (sorted). Also, there is a single element which is repeating X (any variable) number of times. Now, the task is to find the element which is repeated and number of times it is repeated.

Input:
First line of input contains number of testcases T. For each testcase, first line of input contains number of elements in the array N. Next line contains the array elements.

Output:
For each testcase, there will be a single line containing the element which is repeated and the number of times it is repeated, seperated by space.

Constraints:
1 <= T <= 100
1 <= N <= 107
1 <= arr[i] <= 1015

Input:
2
5
1 2 3 3 4
5
2 3 4 5 5

Output:
3 2
5 2

Example:
Testcase 1: In the given array, 3 is occuring two times.
*/
#include <iostream>

using namespace std;

int find_repeated(int arr[], int l, int r)
{
    int mid = l + (r-l)/2;
    if (arr[mid] == arr[mid+1] || arr[mid] == arr[mid-1])
    {
        return arr[mid];
    }
    if (arr[mid] - arr[l] < mid-l)
    {
        find_repeated(arr,l,mid-1);
    } else find_repeated(arr,mid+1,r);
}

int main()
 {
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    int a[n];
	    for(int i=0;i<n;i++)
	    {
	        cin>>a[i];
	    }
	    int count=0,index=0;
	    count=n-(a[n-1]-a[0]);
	    cout<<find_repeated(a,0,n-1)<<" "<<count<<endl;
	}
	return 0;
}
