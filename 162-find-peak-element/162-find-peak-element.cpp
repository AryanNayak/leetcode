class Solution {
public:
  int findPeakElement(vector<int>& nums) {
        int l = 0, r = nums.size();

        int ans = 0;
        while(l <= r){
            int mid = l + (r - l) / 2;
            if(mid + 1 < nums.size() and nums[mid] < nums[mid + 1])
                l = mid + 1;
            else if(mid - 1 >= 0 and nums[mid] < nums[mid - 1])
                r = mid - 1;
            else{
        return mid;
            }
        }
        return ans;
    }
};