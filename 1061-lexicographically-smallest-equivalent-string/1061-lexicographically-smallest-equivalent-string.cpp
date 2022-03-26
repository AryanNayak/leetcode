class Solution {
public:
    vector<int> par; 
    int findPar(int u)
    {
        if(par[u] == u)
        {
            return u; 
        }        
        
        return par[u] = findPar(par[u]); 
        
    }
    
    string smallestEquivalentString(string s1, string s2, string baseStr) {
     
        for(int i = 0 ; i < 26; i++)
        {
            par.push_back(i); 
        }
        
        for(int i = 0; i < s1.length(); i++)
        {
            
            int p1 = findPar(s1[i] - 'a'); 
            int p2 = findPar(s2[i] - 'a'); 
            
            par[p1] = min(p1, p2); 
            par[p2] = min(p1, p2); 
            
        }
        
        
        string ans = ""; 
        
        
        for(int i = 0 ;i < baseStr.length(); i++)
        {
            
            ans += (char)(findPar(baseStr[i] - 'a') + 'a');
            
        }
        
        
        return ans; 
        
        
        
    }
};