class Solution {
public:
    double myPow(double x, int n) {
    
        long long N = n; 
        
        if(N < 0)
        {
            N = -N; 
            x = 1/x; 
        }
        
       double currP = x; 
        
        double  ans = 1; 
        
        for(long long i =N ; i ; i /= 2)
        {
            
            if(i%2 == 1)
            {
                ans = ans*currP; 
            }
            
            currP = currP*currP; 
            
        }
        
        
        return ans; 
    }
};