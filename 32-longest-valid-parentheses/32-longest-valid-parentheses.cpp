class Solution {
public:
    int longestValidParentheses(string s) {
        
//         stack<int> st; 
//         st.push(-1);
//         int len = 0; 
        
//         for(int i = 0; i < s.length(); i++)
//         { 
//             if(st.top() != -1 && s[st.top()] == '(' && s[i] == ')')
//             {
//                 st.pop(); 
//                 len = max(len, i - st.top()); 
//             }
//             else
//             {
//                 st.push(i); 
//             }
//         }
//         return len; 
        
        
        int open = 0, close = 0, maxLen = 0; 
        
        for(int i = 0; i < s.size(); i++){
    
            if(s[i] == '(')
            {
                open++; 
            }
            else 
            {
                close++; 
            }
            
            if(open == close)
            {
                maxLen = max(maxLen, 2*close); 
            }
            else if(close >= open)
            {
                open = close = 0; 
            }
        }
        
        open = close =0 ; 
        for(int i = s.size() - 1; i >=0; i--)
        {
            
            if(s[i] == '(')
            {
                open++; 
            }
            else 
            {
                close++; 
            }
            
            if(open == close)
            {
                maxLen = max(maxLen, 2*open); 
            }
            else if(open >= close)
            {
                open = close = 0; 
            }
            
            
        }
        
        return maxLen; 
        
    }
};