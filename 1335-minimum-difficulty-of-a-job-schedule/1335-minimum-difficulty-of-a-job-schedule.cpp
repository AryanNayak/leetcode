class Solution {
public:
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        if(d > jobDifficulty.size())
        {
            return -1; 
        }
        
        vector<vector<int>> dp(d + 1, vector<int>(jobDifficulty.size(), -1)); 

        return dfs(jobDifficulty, d, dp, 0); 
    }
    
    int dfs(vector<int>& jobDifficulty, int d, vector<vector<int>>& dp, int idx)
    {
        if(d == 1)
        {
            int maxi = 0; 
            while(idx < jobDifficulty.size())
            {
                maxi = max(maxi, jobDifficulty[idx++]); 
            }
            return maxi; 
        }
        
        if(dp[d][idx] != -1)
        {
            return dp[d][idx]; 
        }
        
        int maxi= 0; 
        int res = INT_MAX;
        for(int i = idx; i < jobDifficulty.size() - d + 1; i++)
        {
            maxi = max(maxi, jobDifficulty[i]); 
            res = min(res, maxi + dfs(jobDifficulty, d - 1, dp, i + 1)); 
        }
        
        return dp[d][idx] = res;
    }
};