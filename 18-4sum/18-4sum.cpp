class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        
        sort(nums.begin(), nums.end()); 
        
        vector<vector<int>> ans; 
        
        for(int i = 0; i < nums.size(); i++)
        {
            for(int j = i + 1; j < nums.size(); j++)
            {
                
                int l = j + 1, r = nums.size() - 1; 
                
                int remaining = target - nums[i] - nums[j]; 
                
                
                while(l < r)
                {
          
                    if(nums[l]+nums[r] == remaining)
                    {
                        ans.push_back({nums[i], nums[j], nums[l], nums[r]}); 
                        ++l;
                        while(l  < r && nums[l] == nums[l - 1])
                            l++; 
                    }
                    else if(nums[l] + nums[r] > remaining)
                    {
                        r--; 
                    }
                    else 
                    {
                        l++; 
                    }
                }
                
                while(j + 1 < nums.size() && nums[j] == nums[j + 1])
                    j++; 
                
            }
            while(i + 1 < nums.size() && nums[i] == nums[i + 1])
                i++; 
        }
        
        return ans; 
        
    }
};