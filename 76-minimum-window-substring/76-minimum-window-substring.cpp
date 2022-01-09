class Solution {
public:
    string minWindow(string s, string t) {
        
        vector<int> freq(128, 0); 
        
        for(auto m : t)
        {
            freq[m]++; 
        }
        
        
        int n = s.size(); 
        
        
        int release = t.size(); 
        
        
        int left = 0, right = 0; 
        
        int minStart = 0, minLen = INT_MAX; 
        
        while(right < n)
        {
            
            if(--freq[s[right]] >= 0)
            {
                release--; 
            }
            
            right++; 
            
            
            while(release == 0)
            {
                if(right - left < minLen)
                {
                    minLen = right - left; 
                    minStart = left; 
                }
                
                if(++freq[s[left]] >  0)
                {
                    release++; 
                }
                left++;
            }  
        }
        
        return minLen  < INT_MAX ? s.substr(minStart, minLen) : ""; 
    }
};