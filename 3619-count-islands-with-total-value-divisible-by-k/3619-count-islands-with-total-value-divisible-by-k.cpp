class Solution {
public:
    vector<int>dr={-1,0,1,0};
    vector<int>dc={0,1,0,-1};
    int n,m;
    long long dfs(int i,int j,vector<vector<int>>&grid,int k){
        long long sum=0;
        if(0<=i && i<n && 0<=j && j<m){
            sum=grid[i][j];
            grid[i][j]=0;
            }
        for(int d=0;d<4;d++){
            int nr=i+dr[d];
            int nc=j+dc[d];
            if(nr>=0 && nr<n && 0<=nc && nc<m && grid[nr][nc]>0){
                sum+=dfs(nr,nc,grid,k);
            }
        }
        return sum;
    };
    int countIslands(vector<vector<int>>& grid, int k) {
        n=grid.size();
        m=grid[0].size();
        int res=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]>0 && dfs(i,j,grid,k)%k==0){
                    res++;
                }
            }
        }
        return res;
    }
};