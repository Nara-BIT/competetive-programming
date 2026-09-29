class Solution {
public:
    int n,m;
    bool dfs(int i,int j,int cnt,vector<vector<char>>&grid,vector<vector<vector<int>>>&dp){
        if(i>=n || j>=m){
            return false;
        }
        if(grid[i][j]=='('){
            cnt++;
        }
        else{
            cnt--;
        }
        if(cnt<0){
            return false;
        }
        if(dp[i][j][cnt]!=-1){
            return dp[i][j][cnt];
        }
        if(i==n-1 && j==m-1){
            return dp[i][j][cnt]=(cnt==0);
        }
        bool down=dfs(i+1,j,cnt,grid,dp);
        bool right=dfs(i,j+1,cnt,grid,dp);
        return dp[i][j][cnt]=(down||right);

    }
    bool hasValidPath(vector<vector<char>>& grid) {
        n=grid.size();
        m=grid[0].size();
        int cnt=0;
        if((m+n-1)%2!=0){
            return false;
        }
        if(grid[0][0]==')' || grid[n-1][m-1]=='('){
            return false;
        }
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(m,vector<int>(201,-1)));
        return dfs(0,0,cnt,grid,dp);
    }
};