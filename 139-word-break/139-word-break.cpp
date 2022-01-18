class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        
        int n = s.size(); 
        vector<bool> dp(n + 1); 
        
        dp[0] = true; 
        
        
        for(auto c : dp)
            cout << c << endl; 
        
        
        cout << " " << endl; 
        
        
        set<string> st(wordDict.begin(), wordDict.end()); 
        
        for(int i = 1; i <= n; i++)
        {
            for(int j = 0; j < i; j++)
            {
                
                if(dp[j] == true && st.find(s.substr(j, i- j)) != st.end())
                {
                    dp[i] = true;
                    break; 
                }
            }
        }
        
        
                
        for(auto c : dp)
            cout << c << endl; 
        
        return dp[n]; 
    }
};