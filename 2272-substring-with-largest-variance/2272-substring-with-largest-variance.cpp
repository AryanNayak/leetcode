class Solution {
public:
 int largestVariance(string s) {
        int ans = 0; 
        for (auto& x : "abcdefghijklmnopqrstuvwxyz") 
            for (auto& y : "abcdefghijklmnopqrstuvwxyz") 
                if (x != y) {
                    int prefix = 0, buff = 0, m = 10000; 
                    for (auto& ch : s) {
                        
                        if (ch == x) ++prefix; 
                        
                        else if (ch == y) {
                            // // cout <<"M "<<  m << " " << buff << endl; 
                            m = min(m, buff);
                            // cout << "m:"<<  m << endl;
                            buff = --prefix; 
                        }
                        
                            // cout << ans << " " << prefix << " "<< m << endl; 

                        ans = max(ans, prefix - m);
                        
                    }
                }
        return ans; 
    }
};