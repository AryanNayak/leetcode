class SparseVector {
public:
    
    unordered_map<int,int> m; 
    
    SparseVector(vector<int> &nums) {
        for(int i = 0; i < nums.size();i++)
        {
            if(nums[i])
                m[i] = nums[i]; 
        }
    }
    
    // Return the dotProduct of two sparse vectors
    int dotProduct(SparseVector& vec) {
        
       int res = 0; 
       int size1 = m.size(); 
       int size2 = vec.m.size(); 
        if(size1  < size2)
        {
            for(auto &itr: m)
            {
                if(vec.m.count(itr.first))
                    res += (itr.second* vec.m[itr.first]); 
            }
        }
        else
        {
            for(auto &itr: vec.m)
            {
                if(m.count(itr.first))
                    res += (itr.second* m[itr.first]); 
            }
        }
        
        return res;
        
        
    }
};

// Your SparseVector object will be instantiated and called as such:
// SparseVector v1(nums1);
// SparseVector v2(nums2);
// int ans = v1.dotProduct(v2);