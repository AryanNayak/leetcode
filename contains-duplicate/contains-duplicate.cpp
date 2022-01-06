class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        
//         set<int> st; 
        
//         for(int i = 0; i < nums.size(); i++)
//         {
//             if(st.find(nums[i]) != st.end())
//             {
//                 return true;
//             }
//             else
//             {
//                 st.insert(nums[i]); 
//             }
//         }
        
//         return false; 
        
        
        sort(nums.begin(), nums.end()); //sorting -> ascending 

        for (int i = 0; i < nums.size() -1; i++){
            if (nums[i] == nums[i+1]){
                return true;
            }
        }
        return false; 

    }
};