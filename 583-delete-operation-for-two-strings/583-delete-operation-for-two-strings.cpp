class Solution {
public:
    
    int lcs(string& word1, string& word2, int n, int m, vector<vector<int>>& dp)
    {
        if(n == 0 || m == 0)
        {
            return dp[n][m] = 0; 
        }
    
        if(dp[n][m] != -1)
        {
            return dp[n][m]; 
        }
        
        
        if(word1[n - 1] == word2[m - 1])
        {
             dp[n][m] = 1 + lcs(word1, word2, n - 1, m - 1, dp); 
        }
        else
        {
            dp[n][m] = max(lcs(word1, word2, n - 1, m, dp), lcs(word1, word2, n, m - 1, dp)); 
        }
        
        return dp[n][m];   
    }
    int minDistance(string word1, string word2) {
        
        int n = word1.size(); 
        int m = word2.size(); 
        
        
        vector<vector<int>> dp(word1.size() + 1, vector<int>( word2.size() + 1, -1)); 
        
        
        lcs(word1, word2, n, m, dp); 
        
        int lcsLength = dp[n][m]; 
        
        return (n + m) - 2*lcsLength; 
        
    }
};