class Solution {
public:
    
   vector<vector<int>>  getSkyline(vector<vector<int>>& buildings) {
        // use walls to record buildings; left wall is an insertion event, and right wall is a deletion event
        vector<pair<int, int>> walls, ans;                  // first: x, second: height
       vector<vector<int>> fans; 
        for (auto b : buildings) {
            // push in left / right walls
            // let left wall has negative height to ensure left wall goes to multiset first if with same 'x' as right wall
            walls.push_back(make_pair(b[0], -b[2]));
            walls.push_back(make_pair(b[1], b[2]));
        }
        sort(walls.begin(), walls.end());                   // sort walls
        
        multiset<int> leftWallHeights = {0};                // keep left wall heights sorted; dummy '0' for convenience
        int top = 0;                                        // current max height among leftWallHeights
        for (auto w : walls) {
            if (w.second < 0) {                             // it's a left wall, insert the height
                leftWallHeights.insert(-w.second);
            } else {                                        // it's a right wall, delete the height
                leftWallHeights.erase(leftWallHeights.find(w.second));
            }
            
            // cout << top << endl; 
            
            // cout << "here" << *leftWallHeights.rbegin() << endl; 
            if (*leftWallHeights.rbegin() != top) {         // mark a skyline point if top changes
                fans.push_back({w.first, top = *leftWallHeights.rbegin()});
            }
        }
        
        return fans;
}
//     vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
//         vector<pair<int,int>> edges;
//         for(auto &b:buildings)
//         {
//             edges.push_back({b[0],-b[2]});
//             edges.push_back({b[1], b[2]});
//         }
//         sort(edges.begin(),edges.end());
        
//         for(auto m : edges)
//         {
//             cout << m.first << m.second << endl; 
//         }
        
//         int xlast = edges[0].first, h = 0;
//         vector<vector<int>> o;
//         multiset<int> current;
//         for(auto p:edges)
//         {
//             int x = p.first, height = p.second;
//             if(x != xlast && (o.empty() || o.back()[1] != h)) o.push_back({xlast,h});
//             xlast = x;            
//             if(height < 0) current.insert(-height);
//             else           current.erase(current.find(height));
//             h = current.empty() ? 0 : *--current.end();
//         }
//         o.push_back({xlast,h});
//         return o;
//     }
};