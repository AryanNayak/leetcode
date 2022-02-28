class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        int i = 0, j = 0; 
        
        int n1 = firstList.size();
        int n2 = secondList.size(); 
        
        vector<vector<int>> ans; 
        
        while(i < n1 && j < n2)
        {
            
            
//             if(firstList[i][0] <=  secondList[j][0] || firstList[i][1] >= secondList[j][1])
//             {

        int low = max(firstList[i][0],secondList[j][0]); 
        int high = min(firstList[i][1],secondList[j][1] );

        if(low <= high)
        ans.push_back({low,high});            

        if(firstList[i][1] > secondList[j][1])
        {
            j++;
        }
        else
        {
            i++; 
        }

        // cout << i << " " << j << endl; 
    // }
        }
        return ans; 

    }
};