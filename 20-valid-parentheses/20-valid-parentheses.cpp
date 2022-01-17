class Solution {
public:
    bool isValid(string s) {
        
        stack<char> st; 


        for(auto c : s)
        {


                if(c == '(' || c == '{' || c == '[')
                {
                    st.push(c); 
                }
                else
                {


                    if(st.empty() == true)
                    {
                        return false; 
                    }

                    if(c == ')' && st.top() != '(')
                    {
                        return false; 
                    }


                    if(c == '}' && st.top() != '{')
                    {
                        return false; 
                    }


                    if(c == ']' && st.top() != '[')
                    {
                        return false; 
                    }

                    st.pop(); 

                }

        }

        return st.empty() == true; 
        
    }
};