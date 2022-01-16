class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int minPrice = INT_MAX; 
        
        int maxProfit = 0; 
        
        for(int i = 0; i < prices.size(); i++)
        {
            
            if(minPrice > prices[i])
            {
                minPrice = min(prices[i], minPrice);
            }
                
            if(maxProfit < prices[i] - minPrice)
            {
                    maxProfit = prices[i] - minPrice; 
            }
        }
        
        return maxProfit; 
    }
};