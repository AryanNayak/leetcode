class Solution {
public:
    string breakPalindrome(string palindrome) {
    
    
        int n = palindrome.length(); 
        
        if(n < 2)
            return ""; 
        
        
        for(int j = 0; j < n/2; j++)
        {
            if(palindrome[j] != 'a')
            {
                palindrome[j] = 'a'; 
                return palindrome; 
            }
        }
        
        palindrome[n-1] = 'b'; 
        return palindrome; 
        
        
        
        
        
        
        
    }
};