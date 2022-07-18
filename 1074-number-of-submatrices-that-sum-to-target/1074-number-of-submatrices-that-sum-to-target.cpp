class Solution {
public:
    int checksubmatrix(vector<vector<int>>& matrix, int r1, int r2, int target)
    {
     
        unordered_map<int, int> mp; 
        
        mp[0] = 1; 
        
        int ans = 0; 
        int curr = 0; 
        
        
        for(int i = 0; i < matrix[0].size(); i++)
        {
            
            if(r1 > 0)
            {
                curr += matrix[r2][i] - matrix[r1-1][i]; 
            }
            else
                curr += matrix[r2][i]; 
            
            if(mp.find(curr - target) != mp.end())
                ans += mp[curr - target]; 
            
            
            mp[curr]++; 
        }

        return ans; 
        
    }
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target)
    {
        
                ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

    
        int n = matrix.size(), m = matrix[0].size(); 
        
        if(n == 0 || m == 0)
            return 0; 
        
        
        for(int i = 0; i < n; i++ )
        {
            for(int j = 0; j < m; j++)
            {
                if(i > 0)
                matrix[i][j] += matrix[i-1][j]; 
                

            }
        }
        
        
        int ans = 0; 
        
        
        for(int i = 0; i < n; i++)
        {
            for(int j = i; j < n; j++)
            {
                
                ans += checksubmatrix(matrix, i, j, target); 
            }
        }
        
        
        
        return ans; 
        
        
        
    }
};