class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        
        vector<int> dis(n, 1e9);
        vector<int> nDis(n, 1e9);
        dis[src] = 0; 
        
        for(int i = 1;i <= k + 1; i++)
        {
            nDis = dis; 
            
            for(auto e : flights)
            {

            int u = e[0], v = e[1], w = e[2]; 
            
            if(dis[u] != (int)1e9  && dis[u] + w < nDis[v])
            {
                nDis[v] = dis[u] + w; 
            }   
            }
            
            dis = nDis; 
        }
        
        return dis[dst] != 1e9 ? dis[dst] : -1; 
        
    }
};