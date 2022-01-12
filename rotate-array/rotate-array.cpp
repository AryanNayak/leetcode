class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        
        int n = nums.size(); 
        
        k = k%nums.size(); 
             
        // cout << (0 +k)%n << endl; 
        
        reverse(nums.begin(), nums.end()); 
        reverse(nums.begin(), nums.begin() + k%n); 
        reverse(nums.begin() + k%n, nums.end()); 
        
   
        
    }
};