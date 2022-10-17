class Solution {
public:
    void dfs(vector<vector<char>>&board,int x,int y,int row,int col)
    {
        if(x<0||y<0||x>=row||y>=col||board[x][y] != 'O')
        {
            return;
        }
        board[x][y] = 'K';
        dfs(board,x-1,y,row,col);
        dfs(board,x,y+1,row,col);
        dfs(board,x+1,y,row,col);
        dfs(board,x,y-1,row,col);
    }
    void solve(vector<vector<char>>& board) {
           int row = board.size();
           int col = board[0].size();
           vector<vector<int>> visited(row,vector<int>(col,0));
            //Moving over first and last column   
     for(int i=0; i<row; i++) {
         if(board[i][0] == 'O')
             dfs(board, i, 0, row, col);
         if(board[i][col-1] == 'O')
             dfs(board,i,col-1,row, col);
     }
        
        
     //Moving over first and last row   
     for(int j=0; j<col; j++) {
         if(board[0][j] == 'O')
             dfs(board, 0, j, row, col);
         if(board[row-1][j] == 'O')
             dfs(board,row-1, j,row,col);
     }  
        for(int i = 0;i<row;i++)
        {
            for(int j = 0;j<col;j++)
            {
                cout<<board[i][j]<<" ";
            }
            cout<<endl;
        }
        for(int i = 0;i<row;i++)
        {
            for(int j = 0;j<col;j++)
            {
                if(board[i][j] == 'O')
                {
                    board[i][j] = 'X';
                }
                if(board[i][j] == 'K')
                {
                    board[i][j] = 'O';
                }
            }
        }
    }
};
