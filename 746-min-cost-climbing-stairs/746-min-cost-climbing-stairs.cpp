class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        
        if(cost.size() == 0)
        {
            return 0; 
        }
        int n = cost.size(); 
        
        vector<int> dp(n + 1, -1); 
        
        return min(minCost(cost, dp, 0), minCost(cost, dp, 1)); 
    }
    
    int minCost(vector<int>& cost, vector<int>& dp, int start)
    {
     
        if(start >= cost.size())
        {
            return 0; 
        }
        
        if(dp[start] != -1)
        {
            return dp[start]; 
        }
         
        return dp[start] = cost[start] + min(minCost(cost, dp, start + 1), minCost(cost, dp, start + 2)); 
    }

    
};