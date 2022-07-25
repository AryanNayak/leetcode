class Solution {
    public int[] searchRange(int[] nums, int target) {
                
        int left = bSearchL(nums, target); 
        int right = bSearchR(nums, target);
        int arr[] = new int[2];
        arr[0] = left; 
        arr[1] = right; 
        return arr; 
    }
    
    int bSearchL(int[] nums, int target)
    {
        int low = 0, high = nums.length - 1; 
        
        while(low <= high)
        {
            
            int mid = (low + high)/2; 
            
            
            if(nums[mid] < target){
                low = mid + 1; 
            }
            else if(nums[mid] > target)
            {
                high = mid - 1; 
            }
            else
            {
                
                if(mid == 0 || nums[mid] != nums[mid - 1])
                {
                    return mid; 
                }
                else
                {
                    high = mid - 1; 
                }
            }
        }
        return -1; 
     
        
    }
    int bSearchR(int[] nums, int target)
    {
        
        int low = 0, high = nums.length - 1; 
        
        while(low <= high)
        {
            
            int mid = (low + high)/2; 
            
            
            if(nums[mid] < target){
                low = mid + 1; 
            }
            else if(nums[mid] > target)
            {
                high = mid - 1; 
            }
            else
            {
                
                if(nums.length - 1  == mid || nums[mid] != nums[mid + 1])
                {
                    return mid; 
                }
                else
                {
                    low = mid + 1; 
                }
            }
        }
        return -1; 
        
    }
}
