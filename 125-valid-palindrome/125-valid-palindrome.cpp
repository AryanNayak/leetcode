class Solution {
public:
    bool isPalindrome(string s) {
        
        string p = ""; 
        
        for(auto c : s)
        {
            if(isalnum(c)) // if(isChar.Digit(s[i]) &&& isChar.Letter(s[i]))
            {
                p += tolower(c);  // p += tolowercase(s[i])
            }
        }
        
        
        int i = 0, j = p.size() -1; 
        
        while(i < j)
        {
            if(p[i] != p[j])
            {
                return false; 
            }
            i++; 
            j--; 
        }
        
        return true; 
        
    }
};