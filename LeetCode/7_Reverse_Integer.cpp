// Problem 7 - Given a 32-bit signed integer, reverse digits of an integer.

class Solution {
public:
    int reverse(int x) {
        
        long y=0;
        while (x != 0) {
            y = y*10 + x%10;
            x=x/10;
        }
        if (y < INT_MAX && y > INT_MIN) 
            return (int)y;
        else return 0;

    }
};
