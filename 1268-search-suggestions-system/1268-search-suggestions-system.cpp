class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        
        int n = searchWord.size(); 
        
        sort(products.begin(), products.end()); 
        
        
        vector<vector<string>> res(n, vector<string>{}); 
        
        for(auto& product : products)
        {
            for(int i = 0; i <  n; i++)
            {
                if(product[i] != searchWord[i])
                {
                    break; 
                }
                
                if(product[i] == searchWord[i] && res[i].size() < 3)
                {
                    res[i].push_back(product); 
                }        
            }
        }
        
        return res; 
    }
};