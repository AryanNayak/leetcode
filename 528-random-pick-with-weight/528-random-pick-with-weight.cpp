class Solution {
private: 
    vector<int> s; 
public:
    Solution(vector<int>& w) {
        
        for(int i = 0; i < w.size(); i++)
        {
            if(s.empty())
            {
                s.push_back(w[i]); 
            }
            else
            {
                s.push_back(w[i] + s.back()); 
            }
        }
        
    }
    
    int pickIndex() {
        
        int x = s.back(); 
        
        int findVal = rand()%x; 
        
        auto it = upper_bound(s.begin(), s.end(), findVal); 
        
        
        return it - s.begin(); 
        
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */