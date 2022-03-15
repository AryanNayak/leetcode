class Solution {
public:
    int edit(string& s1, string& s2, int n, int m, vector<vector<int>>& dp)   
    {
        if(n == 0 || m == 0)
        {
             dp[n][m] = n == 0 ? m : n;
        }
        
        
        if(dp[n][m] != -1)
        {
            return dp[n][m]; 
        }
        
        int insert = edit(s1, s2, n - 1, m, dp); 
        int dele = edit(s1, s2, n , m - 1, dp); 
        int replace = edit(s1, s2, n - 1, m - 1, dp); 
        
        if(s1[n - 1] == s2[m - 1])
        {
            return dp[n][m] = replace; 
        }
        else
        {
            return dp[n][m] = 1 + min({replace, insert, dele}); 
        }
        
        return dp[n][m]; 
    }
    int minDistance(string word1, string word2) {
        int n = word1.size(); 
        int m = word2.size(); 
        
        vector<vector<int>> dp(n + 1, vector<int>( m + 1, -1)); 
        
        return edit(word1, word2, n, m, dp); 
    }
};