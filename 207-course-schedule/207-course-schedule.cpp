class Solution {
public:
    vector<int> kahnsAlgo(int n, vector<vector<int>>& graph)
    {       
        
        vector<int> indegree(n); 
        
        for(int i = 0; i < n; i++)
        {
            for(auto e : graph[i])
            {
                indegree[e]++; 
            }
        }
        
        vector<int> ans; 
        
        queue<int> q; 
        
        for(int i = 0; i < n; i++)
        {
            if(indegree[i] == 0)
            {
                q.push(i); 
            }
        }
        
        
        while(q.empty() == false)
        {
            
            int count = q.size(); 
            
            for(int i  = 0; i < count; i++)
            {
                
                int curr = q.front(); 
                q.pop(); 
                
                ans.push_back(curr); 
                
                for(auto e : graph[curr])
                {
                    if(--indegree[e] == 0)
                    {
                        q.push(e); 
                    }
                }
            }
        }
        
    return ans; 
        
    }
    bool canFinish(int n , vector<vector<int>>& pre) {
        
        vector<vector<int>> graph(n); 
        
        for(auto p : pre)
        {
            graph[p[0]].push_back(p[1]); 
        }
        
        
        
        vector<int> ans = kahnsAlgo(n, graph); 
        
        for(auto e : graph)
        {
            for( auto p : e)
            {
                cout << p << " "; 
            }
            cout << endl; 
        }
        
//         for(auto e : ans)
//         {
//             cout << e << endl; 
//         }
        
        return ans.size() >= n; 
    }
};