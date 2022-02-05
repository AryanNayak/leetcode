/**
 * // This is the BinaryMatrix's API interface.
 * // You should not implement it, or speculate about its implementation
 * class BinaryMatrix {
 *   public:
 *     int get(int row, int col);
 *     vector<int> dimensions();
 * };
 */

class Solution {
public:
    int leftMostColumnWithOne(BinaryMatrix &binaryMatrix) {
                int n = binaryMatrix.dimensions()[0];
        int m = binaryMatrix.dimensions()[1]; 
        
        int check = m - 1; 
        
        for(int i = 0; i < n; i++)
        {
            while(check >= 0 && binaryMatrix.get(i, check) == 1)
            {
                check--; 
            }
        }
        
    
    
    return (check == m - 1 ? -1 : check + 1); 
    }
};