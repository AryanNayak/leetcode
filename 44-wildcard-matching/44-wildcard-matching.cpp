class Solution {
public:
    int isMatchMemo(string& s, string& p, int n, int m, vector<vector<int>>& dp)
    {
     
        if(n == 0 || m == 0)
        {
            if(n == 0 && m == 0)
            {
                return dp[n][m] = 1; 
            }
            else if(m == 1 && p[m - 1] == '*')
            {
                return dp[n][m] = 1; 
            }
            return dp[n][m] = 0; 
        }
        
        
        if(dp[n][m] != -1)
            return dp[n][m]; 
        
        char ch1 = s[n - 1]; 
        char ch2 = p[m - 1]; 
        
        
        int val = -1; 
        
        if(ch1 == ch2 || ch2 == '?')
        {
            val = isMatchMemo(s, p, n - 1, m - 1, dp); 
        }
        else if(ch2 == '*')
        {
            
            bool res = false; 
            
            res = res || (isMatchMemo(s, p, n - 1, m, dp)== 1); 
            res = res || (isMatchMemo(s, p, n, m - 1, dp) == 1); 
            
            val = res ? 1 : 0;
            
        }
        else 
            val = 0; 
        
        
        return dp[n][m] = val; 
    }
    string removeStars(string& s)
    {
        
        if(s.length() == 0)
            return ""; 
        
        string sb; 
        
        sb += s[0]; 
        
        
        int i = 1; 
        
        while(i < s.length())
        {
            while(i < s.length() && s[i - 1] == '*' && s[i] == '*')
                i++; 
            
            if(i < s.length())
                sb += s[i]; 
            
        i++; 
        }
        return sb; 
    }
    bool isMatch(string s, string p) {
        
        p = removeStars(p); 
        
        cout << p << endl; 
        
        int n = s.length(); 
        int m = p.length(); 
        
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, - 1)); 
        return isMatchMemo(s, p, n, m, dp) == 1;
        
    }
};