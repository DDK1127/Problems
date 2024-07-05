// LeetCode 88.Merge Sorted Array

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int mm = m-1, nn = n-1;
        for(int i = m+n-1; i >= 0; i--){
            if(mm >= 0 && nn >= 0){
                if(nums1[mm] >= nums2[nn])
                    nums1[i] = nums1[mm--];
                else
                    nums1[i] = nums2[nn--];
            }
            else if(mm < 0)
                nums1[i] = nums2[nn--];
            else if(nn < 0)
                nums1[i] = nums1[mm--];

        }
    }
};
