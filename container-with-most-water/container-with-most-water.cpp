class Solution {
public:
    int maxArea(vector<int>& height) {
        
        int i = 0, j = height.size() - 1; 
        
        int res = 0; 
        
        while(i < j)
        {
            
            int minHeight = min(height[i], height[j]); 
            
            res = max(res, minHeight*(j - i)); 
            
            if(height[i] < height[j])
            {
                i++; 
            }
            else
            {
                j--; 
            }
            
        }
        
        return res; 
    }
};