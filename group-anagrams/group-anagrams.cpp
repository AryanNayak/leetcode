class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        unordered_map<string, vector<string>> mp; 
        
        for(auto m : strs)
        {
            
            string c = m; 
            
            sort(c.begin(), c.end()); 
            
            mp[c].push_back(m); 
        }
        
        
        vector<vector<string>> ans; 
        
        for(auto m : mp)
        {
            ans.push_back(m.second); 
        }
        
        return ans; 
        
    }
};