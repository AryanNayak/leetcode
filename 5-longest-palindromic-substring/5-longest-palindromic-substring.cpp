class Solution {
public:
    string longestPalindrome(string s) {
        
        int len = 0, start = 0; 
        
        for(int i = 0; i < s.size(); i++)
        {
            
            extend(s, i, i, len, start); 
            extend(s, i, i + 1, len, start); 
        }
        return s.substr(start, len); 
    }
    
    void extend(string& s, int left, int right, int& len, int& start)
    {
     
        while(left >= 0 && right <= s.size() - 1 && s[left] == s[right])
        {
            left--; 
            right++; 
        }
        
        
        if(right - left - 1 > len)
        {
            start = left + 1; 
            len = right - left - 1; 
        }
    }
};