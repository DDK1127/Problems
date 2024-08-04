// LeetCode 1480.Running Sum of 1d Array

class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int> result;
        result.push_back(nums[0]);
        for(int i = 1; i < nums.size(); i++)
            result.push_back(result[i-1]+nums[i]);
        return result;
    }
};