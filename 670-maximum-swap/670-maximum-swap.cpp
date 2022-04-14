class Solution {
public:
    int getMax(string s, int i)
    {
        int max = i; 
        for(int j = i; j < s.size(); j++)
        {
            if(s[max] <= s[j])
            {
                max = j; 
            }
        }
        return max; 
    }    
    int maximumSwap(int num) {
        string s = to_string(num); 
        string s1 = s; 
        
        for(int i = 0; i < s.size(); i++)
        {
            int temp = getMax(s, i); 
            swap(s[i], s[temp]); 
            if(s != s1)
            {
                break; 
            }
        }
        int number = stoi(s);
        return number; 
    }
};