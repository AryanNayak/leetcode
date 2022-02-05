class Solution {
public:
    string minRemoveToMakeValid(string s) {
        
             set<int> indexToRemove; 
        stack<int> st; 
        
        
        for(int i = 0; i < s.size(); i++)
        {
            if(s[i] == '(')
            {
                st.push(i); 
            }else if(s[i] == ')')
            {
                if(st.empty())
                {
                    indexToRemove.insert(i); 
                }
                else
                {
                    st.pop(); 
                }
            }
        }
        
        while(st.empty() == false)
        {
            indexToRemove.insert(st.top()); 
            st.pop(); 
        }
        
        string ans = ""; 
        
        
        for(int i = 0 ; i < s.size(); i++)
        {
            if(!indexToRemove.count(i))
            {
                ans += s[i]; 
            }
        }
        
        return ans; 
    }
};