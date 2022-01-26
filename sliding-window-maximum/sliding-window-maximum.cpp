class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        
        priority_queue<pair<int, int>, vector<pair<int, int>>> pq;
        
        int i = 0; 
        
        vector<int> ans; 
        
        for(int i = 0; i < nums.size(); i++)
        {
            
            while(pq.empty() == false && pq.top().second <= (i - k))
            {
                pq.pop(); 
            }
            
            pq.push({nums[i], i}); 
            
            
            if(i >= k - 1)
            {
                ans.push_back(pq.top().first); 
            }   
        }
        
        return ans;
        
    }
};