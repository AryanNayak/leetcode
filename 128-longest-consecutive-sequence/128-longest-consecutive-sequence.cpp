class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        unordered_set<int> st(nums.begin(), nums.end()); 
        
        int i =0; 
        int n = nums.size(); 
        int len = 0;
        while(i < n)
        {
            
            if(st.find(nums[i] - 1) == st.end())
            {
                
                
                int streak = 1; 
                int currNum = nums[i]; 
                
                
                while(st.find(currNum + 1) != st.end())
                {
                    streak++; 
                    currNum++; 
                }
                
                
                len = max(streak, len); 
                
            }
            
            i++; 
        }
        
        return len; 
        
        
        
    }
};