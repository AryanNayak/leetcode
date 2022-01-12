class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        
        vector<vector<int>> perm; 
        
        combine(nums, 0, perm); 
        
        return perm;
        
    }
    
    void combine(vector<int> nums, int idx, vector<vector<int>>& perm)
    {
        if(idx == nums.size())
        {
            perm.push_back(nums); 
            return ; 
        }
        
        for(int j = idx; j < nums.size(); j++){
            swap(nums[idx], nums[j]); 
            combine(nums, idx + 1, perm); 
        }
           
    }
};