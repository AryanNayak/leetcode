class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        
        
        if(grid.size() == 0 || grid[0].size() == 0)
        {
            return -1; 
        }
        
        
        int n  = grid.size(), m = grid[0].size(); 
        
                
        if(grid[0][0] == 1 || grid[n-1][n-1] == 1)
            return -1; 
        
        
        vector<vector<int>> dir = {{0, 1}, {1, 0}, {0,-1}, {-1, 0}, {-1, -1}, {1, 1}, {1, -1}, {-1, 1}}; 
        
        
        queue<int> q; 
        grid[0][0] = 1; 
        
        q.push(0*m + 0); 
        
        int level = 1; 
        
        while(q.empty() == false)
        {
            
            
            int count =  q.size(); 
            
            
            for(int i = 0; i < count; i++)
            {
                
                int curr =q.front(); 
                q.pop(); 
                
                
                int r = curr/m; 
                int c = curr%m; 
                
                
                if(r == n - 1 && c == m - 1)
                {
                    return level; 
                }
                
                
                for(int d = 0; d < dir.size(); d++)
                {
                    
                    
                    int x = r + dir[d][0]; 
                    int y = c + dir[d][1]; 
                    
                    
                    
                    if(x < n && y < m && x >= 0 && y >= 0 && grid[x][y] == 0)
                    {
                        
                        grid[x][y] = 1; 
                        q.push(x*m + y); 
                    }
                    
                }
                 
            }
                
            level++; 
            
        }
        
        
        
        
        
        
        return -1; 
        
    }
};