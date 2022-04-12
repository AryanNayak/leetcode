class Solution {
public:
    
    int prescedence(char ch)
    {
        if(ch == '*' || ch == '/')
        {
            return 3;
        } 
        else if(ch == '+' || ch == '-')
        {
            return 2; 
        }
        else
        {
            return 1; 
        }
    }
    
    
    int calc(char ch, int a, int b)
    {
        if(ch == '*')
        {
            return a*b; 
        }
        else if(ch == '/')
        {
            return b/a; 
        }
        else if(ch == '-')
        {
            return b - a; 
        }
        
        return a + b; 
    }
    int process(string s)
    {
        
        stack<int> stk; 
        
        for(int i = 0; i < s.size();)
        {
            if(s[i] == ',')
            {
                i++; 
                continue;
            }
            else if(s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/')
            {
                int a = stk.top(); 
                stk.pop(); 
                int b = stk.top(); 
                stk.pop(); 
                stk.push(calc(s[i], a, b)); 
                i++; 
            }
            else if(isalnum(s[i]))
            {
                string temp; 
                while(i < s.size() && isalnum(s[i]))
                {
                    temp = temp + s[i]; 
                    i++; 
                }
                stk.push(stoi(temp)); 
            }
            else
            {
                i++; 
            }
        }

        return stk.top(); 
    }
    int calculate(string s) {
        
        string postfix_expression = ""; 
        
        stack<char> stk; 
        
        for(int i =0; i < s.size(); )
        {
            char ch = s[i]; 
            if(isalnum(ch))
            {
                while(i < s.size() && isalnum(s[i]))
                {
                    postfix_expression += s[i]; 
                    i++; 
                }
                postfix_expression += ','; 
            }
            else if(ch == '(')
            {
                stk.push(ch); 
                i++; 
            }
            else if(ch == ')')
            {
                while(!stk.empty() && stk.top() != '(')
                {
                    postfix_expression += stk.top(); 
                    stk.pop(); 
                }
                stk.pop(); 
                i++; 
            }else
            {
                while(!stk.empty() && prescedence(stk.top()) >= prescedence(ch))
                {
                    postfix_expression += stk.top(); 
                    stk.pop(); 
                }
                stk.push(ch); 
                i++; 
            }
        }
        
        while(!stk.empty())
        {
            postfix_expression += stk.top(); 
            stk.pop(); 
        }
        
        int ans = process(postfix_expression); 
        return ans; 
    }
};