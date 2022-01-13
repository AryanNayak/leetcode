class Solution {
public:
    
    //[[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
    
    vector<vector<int>> permute(vector<int>& nums) {
        //order doesn't matter -> we need all orders -> not sorting that's why 
        
        vector<vector<int>> perm; //final ans 
        
        combine(nums, 0, perm); 
        
        return perm;   
    }
    //LOGIC WAS 
    //TO KEEP ONE ELEMENT STATIONARY -> GENERATE ALL THE POSSIBLE COMBINATION 
    
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