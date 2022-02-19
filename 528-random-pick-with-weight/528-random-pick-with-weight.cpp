class Solution {
    vector<int> s; 
public:
    Solution(vector<int>& w) {
        
        for(auto m : w)
        {
            if(s.empty())
            {
                s.push_back(m); 
            }
            else
            {
                s.push_back(m + s.back());     
            }
        }
    }
    
    int pickIndex() {
        
        int x = s.back(); 
        
        int index = rand() % x;
        auto it = upper_bound(s.begin(), s.end(), index); 
        return it - s.begin(); 
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */