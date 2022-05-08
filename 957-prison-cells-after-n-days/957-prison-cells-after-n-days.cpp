class Solution {
public:
    vector<int> prisonAfterNDays(vector<int>& cells, int n) {
        
        vector<int> temp(8); 
        vector<vector<int>> alreadySeenSets; 
        
        while(n--)
        {
            
            for(int i = 1; i < 7; i++)
            {
                
                temp[i] = cells[i -1] == cells[i + 1]; 
                
                
            }            
            
            
            if(alreadySeenSets.size() != 0 && alreadySeenSets.front() == temp)
            {
                
                return alreadySeenSets[n%alreadySeenSets.size()]; 
            
            }
            else
            {
                alreadySeenSets.push_back(temp); 
            }
            
            cells = temp; 
            
        }
        
        
        
        
        return cells; 
        
    }
};