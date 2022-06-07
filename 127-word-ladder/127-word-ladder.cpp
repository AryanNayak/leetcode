class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        
        unordered_set<string> st(wordList.begin(), wordList.end()); 
        
        
        queue<string> q; 
        
        q.push(beginWord); 
        int ladder = 1;
        
        while(q.size() != 0)
        {
            
            int count = q.size(); 
            
            
            for(int i = 0; i < count ; i++)
            {
                
                string curr =q.front(); 
                q.pop();
                
                
                if(curr == endWord)
                {
                    return ladder; 
                }
                
                
                 st.erase(curr); 
                
                for(int j =0; j < curr.size(); j++)
                {
                    
                    
                    char a = curr[j]; 
                    
                    
                    for(int k = 0; k < 26; k++)
                    {
                        
                        
                        curr[j] = 'a' + k; 
                        
                        
                        if(st.find(curr) != st.end())
                        {
                            q.push(curr); 
                        }
                        
                    }
                    
                    curr[j] = a;
                    
                }
            }            
        
                ladder++;
            
        }
        
     return 0;    
        
        
    }
};