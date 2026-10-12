class Solution {
public:
    int n,m;
    int dr[4]={-1,0,1,0};
    int dc[4]={0,1,0,-1};
    vector<vector<int>>dp;
    bool isValid(int r,int c){
        if(0<=r && r<n && 0<=c && c<m){
            return true;
        }
        return false;
    }
    int dfs(int i,int j,vector<vector<int>>& mat){
        if(dp[i][j]>0){
            return dp[i][j];
        }
        int max_path=1;
        bool isPossible=false;
        for(int k=0;k<4;k++){
            int nr=i+dr[k];
            int nc=j+dc[k];
            if(isValid(nr,nc)){
                if(mat[i][j]<mat[nr][nc]){
                    max_path=max(max_path,1+dfs(nr,nc,mat));
                }

            }
        }
        
        return dp[i][j]=max_path;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int res=1;
        n=matrix.size();
        m=matrix[0].size();
        dp.assign(n,vector<int>(m,0));
        if(matrix.empty() || matrix[0].empty()){
            return 0;
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                
                res=max(res,dfs(i,j,matrix));
            }
        }
        return res;
    }
};