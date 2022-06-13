class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        
        for(int level = 1; level < triangle.size(); level++)
        {
            for(int i = 0; i <= level; i++)
            {
       	triangle[level][i] += min(triangle[level - 1][min(i, (int)size(triangle[level - 1]) - 1)], // we can either come from previous level and same index
			                          triangle[level - 1][max(i - 1, 0)]);
            }
        }
        
        return *min_element(triangle.back().begin(), triangle.back().end()); 
    }
};