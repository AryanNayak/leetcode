class Solution {
public:
    string longestPalindrome(string s) {
                
        int count = 0; 
        int n = s.length(); 
        vector<vector<bool>> dp(n, vector<bool>(n, false)); 
        
        int start = 0; 
        int len = 0; 
        
        for(int g = 0 ; g < n; g++)
        {
            for(int i = 0, j = g; j < n; j++, i++)
            {
                
                if(g == 0)
                {
                    dp[i][j] = true; 
                }
                else if(g == 1)
                {
                    if(s[i] == s[j])
                    {
                        dp[i][j] = true;
                    }
                    else
                    {
                        dp[i][j] = false; 
                    }
                }
                else
                {
                    if(s[i] == s[j] && dp[i + 1][j - 1] == true)
                    {
                        dp[i][j] = true; 
                    }
                    else
                    {
                        dp[i][j] = false; 
                    }
                }
                
                if(dp[i][j] == true)
                {
                    len = g + 1; 
                    start = i; 
                }
                    
            }
        }
        
            
        return s.substr(start, len); 
    }
};

