/*

Given a string, find the length of the longest substring without repeating characters.

Example 1:

Input: "abcabcbb"
Output: 3 
Explanation: The answer is "abc", with the length of 3. 
Example 2:

Input: "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
Example 3:

Input: "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3. 

Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
             
*/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // complexity is n.
        // store the characters till a duplicate is encountered
        // calculate max and pop the first few elements until the duplicate value
        // end case --> loop doesn't encounter any duplicate
        
        deque<char> substr; 
        int max = 0;
        
        for (auto it = s.begin(); it != s.end(); it++) 
        {
            // check if the char is already a part of the keys in the map
            auto itr = std::find (substr.begin(), substr.end(), *it);
            if (itr == substr.end())
            {
                substr.push_back(*it);
            }
            else 
            {
                if (substr.size() > max)
                {
                    max = substr.size();
                }
                for (auto it1 = substr.begin(); it1 <= itr; it1++) 
                {
                    substr.pop_front();
                }
                substr.push_back(*it);
            }
        }
        
        if (substr.size() > max) {
            max = substr.size();
        }
        return max;
    }
        
};
