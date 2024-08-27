// LeetCode 374.Guess Number Higher or Lower

/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        int l = 1, r = n;
        int m = n, p = guess(m);
        while(p != 0){
            if(p == 1)
                l = m;
            else if(p == -1)
                r = m;
            m = l+(r-l)/2;
            p = guess(m);
        }        
        return m;
    }
};