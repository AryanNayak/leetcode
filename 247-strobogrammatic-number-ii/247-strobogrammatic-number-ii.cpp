class Solution {
public:
    vector<string> findStrobogrammatic(int n) {
        
        return helper(n, n); 
        
    }
    
    vector<string> helper(int n, int m)
    {
        
        if(n == 0)
        {
            return {""}; 
        }
        
        if(n == 1)
        {
            return {"1", "0", "8"}; 
        }
        
        
        vector<string> list = helper(n - 2, m); 
        
        
        vector<string> res; 
        
        
        for(int i = 0; i < list.size(); i++)
        {
            
            
            string s = list[i]; 
            
            if(n != m)
            {
                res.push_back("0" + s + "0"); 
            }
            
            res.push_back("1" + s + "1"); 
            res.push_back("6" + s + "9"); 
            res.push_back("8" + s + "8"); 
            res.push_back("9" + s + "6"); 
        }
        
        return res; 
           
    }  
};