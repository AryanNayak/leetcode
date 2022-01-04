class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        sort(nums.begin(), nums.end()); 
        
        vector<vector<int>> ans; 
        for(int i = 0; i < nums.size() && nums[i] <= 0; i++)
        {
            if(i == 0 || nums[i] != nums[i - 1])
            {
                twoSumSearch(nums, i, ans); 
            }
        }
        
        
        return ans; 
    }
    
    void twoSumSearch(vector<int>& nums, int i, vector<vector<int>>& ans)
    {
        
        unordered_set<int> mp; 
        
        for(int j = i + 1; j < nums.size(); j++)
        {
            int complement = - nums[i] - nums[j]; 
            
            if(mp.count(complement))
            {
                ans.push_back({nums[i], nums[j], complement});
                
                while(j + 1 < nums.size() && nums[j] == nums[j + 1])
                {
                    j++; 
                }
            }
            
            mp.insert(nums[j]); 
        }
        
        
    }
    
    
};