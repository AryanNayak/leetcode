class Solution {
public:
    vector<int> findBuildings(vector<int>& height) {
        
        int n = height.size(); 
        vector<int> answer; 
        for(int i = 0; i < n; i++)
        {
            while(!answer.empty() && height[answer.back()] <= height[i])
            {
                answer.pop_back();
            }
            answer.push_back(i); 
        }
        return answer; 
    }
};