class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        queue<string> q; 
        
        unordered_set<string> ht; 
        
        q.push(s); 
        
        vector<string> res; 
        
        while(q.empty() == false)
        {
            
            string ans = q.front(); 
            
            q.pop(); 
            
            
            if(ht.count(ans)){
                continue; 
            }
            
            
            ht.insert(ans); 
            
            if(isValid(ans))
            {
                res.push_back(ans); 
            }
            else if(res.empty())
            {
                
                for(int i = 0; i < ans.size(); i++){
                    
                    if(ans[i] == ')' || ans[i] == '(')
                    {
                        q.push(ans.substr(0, i) + ans.substr(i + 1)); 
                    }   
                }   
            }
        }
        
        
        return res;
        
    }
    bool isValid(string& s)
    {
        int count = 0; 
        for(auto c : s)
        {
            if(c == '(')
            {
                count++; 
            }
            if(c == ')')
            {
                if(count > 0)
                    count--; 
                else
                    return false; 
            }
            
        }
        
        return !count; 
        
    }
    
    
};