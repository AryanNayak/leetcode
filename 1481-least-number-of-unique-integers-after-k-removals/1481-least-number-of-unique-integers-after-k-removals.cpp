class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        
        unordered_map<int, int> mp; 
        
        for(auto m : arr)
        {
            mp[m]++;
        }
        
        priority_queue<int, vector<int>, greater<int>> pq; 
        
        
        for(auto m : mp )
        {
            pq.push(m.second); 
        }
        
        for(int i = 0; i < k; i++)
        {
        
            int f = pq.top(); 
            pq.pop(); 
            f--; 
            if(f != 0)
            {
                pq.push(f);
            }
        }
        
        return pq.size(); 
        
        
    }
};