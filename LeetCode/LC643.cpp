class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {

        int n = nums.size();
        int temp, m = 0;
        vector<int> v;

        for(int i = 0; i < k; i++)
            m += nums[i];
        temp = m;
        for(int i = k; i < n; i++){
            temp = temp + nums[i] - nums[i-k];
            m = max(m, temp);
        }
        return (double)m/k;
    }
};