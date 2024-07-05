// LeetCode 278.First Bad Version.

// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    long long int firstBadVersion(long long int n) {
        long long int l = 1, r = n+1, mid;
        while(l <= r){
            mid = l+(r-l)/2;
            cout << "mid is = " << mid << endl;
            if(isBadVersion(mid) && !isBadVersion(mid-1))
                break;
            if(isBadVersion(mid))
                r = mid-1;
            else
                l = mid+1;
        }
        return mid;
    }
};
