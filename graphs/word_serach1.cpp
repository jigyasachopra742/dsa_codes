class Solution
{
public:
    bool helper(vector<vector<char>>& board,  string &word, int sr, int sc, int num)
    {
        if(num == word.size())
        {
            return true;
        }
        
        if(sr < 0 || sc < 0 || sr ==  board.size()||sc == board[0].size() || board[sr][sc] == '.')
        {
            return false;
        }
        
        if(board[sr][sc] != word[num])
        {
            return false;
        }
        
             //"ABCCED" 
        char temp = board[sr][sc]; //char temp = 'A'
        board[sr][sc] = '.'; //marked already visited if correct //A = '.'(MARKED)
        
        if(helper(board, word, sr - 1, sc, num + 1)) return true; //top
        if(helper(board, word, sr, sc-1, num + 1)) return true; //left
        if(helper(board, word, sr + 1, sc, num + 1)) return true; //bottom
        if(helper(board, word, sr, sc + 1, num + 1)) return true; //right
        //and increasing the size of num
        
        board[sr][sc] = temp; //unmarked if wrong
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) 
    {
        for(int r = 0; r < board.size(); r++)
        {
            for(int c = 0; c < board[0].size(); c++)
            {
                if(helper(board, word, r, c, 0))
                {
                    return true;
                }
            }
        }
        
        return false;
        
    }
};