class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        
        if(matrix.size() == 0){
            return 0; 
        }
        
        int n = matrix.size(); 
        int m = matrix[0].size(); 
        
        
        vector<vector<int>> dp(n, vector<int>(m, 0)); 
        
        int ans = 0; 
        
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(!i || !j  || matrix[i][j] == '0')
                {
                    dp[i][j] = matrix[i][j] - '0'; 
                }
                else
                {
                    dp[i][j] = 1 + min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]}); 
                }
                ans = max(ans, dp[i][j]);
            }
        
        }
        
        return ans*ans; 
        
    }
};