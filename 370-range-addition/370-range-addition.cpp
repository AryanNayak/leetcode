class Solution {
public:
   vector<int> getModifiedArray(int length, vector<vector<int>>& updates) {
        vector<int> res(length, 0);
        for(auto u : updates) {
            res[u[0]] += u[2];
            if(u[1] < length-1) {
                res[u[1] + 1] -= u[2];
            }
        }
        for(auto c : res)
            cout << c << endl; 
        
        for(int i = 1; i < length; i++) {
            res[i] += res[i-1];
        }
        return res;
    }
};