// LeetCode 283.Move Zeros

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int index = 0, n = nums.size();
        for(int i = 0; i < n; i++){
            if(nums[i] != 0)
                nums[index++] = nums[i];
        }
        while(index < n)
            nums[index++] = 0;
    }
};