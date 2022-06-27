class Solution {
public:
    int minPartitions(string n) {
        
        int maximum = 0; 
        
        
        for(auto c : n)
        {
            
            maximum = max(c - '0', maximum); 
            
        }
        
        
        return maximum; 
        
        
        
    }


};