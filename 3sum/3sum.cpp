class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        sort(nums.begin(), nums.end()); 
        
        vector<vector<int>> res; 
        for(int i = 0; i < nums.size() && nums[i] <= 0; i++)
        {
            
            if(i == 0 || nums[i] != nums[i -1 ])
            {
                twoSum(res, i, nums); 
            }
        }
        
        return res; 
    }
    
    void twoSum(vector<vector<int>>& res, int i, vector<int>& nums)
    {
     
        int low = i + 1, high = nums.size() - 1; 
        
        while(low < high)
        {
            
            int sum = nums[low] + nums[high] + nums[i]; 
            
            if(sum < 0)
            {
                low++; 
            }
            else if(sum > 0)
            {
                high--; 
            }
            else
            {
                
                res.push_back({nums[low++], nums[i], nums[high]}); 
                
                while(low < high && nums[low] == nums[low - 1])
                {
                    low++; 
                }
                
            }  
        }
        
        
    }
};