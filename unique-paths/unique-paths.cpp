class Solution {
public:
    int path(int sr, int sc, int er, int ec, vector<vector<int>>& dp)
    {
        
        if(sr == er && sc == ec)
        {
            return dp[sr][sc] = 1; 
        }
        
        
//         if(sr == er || sc == ec)
//         {
//             return dp[sr][sc] = 0; 
//         }
        
        
        if(dp[sr][sc] != -1)
        {
            return dp[sr][sc]; 
        }
        
        
        int count = 0; 
        
        if(sr + 1 <= er)
        {
            count += path(sr + 1, sc, er, ec, dp);     
        }
        
        if(sc + 1 <= ec)
        {
            count += path(sr, sc + 1, er, ec, dp); 
        }
        
        return dp[sr][sc] = count; 
        
    }

    int uniquePaths(int m, int n) {
        
        if(m == 0|| n == 0)
            return 0; 
        
        vector<vector<int>> dp(m  + 1, vector<int>(n + 1, -1)); 
        
        
        return path(0, 0, m - 1, n - 1, dp); 

    }
};