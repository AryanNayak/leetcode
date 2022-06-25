class Solution {
public:
    int largestRectangleArea(vector<int>& height) {
    
        
        int n = height.size(); 
        
        int area = 0, h, l; 
        
        stack<int> st; 
        
        for(int i = 0 ; i<= n; i++)
        {
            
            
            while(i == n || (!st.empty() && height[st.top()] > height[i]))
            {
                if(i == n && st.empty())
                {
                     h = 0; 
                    i++; 
                }
                else
                {
                     h = height[st.top()]; 
                     st.pop(); 
                }
                
                l = st.empty() ? -1 : st.top(); 
                area = max(area, h*(i - l -1)); 
                
            }
            
         st.push(i);    
            
        }
        
      return area;   
        
        

        
//         int n = height.size();
        
//         int area = 0, h , l;
        
//         stack<int> indexes;
        
//         for(int i = 0; i <= n; i++)
//         {
//             while(i == n || (!indexes.empty() && height[indexes.top()] > height[i]))
//             {
//                 if(i == n && indexes.empty())
//                 {
//                     h = 0;
//                      i++;
//                 }
//                 else
//                 {
//                     h = height[indexes.top()];
//                     indexes.pop();
//                 }
//                 l = indexes.empty() ? - 1: indexes.top();
//                 area = max(area, h*(i-l-1));
//             }
//             indexes.push(i);
//         }
        
//         return area;
    }
};