class Solution {
public:
    vector<int> partitionLabels(string s) {
        
        vector<int> arr(26, 0); 
        
        for(int i = 0; i < s.size(); i++)
        {
            arr[s[i] - 'a'] = i;
        }
        
        
        int n = s.size(); 
        int i = 0; 
        int end = 0; 
        
        vector<int> res; 
        
        while(i < n)
        {
            
            int j = i; 
            
            int end = arr[s[i] - 'a']; 
            
            
            while(j != end)
            {
                
                end = max(end, arr[s[j++] -'a']);
                
            }
            
            
            res.push_back(j - i + 1); 
            
            
            i = j + 1; 
            
        }
        
        return res; 
        
        
        
        
    }
};