class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        sort(intervals.begin(), intervals.end()); 
        
        
        vector<vector<int>> merged; 
        
            
        for(auto m : intervals)
        {
            
            if(merged.empty() || merged.back()[1] < m[0])
            {
                merged.push_back(m); 
            }
            else
            {
               merged.back()[1] = max(merged.back()[1], m[1]);
            }
    
        }
        return merged;         
        
    }
};