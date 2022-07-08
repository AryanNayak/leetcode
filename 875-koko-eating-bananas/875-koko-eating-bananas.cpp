class Solution {
public:
    bool isPossible(vector<int>& piles, int h, int k)
    {
        int time = 0; 
        
        for(auto m : piles)
        {
            time += (m - 1 )/ k + 1;
        }
        
        return time <= h; 
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        
        int maxi = INT_MIN; 
        for(auto m : piles)
        {
            maxi = max(maxi, m); 
        }
  
        int low = 1, high =maxi;  
        
        while(low < high)
        {
            
            int mid = low + (high - low)/2; 
            
            
            if(!isPossible(piles, h, mid))
            {

                low = mid + 1; 
                
            }            
            else
            {
                high = mid; 
            }
        }
        
        return low; 
    }
};