class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        
        sort(intervals.begin(), intervals.end()); 
        
        priority_queue<int, vector<int>, greater<int>> pq; 
        
        
        for(auto m : intervals)
        {
            if(pq.empty() == false && pq.top() <= m[0])
            {
                pq.pop(); 
            }
            pq.push(m[1]); 
        }
        
        return pq.size(); 
    }
};