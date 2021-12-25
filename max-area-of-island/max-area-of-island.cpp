class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        
        int n = grid.size(); 
        int m = grid[0].size(); 
        
        if(n == 0 || m == 0)
            return 0; 
        
     
        int maxArea = 0; 
        for(int i = 0; i < grid.size(); i++)
        {
            for(int j = 0; j < grid[i].size(); j++)
            {
                int ans = 0; 
                if(grid[i][j] == 1)
                {
                dfs(grid, i, j, ans); 
                maxArea = max(ans, maxArea); 
                }
                
                
            }
        }
            
        return maxArea; 
    }
    
    void dfs(vector<vector<int>>& grid, int i, int j, int& ans)
    {
            
        if(i < 0 || j < 0 || i > grid.size() - 1 || j > grid[0].size() - 1 || grid[i][j] == 0)
            return ; 
        
            grid[i][j] = 0;     
        
            ans++; 
            dfs(grid, i + 1, j ,ans); 
            dfs(grid, i - 1, j , ans); 
            dfs(grid, i, j + 1, ans); 
            dfs(grid, i, j - 1, ans); 


    }    
   
};