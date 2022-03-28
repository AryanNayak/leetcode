class Solution {
public:
    vector<int> par; 
    
    int findPar(int u)
    {
        if(par[u] == u)
        {
            return u; 
        }
    
        return par[u] = findPar(par[u]); 
    }
    
    int minCostToSupplyWater(int n, vector<vector<int>>& Edges)
    {
        
        for(int i = 0; i <= n; i++)
        {
            par.push_back(i); 
        }
        
        
        int cost = 0; 
        
        for(vector<int>& edge : Edges)
        {
            
            int u = edge[0], v = edge[1], w = edge[2]; 
            
            int p1 = findPar(u); 
            int p2 = findPar(v); 
            
            if(p1 != p2)
            {
                par[p1] = p2; 
                cost += w; 
            }
        }
        
        
        return cost; 
        
        
        
    }
    int minCostToSupplyWater(int n, vector<int>& wells, vector<vector<int>>& pipes) {
        
        for(int i = 0; i < wells.size(); i++)
        {
            pipes.push_back({0, i + 1, wells[i]}); 
        }
        
        
        sort(pipes.begin(), pipes.end(), [](vector<int>& a, vector<int>& b){
            return a[2] < b[2]; 
        });
        
 for(vector<int>& edge : pipes)
 {
    cout << edge[0] << endl; 
    cout << edge[1] << endl; 
     cout << edge[2] << endl; 
     cout << endl;
 }
        
        return minCostToSupplyWater(n, pipes);     
    }
};