class Solution {
public:
    int lengthOfLongestSubstring(string s) {
            
        set<char> st; 
        
        int i = 0, j = 0; 
        
        int n = s.size(); 
        
        int ans = 0; 
        
        while(i < n && j < n)
        {
            
            if(st.find(s[i]) == st.end())
            {
                st.insert(s[i++]); 
                ans = max(ans, i- j); 
            }
            else
            {
                st.erase(s[j++]); 
            }
        }
        return ans; 
    }
};