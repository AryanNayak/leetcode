class Solution {
public:
    bool winnerOfGame(string s) {
        
        map<char, int> mp; 
        
        
        for(int i =  1; i < s.size(); i++)
        {
            if(s[i] == 'A')
            {
                if(s[i - 1]  == 'A' && s[i + 1] == 'A')
                {
                    mp['A']++; 
                }
            }
            else   if(s[i] == 'B')
            {
                if(s[i - 1]  == 'B' && s[i + 1] == 'B')
                {
                    mp['B']++; 
                }
            }
        }
        
        bool res = true; 
        while(mp['A'] > 0 && mp['B'] > 0)
        {
            if(res)
            {
                mp['A']--; 
                
                if(mp['A'] == 0)
                {
                    return false; 
                }
            }
            else
            {
                mp['B']--;
                if(mp['B'] == 0)
                {
                    return true; 
                }
            }
            res = !res; 
        }
        
        if(mp['B'] == 0 && mp['A'] != 0)
        {
            return true; 
        }
    
        return false;     
    }
};