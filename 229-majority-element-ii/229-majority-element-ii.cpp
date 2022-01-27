class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
    
        int nums1 = 0, nums2 = 0, count1 = 0, count2 = 0; 
        
        for(int i = 0; i < nums.size(); i++)
        {
            
            if(nums[i] == nums1)
            {
                count1++; 
            }
            else if(nums[i] == nums2)
            {
                count2++; 
            }
            else if(count1 == 0)
            {
                count1 = 1; 
                nums1 = nums[i]; 
            }
            else if(count2 == 0)
            {
                count2 = 1; 
                nums2 = nums[i]; 
            }
            else
            {
                count1--;
                count2--; 
            }
        }
        
        count1 =count2 = 0; 
        
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] ==   nums1)
            {
                count1++; 
            }
            else if(nums[i] == nums2)
            {
                count2++; 
            }
        }
        
        
        vector<int> ans; 
        
        if(count1 > nums.size()/3)
            ans.push_back(  nums1); 
        
        if(count2 > nums.size()/3)
            ans.push_back(nums2); 
        
        return ans; 
    }
};