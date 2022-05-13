class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time)
    {
        vector<int> mp(60); 
    
        int res = 0; 
        
        for(auto t : time)
        {
            if(t%60 == 0)
            {
                res += mp[0];
            }
            else
            {
                res += mp[60 - t%60]; 
            }
            
            mp[t%60]++; 
        }
        
        
        for(auto m : mp)
            cout << m << endl;
        
        return res; 
        
        
        
        
    }
};