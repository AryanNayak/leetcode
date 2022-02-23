class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp; 
        
        for(int i = 0; i < nums.size(); i++)
        {
            int complement = target - nums[i] ; 
            
            if(mp.find(complement) != mp.end() && mp[complement] != i)
            {
                 // cout << i <<  mp[complement] << endl; 
                return {i, mp[complement]}; 
            }
            mp[nums[i]] = i; 
        }
        
        return {}; 
    }
};