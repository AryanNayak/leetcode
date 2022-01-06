class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        
        unordered_map<int, int> mp; 
        mp[0]++;
        
        int cumulativeSum = 0; 
        int count = 0; 
        
        for(auto m : nums)
        {
            cumulativeSum += m; 
            
            count += mp[cumulativeSum - k]; 
            
            mp[cumulativeSum]++; 
        }
        
        return count; 
    }
};