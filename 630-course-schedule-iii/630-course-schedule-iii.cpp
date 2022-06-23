class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        
        sort(courses.begin(), courses.end(), [](vector<int>& a, vector<int>& b){
           return b[1] > a[1];  
        });
        
        
        priority_queue<int> pq; //MAX HEAP 
        
        int sum = 0;
        
        for(auto& c: courses)
        {
            pq.push(c[0]); 

            sum += c[0]; 

            
            if(sum > c[1])
            {
                
                sum -= pq.top(); 
                
                pq.pop(); 
               
            } 
        }
        
        
        
        return pq.size(); 
      
        
    }
};