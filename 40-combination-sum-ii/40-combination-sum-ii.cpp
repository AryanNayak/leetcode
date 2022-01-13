class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        
        sort(candidates.begin(), candidates.end()); 
        
        
        vector<vector<int>> subs; 
        vector<int> sub; 
        solve(candidates, subs, sub, target, 0); 
        
        return subs; 
        
    }
    
    void solve(vector<int>& candidates, vector<vector<int>>& subs, vector<int>& sub, int target, int i)
    {
        
        if(target == 0)
        {
            subs.push_back(sub); 
            return ; 
        }
        
        for(int j = i; j < candidates.size() && target >= candidates[j]; j++)
        {
            
            if(j == i || candidates[j] != candidates[j - 1])
            {
                
                sub.push_back(candidates[j]); 
                solve(candidates, subs, sub, target - candidates[j], j + 1); 
                sub.pop_back();
                
            }            
        }
  
    }
};