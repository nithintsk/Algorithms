/*
Given an integer x. The task is to find the square root of x. If x is not a perfect square, then return floor(vx).

Input Format:
First line of input contains number of testcases T. For each testcase, the only line contains the number x.

Output Format:
For each testcase, print square root of given integer.

User Task:
The task is to complete the function floorSqrt() which should return the square root of given number x.

Constraints:
1 = T = 1000
1 = x = 107

Example:
Input:
2
5
4

Output:
2
2

Explanation:
Testcase 1: Since, 5 is not perfect square, so floor of square_root of 5 is 2.
Testcase 2: Since, 4 is a perfect square, so its square root is 2.
*/
#include <iostream>

using namespace std;

long long int floorSqrt(long long int x) ;

int main() {
	while (1) {
		cout<<"Enter number whose square root has to be found: ";
		long long int x;
		cin>> x;
		cout<<"\nSquare root of "<<x<<" is: "<<floorSqrt(x)<<"\n";
	}
}

long long int floorSqrt(long long int x) 
{
    long long ans=0;
    long long start=0;
    long long end=x;
    long long mid=0;
    while (start <= end)
    {
        mid = start + (end-start)/2;
        if (mid*mid == x) 
        {
            return mid;
        }
        if (mid * mid < x)
        {
            ans = mid;
            start = mid + 1;
        }
        else
        {
            end = mid -1;
        }
    }
    return ans;
}
