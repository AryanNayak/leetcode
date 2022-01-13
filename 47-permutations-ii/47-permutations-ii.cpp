class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        
        sort(nums.begin(), nums.end()); 
        vector<vector<int>> perm; 
        
        permute(nums, 0, perm); 
        
        return perm;    
    }
    void permute(vector<int> nums, int i, vector<vector<int>>& perm)
    {
        if(i == nums.size())
        {
            perm.push_back(nums); 
            return; 
        }   
        
        for(int j = i; j < nums.size(); j++)
        {
            
            if(j == i || nums[i] != nums[j])
            {
                swap(nums[i], nums[j]); 
                permute(nums, i + 1, perm); 
                
            }
        }
        
       
    }
};