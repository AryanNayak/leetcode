class Solution {
public:
    vector<string> findStrobogrammatic(int n) {
        
        return helper(n, n); 
    }
    
    vector<string> helper(int n, int target)
    {
        //BASE CASE 
        
        if(n == 0)
        {
            return {""}; 
        }
        
        if(n == 1)
        {
            return {"0", "1", "8"}; 
        }
            
        //RECURRENCE RELATIONS
        
        vector<string> list = helper(n - 2, target); //n = 2 -> ""
                                                    //n = 4 -> {"00", "11", "69", "96"}
        
        vector<string> res; 
        

        
        for(int i =0 ; i < list.size(); i++)
        {
            
            string s = list[i];  // "" n = 4  
            
            if(n != target)
            {
                res.push_back("0" + s + "0");  
            }
        
            res.push_back("1" + s + "1"); // 11 // 1001 // 1 11 1
            res.push_back("6" + s + "9"); //69 //6009 // 6 11 9 
            res.push_back("9" + s + "6"); //96 /9006
            res.push_back("8" + s + "8"); //88// 8008
    
        }
        
        return res; 
        
    }   
};