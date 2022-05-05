class Solution {
public:
    int minSwaps(vector<int>& data) {
        
        int ones = 0; 
        for(auto m : data)
        {
            if(m == 1)
            {
                ones++; 
            }
        }
        
        int count_one = 0, max_one = 0; 
        
        int l = 0, r = 0; 
        
        while(r < data.size())
        {
            count_one += data[r++]; 
            if(r - l > ones)
            {
                count_one -= data[l++]; 
            }
            max_one = max(max_one, count_one); 
        }
        return ones - max_one; 
    }
};