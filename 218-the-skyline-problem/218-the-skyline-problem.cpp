class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        
        vector<pair<int, int>> walls; 
        
        for(auto m : buildings)
        {
            walls.push_back(make_pair(m[0], -m[2])); 
            walls.push_back(make_pair(m[1],m[2])); 
        }
        
        sort(walls.begin(), walls.end()); 
        
        multiset<int> leftWallHeight = {0}; 
        
        vector<vector<int>> ans; 
        
        int top = 0; 
        
        for(auto w : walls)
        {
            if(w.second < 0)
            {
                leftWallHeight.insert(-w.second);
            }else
            {
                leftWallHeight.erase(leftWallHeight.find(w.second)); 
            }
        
            if(*leftWallHeight.rbegin() != top)
            {
                ans.push_back({w.first, top = *leftWallHeight.rbegin()}); 
            }
        
        }
        
        
        return ans;
    }
};