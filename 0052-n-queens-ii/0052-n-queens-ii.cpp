class Solution {
public:
    vector<vector<string>>res;
    string row="";
    vector<string>board;
    bool isSafe(int row,int col,int n){
        int r=row;
        int c=col;
        while(0<=r && r<n && 0<=c && c<n){
            if(board[r][c]=='Q'){
                return false;
            }
            r--;
            c--;
        }
        r=row;
        c=col;
        while(0<=r && r<n && 0<=c && c<n){
            if(board[r][c]=='Q')
                return false;
            r--;
            c++;
        }
        r=row;
        c=col;
        while(0<=r && r<n && 0<=c && c<n){
            if(board[r][c]=='Q')
                return false;
            r--;
        }
        r=row;
        c=col;
        while(0<=r && r<n && 0<=c && c<n){
            if(board[r][c]=='Q')
                return false;
            c--;
        }
        return true;
        
    }
    void backtrack(int ind,int n){
        if(ind==n){
            res.push_back(board);
            return;
        }
        for(int i=0;i<n;i++){
            if(isSafe(ind,i,n)){
                board[ind][i]='Q';
                backtrack(ind+1,n);
                board[ind][i]='.';
            }
        }
        return;

    }
    int totalNQueens(int n) {
        board.assign(n,string(n,'.'));
        backtrack(0,n);
        return res.size();
    }
};