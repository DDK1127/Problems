// LeetCode 53. Maximum Subarray
// Time complexity: O(n)
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int r = nums[0], Max = nums[0];
        for(int i = 1; i < nums.size(); i++){
            nums[i] > r+nums[i] ? r = nums[i] : r+= nums[i];
            if(Max < r) Max = r;
        }
        return Max;
    }
};