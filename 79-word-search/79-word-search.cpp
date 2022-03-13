class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
    
        for(int i = 0; i < board.size(); i++)
        {
            for(int j = 0; j < board[0].size(); j++){
               
                if(dfs(board, i, j, word, 0))
                    return true;
            }
        }
        
        return false; 
    }
    
    bool dfs(vector<vector<char>>& board, int i, int j , string word, int idx)
    {
        
        if(idx == word.size())
            return true; 
        
        if(i < 0 || j < 0 || i  > board.size() - 1 || j > board[0].size() - 1 || board[i][j] == '*')
            return false; 
       
        if(word[idx] != board[i][j])
        {
            return false; 
        }
        
        char c = board[i][j]; 
        
        board[i][j] = '*'; 
        
        bool fSearch = dfs(board, i + 1, j, word, idx + 1) || 
                       dfs(board, i - 1, j, word, idx + 1) || 
                       dfs(board, i , j  + 1, word, idx + 1) || 
                      dfs(board, i, j - 1, word, idx + 1); 
        
        
        board[i][j] = c; 
        
        return fSearch; 
    }  
};