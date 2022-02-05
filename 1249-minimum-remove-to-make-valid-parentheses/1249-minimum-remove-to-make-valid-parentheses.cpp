class Solution {
public:
    string minRemoveToMakeValid(string s) {
        
        int open = 0; 
        string str = ""; 
        
        for(int i = 0 ;i < s.size(); i++)
        {
            if(s[i] == ')' && open == 0)
            {
                s[i] = '#'; 
            }
            if(s[i] == '(')
            {
                open++; 
            }
            else if(s[i] == ')')
            {
                open--; 
            }
        }
        
        
        for(int i = s.size() - 1; i >= 0; i--)
        {
            
            if(open > 0 && s[i] == '(' )
            {
                s[i] = '#'; 
                open--; 
            }
            
            if(open == 0)
            {
                break; 
            }   
        }
        
        
        for(int i = 0; i < s.size(); i++)
        {
            if(s[i] != '#')
            str += s[i]; 
        }
        
        return str; 
    }
};