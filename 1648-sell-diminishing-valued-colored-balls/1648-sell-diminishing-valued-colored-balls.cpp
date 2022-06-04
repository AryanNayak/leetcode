#define mod 1000000007
class Solution {
public:
    int maxProfit(vector<int>& inv, int orders) {
        
        int n = inv.size();
        
        long long ans = 0; 
        
        sort(inv.begin(), inv.end()); 
        
        for(int i = n - 1; i >= 0; i--)
        {
            long long diff = inv[i] - (i > 0 ? inv[i - 1] : 0); 
            
            long long x = min((long long)orders, (n - i)*diff); 
            
            long long r = inv[i]; 
            
            long long l = r - x/(n-i); 
            
            
            ans += (r*(r + 1)/2 - l*(l + 1)/2)*(n - i); 
            
            ans %= mod; 
            
            ans += l*(x%(n - i)); 
            
            ans %= mod; 
            
            orders -= x; 
        }
        
        
        return ans; 
        
    }
};

