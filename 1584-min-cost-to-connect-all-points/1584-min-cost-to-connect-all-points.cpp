class UnionFind
{
    vector<int> component; 
    int distinctComponents; 
public:
    
    UnionFind(int n)
    {
        distinctComponents = n; 
        for(int i = 0; i <= n; i++)
        {
            component.push_back(i); 
        }
    }
    
    bool unite(int a, int b)
    {
        if(findComponent(a) == findComponent(b))
        {
            return false; 
        }
        
        component[findComponent(a)] = b; 
        distinctComponents--; 
        return true;
    }
    
    
    int findComponent(int a)
    {
        if(component[a] != a)
        {
            component[a] = findComponent(component[a]); 
        }
        return component[a]; 
    }
    
    
    bool united(){
        
        return distinctComponents == 1; 
        
    }
    
};


class Solution {    
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
       int n = points.size(); 
       vector<array<int, 3>> edges; 
       for(int i = 0; i < n - 1; i++)
       {
           for(int j = i + 1; j < n; j++)
           {
               int dist = abs(points[i][0] - points[j][0])  +
                          abs(points[i][1] - points[j][1]); 
               
               edges.push_back({dist, i, j}); 
                }
       }
        
        make_heap(edges.begin(), edges.end(), greater<>()); 
        
        UnionFind uf(n); 
        
        int cost = 0; 
        
        while(!edges.empty() && !uf.united())
        {
            pop_heap(edges.begin(), edges.end(), greater<>()); 
            
            auto edge = edges.back(); 
            
            int p1 = edge[1]; 
            int p2 = edge[2]; 
            
            if(uf.unite(p1, p2))
            {
                cost += edge[0]; 
            }
            
            edges.pop_back(); 
            
        }
        
            return cost; 
        
    }
};