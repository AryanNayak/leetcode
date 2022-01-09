/**
 * The read4 API is defined in the parent class Reader4.
 *     int read4(char *buf4);
 */

class Solution {
    
private: 
     int len = 0, bp = 0;
     char buffer[5]; 

public:
    /**
     * @param buf Destination buffer
     * @param n   Number of characters to read
     * @return    The number of actual characters read
     */
    int read(char *buf, int n) {

        int i = 0; 
        while(i < n)
        {
            
            if(bp == len)
            {
                
                bp = 0; 
                
                len = read4(buffer); 
        
                if(len == 0)
                    break; 
                
            }
            
            buf[i++] = buffer[bp++]; 
        }
        
        return i; 
    }
};