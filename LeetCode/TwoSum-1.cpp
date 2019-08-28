/*

Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

Example:

Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].

*/

class Solution {
public:
	
	// Method 1 - Brute Force O(n^2)
    vector<int> twoSum(vector<int>& nums, int target) {
        
        vector<int> result{0, 0};
        for (auto it = nums.begin(); it != nums.end()-1; it++)
        {
            for (auto it1 = it+1; it1 != nums.end(); it1++) 
            {
                if ((*it) + (*it1) == target) {
                    vector <int> result;
                    result.push_back(it - nums.begin());
                    result.push_back(it1 - nums.begin());
                    return result;
                }
            }
        }
        return result;
    }
    
    // Method 2 - Using Hash maps where searching is O(1)
	// Time Complexity - O(n) && Space Complexity O(n)
    vector<int> twoSum(vector<int>& nums, int target) {
        
        vector <int> result;
        map<int,int> array_map;
        for (auto it = nums.begin(); it!=nums.end(); it++)
        {
        	array_map[*it] = it - nums.begin();
        }
        map<int, int>::iterator it;
        for (it = array_map.begin(); it != array_map.end(); it++)
        {
        	int difference = target - it->first;
        	map<int,int>::iterator itr = array_map.find(difference);
        	if (itr != it) {
        		result.push_back(it->second);
                result.push_back(itr->second);
        		return result;
			}
		}
        return result;
    }
    
};

