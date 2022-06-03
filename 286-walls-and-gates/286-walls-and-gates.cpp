class Solution {
public:
    void wallsAndGates(vector<vector<int>>& grid) {
        
        
        int n = grid.size(); 
        
        int m = grid[0].size(); 
        
        vector<vector<int>> dir = {{0,-1}, {0, 1}, {1, 0}, {-1, 0}}; 
        
        queue<int> q;
        
        
        int countRooms = 0, distance = 0; 
        
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                
                if(grid[i][j] == 0)
                {
                    q.push(i*m + j);     
                }
                else if(grid[i][j] == 2147483647)
                    countRooms++;       
            }
        }
        
        
        while(!q.empty())
        {
            
            int count = q.size(); 
            
            
            for(int i = 0; i < count; i++)
            {
                
                int curr= q.front(); 
                q.pop(); 
                
                int r = curr/m; 
                int c = curr%m; 
                
                
                for(int d = 0; d < 4; d++)
                {
                    int x = r + dir[d][0]; 
                    int y = c + dir[d][1]; 
                    
                    
                    if(x >= 0 && y >= 0 && x < n && y < m && grid[x][y] == 2147483647)
                    {
                        
                        countRooms--; 
                        grid[x][y] = distance + 1; 
                        q.push(x*m + y); 
                        
                        // if(roomsCounter == 0)
                        // {
                        //     return; 
                        // }   
                    }                    
                }
            }
            distance++; 
        }
    
    }
};