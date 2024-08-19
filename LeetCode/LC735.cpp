// LeetCode 735.Asteroid Collision

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> s;
        int t;
        bool stable;
        for(int i = 0; i < asteroids.size(); i++){
            stable = false;
            while(!stable){
                stable = true;
                if(s.empty())
                    s.push(asteroids[i]);
                else{
                    t = s.top();
                    if(s.top() < 0 || asteroids[i] > 0)
                        s.push(asteroids[i]);
                    else if((t + asteroids[i]) == 0) 
                        s.pop();
                    else{
                        if(abs(asteroids[i]) > abs(t))
                            s.pop(),stable = false;
                    }
                }
            }
        }
        vector<int> v(s.size());
        for(int i = s.size()-1; i >= 0 ; i--)
            v[i] = s.top(), s.pop();
        return v;
    }
};