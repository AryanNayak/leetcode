class Solution {
public:
    string minRemoveToMakeValid(string s) {
        
        set<int> st; 
        
        stack<int> stk; 
        
        for(int i =0; i < s.size(); i++)
        {
            if(s[i] == '(')
            {
                stk.push(i); 
            }
            if(s[i] == ')')
            {
                if(stk.empty())
                {
                    st.insert(i); 
                }
                else
                {
                    stk.pop(); 
                }
            }
        }
        
        
        while(stk.size() != 0)
        {
            st.insert(stk.top()); 
            stk.pop(); 
        }
        
        string ans = ""; 
        for(int i= 0; i < s.size(); i++)
        {
            if(st.find(i) == st.end())
            {
                ans += s[i]; 
            }
        }
        
        return ans; 
        
    }
};